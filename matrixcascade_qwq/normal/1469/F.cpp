/*
qwq
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
const int maxn=202020;
int a[maxn];
int ans[maxn<<2],tag[maxn<<2];
#define ls (x<<1)
#define rs ((x<<1)|1)
#define mid ((l+r)>>1)
void pushup(int x)
{
	ans[x]=ans[ls]+ans[rs];
}
void pushdown(int x,int l,int r)
{
	ans[ls]+=tag[x]*(mid-l+1);ans[rs]+=tag[x]*(r-mid);
	tag[ls]+=tag[x];tag[rs]+=tag[x];
	tag[x]=0;
}
void update(int x,int l,int r,int ql,int qr,int v=1)
{
	if(ql<=l&&r<=qr)
	{
		ans[x]+=(r-l+1)*v;
		tag[x]+=v;
		return;
	}
	pushdown(x,l,r);
	if(ql<=mid)update(ls,l,mid,ql,qr,v);
	if(mid<qr)update(rs,mid+1,r,ql,qr,v);
	pushup(x);
	
}
int query(int x,int l,int r,int k)
{
	if(l==r)
	{
		return l;
	}
	pushdown(x,l,r);
//	cout<<l<<" "<<mid<<" "<<ans[ls]<<'\n';
	if(ans[ls]>=k)
	{
		return query(ls,l,mid,k);
	}
	else return query(rs,mid+1,r,k-ans[ls]);
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdk;
		upn 
		{
			rd(a[i]);
		}
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		int nw=1;
		int N=200010;
		update(1,0,N,0,0);
	//	cout<<query(1,0,N,1)<<'\n';
		int mn=Min();
		upn
		{
			nw+=a[i];nw-=2;
			int f=query(1,0,N,1);
			if(a[i]&1)
			{
				update(1,0,N,f+2,f+a[i]/2+1);
				update(1,0,N,f+2,f+a[i]/2+1);
		//		cout<<f+1<<" "<<f+a[i]/2+1<<'\n';
		//		cout<<f+2<<" "<<f+a[i]/2+1<<'\n';
				update(1,0,N,f,f,-1);
			}
			else
			{
				update(1,0,N,f+2,f+a[i]/2+1);
				update(1,0,N,f+2,f+a[i]/2);
				update(1,0,N,f,f,-1);
			}
			if(nw>=k)
			{
				mn=min(mn,query(1,0,N,k));
			}
		}
		if(nw<k)
		{
			puts("-1");
		}
		else
		{
			cout<<mn;
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