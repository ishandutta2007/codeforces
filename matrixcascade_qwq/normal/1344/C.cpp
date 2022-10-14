/*
qwq
*/


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
vector<int>v[202020],g[202020];
int deg[202020],deg2[202020];
int c[202020],d[202020];
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;
		upn c[i]=d[i]=i;
		upm
		{
			int x,y;
			rd(x);rd(y);
			v[x].ep(y);
			++deg[y];
			g[y].ep(x);
			++deg2[x];
		}
		queue<int>q;
		upn
		{
			if(!deg[i])q.push(i);
		}
		while(!q.empty())
		{
			int nw=q.front();q.pop();
			fp v[nw] pf
			{
				--deg[to];
				c[to]=min(c[to],c[nw]);
				if(!deg[to])q.push(to);
			}
		}
		upn
		{
			if(deg[i])
			{
				puts("-1");
				return 0;
			}
		}
		upn
		{
			if(!deg2[i])q.push(i);
		}
		while(!q.empty())
		{
			int nw=q.front();q.pop();
			fp g[nw] pf
			{
				--deg2[to];
				d[to]=min(d[to],d[nw]);
				if(!deg2[to])q.push(to);
			}
		}
		int ans=0;
		upn
		{
		//	cout<<c[i]<<" "<<d[i]<<'\n';
			if(c[i]==i&&d[i]==i)
			{
				++ans;
			}
		}
		cout<<ans;edl;
		upn
		{
			if(c[i]==i&&d[i]==i)
			{
				cout<<"A";
			}
			else cout<<"E";
		}
	}
}
/*
1 2
3 2
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/