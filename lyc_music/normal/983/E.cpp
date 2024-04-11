//QwQcOrZ yyds!!!
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 998244353
#define Endl endl
//#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,q,x,y,dep[N],fa[N][25],L[N][25],c[N],dfn[N],ldfn[N],rdfn[N],DFN,Ans[N],Ans1[N],sum[N];
struct node
{
	int x,id,fh;
};
struct 
{
	int x,y;
}Q[N];
vector<node>SQ[N];
vector<int>H[N];
vector<int>G[N];
void update(int x)
{
	while (x<=n)
	{
		c[x]+=1;
		x=x+(x&(-x));
	}
}
int query(int x)
{
	int res=0;
	while (x)
	{
		res=(res+c[x]);
		x-=(x&(-x));
	}
	return res;
}
void ad(int x,int y)
{
	G[x].push_back(y);
}
void dfs(int x,int fa)
{
	if (x==1) dep[x]=1; else dep[x]=dep[fa]+1;
	dfn[x]=++DFN;
	ldfn[x]=dfn[x];
	for (int i=0;i<G[x].size();i++)
	{
		dfs(G[x][i],x);
	}
	rdfn[x]=DFN;
}
void ddfs(int k,int fa)
{
	for (int i=0;i<G[k].size();i++)
	{
		int u=G[k][i];
		ddfs(u,k);
		if (dep[L[k][0]]>dep[L[u][0]]||L[k][0]==0) L[k][0]=L[u][0];
	}
	if (dep[L[k][0]]>=dep[k]) L[k][0]=0;
}
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=20;i>=0;i--)
		if (dep[fa[x][i]]>=dep[y]&&fa[x][i]!=0) x=fa[x][i];
	if (x==y) return x;
	for (int i=20;i>=0;i--)
		if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
inline bool check(int x,int rt)
{
	for(int i=20;i>=0&&dep[x]>dep[rt];i--) if(L[x][i]) x=L[x][i];
	return dep[x]<=dep[rt];
}
pa get(int x,int y)
{
	pa res;
	res.fi=0;
	if(x==y) return mp(0,x);
	for (int i=20;i>=0;i--)
		if (dep[L[x][i]]>dep[y]&&L[x][i]!=0) x=L[x][i],res.fi+=(1<<i);
	x=L[x][0];res.fi++;
	res.se=x;
	return res;
}
pa get1(int x,int y)
{
	pa res;
	if (y==0) return mp(114514,x);
	for (int i=20;i>=0;i--)
		if (y&(1<<i)) x=L[x][i],res.fi+=(1<<i);
	res.se=x;
	return res;
}
signed main()
{
	n=read();
	for (int i=1;i<n;i++) 
	{
		x=read();
		fa[i+1][0]=x;
		ad(x,i+1);
	}
	dep[0]=inf;
	dfs(1,0);
	for (int i=1;i<=20;i++)
		for (int j=1;j<=n;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1];
	m=read();
	for (int i=1;i<=m;i++)
	{
		x=read(),y=read();
		int u=lca(x,y);
		if (x!=u&&y!=u) 
		{
			H[min(dfn[x],dfn[y])].push_back(max(dfn[x],dfn[y]));
		}
		if (dep[L[y][0]]>dep[u]) L[y][0]=u;
		if (dep[L[x][0]]>dep[u]) L[x][0]=u;
	}
	ddfs(1,0);
//	for (int i=1;i<=n;i++) writesp(L[i][0]),writeln(i);
	for (int i=1;i<=20;i++)
		for (int j=1;j<=n;j++)
			L[j][i]=L[L[j][i-1]][i-1];
	q=read();
	for (int i=1;i<=q;i++)
	{
		Q[i].x=read(),Q[i].y=read();
		int u=lca(Q[i].x,Q[i].y);
			if (check(Q[i].x,u)==0||check(Q[i].y,u)==0) 
			{
				Ans[i]=-1;
				continue;
			}
		if (Q[i].x!=u&&Q[i].y!=u)
		{
			pa v=get(Q[i].x,u);
			pa v1=get(Q[i].y,u);
			Ans[i]=v.fi+v1.fi;
			v=get1(Q[i].x,v.fi-1);
			v1=get1(Q[i].y,v1.fi-1);
			if (dfn[v.se]>dfn[v1.se]) swap(v,v1);
			SQ[ldfn[v.se]-1].push_back((node){ldfn[v1.se]-1,i,1});
			SQ[ldfn[v.se]-1].push_back((node){rdfn[v1.se],i,-1});
			SQ[rdfn[v.se]].push_back((node){ldfn[v1.se]-1,i,-1});
			SQ[rdfn[v.se]].push_back((node){rdfn[v1.se],i,1});
		} else
		if (Q[i].x==u) 
		{
			Ans[i]=get(Q[i].y,u).fi;
		} else
		{
			Ans[i]=get(Q[i].x,u).fi;
		}
	}
	
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<H[i].size();j++)
			update(H[i][j]);
		for (int j=0;j<SQ[i].size();j++)
		{
			sum[SQ[i][j].id]+=SQ[i][j].fh*query(SQ[i][j].x);
		}
	}
	for (int i=1;i<=q;i++)
	{
		if (sum[i]) Ans[i]--;
		if (Ans[i]>m) puts("-1"); else writeln(Ans[i]);
	}
}
/*
3
1 2
2
1 2
1 3
6
1 2
2 3
1 3
2 1
3 2
3 2

*/