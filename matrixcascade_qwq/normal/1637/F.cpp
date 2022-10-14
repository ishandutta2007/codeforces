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
const int maxn=2e5+100;
int h[maxn],d[maxn],w[maxn];
vector<int>v[maxn];
int rt;
int gg=0;
void dfs(int x,int fa)
{
//	gg+=w[x];
//	cout<<w[x];edl;
	w[x]=h[x];
	fp v[x] pf
	{
		if(to==fa)continue;
		
		dfs(to,x);w[x]=max(w[x],w[to]);;
	}
}
int cmp(int a,int b)
{
	return w[a]>w[b];
}
void dfs2(int x,int fa,int mx)
{
//	cout<<x;edl;
	if(x==rt)
	{
	//	cout<<"qwrqfefq";
		if(d[x]==1)
		{
			gg+=mx;
			int ss=0;
			fp v[x] pf
			{
				if(to==fa)continue;
				if(w[to]>w[ss])
				{
					ss=to;
				}
			}
			fp v[x] pf
			{
				if(to==fa)continue;
				if(ss==to)dfs2(to,x,mx);
				else dfs2(to,x,w[to]);
			}
			return;
		}
		vector<int>g;
		fp v[x] pf g.ep(to);
		sort(g.begin(),g.end(),cmp);
		up(i,0,(int)g.size()-1)
		{
		//	cout<<g[i]<<" ";
			if(g[i]==fa)continue;
			if(i<2)dfs2(g[i],x,mx);
			else dfs2(g[i],x,w[g[i]]);
		}//edl;
//		fp v[x] pf
//		{
//			dfs2(to,x,w[to]);
//		}
		return;
	}
	
	int son=0;//cout<<x<<" "<<w[x];edl;
	if(v[x].size()==1)
	{
		
		gg+=mx;
	}
	fp v[x] pf
	{
		if(to==fa)continue;
		if(w[to]>w[son])
		{
			son=to;
		}
	}
	fp v[x] pf
	{
		if(to==fa)continue;
		if(son==to)dfs2(to,x,mx);
		else dfs2(to,x,w[to]);
	}return;
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;
		int mx=0;
		upn rd(h[i]),mx=max(mx,h[i]);
		up_(n-1)
		{
			int x,y;rd(x);rd(y);v[y].ep(x);v[x].ep(y);++d[x];++d[y];
		}
		if(n==2)
		{
			int ans=max(h[1],h[2])*2;
			opl(ans);
			continue;
		}
		vector<int>vv;
		upn
		{
			if(h[i]>h[rt])rt=i;
		}
		dfs(rt,0);
		dfs2(rt,0,w[rt]);
		opl(gg);
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/