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
  
const int maxn=100005;
int ans[2*maxn];
vector<int> g[2*maxn];
int dat[maxn][2];
int n,i;

void dfs(int now,int num)
{
    ans[now]=num;
    for(unsigned int t=0;t<g[now].size();t++)
        if(ans[g[now][t]]==0)
            dfs(g[now][t],3-num);
}

int main()
{
    scanf("%d",&n);
    for(i=1;i<=n-1;i++)
    {
        g[2*i].push_back(2*i+1);
        g[2*i+1].push_back(2*i);
    }
    g[1].push_back(2*n);
    g[2*n].push_back(1);
    for(i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
        dat[i][0]=x;
        dat[i][1]=y;
    }
    for(i=1;i<=2*n;i++)
        if(ans[i]==0)dfs(i,1);
    for(i=1;i<=n;i++)
    {
        printf("%d %d\n",ans[dat[i][0]],ans[dat[i][1]]);
    }
    return 0;
}