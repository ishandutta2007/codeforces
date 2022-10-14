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
const int maxn=101010;
char c[maxn],s[maxn];
int dp[maxn][33];
const int mod=998244353,bas=17;
int pw[maxn];
int h1[maxn],h2[maxn];
void pre()
{
	pw[0]=1;up(i,1,maxn-10)pw[i]=1ll*pw[i-1]*bas%mod;
}
int hs1(int l,int r)
{
	return (mod+h1[r]-1ll*pw[r-l+1]*h1[l-1]%mod)%mod;
}
int hs2(int l,int r)
{
	return (mod+h2[r]-1ll*pw[r-l+1]*h2[l-1]%mod)%mod;
}
signed main()
{
	int T=1;
	while(T--)
	{
		pre();
		rdn;
		scanf("%s",c+1);
		rdm;
		scanf("%s",s+1);
		int x;rd(x);
		upn
		{
			h1[i]=(1ll*h1[i-1]*bas%mod+c[i]-'a'+1)%mod;
		}
		up_(m)
		{
			h2[i]=(1ll*h2[i-1]*bas%mod+s[i]-'a'+1)%mod;
		}
	//	opls(hs1(2,4));opls(hs2(1,3));
		up(i,0,n)
		{
			up(j,0,min(i,x))
			{
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
				int x=i+1,y=dp[i][j]+1;
				int ans=0;
				int len=min(n-x+1,m-y+1);
				int l=1,r=len;
				while(l<=r)
				{
					int mid=(l+r)>>1;
					if(hs1(x,x+mid-1)==hs2(y,y+mid-1))
					{
						ans=mid;l=mid+1;
					}
					else
					{
						r=mid-1;
					}
				}
				if(ans!=0)dp[i+ans][j+1]=max(dp[i+ans][j+1],dp[i][j]+ans);
			}
		}
		up(i,0,x)
		{
		//	opl(dp[n][i]);edl;
			if(dp[n][i]==m)
			{
				YES;
				error;
			}
		}
		NO;
		def;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/