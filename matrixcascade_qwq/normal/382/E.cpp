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
const int maxn=2020;
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
int dp[55][55][2];int i2=qpow(2);
int dfs(int n,int m,int fl)
{
	
	if(n==0&&m==0&&fl==1)return 1;
	else if(n==0)return 0;
//	if(m<n/2-1)return 0;
//	if(m<0)return 0;
	if(n==1)
	{
		if(m==0&&fl==0)return 1;
		else return 0;
	}//cout<<n<<" "<<m<<" "<<fl;edl;
	if(~dp[n][m][fl])return dp[n][m][fl];
	int ans=0;
	up(ln,0,n-1)
	{
		int rn=n-ln-1;
	//	cout<<ln<<" "<<rn;edl;
		if(ln>rn)break;
		up(lm,0,ln/2)
		{
			int rm=m-lm-1;
	//		mc;
			up(lf,0,1)
			{
				up(rf,0,1)
				{
				//	mc;
					int ff=lf&rf;
					ff=1-ff;
					if(lm+rm+ff!=m)continue;
					if(ff!=fl)continue;
			//		cout<<n<<" "<<m<<" "<<fl<<": to : "<<ln<<" "<<lm<<" "<<lf<<" and "<<rn<<" "<<rm<<" "<<rf;edl;
			///		cout<<dfs(ln,lm,lf)<<" "<<dfs(rn,rm,rf);edl;
					int val=dfs(ln,lm,lf)*dfs(rn,rm,rf)%mod*C(ln+rn,rn)%mod*(ln+rn+1)%mod;
				//	cout<<n<<" "<<m<<" "<<ln<<" "<<lm;edl;
					if(ln==rn)val*=i2,val%=mod;
					ans+=val;ans%=mod;
				}
			}
			rm=m-lm;
			if(rm<0)continue;
			up(lf,0,1)
			{
				up(rf,0,1)
				{
//					mc;
					int ff=lf&rf;
					ff=1-ff;
					if(lm+rm+ff!=m)continue;
					if(ff!=fl)continue;
				//	cout<<n<<" "<<m<<" "<<fl<<": to : "<<ln<<" "<<lm<<" "<<lf<<" and "<<rn<<" "<<rm<<" "<<rf;edl;
			//		cout<<dfs(ln,lm,lf)<<" "<<dfs(rn,rm,rf);edl;
					int val=dfs(ln,lm,lf)*dfs(rn,rm,rf)%mod*C(ln+rn,rn)%mod*(ln+rn+1)%mod;
					if(ln==rn)val*=i2,val%=mod;
					ans+=val;ans%=mod;
				}
			}
		}
	}
	dp[n][m][fl]=ans;
	return ans;
}
signed main()
{
	pre();
	int T=1;
	while(T--)
	{
		rdn;rdk;
		memset(dp,-1,sizeof(dp));
		int val1=dfs(n,k,1);
		int val0=dfs(n,k,0);
		int w=val0+val1;w%=mod;w*=qpow(n);w%=mod;
		cout<<w;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/