//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define int long long
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
struct bit
{
	int c[2][2][1111][1111];
	int lowbit(int x)
	{
		return x&(-x);
	}
	void upd(int x,int y,int val=1)
	{
		for(int i=x;i<=n;i+=lowbit(i))
		{
			for(int j=y;j<=n;j+=lowbit(j))
			{
				c[x&1][y&1][i][j]^=val;;
			}
		}
	}
	int qry(int x,int y)
	{
		int ans=0;
		for(int i=x;i;i-=lowbit(i))
		{
			for(int j=y;j;j-=lowbit(j))
			{
				
				ans^=c[x&1][y&1][i][j];
			}
		}
		return ans;
	}
}a1,a2,a3,a4;
void update(int x,int y,int k)
{
	a1.upd(x,y,k);
}
int query(int x,int y)
{
	int ans=0;
	ans+=a1.qry(x,y);
	return ans;
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;
		int opt;
		while(m--)
		{
			rd(opt);
			int l1,r1,l2,r2;rd(l1);rd(r1);rd(l2);rd(r2);
			if(opt==2)
			{
				int w=read();
				update(l1,r1,w);
				update(l1,r2+1,w);
				update(l2+1,r1,w);
				update(l2+1,r2+1,w);
			}
			else
			{
				int ans=query(l2,r2)^query(l1-1,r2)^query(l2,r1-1)^query(l1-1,r1-1);
				printf("%lld",ans);edl;
			}
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