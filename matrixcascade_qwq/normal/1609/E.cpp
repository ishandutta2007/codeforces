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
//a...a + c...c +  b...b 
//b...b + a...a + c...c
//c...c
//bc+ac+ab

#define ls ((x<<1))
#define rs ((x<<1)|1)
#define mid ((l+r)>>1)

const int maxn=4e5+10;
char ch[maxn];
int bc[maxn],ac[maxn],ab[maxn];
int f[maxn],g[maxn];
//f bcac
//g acab
//ans bc ac ab
int ans[maxn];
void pushup(int x)
{
	bc[x]=bc[ls]+bc[rs];
	ac[x]=ac[ls]+ac[rs];
	ab[x]=ab[ls]+ab[rs];
	f[x]=min(f[ls]+ac[rs],bc[ls]+f[rs]);
	g[x]=min(g[ls]+ab[rs],ac[ls]+g[rs]);
	ans[x]=Min(ans[ls]+ab[rs],bc[ls]+ans[rs],f[ls]+g[rs]);
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		bc[x]=(ch[l]=='a');
		ac[x]=(ch[l]=='b');
		ab[x]=(ch[l]=='c');
		return;
	}
	build(ls,l,mid);build(rs,mid+1,r);pushup(x);
}
void update(int x,int l,int r,int p,char c)
{
	if(l==r)
	{
		bc[x]=(c=='a');
		ac[x]=(c=='b');
		ab[x]=(c=='c');
		f[x]=g[x]=ans[x]=0;
		return;
	}
	if(p<=mid)update(ls,l,mid,p,c);
	else update(rs,mid+1,r,p,c);
	pushup(x);
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;int q;rd(q);
		cin>>(ch+1);
		build(1,1,n);
	//	cout<<ans[1]<<endl;
		up_(q)
		{
			int p;char t;rd(p);cin>>t;
			update(1,1,n,p,t);
			opl(ans[1]);edl;
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