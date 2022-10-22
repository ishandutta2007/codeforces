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
char a[1005];
int vis[1005];
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
        scanf("%s",a);
        int i;
        for (i=0;i<n;i++)
        {
            vis[i] = 0;
        }
        int up_size = n/m;
        for (i=0;i<m;i++)
        {
            char j;
            int cnt = 0;
            for (j='a';j<='z';j++)
            {
                if (cnt == up_size)
                {
                    printf("%c",j);
                    break;
                }
                int k;
                for (k=0;k<n;k++)
                {
                    if (vis[k])
                    {
                        continue;
                    }
                    if (a[k] == j)
                    {
                        vis[k] = true;
                        cnt ++;
                        break;
                    }
                }
                if (k == n)
                {
                    printf("%c",j);
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}