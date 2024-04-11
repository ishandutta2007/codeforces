//QwQcOrZ yyds!!!
#pragma GCC optimize(2,3,"Ofast")
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
#define il inline
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
#define inf 1e18
#define mod 998244353
#define Endl endl
#define int ll
#define N 1000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
//#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
priority_queue<pa>q;
int n,m,id[N],dis[N],fa[N],k,x,y,z,a[N];
struct zyy
{
	int x,y,w;
}E[N];
vector<pa>G[N];
int cnt;
inline int gf(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=gf(fa[x]);
}
void ad(int x,int y,int z)
{
	G[x].push_back({y,z});
}
int ans;
bool cmp(zyy x,zyy y)
{
	return x.w<y.w;
}
signed main()
{
	n=read();m=read();
	for (int i=1;i<=n;i++) id[i]=0;
	for (int i=1;i<=m;i++)
	{
		x=read(),y=read(),z=read();
		ad(x,y,z);
		ad(y,x,z);
	}
	memset(dis,0x3f,sizeof(dis));
	k=read();
	for (int i=1;i<=k;i++) a[i]=read(),id[a[i]]=i,dis[a[i]]=0,q.push({0,a[i]}),fa[i]=i;
	while (!q.empty())
	{
		int u=q.top().se,tmp=q.top().fi;
		q.pop();
		if(-tmp>dis[u])continue;
		for (auto v:G[u])
		{
			if (dis[u]+v.se<dis[v.fi])
			{
				id[v.fi]=id[u];
				dis[v.fi]=dis[u]+v.se;
				q.push({-dis[v.fi],v.fi});
			}
		}
	}
	for (int i=1;i<=n;i++)
		for (auto u:G[i])
			if (id[u.fi]<id[i])
			{
				E[++cnt]={id[i],id[u.fi],dis[i]+dis[u.fi]+u.se};
			}
	sort(E+1,E+cnt+1,cmp);
	int tm=0;
	for (int i=1;i<=cnt;i++)
	{
		if (gf(E[i].x)!=gf(E[i].y))
		{
			fa[fa[E[i].x]]=fa[E[i].y];
			ans+=E[i].w;
			tm++;
			if (tm==k-1) break;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	q.push({0,1});
	while (!q.empty())
	{
		int u=q.top().se,tmp=q.top().fi;
		q.pop();
		if(-tmp>dis[u])continue;
		for (auto v:G[u])
		{
			if (dis[u]+v.se<dis[v.fi])
			{
				id[v.fi]=id[u];
				dis[v.fi]=dis[u]+v.se;
				q.push({-dis[v.fi],v.fi});
			}
		}
	}
	int zdy=inf;
	for (int i=1;i<=k;i++)
		zdy=min(zdy,dis[a[i]]);
	writeln(ans+zdy);
}
/*
3 3
1 2 2
1 3 1
2 3 5
2
2 3
*/