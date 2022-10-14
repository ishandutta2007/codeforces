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
int mod;
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
}int fac[2222],ifac[2222];
const int maxn=2000;
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
int d;
int dp[1110][11][1110];
int C(int n,int m)
{
	int ans=ifac[m];
	pu(i,n,n-m+1)ans*=i,ans%=mod;
	return ans;
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rd(d);rd(mod);pre();
		if(n==1||n==2)
		{
			puts("1");return 0;
		}
		up(j,0,10)up(k,0,1100)dp[1][0][k]=1;
		dp[1][0][0]=1;
		up(i,2,n)
		{
			up(j,1,min(d,i-1))
			{
				up(k,1,n)
				{
					dp[i][j][k]=dp[i][j][k-1];
					up(t,1,j)
					{
						if(i-k*t>0&&j-t>=0)
						{
							if(k==1)dp[i][j][k]+=dp[i-k*t][j-t][k-1]*C(dp[k][0][k-1]+t-1,t),dp[i][j][k]%=mod;
							else dp[i][j][k]+=dp[i-k*t][j-t][k-1]*C(dp[k][d-1][k-1]+t-1,t),dp[i][j][k]%=mod;
							if(i==2&&j==1&&k==1)
							{
							//	cout<<i-k*t<<" "<<j-t<<" "<<k<<" "<<dp[i-k*t][j-t][k]<<" ww\n";
							//	cout<<k<<" "<<d-1<<" "<<k-1<<" "<<dp[k][d-1][k-1];edl;
							//	cout<<dp[i][j][k];edl;
							}
						}
					}
				}
			}
		}
//		upn
//		{
//			up(j,0,d)
//			{
//				up(k,0,n)
//				{
//					cout<<i<<" "<<j<<" "<<k<<" : "<<dp[i][j][k];edl;
//				}
//			}
//		}
		if(n%2==0)
		{
			int ans;
			ans=dp[n][d][n/2];
			ans-=C(dp[n/2][d-1][n/2-1],2);ans+=mod;ans%=mod;
			opl(ans);return 0;
		}
		cout<<dp[n][d][n/2];edl;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/