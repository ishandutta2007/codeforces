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
const int maxn=2e5+10;
int d[maxn],h[maxn];
#define mid ((l+r)>>1)
#define ls ((x)<<1)
#define rs ((x<<1)|1)
struct node
{
	int mx,mn,ans;
}t[maxn<<2];
node pushup(node a,node b)
{
	node w;
	w.ans=max(max(a.ans,b.ans),a.mn+b.mx);
	w.mx=max(a.mx,b.mx);
	w.mn=max(a.mn,b.mn);
	return w;
}
void build(int x,int l,int r)
{
	//cout<<x<<" "<<l<<" "<<r;edl;
	if(l==r)
	{
		t[x].mx=d[l]+h[l];
		t[x].mn=h[l]-d[l];
		t[x].ans=Max();
		return;
	}
	assert(l!=r);
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[x]=pushup(t[ls],t[rs]);
}
node query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql)
	{ 	
		return (node){-1000000000000000ll,-1000000000000000ll,-1000000000000000ll};
	}
	if(ql<=l&&r<=qr) return t[x];
	return pushup(query(ls,l,mid,ql,qr),query(rs,mid+1,r,ql,qr));
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;
		up(i,2,n+1) rd(d[i]),d[i+n]=d[i];
		upn rd(h[i]),h[i+n]=h[i]*2,h[i]*=2;
		up_(n+n) d[i]+=d[i-1];
	//	up_(n+n)opls(h[i]);
	//	edl;
		build(1,1,n+n);
		while(m--)
		{
			int l,r;rd(l);rd(r);
			swap(l,r);
			if(l<r)++l,--r;
			else r+=n-1,++l;
		//	cout<<l<<" "<<r;edl;
			opl(query(1,1,n+n,l,r).ans);edl;
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