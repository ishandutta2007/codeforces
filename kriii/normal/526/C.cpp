#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    long long C,hr,hb,wr,wb;

    scanf ("%lld %lld %lld %lld %lld",&C,&hr,&hb,&wr,&wb);
    long long ans = 0;
    for (int k=0;k<2;k++){
        set<long long> chk;
        long long ur = C / wr, ub = (C - ur * wr) / wb;
        while (1){
            long long use = ur*wr+ub*wb;
            ans = max(ans,ur*hr+ub*hb);
            if (chk.count(use)) break;
            chk.insert(use);

            ub += (C - use) / wb + 1;
            use = ur*wr+ub*wb;
            ur -= (use - C + wr - 1) / wr;
            use = ur*wr+ub*wb;
            ub += (C - use) / wb;
            if (ur < 0) break;
        }

        swap(hr,hb);
        swap(wr,wb);
    }
    printf ("%lld\n",ans);

    return 0;
}