#include <iostream>

#include "HybridDetect.h"

int main()
{

    bool cutting_edge_chipset = false;

    HybridDetect::PROCESSOR_INFO processor_info = {};
    GetLogicalProcessors(processor_info);
    std::vector<uint32_t> p_cores(processor_info.cores.size());
    std::vector<uint32_t> e_cores(processor_info.cores.size());
    uint32_t p_core_count = 0;
    uint32_t e_core_count = 0;

    for (auto& core: processor_info.cores)
    {
        if (core.efficiencyClass == 1)
        {
            cutting_edge_chipset = true;
            p_cores[p_core_count] = core.id;
            p_core_count +=  1;
        }
        else 
        {
            e_cores[e_core_count] = core.id;
            e_core_count += 1;
        }
    }
    p_cores.resize(p_core_count);
    e_cores.resize(e_core_count);
    for (auto core: p_cores)
    {
        std::cerr <<  "p core: " <<  core << '\n';
    }

    auto AssignToPCore = [&](HANDLE hThread)
	{
	    BOOL r = SetThreadSelectedCpuSets(hThread, PCores, cntPCore);
	    assert(r);
	};
	auto AssignToECore = [&](HANDLE hThread)
	{
	    BOOL r = SetThreadSelectedCpuSets(hThread, ECores, cntECore);
	    assert(r);
	};

}