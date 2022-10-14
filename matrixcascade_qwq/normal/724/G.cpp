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
const int maxn=404040;
int head[maxn],to[maxn],nxt[maxn],w[maxn],tot,val[maxn],vis[maxn];
const int mod=1e9+7;
int f[70];
vector<int>g;
void ins(int x)
{
	pu(i,63,0)
	{
		if(!(x&(1ll<<i)))continue;
		if(!f[i])
		{
		//	cout<<"nmsl ";opls(i);opls(x);
			f[i]=x;//opls(f[i]);edl;
			return;
		}x^=f[i];
	}
}
int a[maxn],b[maxn],c[maxn],cnt;
int d1[70],d2[70];
void add(int a,int b,int c)
{
	to[++tot]=b;w[tot]=c;
	nxt[tot]=head[a];head[a]=tot;
}
void dfs(int x,int fa)
{
	g.ep(x);vis[x]=1;
//	mc;
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa)continue;
		if(vis[v])
		{
			a[++cnt]=x;b[cnt]=v;c[cnt]=w[i];continue;
		}
		val[v]=val[x]^w[i];
		dfs(v,x);
	}
}
int qpow(int a,int b)
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
		rdn;rdm;
		upm
		{
			int x,y,z;rd(x);rd(y);rd(z);
			add(x,y,z);add(y,x,z);
		}
		int ans=0;
		upn
		{
			if(vis[i])continue;
			g.clear();cnt=0;
			memset(f,0,sizeof(f));memset(d1,0,sizeof(d1));
			memset(d2,0,sizeof(d2));
			dfs(i,0);int siz=g.size();
	//		upn cout<<val[i]<<" ";edl;
			up(j,1,cnt)
			{
				int w=val[a[j]]^val[b[j]]^c[j];
				ins(w);//cout<<a[j]<<" "<<b[j]<<" "<<c[j]<<"w"<<w;edl;
			}
			fp g pf
			{
				up(j,0,63)
				{
					if(val[to]&(1ll<<j))
					{
						d1[j]++;
					}
				}
			}
			int cntt=0;
			up(j,0,63)if(f[j])cntt++;
		//	cout<<cntt;edl;
			up(j,0,63)
			{
				if(!f[j])continue;
				up(t,0,63)
				{
					if(f[j]&(1ll<<t))d2[t]++;
				}
			}
			up(j,0,63)
			{
				int g0=d1[j]*(d1[j]-1)/2+(siz-d1[j])*(siz-d1[j]-1)/2;
				g0%=mod;
				int g1=d1[j]*(siz-d1[j])%mod;
				assert(g0>=0);assert(g1>=0);
			//	if(g0==6)continue;
	//		if(j>=4)continue;
		//		cout<<j<<" "<<g0<<" "<<g1<<" "<<d1[j]<<" "<<d2[j];edl;
				if(d2[j])
				{
					ans+=(qpow(2,j)%mod)%mod*(qpow(2,cntt-1)%mod)%mod*((siz*(siz-1)/2)%mod)%mod;
				}
				else
				{
					ans+=(qpow(2,j)%mod)%mod*(qpow(2,cntt)%mod)%mod*g1%mod;
				}
				assert(ans>=0);
				ans%=mod;
			}
		}
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