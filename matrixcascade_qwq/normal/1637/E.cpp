#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
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
const int maxn=6e5+100;
int a[maxn];
int x[maxn],y[maxn],fx[maxn],fy[maxn];
int w[maxn],tot,vis[maxn];
int cnt,lsh[maxn];
vector<int>v[maxn];
signed main()
{
	int T=read();
	while(T--)
	{
		rdn;rdm;
		map<int,int>mpp;
		upn rd(a[i]),mpp[a[i]]++;cnt=0;
		map<pii,int>mp;
		up_(m)
		{
			rd(x[i]);rd(y[i]);mp[mkp(x[i],y[i])]=1;mp[mkp(y[i],x[i])]=1;
		}
		
		
		fp mpp pf
		{
			if(!vis[to.second])
			{
				w[++tot]=to.second;
				vis[to.second]=1;
			}
			v[to.second].ep(to.first);
		}
		up(i,1,tot)
		{
			sort(v[w[i]].begin(),v[w[i]].end());
		}
		ll ans=0;
		up(i,1,tot)
		{
			int siz=v[w[i]].size();
			pu(j,siz-1,0)
			{
				pu(t,j-1,0)
				{
					if(mp.count(mkp(v[w[i]][j],v[w[i]][t]))==0)
					{
						ans=max(ans,1ll*(w[i]+w[i])*(v[w[i]][j]+v[w[i]][t]));
						break;
					}
				}
			}
		}
		up(i,1,tot)
		{
			up(j,i+1,tot)
			{
				int siz1=v[w[i]].size(),siz2=v[w[j]].size();
				pu(k,siz1-1,0)
				{
					pu(t,siz2-1,0)
					{
						if(mp.count(mkp(v[w[i]][k],v[w[j]][t]))==0)
						{
							ans=max(ans,1ll*(w[i]+w[j])*(v[w[i]][k]+v[w[j]][t]));
							break;
						}
					}
				}
			}
		}
		
		tot=0;
		upn
		{
			v[i].clear();vis[i]=0;
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