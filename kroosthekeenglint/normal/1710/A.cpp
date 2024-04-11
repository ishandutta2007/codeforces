#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    int zu;
    for (zu=0;zu<t;zu++)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        long long sum_r = 0, sum_c = 0;
        bool have_3_r = 0, have_3_c = 0;
        int i;
        for (i=0;i<k;i++)
        {
            int x;
            scanf("%d",&x);
            if (x/n >= 2)
            {
                sum_r += x/n;
            }
            if (x/m >= 2)
            {
                sum_c += x/m;
            }
            if (x/n >= 3)
            {
                have_3_r = true;
            }
            if (x/m >= 3)
            {
                have_3_c = true;
            }
        }
        bool is_yes = false;
        if (sum_r >= m)
        {
            if ((m%2==0) || (have_3_r))
            {
                is_yes = true;
            }
        }
        if (sum_c >= n)
        {
            if ((n%2==0) || (have_3_c))
            {
                is_yes = true;
            }
        }
        if (is_yes)
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
    return 0;
}