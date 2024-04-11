#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
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
#define ft(x) for(int i=head[x];i;i=nxt[i])
#define upn up(i,1,n)
#define upm up(j,1,m)
#define pun pu(i,n,1)
#define pum pu(j,m,1)
#define up_(x) up(i,1,x)
#define pu_(x) pu(j,x,1)
#define ep emplace_back
#define fp for(auto to:
#define pf )
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define mkp make_pair
#define fi first
#define se second
#define mii map<int,int>
#define mis map<int,string>
#define msi map<string,int>
#define mvi map<vector<int>,int>
#define miv map<int,vector<int>>
#define rdn rd(n)
#define rdm rd(m)
#define rdk rd(k)
#define pb push_back
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

#define inf 1000000000000000000ll
ll Max(ll a=-inf,ll b=-inf,ll c=-inf,ll d=-inf,ll e=-inf,ll f=-inf,ll g=-inf,ll h=-inf)
{
	return max(max(max(a,b),max(c,d)),max(max(e,f),max(g,h)));
}
ll Min(ll a=inf,ll b=inf,ll c=inf,ll d=inf,ll e=inf,ll f=inf,ll g=inf,ll h=inf)
{
	return min(min(min(a,b),min(c,d)),min(min(e,f),min(g,h)));
}
#undef inf
void chkmin(int &x,int y)
{
	if(x>y)x=y;
}
void chkmax(int &x,int y)
{
	if(x<y)x=y;
}
const int maxn=101010;
int ans=0,h=0;
int f[maxn],g[maxn];
int w[maxn],hh[maxn];
int head[maxn],to[maxn*2],nxt[maxn*2];
int tot;
void add(int a,int b)
{
	to[++tot]=b;nxt[tot]=head[a];head[a]=tot;
}
int cnt;int dfn[maxn],fat[maxn];
void dfs(int x,int fa)
{
	fat[x]=fa;
	ver(x)
	{
		if(to[i]==fa)continue;
		dfs(to[i],x);
	}
	dfn[++cnt]=x;
}
int slv(int x)
{
	ans=0;
	upn f[i]=1;
	upn
	{
		int u=dfn[i];
		int ft=fat[u];
		if(ft==0)continue;
		if(f[u]!=-1&&f[ft]!=-1)
		{
			if(f[ft]+f[u]>=x)
			{
				++ans;f[ft]=-1;
			}
			else chkmax(f[ft],f[u]+1);
		}
	}
	return ans;
}
int solve(int x)
{
	if(hh[x]!=-1)return hh[x];
	h=x;ans=0;f[1]=g[1]=0;
	slv(x);hh[x]=ans;
	return ans;
}
signed main()
{
	memset(hh,-1,sizeof(hh));
	int T=1;
	while(T--)
	{
		rdn;
		up_(n-1)
		{
			int x,y;rd(x);rd(y);add(x,y);add(y,x);
		}
		int B=sqrt(n*log2(n));dfs(1,0);
		up_(B)
		{
			w[i]=solve(i);
		}
		int li=B+1,rr;
		while(li<=n)
		{
			int l=li,r=n;
			int as=-1;
			int val=solve(li);
	//		cout<<val;edl;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(solve(mid)==val)
				{
					ans=mid;l=mid+1;
				}
				else r=mid-1;
			}
			up(i,li,r)w[i]=val;
			li=r+1;
		}w[1]=n;
		upn opd(w[i]),edl;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/