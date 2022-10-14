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
const int mod=1e9+7;
const int maxn=202020;
int fac[maxn+10],ifac[maxn+10];
int qpow(int a,int b=mod-2)
{
    int ans=1;
    while(b)
    {
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int inv(int k)
{
    return qpow(k,mod-2);
}
void pre()
{
    fac[0]=1;
    for(int i=1;i<=maxn;++i)
        fac[i]=fac[i-1]*i%mod;
    ifac[maxn]=inv(fac[maxn]);
    for (int i=maxn-1;i>=0;--i)
        ifac[i]=ifac[i+1]*(i+1)%mod;
}
int C(int nn,int mm)
{
    if(nn<0||nn-mm<0)return 0;
    return fac[nn]*ifac[mm]%mod*ifac[nn-mm]%mod;
}
int invC(int nn,int mm)
{
    if(nn<0||nn-mm<0)return 0;
    return ifac[nn]*fac[mm]%mod*fac[nn-mm]%mod;
}
vector<int>v[maxn];
int dp[maxn][202];
int s[202][202],siz[maxn],ans[maxn];
void dfs(int x,int fa)
{
	dp[x][0]=1;siz[x]=1;
	fp v[x] pf
	{
		if(to==fa)continue;
		dfs(to,x);
		pu(j,min(siz[x],k),0)
		{
			pu(t,min(siz[to],k-j),0)
			{
				int w=dp[x][j]*dp[to][t]%mod;
				dp[x][j+t]+=w;dp[x][j+t]%=mod;
				ans[j+t]+=w;ans[j+t]%=mod;
			}
		}
		up(j,0,min(siz[to],k))dp[x][j]+=dp[to][j],dp[x][j]%=mod;
		siz[x]+=siz[to];
	}
	pu(i,min(siz[x],k),0)dp[x][i+1]+=dp[x][i],dp[x][i+1]%=mod;
	
}
signed main()
{
	pre();
	int T=1;
	while(T--)
	{
		rdn;rdk;
		up_(n-1)
		{
			int x,y;rd(x);rd(y);
			v[x].ep(y);v[y].ep(x);
		}
		s[0][0]=1;
		up(i,1,k)
		{
			s[i][1]=1;
			up(j,2,i)s[i][j]=(s[i-1][j-1]+j*s[i-1][j])%mod;
		}
		int val=0;
		dfs(1,0);
		up(i,0,k)
		{
			val+=ans[i]*fac[i]%mod*s[k][i]%mod;
			val%=mod;
		}
		opl(val);
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/