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
const int mod=998244353;
const int maxn=3650;
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
int dp1[maxn][maxn/2];
int dp2[maxn][maxn/2];
int b1[maxn],b2[maxn];
int tot1=0,tot2=0;
int get1(int i,int j)
{
	int ans=dp1[n][i];
	ans*=C(tot1-i*2,j);ans%=mod;return ans;
}
int get2(int i,int j)
{
	int ans=dp2[m][i];
//	cout<<dp2[m][i];edl;
	ans*=C(tot2-i*2,j);ans%=mod;return ans;
}
signed main()
{
	pre();
	int T=1;
	while(T--)
	{
		rdn;rdm;rdk;
		dp1[0][0]=1;
		up_(k)
		{
			int a,b,c,d;rd(a);rd(b);rd(c);rd(d);
			b1[a]=b1[c]=1;
			b2[b]=b2[d]=1;
		}upn if(b1[i]==0)++tot1;up_(m)if(b2[i]==0)++tot2;
		upn
		{
			up(j,0,i/2)
			{
				dp1[i][j]=dp1[i-1][j];
				if(j)
				{
					if(i>1&&b1[i]==0&&b1[i-1]==0)dp1[i][j]+=dp1[i-2][j-1];
				}dp1[i][j]%=mod;
			}
		}dp2[0][0]=1;
		up_(m)
		{
			up(j,0,i/2)
			{
				dp2[i][j]=dp2[i-1][j];
				if(j)
				{
					if(i>1&&b2[i]==0&&b2[i-1]==0)dp2[i][j]+=dp2[i-2][j-1];
				}dp2[i][j]%=mod;
			//	cout<<i<<" "<<j<<" "<<dp2[i][j];edl;
				
			}
		}
	//	cout<<dp1[5][0];edl; cout<<get2(1,0);edl;cout<<dp2[m][1];edl;
		int ans=0;
		up(i,0,max(n,m))
		{
			up(j,0,max(n,m))
			{
				
		//		cout<<dp2[2][1];edl;
				int w;w=fac[i]*fac[j]%mod*get1(i,j)%mod*get2(j,i)%mod;
		//		if(w)cout<<i<<" "<<j<<" "<<get1(i,j)<<" "<<get2(j,i),edl;
				ans+=w;ans%=mod;
			}
		}
		opl(ans);
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/