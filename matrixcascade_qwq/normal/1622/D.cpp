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
#define fr for(auto to:
#define rf )
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
int b[5050];
const int mod=998244353;
int dp[5050][5050];
int l[5050],r[5050],sum[5050];
const int maxn=20202;
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
	if(nn<mm)return 0;
    return fac[nn]*ifac[mm]%mod*ifac[nn-mm]%mod;
}
int invC(int nn,int mm)
{
    return ifac[nn]*fac[mm]%mod*fac[nn-mm]%mod;
}
int z[5050],tt=0;
signed main()
{
	int T=1;
	pre();	
	while(T--)
	{
		rd(n);rd(k);
		if(k==0)
		{
			puts("1");
			continue;
		}
		upn scanf("%1lld",&b[i]),sum[i]=sum[i-1]+b[i];
		upn
		{
			if(b[i]==1)z[++tt]=i;
		}
		
		int pl=-1,pr=-1,ans=1;
		for(int i=1;i+k-1<=tt;++i)
		{
			int L=z[i],R=z[i+k-1];
			pu(j,z[i]-1,1)
			{
				if(b[j]==1)break;
				L=j;
			}
			up(j,z[i+k-1]+1,n)
			{
				if(b[j]==1)break;
				R=j;
			}
			ans+=C((R-L+1),k)-1;ans+=mod;
			ans%=mod;
			if(pl!=-1)
			{
				ans-=C(pr-L+1,k-1)-1;
				ans+=mod;ans%=mod;
				
			}
			pl=L;pr=R;
			
		}
		opl(ans);
		
	}
}
/*
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/
/*
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
#define fr for(auto to:
#define rf )
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
int b[5050];
const int mod=998244353;
int dp[5050][5050];
int l[5050],r[5050],sum[5050];
const int maxn=20202;
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
	if(nn<mm)return 0;
    return fac[nn]*ifac[mm]%mod*ifac[nn-mm]%mod;
}
int invC(int nn,int mm)
{
    return ifac[nn]*fac[mm]%mod*fac[nn-mm]%mod;
}
int z[5050],tt=0;
signed main()
{
	int T=1;
	pre();	
	while(T--)
	{
		rd(n);rd(k);
		if(k==0)
		{
			puts("1");
			continue;
		}
		upn scanf("%1lld",&b[i]),sum[i]=sum[i-1]+b[i];
		upn
		{
			if(b[i]==1)z[++tt]=i;
		}
		
		int pl=-1,pr=-1,ans=1;
		for(int i=1;i+k-1<=tt;++i)
		{
			int L=z[i],R=z[i+k-1];
			pu(j,z[i]-1,1)
			{
				if(b[j]==1)break;
				L=j;
			}
			up(j,z[i+k-1]+1,n)
			{
				if(b[j]==1)break;
				R=j;
			}
			ans+=C((R-L+1),k)-1;ans+=mod;
			ans%=mod;
			if(pl!=-1)
			{
				ans-=C(pr-L+1,k-1)-1;
				ans+=mod;ans%=mod;
				
			}
			pl=L;pr=R;
			
		}
		opl(ans);
		
	}
}#include <bits/stdc++.h>
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
#define fr for(auto to:
#define rf )
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
int b[5050];
const int mod=998244353;
int dp[5050][5050];
int l[5050],r[5050],sum[5050];
const int maxn=20202;
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
	if(nn<mm)return 0;
    return fac[nn]*ifac[mm]%mod*ifac[nn-mm]%mod;
}
int invC(int nn,int mm)
{
    return ifac[nn]*fac[mm]%mod*fac[nn-mm]%mod;
}
int z[5050],tt=0;
signed main()
{
	int T=1;
	pre();	
	while(T--)
	{
		rd(n);rd(k);
		if(k==0)
		{
			puts("1");
			continue;
		}
		upn scanf("%1lld",&b[i]),sum[i]=sum[i-1]+b[i];
		upn
		{
			if(b[i]==1)z[++tt]=i;
		}
		
		int pl=-1,pr=-1,ans=1;
		for(int i=1;i+k-1<=tt;++i)
		{
			int L=z[i],R=z[i+k-1];
			pu(j,z[i]-1,1)
			{
				if(b[j]==1)break;
				L=j;
			}
			up(j,z[i+k-1]+1,n)
			{
				if(b[j]==1)break;
				R=j;
			}
			ans+=C((R-L+1),k)-1;ans+=mod;
			ans%=mod;
			if(pl!=-1)
			{
				ans-=C(pr-L+1,k-1)-1;
				ans+=mod;ans%=mod;
				
			}
			pl=L;pr=R;
			
		}
		opl(ans);
		
	}
}
*/