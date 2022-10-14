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
const int maxn=202020;
int inv[maxn];
int qpow(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%m;
		a=a*a%m;
		b>>=1;
	}
	return ans;
}
int head[maxn],to[maxn],nxt[maxn],w[maxn],tot;
int rt,siz[maxn],mx[maxn],vis[maxn],sum;
int d1[maxn],d2[maxn],dep[maxn],d3[maxn];
void add(int a,int b,int c)
{
	to[++tot]=b;
	w[tot]=c;
	nxt[tot]=head[a];
	head[a]=tot;
}
void getroot(int x,int fa)
{
	siz[x]=1;mx[x]=0;
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa)continue;
		if(vis[v])continue;
		getroot(v,x);
		siz[x]+=siz[v];
		mx[x]=max(mx[x],siz[v]);
	}
	mx[x]=max(mx[x],sum-siz[x]);
	if(mx[x]<mx[rt])rt=x;
}
/*
x-y
x->rt  v1
rt->y  v2
 v1*10^(dep[v2])+v2
 v1+v2*10^(-dep[v2]) 
*/
map<int,int>mp,mp2;
int fl=1,ans=0;
void dfs1(int x,int fa)
{
	mp[(-1*d1[x]+m*m)%m]++;
//	opl((-1*d1[x]+m*m)%m);cout<<"qwq";edl;
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(vis[v])continue;
		if(v==fa)continue;
		d3[v]=(d3[x]*10+w[i])%m;
	//	cout<<qpow(inv[10],dep[v]);edl;
	//	opl(inv[10%m]);edl;
		d1[v]=d3[v]*qpow(inv[10%m],dep[v]);d1[v]%=m;
	//	opl(d1[v]);
		
		dfs1(v,x);
	}
}
void dfs2(int x,int fa)
{
	int val;
//	opl(d2[x]);edl;
	val=mp[d2[x]%m];
//	if((d1[x]*qpow(10,dep[x])%m+d2[x])%m==0)
//	{
//		--val;
//	}
	
	ans+=fl*val;
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		
		if(vis[v])continue;
		if(v==fa)continue;
	//	opl(v);edl;
		d2[v]=(d2[x]+w[i]%m*qpow(10,(dep[x]))%m)%m;
	//	opls(x);opls(dep[x]);edl;
	//	opls(d2[v]),opl(d2[x]+10*w[i]);edl; 
		dfs2(v,x);
	}
	 
}
void dfs3(int x,int fa)
{
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(vis[v])continue;
		if(v==fa)continue;
		dep[v]=dep[x]+1;
		dfs3(v,x);
	}
}
void dfs4(int x,int fa)
{
	ans+=mp2[d1[x]%m];
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(vis[v])continue;
		if(v==fa)continue;
	//	if(d1[v]==0)++ans;
	//	if(d3[v]==0)++ans;
		dfs4(v,x);
	}
}
void dfs5(int x,int fa)
{
	mp2[(-1*d2[x]+m*m)%m]++;
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(vis[v])continue;
		if(v==fa)continue;
	//	if(d1[v]==0)++ans;
	//	if(d3[v]==0)++ans;
		dfs5(v,x);
	}
}
void calc(int x)
{
	mp.clear();mp2.clear();
	mp[0]=1;mp2[0]=1;
	d1[x]=d2[x]=dep[x]=d3[x]=0;
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(vis[v])continue;
		dep[v]=1;d3[v]=w[i]%m;d1[v]=w[i]*inv[10%m]%m;d2[v]=w[i]%m;
		dfs3(v,x);dfs2(v,x);dfs1(v,x);dfs4(v,x);dfs5(v,x);
	//	opl(ans);edl;
		
	}
//	upn opls(d2[i]);edl; 
//	upn opls(d1[i]);edl; 
//	upn opls(dep[i]);edl; 
	//upn opls(d2[i]),opls(d1[i]),opls(dep[i]);edl;
//	for(int i=head[x];i;i=nxt[i])
//	{
//		int v=to[i];
//		if(vis[v])continue;
//		
//	}
}

void solve(int x)
{
//	opl(x);edl;
	fl=1;
	calc(x);
	vis[x]=1;
//	opl(ans);
//	dfs4(x,0);
//	fp mp pf opls(to.first),opls(to.second);
//	exit(0);
//	for(int i=head[x];i;i=nxt[i])
//	{
//		int v=to[i];
//		if(vis[v])continue;
//		fl=-1;
//		calc(v);
//	}
//	opl(ans);edl;
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(vis[v])continue;
		rt=0;
		mx[0]=n;
		rt=0;
		sum=siz[v];
		mx[0]=n;
		getroot(v,x);
		solve(rt);
	}
	
}
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    ll r = exgcd(b,a%b,x,y);
    ll t = x;
        x = y;
        y = t - a/b*y;
    return r;
}
ll invv(ll n,ll m){
    ll x,y;
    ll ans = exgcd(n,m,x,y);
    if(ans == 1)
        return (x%m+m)%m;
		else
        return -1;
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;
		inv[1]=1;
        up(i,2,2000)inv[i]=1ll*inv[m%i]*(m-m/i)%m;
        inv[10]=invv(10,m);
    //    opl(inv[10]);edl;
        up_(n-1)
        {
        	int x,y,z;rd(x);rd(y);rd(z);
        	++x;++y;add(x,y,z);add(y,x,z);
		}
		
//		dfs3(1,0);dfs1(1,0);dfs2(1,0);
//		upn
//		{
//			opls(d2[i]);opl(d1[i]);edl;
//		}
/*
3 7
0 1 1//
1 2 4

10 999999999
1 0 9
2 1 9
3 2 9
4 3 9
5 4 9
6 5 9
7 6 9
8 7 9
9 8 9

6 7
0 1 2
4 2 4
2 0 1
3 0 9
2 5 7
*/
		
		mx[0]=n;rt=0;
		sum=n;
		getroot(1,0);
	//	rt=rand()%n+1;
		solve(rt);
		opl(ans);edl;
//		
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/