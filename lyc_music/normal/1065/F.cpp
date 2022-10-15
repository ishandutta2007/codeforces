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
#define N 1000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int chu[N],n,K,sta[N],tp,f[N],bel[N],sum[N],ye[N],dis[N],ans,cnt,ru[N],dfn[N],low[N],vis[N],_dfn;
queue<int>q;
vector<int>G[N],E[N];
void ad(int x,int y)
{
	G[x].push_back(y);chu[x]++;
}
void ad1(int x,int y)
{
	E[x].push_back(y);ru[y]++;
}
void dfs(int k,int fa)
{
	sta[++tp]=k;
	f[k]=sta[max(1,tp-K)];
	for (auto u:G[k])
	{
		dfs(u,k);
	}
	tp--;
}
void Tarjan(int k)
{
	dfn[k]=++_dfn;
	low[k]=dfn[k];
	sta[++tp]=k;
	vis[k]=1;
	for (auto u:G[k])
	{
		if (!dfn[u])
		{
			Tarjan(u);
			low[k]=min(low[k],low[u]);
		} else
			if (vis[u]) low[k]=min(low[k],dfn[u]);
	}
	if (dfn[k]==low[k])
	{
		++cnt;
		while (sta[tp]!=k)
		{
			bel[sta[tp]]=cnt;
			vis[sta[tp]]=0;
			tp--;
		}
			bel[sta[tp]]=cnt;
			vis[sta[tp]]=0;
			tp--;
	}
}
		
signed main()
{
	n=read(),K=read();
	for (int i=1;i<n;i++) ad(read(),i+1);
	dfs(1,0);
	for (int i=2;i<=n;i++)
		if (!chu[i]) 
		{
			ye[i]=1;ad(i,f[i]);
		}
		
	for (int i=1;i<=n;i++) 
		if (!dfn[i]) 
			Tarjan(i);
	for (int i=1;i<=n;i++)
		for (auto u:G[i])
		{
			if (bel[u]!=bel[i]) ad1(bel[i],bel[u]);
		}
	for (int i=1;i<=n;i++)
		sum[bel[i]]+=ye[i];
	for (int i=1;i<=cnt;i++)
		if (!ru[i]) q.push(i),dis[i]=sum[i],ans=max(ans,dis[i]);
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		for (auto v:E[u])
		{
			dis[v]=max(dis[v],dis[u]+sum[v]);
			ans=max(ans,dis[v]);
			ru[v]--;
			if (!ru[v]) q.push(v);
		}
	}
	writeln(ans);
}
/*

*/