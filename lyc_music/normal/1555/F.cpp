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
//#define int ll
#define N 500005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int siz[N],dep[N],fa[N],dis[N],son[N],top[N],dfn[N],tr[N<<2],tag[N<<2],vis[N];
int n,m,q,DFN;
vector<pa>G[N];
struct node
{
	int u,v,w;
}e[N<<1];
int gf(int k)
{
	if (fa[k]==k) return k;
	return fa[k]=gf(fa[k]);
}
void dfs(int k,int faa)
{
	siz[k]=1;dep[k]=dep[faa]+1;
	fa[k]=faa;
	for (auto U:G[k])
	{
		int u=U.fi,w=U.se;
		if (u==faa) continue;
		dis[u]=dis[k]^w;
		dfs(u,k);
		siz[k]+=siz[u];
		if (siz[u]>siz[son[k]]) son[k]=u;
	}
}
void dfs1(int k,int tp)
{
	top[k]=tp;dfn[k]=++DFN;
	if (son[k]) dfs1(son[k],tp);
	for (auto U:G[k])
	{
		int u=U.fi,w=U.se;
		if (u==fa[k]||u==son[k]) continue;
		dfs1(u,u);
	}
}

void pushdown(int k,int l,int r)
{
	int mid=l+(r-l)/2;
	if (!tag[k]) return;
	tr[k<<1]+=tag[k]*(mid-l+1);
	tr[k<<1|1]+=tag[k]*(r-mid);
	tag[k<<1]+=tag[k];
	tag[k<<1|1]+=tag[k];
	tag[k]=0;
}
void pushup(int k)
{
	tr[k]=tr[k<<1]+tr[k<<1|1];
}
void update(int k,int l,int r,int L,int R,int val)
{
	if (L<=l&&r<=R)
	{
		tr[k]+=(r-l+1)*val;
		tag[k]+=val;
		return;
	}
	int mid=l+(r-l)/2;
	pushdown(k,l,r);
	if (L<=mid) update(k<<1,l,mid,L,R,val);
	if (R>mid) update(k<<1|1,mid+1,r,L,R,val);
	pushup(k);
}
int query(int k,int l,int r,int L,int R)
{
	if (L<=l&&r<=R) 
	{
		return tr[k];
	}
	int mid=l+(r-l)/2,res=0;
	pushdown(k,l,r);
	if (L<=mid) res+=query(k<<1,l,mid,L,R);
	if (R>mid) res+=query(k<<1|1,mid+1,r,L,R);
	pushup(k);
	return res;
}


int Query(int x,int y)
{
	int res=0;
	while (top[x]!=top[y])
	{
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		res+=query(1,1,n,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if (dep[x]>dep[y]) swap(x,y);
	res+=query(1,1,n,dfn[x]+1,dfn[y]);
	return res;
}
void Update(int x,int y)
{
	while (top[x]!=top[y])
	{
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		update(1,1,n,dfn[top[x]],dfn[x],1);
		x=fa[top[x]];
	}
	if (dep[x]>dep[y]) swap(x,y);
	update(1,1,n,dfn[x]+1,dfn[y],1);
}


signed main()
{
	n=read();q=read();
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=q;i++)
	{
		e[i].u=read(),e[i].v=read(),e[i].w=read();
		if (gf(e[i].u)!=gf(e[i].v))
		{
			fa[fa[e[i].u]]=fa[e[i].v];
			vis[i]=1;
			G[e[i].u].push_back({e[i].v,e[i].w});
			G[e[i].v].push_back({e[i].u,e[i].w});
		}
	}
	for (int i=1;i<=n;i++)
		if (gf(i)==i) G[n+1].push_back({i,0});
	dfs(n+1,0);
	dfs1(n+1,n+1);n++;
	for (int i=1;i<=q;i++)
	{
		if (vis[i]) puts("YES");
		else
		{
			int u=e[i].u,v=e[i].v,w=e[i].w;
			if (dis[u]^dis[v]^w==0) puts("NO");
			else
			{
				if (Query(u,v)) puts("NO");
				else puts("YES"),Update(u,v);
			}
		}
//		puts("FU");
//		Query(2,9);
	}
}
/*
10 25
6 8 1
6 3 1
8 3 0
6 10 0
8 10 1
6 1 1
8 1 0
8 9 0
6 9 0
6 5 1
8 5 1
6 7 0
8 7 1
6 4 1
8 4 0
8 2 0
6 2 0
2 10 0
7 9 0
10 1 1
7 3 0
9 2 1
4 5 0
1 4 1
4 7 0
*/