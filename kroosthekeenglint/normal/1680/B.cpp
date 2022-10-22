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
char a[15][15];
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
        int i,j;
        for (i=0;i<n;i++)
        {
            scanf("%s",a[i]);
        }
        int min_i=10,min_j=10;
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                if (a[i][j]=='R')
                {
                    min_i=min(min_i,i);
                    min_j=min(min_j,j);
                }
            }
        }
        if ((min_i==10)||(a[min_i][min_j]=='E'))
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}