/*
FUCK YOU XJOI.
FUCK YOU XJOI.
FUCK YOU XJOI.
FUCK YOU XJOI.
And in that light,I find deliverance.
*/

//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")
#define edl puts("")
#define mc cerr<<"qwq\n"
#define error goto gg
#define def gg:
#define rd(x) x=read()
#define opl(x) printf("%lld",x)
#define opls(x) printf("%lld ",x)
#define opd(x) printf("%d",x)
#define opds(x) printf("%d ",x)
#define ver(x) for(int i=head[x];i;i=nxt[i])
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define pu(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
using namespace std;
int n, m, k;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
const int maxn=1010010;
vector<int>v[1010100];
int f[maxn],dep[maxn],dp[maxn];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	f[x]=INT_MAX;
	if(!v[x].size())
	{
		f[x]=dep[x];
	}
	for(auto to:v[x])
	{
		dfs(to,x);f[x]=min(f[x],f[to]);
	}
}
void dfs2(int x)
{
	if(!v[x].size())dp[x]=1;
	for(auto to:v[x])
	{
		dfs2(to);
		if(abs(dep[x]-f[to])<=k)
		{
			dp[x]+=dp[to];dp[to]=0;
		}
	}
}
int dfs3(int x)
{
	int ans=0;
	for(auto to:v[x])ans=max(ans,dfs3(to));return ans+dp[x];
}
signed main()
{
//	freopen("qaq.in","r",stdin);
//	freopen("2.out","w",stdout);
	int T=1;
	while(T--)
	{
		n=read(),k=read();
		up(i,2,n)
		{
			int fa=read();v[fa].emplace_back(i);
		}dfs(1,0);dfs2(1);printf("%d\n",dfs3(1));
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/