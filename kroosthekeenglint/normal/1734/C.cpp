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
int cost[1000005];
char a[1000005];
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
        int n;
        scanf("%d",&n);
        scanf("%s",a);
        int i;
        for (i=0;i<n;i++)
        {
            cost[i+1] = i+1;
            if (a[i] == '1')
            {
                cost[i+1] = 0;
            }
        }
        for (i=1;i<=n;i++)
        {
            if (a[i-1] == '0')
            {
                int j;
                for (j=i+i;j<=n;j+=i)
                {
                    if (a[j-1] == '1')
                    {
                        break;
                    }
                    cost[j] = min(cost[j], i);
                }
            }
        }
        long long ans = 0;
        for (i=1;i<=n;i++)
        {
            ans += cost[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}