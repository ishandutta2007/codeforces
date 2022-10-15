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
int n,m,a[N],ans,fa[N],du[N],val[N],sum[N];
set<int>S;
struct
{
	int x,y;
}e[N];
int gf(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=gf(fa[x]);
}
signed main()
{
	n=read();m=read();for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		e[i].x=read(),e[i].y=read();
		du[e[i].x]++,du[e[i].y]++;
	}
	for (int i=1;i<=n;i++) val[i]=du[i]%2,ans+=val[i],sum[i]=du[i];
	for (int i=1;i<=m;i++)
	{
		if (gf(e[i].x)!=gf(e[i].y))
		{
			val[fa[e[i].y]]|=val[fa[e[i].x]];
			sum[fa[e[i].y]]+=sum[fa[e[i].x]];
			fa[fa[e[i].x]]=fa[e[i].y];
		}
	}
	for (int i=1;i<=n;i++) S.insert(gf(i));
	if (S.size()==1)
		return writeln(ans/2),0;
	int fuck=1;
	for (int i=2;i<=n;i++)
		if (gf(i)==i&&gf(1)!=i)
		{
			if (sum[i]&&val[i]==0) ans+=2;
		}
	int i=gf(1);
	if (sum[i]!=2*m&&val[i]==0) ans+=2;
	writeln(ans/2);
}
/*
10 10
1 8
6 9
8 2
6 2
6 5
3 10
2 3
10 9
7 8
7 1
*/