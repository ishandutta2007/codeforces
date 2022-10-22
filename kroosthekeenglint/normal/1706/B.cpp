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
int od[100005];
int ev[100005];
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
        int i;
        for (i=1;i<=n;i++)
        {
            od[i]=0;
            ev[i]=0;
        }
        for (i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if (i%2==1)
            {
                od[x] = max(od[x], ev[x]+1);
            }
            else
            {
                ev[x] = max(ev[x], od[x]+1);
            }
        }
        for (i=1;i<=n;i++)
        {
            printf("%d ",max(od[i],ev[i]));
        }
        printf("\n");
    }
    return 0;
}