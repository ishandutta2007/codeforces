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
#define mid ((l+r)>>1)
const int maxn=6e5+10;
int a[maxn],b[maxn];
vector<int>v[maxn];
int rt[maxn],ls[maxn*6],rs[maxn*6],dp[maxn];
pii ans[maxn*6];
int cnt;
int f(pii x,int y)
{
	return x.fi*y+x.se;
}
int fl=0;
void update(int &x,int l,int r,pii w)
{
//	if(w.fi==-80)cout<<l<<" "<<r,edl;

	if(!x)
	{
	//	mc;
		x=++cnt;ans[x]=w;return;
	}
	if(l==r)
	{
		if(f(ans[x],l)>f(w,l))ans[x]=w;return;
	}
	if(ans[x].fi>w.fi)
	{
		
		if(f(ans[x],mid)<f(w,mid))
		{
			update(rs[x],mid+1,r,w);
		}
		else
		{
			update(ls[x],l,mid,ans[x]);
			ans[x]=w;
		}
	}
	else if(ans[x].fi==w.fi)
	{
		if(f(ans[x],mid)>f(w,mid))ans[x]=w;
	}
	else
	{
		if(f(ans[x],mid)<f(w,mid))
		{
			update(ls[x],l,mid,w);
		}
		else
		{
			update(rs[x],mid+1,r,ans[x]);
			ans[x]=w;
		}
	}
}
int query(int x,int l,int r,int y)
{
	
	if(!x)return Min();
	//if(fl==5)cout<<ans[x].fi<<" "<<ans[x].se<<'\n';
	if(l==r)
	{
		return f(ans[x],y);
	}
//	cout<<ans[x].fi<<" "<<ans[x].se;edl;
	int nw=f(ans[x],y);
	if(y<=mid)nw=min(nw,query(ls[x],l,mid,y));
	else nw=min(nw,query(rs[x],mid+1,r,y));
	return nw;
}
int merge(int x,int y,int l,int r)
{
//	cout<<x<<" "<<y;edl;
	if(!x||!y)return x|y;
//	mc;
	if(l==r)
	{
		if(f(ans[x],l)>f(ans[y],l))ans[x]=ans[y];
		return x;
	}
	ls[x]=merge(ls[x],ls[y],l,mid);rs[x]=merge(rs[x],rs[y],mid+1,r);
	update(x,l,r,ans[y]);
	return x;
}
void dfs(int x,int fa)
{
//	cout<<x;edl;
	int u=0;
	fp v[x] pf
	{
		if(to==fa)continue;dfs(to,x);
	//	cout<<x<<" "<<to<<" "<<rt[x]<<" "<<rt[to];edl;
		rt[x]=merge(rt[x],rt[to],-100000,100000);++u;
		
	}
	fl=x;
	if(!u)
	{
	//	mc;
		dp[x]=0;
	}
	else
	{
		dp[x]=query(rt[x],-100000,100000,a[x]);
	}
//	cout<<x<<" "<<b[x];edl;
	update(rt[x],-100000,100000,mkp(b[x],dp[x]));
//	if(x==2)
//	{
		//cout<<(rt[x],-100000,100000)
//	}
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;
		upn rd(a[i]);
		upn rd(b[i]);
		up_(n-1)
		{
			int x,y;rd(x);rd(y);
			v[x].ep(y);v[y].ep(x);
		}
		//upn rt[i]=i;
		dfs(1,0);
	//	assert(cnt<=500000);
	//	upn opls(rt[i]);edl;
		upn
		{
			opls(dp[i]);
		}
	}
}
/*
5
7 -8 -8 -3 -10
6 1 -6 7 5
3 1
2 5
1 4
4 5
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/