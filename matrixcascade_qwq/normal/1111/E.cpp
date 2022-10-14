//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
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
ll n, m, k;
ll read()
{
    ll s = 0, f = 1;
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
void chkmin(ll &x,ll y)
{
	if(x>y)x=y;
}
void chkmax(ll &x,ll y)
{
	if(x<y)x=y;
}
const ll maxn=202020;

ll head[maxn],to[maxn],nxt[maxn],tot;
ll dfn[maxn],cnt,f[maxn][19],dep[maxn];
ll fac[maxn+10],ifac[maxn+10];
const ll mod=1e9+7;
ll qpow(ll a,ll b=mod-2)
{
    ll ans=1;
    while(b)
    {
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
ll inv(ll k)
{
    return qpow(k,mod-2);
}
void pre()
{
    fac[0]=1;
    for(ll i=1;i<=maxn;++i)
        fac[i]=fac[i-1]*i%mod;
    ifac[maxn]=inv(fac[maxn]);
    for (ll i=maxn-1;i>=0;--i)
        ifac[i]=ifac[i+1]*(i+1)%mod;
}
ll C(ll nn,ll mm)
{
    if(nn<0||nn-mm<0)return 0;
    return fac[nn]*ifac[mm]%mod*ifac[nn-mm]%mod;
}
ll invC(ll nn,ll mm)
{
    if(nn<0||nn-mm<0)return 0;
    return ifac[nn]*fac[mm]%mod*fac[nn-mm]%mod;
}
void add(ll a,ll b)
{
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
}
void dfs1(ll x,ll fa)
{
	f[x][0]=fa;
	up(i,1,18)f[x][i]=f[f[x][i-1]][i-1];
	dfn[x]=++cnt;
	dep[x]=dep[fa]+1;
	for(ll i=head[x];i;i=nxt[i])
	{
		ll v=to[i];
		if(v==fa)continue;
		dfs1(v,x);
	}
}
ll lca(ll x,ll y)
{
	if(dep[x]<dep[y])swap(x,y);
	pu(i,18,0)if(dep[f[x][i]]>=dep[y])x=f[x][i];
	if(x==y)return x;
	pu(i,18,0)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
ll q[maxn],sta[maxn],top,r;
vector<ll>v[maxn];
ll cmp(ll a,ll b)
{
	return dfn[a]<dfn[b];
}
void build()
{
	sort(q+1,q+k+1,cmp);
	ll nn=unique(q+1,q+k+1)-q-1;
//	up_(nn)opls(q[i]);edl;
	k=nn;
	top=0;
	sta[++top]=1;
	up(i,1,k)
	{
	//	cout<<i;edl;
		if(q[i]==1)continue;
		ll la=lca(sta[top],q[i]);
		while(top>1&&dep[la]<dep[sta[top-1]])
		{
			v[sta[top-1]].ep(sta[top]);v[sta[top]].ep(sta[top-1]);
			--top;
		}
		if(dep[sta[top]]>dep[la])
		{
			v[la].ep(sta[top]);v[sta[top]].ep(la);--top;
		}
		if(!top||sta[top]!=la)
		{
			sta[++top]=la;
		}
		sta[++top]=q[i];
	}
	up_(top-1)v[sta[i]].ep(sta[i+1]),v[sta[i+1]].ep(sta[i]);
}
int dp[maxn/2][303],gw[maxn],g[maxn];
void dfs(ll x,ll fa)
{
	//cout<<x;edl;
	up(i,0,m)dp[x][i]=1;
	fp v[x] pf
	{
		if(to==fa)continue;
		dfs(to,x);
		up(i,0,m)dp[x][i]=1ll*dp[x][i]*dp[to][i]%mod;
	}
	v[x].clear();
	if(gw[x]==0)return;
	pu(i,m,1)dp[x][i]=(1ll*i*dp[x][i-1])%mod;
	dp[x][0]=0;
	gw[x]=0;
}
signed main()
{
	pre();
	ll T=1;
	while(T--)
	{
		rdn;ll qq;rd(qq);
		up_(n-1)
		{
			ll x,y;rd(x);rd(y);
			add(x,y);add(y,x);
		}
		dfs1(1,0);
		while(qq--)
		{
			rdk;rdm;rd(r);
			up_(k)
			{
				rd(q[i]);gw[q[i]]=1;
			}
			q[++k]=r;build();
			dfs(r,0);
			
			ll ans=0;
		//	cout<<"qwq "<<m;edl;
			up(i,1,m)
			{
				ll nw=0;
			//	cout<<dp[r][i];edl;
				up(j,0,i)
				{
					ll ww;
					ww=1ll*C(i,j)*dp[r][i-j]%mod;
					if(j%2==0)nw+=ww;
					else nw-=ww;
					nw+=mod;nw%=mod;
				}
				ans+=nw*ifac[i]%mod;ans%=mod;
			}
			opl(ans);edl;//3 4 7
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