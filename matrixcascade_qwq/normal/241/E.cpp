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
const int maxn=5050;
int p[maxn],q[maxn];
vector<int>v[maxn];
int vis[maxn],v2[maxn];
void dfs(int x)
{
	vis[x]=1;
	if(x==n)return;
	fp v[x] pf
	{
		if(!vis[to])vis[to]=1,dfs(to);
		if(v2[to])v2[x]=1;
	}
}
int tot=0;
int x[maxn*3],y[maxn*3],z[maxn*3];
int dis[maxn];
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;
		up_(m)
		{
			rd(p[i]);rd(q[i]);
			v[p[i]].ep(q[i]);
		}
		v2[n]=1;
		dfs(1);
		up_(m)
		{
			if(v2[p[i]]+v2[q[i]]!=2)continue;
			/*
			-1<=dis q-dis p<=2
			*/
		//	cout<<p[i]<<" "<<q[i];edl;
			x[++tot]=p[i];y[tot]=q[i];z[tot]=2;
			x[++tot]=q[i];y[tot]=p[i];z[tot]=-1;
		}
		memset(dis,1,sizeof(dis));
		upn
		{
			x[++tot]=0;y[tot]=i;z[tot]=0;
		}
		dis[0]=0;
		up(i,1,n+1)
		{
			up(j,1,tot)
			{
				if(dis[y[j]]>dis[x[j]]+z[j])
				{
					dis[y[j]]=dis[x[j]]+z[j];
				}
			}
		}
		up(j,1,tot)
		{
			if(dis[y[j]]>dis[x[j]]+z[j])
			{
				No;return 0;
			}
		}
		Yes;
		up_(m)
		{
			if(v2[p[i]]+v2[q[i]]!=2)
			{
				cout<<1;edl;continue;
			}
			cout<<abs(dis[p[i]]-dis[q[i]]);edl;
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