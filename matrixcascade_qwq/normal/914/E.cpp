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
const int maxn=500202;
vector<int>v[maxn];
int a[maxn];
char c[maxn];
int rt,siz[maxn],mx[maxn],vis[maxn],sum,b[maxn*10],fw[maxn];
void getroot(int x,int fa)
{
	siz[x]=1;mx[x]=0;
	fp v[x] pf
	{
		if(to==fa)continue;
		if(vis[to])continue;
		getroot(to,x);
		siz[x]+=siz[to];
		mx[x]=max(mx[x],siz[to]);
	}
	mx[x]=max(mx[x],sum-siz[x]);
	if(mx[x]<mx[rt])rt=x;
}
void adddis(int x,int fa,int k,int val)
{
	val^=(1<<a[x]);
	b[val]+=k;
	fp v[x] pf
	{
		if(to==fa||vis[to])continue;
		adddis(to,x,k,val);
	}
}
int calc2(int x,int fa,int val)
{
	val^=(1<<a[x]);
	int ans=b[val];
	up(i,0,20)ans+=b[val^(1ll<<i)];
	fp v[x] pf
	{
		if(to==fa)continue;
		if(vis[to])continue;
		ans+=calc2(to,x,val);
	}
	fw[x]+=ans;
	return ans;
}
void calc(int x)
{
	adddis(x,0,1,0);
	int ans=b[0];
	up(i,0,20)ans+=b[(1ll<<i)];
//	opls(ans);
	fp v[x] pf
	{
		if(vis[to])continue;
		adddis(to,x,-1,(1<<a[x]));
		ans+=calc2(to,x,0);
		adddis(to,x,1,(1<<a[x]));
	}
	adddis(rt,0,-1,0);
	assert(ans%2==1);
//	cout<<x<<" "<<ans;edl;
	fw[x]+=ans/2;
	return;
}
void solve(int x)
{
//	opl(x);edl;
	calc(x);
	vis[x]=1;
	fp v[x] pf
	{
		if(vis[to])continue;
		rt=0;
		sum=siz[to];
		mx[0]=n;
		getroot(to,x);
		solve(rt);
	}
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;
		up_(n-1)
		{
			int x,y;rd(x);rd(y);
			v[x].ep(y);v[y].ep(x);
		}
		scanf("%s",c+1);
		upn a[i]=c[i]-'a';
		mx[0]=n;sum=n;
		getroot(1,0);
		//upn opls(mx[i]);edl;
		solve(rt);
		up(i,1,n)opls(fw[i]+1);edl;
	}
}

/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/