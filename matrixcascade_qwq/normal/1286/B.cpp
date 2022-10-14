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
const int maxn=2020;
int p[maxn],c[maxn],siz[maxn];
vector<int>v[maxn];
int w[maxn];
void dfs(int x)
{
	siz[x]=1;
	fp v[x] pf
	{
		dfs(to);siz[x]+=siz[to];
	}
}
int cmp(int a,int b)
{
	return w[a]<w[b];
}
vector<int>h;
void dfs3(int x)
{
	h.ep(x);
	fp v[x] pf
	{
		
		dfs3(to);
	}
}

void dfs2(int x)
{
//	cout<<x;edl;
	if(v[x].size()==0)
	{
		w[x]=rand()*rand()%1000000+x*((rand())%1247);return;
	}
	int mx=-1;
	fp v[x] pf
	{
		dfs2(to);
	}
	fp v[x] pf
	{
		dfs3(to);
	}
	sort(h.begin(),h.end(),cmp);
//	if(x==1)fp h pf cout<<to<<" ";
//	edl;
//	if(x==1)cout<<w[h[c[x]]],edl;
	if(c[x]==0)w[x]=w[h[0]]/2;
	else if(c[x]!=siz[x]-1)w[x]=(w[h[c[x]]]+w[h[c[x]-1]])/2;
	else w[x]=(w[h[c[x]-1]]+1000000000)/2;
	h.clear();
//	if(x==1)cout<<h[c[x]]<<" "<<h[c[x]-1];edl;
	
}

signed main()
{
	srand(6435);
	int T=1;
	while(T--)
	{
		rdn;int rt;
		upn rd(p[i]),rd(c[i]),v[p[i]].ep(i);
		upn if(p[i]==0)rt=i;
		dfs(rt);
		upn
		{
			if(c[i]>=siz[i])
			{
				NO;return 0;
			}
		}
		dfs2(rt);
		YES;
		upn
		{
			opls(w[i]);
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