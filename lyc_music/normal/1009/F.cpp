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
#define N 2000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int son[N],dep[N],f[N],siz[N],nowans;
int n,x,y,Ans[N];
vector<int>G[N];
void ad(int x,int y){G[x].push_back(y);G[y].push_back(x);}
void dfs(int k,int fa)
{
	dep[k]=dep[fa]+1;
	son[k]=0;siz[k]=1;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		siz[k]+=siz[u];
		if (siz[u]>siz[son[k]]) son[k]=u;
	}
}
void dfs2(int k,int fa,int val)
{
	f[dep[k]]+=val;
	if (f[dep[k]]>f[nowans]||(f[dep[k]]==f[nowans]&&dep[k]<nowans)) nowans=dep[k];
	for (auto u:G[k]) if (u!=fa) dfs2(u,k,val);
}
void dfs1(int k,int fa)
{
	for (auto u:G[k])
	{
		if (u==fa||u==son[k]) continue;
		dfs1(u,k);
		dfs2(u,k,-1);
		nowans=0;
	}
	if (son[k]) dfs1(son[k],k);
	for (auto u:G[k])
	{
		if (u==fa||u==son[k]) continue;
		dfs2(u,k,1);
	}
	f[dep[k]]++;
	if (f[nowans]<=1) nowans=dep[k];
	Ans[k]=nowans-dep[k];
}
		
signed main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		x=read(),y=read();
		ad(x,y);
	}
	dfs(1,0);
	dfs1(1,0);
	for (int i=1;i<=n;i++) writeln(Ans[i]);
}
/*

*/