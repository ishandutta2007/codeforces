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
const int maxn=202020;
int l[maxn],r[maxn],p[maxn];
const int mod=1e9+7;
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
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;
		upn rd(l[i]);
		upn rd(r[i]);
		l[0]=0;r[0]=0;
		p[1]=1;
		up(i,2,n)
		{
			int ql=max(l[i],l[i-1]);int qr=min(r[i],r[i-1]);
			if(ql>qr)p[i]=0;
			else p[i]=qpow((r[i]-l[i]+1)*(r[i-1]-l[i-1]+1)%mod)*(qr-ql+1)%mod;
			p[i]=1-p[i]+mod;p[i]%=mod;
		}
	//	upn cout<<p[i]<<" ";edl;
		int sum=0;
//		upn
//		{
//			up(j,i+1,n)sum+=p[i]*p[j]%mod*2%mod;
//			sum+=p[i];sum%=mod;
//		}
//		opl(sum);edl;sum=0;
		upn
		{
			sum+=p[i];sum%=mod;
		}
		sum*=sum;sum%=mod;
		upn
		{
			sum-=p[i]*p[i]%mod;sum+=p[i]+mod;sum%=mod;
		}
		up(i,1,n-1) sum-=p[i]*p[i+1]*2%mod,sum+=mod,sum%=mod;
		up(i,2,n)
		{
			int g=1;
			g-=(mod+1-p[i-1]);g-=(mod+1-p[i]);	
			g+=mod*55;g%=mod;
			int ql=Max(l[i],l[i-1],l[i-2]),qr=Min(r[i],r[i-1],r[i-2]);
			int w=qpow((r[i]-l[i]+1)*(r[i-1]-l[i-1]+1)%mod*(r[i-2]-l[i-2]+1)%mod)*(max(qr-ql+1,0ll))%mod;
		//	cout<<w;edl;
			g+=w;g%=mod;//cout<<p[i-1]<<" "<<p[i]<<" "<<g;edl;
			sum+=g*2;sum%=mod;
		}
		opl(sum);
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/