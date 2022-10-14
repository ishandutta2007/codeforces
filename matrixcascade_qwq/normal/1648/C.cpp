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
const int mod=998244353;
const int maxn=302020;
int a[maxn],bb[maxn];
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
struct bit
{
    int c[maxn];
    int lowbit(int x){return x&(-x);}
    void upd(int x,int y=1){for(;x<=200000;x+=lowbit(x))c[x]+=y,c[x]%=mod;}
    int qry(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x],ans%=mod;return ans;}
    int operator[](int x) {return qry(x);}
}b;
int w[maxn];
signed main()
{
//	freopen("qwq.in","r",stdin);
//	 freopen("w.out","w",stdout);
	pre();
	int T=1;
	while(T--)
	{
		
		rdn;rdm;
		upn rd(a[i]);
		up_(m)rd(bb[i]);
		upn w[a[i]]++;
		int ans=fac[n];
		up(i,1,200000)
		{
			ans*=qpow(fac[w[i]]);ans%=mod;
		}
		up(i,1,200000)
		{
			if(w[i]==0)continue;
			b.upd(i,w[i]);
		}
		//opl(ans);edl;
		int sum=0;
		int nw=n;
		up(i,1,min(n,m))
		{
		//	if(i==2)mc;
			int g=ans*qpow(nw)%mod*b[bb[i]-1]%mod;
	//		cout<<b[bb[i]-1];edl;
			sum+=g;sum%=mod;
			//cout<<i<<" "<<g;edl;
			b.upd(bb[i],-1);
			w[bb[i]]--;
			ans*=qpow(nw);ans%=mod;
			ans*=(w[bb[i]]+1);ans%=mod;nw--;
			if(w[bb[i]]<0)
			{
				break;
			}
		}
		if(n<m)
		{
			memset(w,0,sizeof(w));
			up_(n)
			{
				w[bb[i]]++;
		//		cout<<b[i];edl;
			}
			upn
			{
				w[a[i]]--;
			}
			int f=1;
			up_(200000)if(w[i]<0)f=0;
			sum+=f;
		}
//		cout<<fac[n];edl;
		opl(sum%mod);
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/