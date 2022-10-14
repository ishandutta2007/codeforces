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
const int maxn=4e5+10;
const int mod=998244353;
int head[maxn],to[maxn],nxt[maxn],p[maxn],q[maxn],tot;
int pr[maxn];
int b[maxn],tott;
int val[maxn];
int qpow(int a,int b=mod-2)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ans;
}
void add(int a,int b,int c,int d)
{
	to[++tot]=b;
	p[tot]=c;
	q[tot]=d;
	nxt[tot]=head[a];
	head[a]=tot;
}
vector<pii>v[maxn];
mii mp;
int g[maxn],mx[maxn];
void dfs(int x,int fa)
{
	ver(x)
	{
		if(to[i]==fa)continue;
		//swap(p[i],q[i]);
		val[to[i]]=val[x]*qpow(p[i])%mod*q[i]%mod;
		fp v[q[i]] pf g[to.fi]+=to.se;
		fp v[p[i]] pf g[to.fi]-=to.se;
		fp v[p[i]] pf mx[to.fi]=max(mx[to.fi],-1*g[to.fi]);
		dfs(to[i],x);
		fp v[q[i]] pf g[to.fi]-=to.se;
		fp v[p[i]] pf g[to.fi]+=to.se;
	}
}
signed main()
{
	pr[1]=0;
	up(i,2,222222)pr[i]=1;
	up(i,2,222222)
	{
		if(pr[i]==1)
		{
			for(int j=i+i;j<=222222;j+=i)pr[j]=0;
		}
	}
	up(i,2,222222)
	{
		if(pr[i])
		{
			b[++tott]=i;
			mp[i]=tott;
		}
	}
	up(i,1,200200)
	{
		int nw=i;
		for(int j=1;b[j]*b[j]<=nw;++j)
		{
			int val=0;
			if(nw%b[j]==0)
			{
				while(nw%b[j]==0)++val,nw/=b[j];
			}
			v[i].ep(mkp(j,val));
		}
		v[i].ep(mp[nw],1);
	}
	int T=read();
	while(T--)
	{
		rdn;
		upn head[i]=0,mx[i]=0,g[i]=0;
		up_(n-1)
		{
			int p,q,x,y;
			rd(p);rd(q);rd(x);rd(y);
			add(p,q,x,y);
			add(q,p,y,x);
		}
		val[1]=1;
		dfs(1,0);
		int ans=1;int ww=0;upn ww+=val[i],ww%=mod;
	//	cout<<ww;edl;
		
		up(i,1,tot)
		{
			if(b[i]>n)break;
			ans*=qpow(b[i],mx[i]);ans%=mod;
		}//cout<<ans;edl;
		opl(1ll*ww*ans%mod);edl;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/