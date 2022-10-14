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
#define Max Min
#define inf 1000000000000000000ll

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
int a[202020];
struct node
{
	int f[31];
}t[404400];
#define ls ((x<<1))
#define rs ((x<<1)|1)
#define mid ((l+r)>>1)
node merge(node x,node y)
{
	vector<int>v;
	up(i,0,30)v.ep(x.f[i]);
	up(i,0,30)v.ep(y.f[i]);
	sort(v.begin(),v.end());
//	reverse(v.begin(),v.end());
	node z;
	up(i,0,30)z.f[i]=v[i];
	return z;
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		t[x].f[0]=a[l];
		up(i,1,30)t[x].f[i]=Max();return;
	}
	build(ls,l,mid);build(rs,mid+1,r);
	t[x]=merge(t[ls],t[rs]);
}
node s;
void query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		s=merge(s,t[x]);return;
	}
	if(ql<=mid)query(ls,l,mid,ql,qr);
	if(mid<qr)query(rs,mid+1,r,ql,qr);
}
signed main()
{
	int T=read();
	while(T--)
	{
		rdn;
		upn rd(a[i]);
		build(1,1,n);
		int q;rd(q);
		up(i,1,q)
		{
			int l,r;rd(l);rd(r);
			int w=Max();
			up(j,0,30)s.f[j]=Max();;
			query(1,1,n,l,r);
			up(j,0,30)
			{
				up(t,j+1,30)
				{
				//	cout<<
					chkmin(w,(s.f[j]|s.f[t]));
				}
			}
			opl(w);edl;
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