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
#define int long long
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
int l,s;
const int maxn=2e5+10;
int w[maxn];
vector<int>v[maxn];
int f[maxn][20],dep[maxn],val[maxn],top[maxn];
int d1[maxn],d2[maxn];
void dfs1(int x,int fa)
{
	f[x][0]=fa;
	up(i,1,19)f[x][i]=f[f[x][i-1]][i-1];
	val[x]=val[fa]+w[x];
	dep[x]=dep[fa]+1;
	for(auto to:v[x])
	{
		if(to==fa)continue;
		dfs1(to,x);
	}
}
void dfs(int x,int fa)
{
	d1[x]=-1;
	d2[x]=0;
	if(!v[x].size())
	{
		d1[x]=top[x]-1,d2[x]=1;
		return;
	}
	for(auto to:v[x])
	{
		if(to==fa)continue;
		dfs(to,x);
		
		d1[x]=max(d1[x],d1[to]-1);
		d2[x]+=d2[to];
	}
	if(d1[x]==-1)d1[x]=top[x]-1,++d2[x];
}
signed main()
{
	int T=1;
	while(T--)
	{
		n=read(),l=read(),s=read();
		up(i,1,n)
		{
			w[i]=read();
			if(w[i]>s)
			{
				puts("-1");
				return 0;
			}
		}
		up(i,1,n-1)
		{
			int x=read();
			v[x].emplace_back(i+1);
		}
		dfs1(1,0);
		up(i,1,n)
		{
			int nw=i;
			pu(j,19,0)
			{
				if(f[nw][j]&&(dep[i]-dep[f[f[nw][j]][0]])<=l&&(val[i]-val[f[f[nw][j]][0]])<=s)
				{
					nw=f[nw][j];
				}
			}top[i]=dep[i]-dep[nw]+1;
		}dfs(1,0);cout<<d2[1];
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/