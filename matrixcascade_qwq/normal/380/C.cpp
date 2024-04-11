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
#define ls (x<<1)
#define rs ((x<<1)|1)
#define mid ((l+r)>>1)
const int maxn=1e6+10;
string s;
int bl[maxn*4],br[maxn*4],ans[maxn*4];
void pushup(int x)
{
	int p=min(br[ls],bl[rs]);
	ans[x]=ans[ls]+ans[rs]+p;
	bl[x]=bl[ls]+bl[rs]-p;
	br[x]=br[ls]+br[rs]-p;
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		if(s[l]=='(')br[x]=1;
		else bl[x]=1;
		return;
	}
	build(ls,l,mid);build(rs,mid+1,r);pushup(x);
}
int nl,nr,na;
void query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		na+=ans[x];
		int p=min(bl[x],nr);
		na+=p;
		nl=nl+bl[x]-p;
		nr=nr+br[x]-p;
		return;
	}
	if(ql<=mid)query(ls,l,mid,ql,qr);
	if(mid<qr)query(rs,mid+1,r,ql,qr);
}
signed main()
{
	int T=1;
	while(T--)
	{
		cin>>s;s=" "+s;build(1,1,(int)s.size()-1);
		rdn;
		while(n--)
		{
			int l,r;rd(l);rd(r);
			nl=nr=na=0;
			query(1,1,(int)s.size()-1,l,r);
			opl(na*2);edl;
		}
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/