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
        int n,m;
        scanf("%d%d",&n,&m);
        int i;
        for (i=0;i<n;i++)
        {
            int j;
            for (j=0;j<m;j++)
            {
                printf("%d ",((i&1)^(j&1)^((i>>1)&1)^((j>>1)&1)));
            }
            printf("\n");
        }
    }
    return 0;
}