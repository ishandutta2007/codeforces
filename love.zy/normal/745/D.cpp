#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))

vector<int> g[15][2];
int ans[1005][15][2];
int used[15];
int da[1005];
int i,j,k,l,m,n;

void QA(int x,int y)
{
    printf("%d\n",g[x][y].size());
    for(unsigned int t=0;t<g[x][y].size();t++)
    {
        if(t>0)printf(" ");
        printf("%d",g[x][y][t]);
    }
    printf("\n");
    fflush(stdout);
    for(int t=1;t<=n;t++)scanf("%d",&ans[t][x][y]);
}

int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        j=i;k=0;
        while(j>0)
        {
            k++;g[k][j&1].push_back(i);
            if(j&1)used[k]=1;
            j>>=1;
        }
        while(k<10)g[++k][0].push_back(i);
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=10;j++)ans[i][j][0]=ans[i][j][1]=1e9+7;
    for(i=1;i<=10;i++)
    {
        if(used[i]<=0)break;
        if(g[i][0].size()>0)QA(i,0);
        if(g[i][1].size()>0)QA(i,1);
    }
    for(i=1;i<=n;i++)
    {
        da[i]=1e9+7;k=i;
        for(j=1;j<=10;j++)
        {
            da[i]=min(da[i],ans[i][j][(k&1)^1]);
            k>>=1;
        }
    }
    printf("-1\n");
    for(i=1;i<=n;i++)
    {
        if(i>1)printf(" ");
        printf("%d",da[i]);
    }
    fflush(stdout);
    return 0;
}