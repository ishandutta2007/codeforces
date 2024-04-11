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
const int maxn=4e5+10;
int a[maxn];
int ans[maxn][11];
int tag[maxn][11];
void pushup(int x)
{
	up(i,0,9)ans[x][i]=ans[ls][i]+ans[rs][i];
}
int bt[11],bs[11];
void f(int x,int y)
{
	memset(bs,0,sizeof(bs));
	memset(bt,0,sizeof(bt));
	up(i,0,9)bs[tag[x][i]]+=ans[y][i];
	up(i,0,9)tag[y][i]=tag[x][tag[y][i]];
	up(i,0,9)
	{
	//	cout<<(ans[y][i]==bs[i])<<" qwq"<<'\n';
		ans[y][i]=bs[i];
	}
}
void pushdown(int x)
{
	f(x,ls);f(x,rs);
	up(i,0,9)tag[x][i]=i;
}
void build(int x,int l,int r)
{
	up(i,0,9)tag[x][i]=i;
	if(l==r)
	{
		int nw=a[l],p=1;
		while(nw)
		{
			ans[x][nw%10]+=p;
			nw/=10;p*=10;
		}
		return;
	}
	build(ls,l,mid);build(rs,mid+1,r);
	pushup(x);
}
void update(int x,int l,int r,int ql,int qr,int xx,int y)
{
	if(ql<=l&&r<=qr)
	{
		ans[x][y]+=ans[x][xx];ans[x][xx]=0;
	//	up(i,0,9)cout<<tag[x][i]<<" ";edl;
	//	cout<<x<<" "<<l<<" "<<r;edl;
		up(i,0,9)if(tag[x][i]==xx)tag[x][i]=y;
//		up(i,0,9)cout<<tag[x][i]<<" ";edl;
		return;
	}
	pushdown(x);
	if(ql<=mid)update(ls,l,mid,ql,qr,xx,y);
	if(mid<qr) update(rs,mid+1,r,ql,qr,xx,y);
	pushup(x);
}
int query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
//		cout<<l<<" "<<r;edl;
		int f=0;
		up(i,0,9)f+=ans[x][i]*i;
		return f;
	}
	int ww=0;
	pushdown(x);
	if(ql<=mid)ww+=query(ls,l,mid,ql,qr);
	if(mid<qr)ww+=query(rs,mid+1,r,ql,qr);
	return ww;
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;
		upn rd(a[i]);
		build(1,1,n);
	//	opl(query(1,1,n,2,4));edl;
		upm
		{
			int opt,l,r,x,y;
			rd(opt);rd(l);rd(r);
			if(opt==1)
			{
				rd(x);rd(y);
				if(x==y)continue;
				
				update(1,1,n,l,r,x,y);
			}
			else
			{
				opl(query(1,1,n,l,r));edl;
			}
		}
	}
}
/*
5 3
1 1 1 1 1
1 1 3 1 5
1 3 5 1 5
2 1 5
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/