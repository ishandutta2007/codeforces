#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

char ch[20];
int a[15][105];
int b[15][105];
int c[15][105];
int used[15][15][105];

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<n;i++)
    {
        scanf("%s",ch);
        for (int j=0;j<m;j++)
        {
            scanf("%d%d%d",&a[i][j],&b[i][j],&c[i][j]);
        }
    }
    int ans=0;
    for (int from=0;from<n;from++)
        for (int to=0;to<n;to++)
            if (from!=to)
            {
                int curused=0;
                int curans=0;
                while (curused<k)
                {
                    int maxd=0;
                    int pmd=-1;
                    for (int i=0;i<m;i++)
                    {
                        if (c[from][i]>0 && !used[from][to][i])
                        {
                            if (b[to][i]-a[from][i]>maxd)
                            {
                                maxd=b[to][i]-a[from][i];
                                pmd=i;
                            }
                        }
                    }
                    if (pmd==-1)
                        break;
                    curans+=maxd*min(c[from][pmd],k-curused);
                    curused+=c[from][pmd];
                    used[from][to][pmd]=1;
                }
                ans=max(ans,curans);
            }
    
    
    printf("%d",ans);


    return 0;
}