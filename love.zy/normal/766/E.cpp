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

int a[maxn][20];
int dp[maxn][20][2];
LL ans[20];
vector<int> g[maxn],son[maxn];
int n,m;

void DFS(int now,int f)
{
    for(unsigned t=0;t<g[now].size();t++)
    {
        if(g[now][t]==f)continue;
        son[now].push_back(g[now][t]);
        DFS(g[now][t],now);
    }
}

void solve(int now)
{
    if(son[now].size()==0)
    {
        for(int i=0;i<=m;i++)dp[now][i][a[now][i]]++;
        for(int i=0;i<=m;i++)ans[i]+=(LL)dp[now][i][1];
        return;
    }
    for(unsigned int t=0;t<son[now].size();t++)solve(son[now][t]);
    for(unsigned int t=0;t<son[now].size();t++)
    {
        int v=son[now][t];
        for(int i=0;i<=m;i++)
        {
            dp[now][i][a[now][i]]+=dp[v][i][0];
            dp[now][i][1^a[now][i]]+=dp[v][i][1];
        }
    }
    for(int i=0;i<=m;i++)
    {
        LL tot=0;
        ans[i]+=(LL)dp[now][i][1];
        if(a[now][i]==1)ans[i]++;
        for(unsigned int t=0;t<son[now].size();t++)
        {
            int v=son[now][t];
            tot+=(LL)dp[v][i][0]*(LL)(dp[now][i][1]-dp[v][i][1^a[now][i]]);
            tot+=(LL)dp[v][i][1]*(LL)(dp[now][i][0]-dp[v][i][0^a[now][i]]);
        }
        ans[i]+=tot/2;
        dp[now][i][a[now][i]]++;
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y=0;
        scanf("%d",&x);
        while(x>0){a[i][y++]=x&1;x>>=1;}
        m=max(y-1,m);
    }
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    DFS(1,0);solve(1);
    LL t=1,sum=0;
    for(int i=0;i<=m;i++)
    {
        sum+=t*ans[i];
        t*=2;
    }
    printf("%lld",sum);
    return 0;
}