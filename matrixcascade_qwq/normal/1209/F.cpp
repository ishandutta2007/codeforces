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
const int mod=1e9+7;
const int maxn=2e6+10;
vector<int>v[maxn][10];
int f[11],g[11];
int ans[maxn];
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;
		int cnt=n;
		up_(m)
		{
			int x,y;rd(x);rd(y);
			int nw=i;int tot=0;
			while(nw)
			{
				f[++tot]=nw%10;nw/=10;
			}
		//	cout<<tot;edl;
			up(j,1,tot-1)g[j]=++cnt;
			g[0]=y;g[tot]=x;reverse(f+1,f+tot+1);
			up(j,1,tot)v[g[j-1]][f[j]].ep(g[j]);
			reverse(f+1,f+tot+1);
			pu(j,tot,1)v[g[j]][f[j]].ep(g[j-1]);
		}
		queue<vector<int>>q;
		memset(ans,-1,sizeof(ans));ans[1]=0;
		vector<int>ww;ww.ep(1);
		q.push(ww);
		while(q.size())
		{
			auto nw=q.front();q.pop();
		//	cout<<nw[0];edl;
			up(i,0,9)
			{
				vector<int>gg;
				fp nw pf
				{
					for(auto tt:v[to][i])
					{	
						if(ans[tt]==-1)
						{
						//	cout<<to<<" "<<tt;edl;
							ans[tt]=(1ll*10*ans[to]%mod+i)%mod;
							gg.ep(tt);
						}
					}
				}
				if(gg.size())q.push(gg);
			}
		}
		up(i,2,n)opl(ans[i]),edl;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/