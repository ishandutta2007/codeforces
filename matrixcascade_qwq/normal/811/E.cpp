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
int a[11][111111];
int cnt=0;
int fa[1010101];
struct node
{
	int l[11],r[11],sum;
}ans[404040];
#define ls ((x<<1))
#define rs ((x<<1)|1)
#define mid ((l+r)>>1)
int find(int x)
{
	return x==fa[x]?fa[x]:fa[x]=find(fa[x]);
}
node get(int l)
{
	node x;x.sum=0;
	upn
	{
		if(a[i][l]!=a[i-1][l])
		{
			x.l[i]=++cnt;++x.sum;
		}
		else
		{
			x.l[i]=x.l[i-1];
		}
	}
	upn x.r[i]=x.l[i];
	return x;
}
node merge(node x,node y,int md)
{
	node ans;
	ans.sum=x.sum+y.sum;
	upn fa[x.l[i]]=x.l[i],fa[y.r[i]]=y.r[i],fa[x.r[i]]=x.r[i],fa[y.l[i]]=y.l[i];
	upn
	{
		ans.l[i]=x.l[i],ans.r[i]=y.r[i];
	}
	upn
	{
		if(a[i][md]==a[i][md+1])
		{
			int fx=find(x.r[i]),fy=find(y.l[i]);
			if(fx!=fy)
			{
				fa[fx]=fy;--ans.sum;
			}
		}
	}upn ans.l[i]=find(ans.l[i]),ans.r[i]=find(ans.r[i]);
	return ans;
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		ans[x]=get(l);
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	ans[x]=merge(ans[ls],ans[rs],mid);
}
node as;
int fl=1;
void query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		if(fl)
		{
			as=ans[x];fl=0;
		}
		else
		{
			as=merge(as,ans[x],l-1);
		}
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
		int q;rdn;rdm;rd(q);
		upn
		{
			upm rd(a[i][j]);
		}
		build(1,1,m);
		while(q--)
		{
			int l,r;rd(l);rd(r);
			fl=1;
			query(1,1,m,l,r);
			opd(as.sum);edl;
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





//