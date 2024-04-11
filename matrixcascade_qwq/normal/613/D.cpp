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
const int maxn=202020;
int head[maxn],to[maxn],nxt[maxn],tot;
int dfn[maxn],cnt,f[maxn][19],dep[maxn];
void add(int a,int b)
{
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
}
void dfs1(int x,int fa)
{
	f[x][0]=fa;
	up(i,1,18)f[x][i]=f[f[x][i-1]][i-1];
	
	dfn[x]=++cnt;
	dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa)continue;
		dfs1(v,x);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	pu(i,18,0)if(dep[f[x][i]]>=dep[y])x=f[x][i];
	if(x==y)return x;
	pu(i,18,0)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
int q[maxn],sta[maxn],top;vector<int>v[maxn];
int b[maxn];
int cmp(int a,int b)
{
	return dfn[a]<dfn[b];
}
void build()
{
	top=0;
	sta[++top]=1;
	up(i,1,k)
	{
	//	cout<<i;edl;
		if(q[i]==1)continue;
		int la=lca(sta[top],q[i]);
		while(top>1&&dep[la]<dep[sta[top-1]])
		{
			v[sta[top-1]].ep(sta[top]);
			--top;
		}
		if(dep[sta[top]]>dep[la])
		{
			v[la].ep(sta[top]);--top;
		}
		if(!top||sta[top]!=la)
		{
			sta[++top]=la;
		}
		sta[++top]=q[i];
	}
	up_(top-1)v[sta[i]].ep(sta[i+1]);
}
vector<int>ls;
int dp[maxn],ans=0;
void dfs(int x)
{
//	cout<<b[x];edl;
//	cout<<x;edl;
	if(b[x]==1)ls.ep(x);
	int w=0;
	fp v[x] pf
	{
		dfs(to);
		if(b[to]==1)++w;
	}
	if(b[x]==1)
	{
		ans+=w;
	}
	else
	{
		if(w>=2)
		{
			ans++;
		}
		else if(w!=0)
		{
			b[x]=1;
		}
	}
	if(b[x]==1)ls.ep(x);
	v[x].clear();
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
			add(x,y);add(y,x);
		}
		dfs1(1,0);
		rdm;
		while(m--)
		{
			//mc;
			rdk;
			mii mp;
		//	upn cout<<b[i]<<" ";edl;
			up_(k)rd(q[i]),b[q[i]]=1;
			up_(k)mp[f[q[i]][0]]=1;
			
			int fl=0;
			up_(k)
			{
				
				if(mp[q[i]]==1)
				{
					fl=1;break;
				}
			}
			if(fl)
			{up_(k)b[q[i]]=0;
				puts("-1");continue;
			}
			sort(q+1,q+k+1,cmp);
			build();
			ans=0;dfs(1);
			opl(ans);edl;
			fp ls pf b[to]=0;ls.clear();
		}
	}
}
/*
4
1 3
2 3
4 3
1
3 1 2 4
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/