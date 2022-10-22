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
int a[505][505];
int x[250005],y[250005],z[250005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    int t;
    scanf("%d",&t);
    int zu;
    for (zu=0;zu<t;zu++)
    {
        scanf("%d%d",&n,&m);
        int i,j;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                a[i][j] = -1;
                if (i == j)
                {
                    a[i][j] = 0;
                }
            }
        }
        for (i=0;i<m;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            x[i]--;
            y[i]--;
            a[x[i]][y[i]] = 1;
            a[y[i]][x[i]] = 1;
            scanf("%d",&z[i]);
        }
        int k;
        for (k=0;k<n;k++)
        {
            for (i=0;i<n;i++)
            {
                if (a[i][k] == -1)
                {
                    continue;
                }
                for (j=0;j<n;j++)
                {
                    if (a[j][k] == -1)
                    {
                        continue;
                    }
                    if ((a[i][j] == -1) || (a[i][j] > a[i][k] + a[k][j]))
                    {
                        a[i][j] = a[i][k] + a[k][j];
                    }
                }
            }
        }
        long long min_ans = 123456789012345678ll;
        for (i=0;i<m;i++)
        {
            int len = min(a[0][x[i]] + 1 + a[y[i]][n-1], a[0][y[i]] + 1 + a[x[i]][n-1]);
            int j;
            for (j=0;j<n;j++)
            {
                len = min(len, a[0][j] + a[j][n-1] + a[x[i]][j] + 2);
                len = min(len, a[0][j] + a[j][n-1] + a[y[i]][j] + 2);
            }
            min_ans = min(min_ans, (long long)len * z[i]);
        }
        printf("%lld\n",min_ans);
    }
    return 0;
}