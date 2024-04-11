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
int a[111],b[111],sum[111];
int dp[2][11111];
signed main()
{
	int T=read();
	while(T--)
	{
		rdn;
		upn rd(a[i]);
		upn rd(b[i]);
		sum[n+1]=0;
		pu(i,n,1)
		{
			sum[i]=sum[i+1]+a[i]+b[i];
		}
		memset(dp,0x3f,sizeof(dp));
		dp[(n+1)&1][0]=0;
		pu(i,n,1)
		{
			up(j,0,10000)
			{
				chkmin(dp[i&1][j+a[i]],dp[(i+1)&1][j]+a[i]*j+b[i]*(sum[i+1]-j));
				chkmin(dp[i&1][j+b[i]],dp[(i+1)&1][j]+b[i]*j+a[i]*(sum[i+1]-j));
			}
			memset(dp[(i+1)&1],0x3f,sizeof(dp[(i+1)&1]));
		}
		int ans=0;
		upn
		{
			up(j,i+1,n)
			{
				ans+=a[i]*a[i];ans+=a[j]*a[j];
				ans+=b[i]*b[i];ans+=b[j]*b[j];
			}
		}
		int mn=Min();
		up(i,0,10000)
		{
			mn=min(mn,dp[1][i]);
		}
		ans+=2*mn;
		opl(ans);edl; 
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/