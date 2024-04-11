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
 
const int maxn=105;

int pre[maxn],low[maxn],a[maxn],sccno[maxn],tot[maxn];
int edge[100005][2];
int dfs_clock,scc_cnt,maxx;
vector<int> g[maxn];
stack<int> s;

int n,m,p0,p1,i,j,k,l;

void dfs(int u)
{
	pre[u]=low[u]=++dfs_clock;
	s.push(u);
	for(unsigned int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(!pre[v])
		{
			dfs(v);
			low[u]=min(low[u],low[v]);
		}else if(!sccno[v])low[u]=min(low[u],pre[v]);
	}
	if(low[u]==pre[u])
	{
		scc_cnt++;
		for(;;)
		{
			int x=s.top();s.pop();
			sccno[x]=scc_cnt;
			if(x==u)break;
		}
	}
}

void find(int n)
{
	dfs_clock=scc_cnt=0;
	memset(sccno,0,sizeof(sccno));
	memset(pre,0,sizeof(pre));
	memset(low,0,sizeof(low));
	while(!s.empty())s.pop();
	for(i=1;i<=n;i++)
    {
        if(pre[i])continue;
        if(g[i][0]==i)
        {
            sccno[i]=++scc_cnt;
            continue;
        }
        dfs(i);
    }
}

LL gcd(LL x,LL y)
{
    if(x==0)return y;
    if(y==0)return x;
    return gcd(y,x%y);
}
vector<int> sc[maxn];
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&j);
        g[i].push_back(j);
    }
    find(n);
    LL cnt[105];
    memset(cnt,0,sizeof(cnt));
    for(i=1;i<=n;i++)
    {
        cnt[sccno[i]]++;
        sc[sccno[i]].push_back(i);
    }
    for(i=1;i<=scc_cnt;i++)
    {
        if(cnt[i]==1 && g[sc[i][0]][0]!=sc[i][0])
        {
            printf("-1");return 0;
        }
    }
    for(i=1;i<=scc_cnt;i++)
        if(cnt[i]%2==0)cnt[i]/=2;
    LL ans=1;
    for(i=1;i<=scc_cnt;i++)
    {
        LL tt=gcd(ans,cnt[i]);
        ans/=tt;
        ans*=cnt[i];
    }
    printf("%lld",ans);
    return 0;
}