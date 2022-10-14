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

const int maxn=2e5+10;
int tot;
int head[maxn],to[maxn],nxt[maxn];
int dfn[maxn],fa[maxn][20],dep[maxn];
int gw[maxn],b[maxn];
void add(int a,int b)
{
	to[++tot]=b;nxt[tot]=head[a];
	head[a]=tot;
}
void predfs(int x)//build the tree
{
	//cout<<x<<endl;
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(dep[v])continue;
		fa[v][0]=x;
		up(j,1,19)fa[v][j]=fa[fa[v][j-1]][j-1];
		dep[v]=dep[x]+1;
		predfs(v);
	}
}
int chk(int x)// x is or not
{
	upn dep[i]=0;
	dep[x]=1;
	upn
	{
		up(j,0,19)fa[i][j]=0;
	}
	predfs(x);
	//chk edges
	
	up(h,1,n)
	{
		for(int i=head[h];i;i=nxt[i])
		{
		//	if(n==6)mc;
			int v=to[i];
			if(fa[v][0]==h)continue;
			if(dep[v]>=dep[h])
			{
			//	cout<<x;edl;
				return 0;
			}
		//	cout<<i;edl;
			int nw=h;
			pu(j,19,0)if(dep[fa[nw][j]]>=dep[v])nw=fa[nw][j];
			if(nw!=v)return 0;
		}
	//	cout<<x<<" nmsl";edl;
	}
	return 1;
}
//x is good,check all!
multiset<int>s[202020];
void dfs(int x)
{
	for(int i=head[x];i;i=nxt[i])
	{
		int vv=to[i];
	//	if(vv==fa[x][0])continue;
		
//		if(x==3)cout<<vv,edl;
		if(fa[vv][0]==x)
		{
	//		
		//	assert(x!=2);
			dfs(vv);
			fp s[vv] pf
			{
				if(to==x)continue;//if(x==3)cout<<to,edl;
				s[x].insert(to);
			}
		}
		else
		{//if(x==3)cout<<v<<endl;
		//	if(x==3)cout<<vv,edl;
			s[x].insert(vv);
			//cout<<x;edl;
		}
		
		
	}
	if(s[x].size()>=2)b[x]=0;
}
void dfs2(int x)
{
	fp s[x] pf
	{
		if(b[to]==0)b[x]=0;
	}
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];if(v==fa[x][0])continue;
		if(fa[v][0]==x)
		{
			dfs2(v);
		}
	}
}
int a[303030];
signed main()
{
	srand(1214);
	int T=read();
	while(T--)
	{
		rdn;rdm;int x;upn head[i]=0;upn b[i]=1,gw[i]=0,dep[i]=0;
		upn s[i].clear();
	//	upn cout<<head[i]<<" ";edl;
		upn b[i]=1;
		tot=0;
		up_(m)
		{
			int x,y;rd(x);rd(y);add(x,y);
		}
		upn a[i]=i;
		random_shuffle(a+1,a+n+1);
		int tim=100,fl=1;
		up(i,1,min(80,n))
		{
			x=a[i];
		//	cout<<x;edl;
		//	while(gw[x])x=rand()%n+1;
			if(chk(x))
			{
				fl=0;break;
			}
			
			gw[x]=1;
		}
	//	cout<<x;edl;
		if(fl)
		{
	//		upn
	//		{
	//			cout<<gw[x]<<" ";
	//		}edl;
			puts("-1");
			continue;
		}
		upn s[i].clear();
		dfs(x);dfs2(x);
	//	upn
	//	{
	//		cout<<i<<" : ";fp s[i] pf cout<<to<<" ";edl;
	//	}
		vector<int>ans;
		upn
		{
			if(b[i]==1)ans.ep(i);
		}
		if((int)ans.size()*5<n)
		{
		//	mc;

			puts("-1");
		}
		else
		{
			fp ans pf opds(to);edl;
		}
		
		
	}
}
/*
1
3 4
2 1
3 1
3 2
1 3

1628
1 0
2 2
2 1
1 2
3 4
2 3
3 1
3 2
1 3
3 3
1 2
2 3
3 1
3 4
2 1
3 1
3 2
1 3
3 4
1 2
2 3
3 1
2 1
3 5
3 2
2 3
1 3
2 1
1 2
/*
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/