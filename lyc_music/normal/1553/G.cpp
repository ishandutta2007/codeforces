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
#define int ll
#define N 1000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,q,a[N],f[N],x,y;
set<pa>E;
int gf(int x)
{
	if (x==f[x]) return x;
	return f[x]=gf(f[x]);
}
signed main()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=1000000;i++) f[i]=i;
	for (int i=1;i<=n;i++)
	{
		int now=a[i];
		for (int j=2;j*j<=now;j++)
			if (now%j==0)
			{
				while (now%j==0)  now/=j;
				if (gf(a[i])!=gf(j)) f[f[a[i]]]=f[j];
			}
		if (now>1){int j=now;if (gf(a[i])!=gf(j)) f[f[a[i]]]=f[j];}
//		cout<<a[i]<<" "<<now<<" "<<gf(a[i])<<" "<<gf(now)<<endl;
	}
	for (int i=1;i<=n;i++)
	{
		int now=a[i];
		vector<int>G1;
		for (int j=2;j*j<=now;j++)
			if (now%j==0)
			{
				while (now%j==0)  now/=j;
				G1.push_back(j);
			}
		if (now>1){int j=now;G1.push_back(now);}
		vector<int>G;
		now=a[i]+1;
		for (int j=2;j*j<=now;j++)
			if (now%j==0)
			{
				while (now%j==0)  now/=j;
				G.push_back(j);
			}
		if (now>1) G.push_back(now);
		for (auto u:G)
		{
			for (auto v:G1)
				if (gf(u)!=gf(v))
					E.insert({min(f[u],f[v]),max(f[u],f[v])});
			for (auto v:G)
				if (gf(u)!=gf(v))
					E.insert({min(f[u],f[v]),max(f[u],f[v])});
		}
		int u=a[i];
	}
//	for (auto u:E) cout<<u.fi<<" "<<u.se<<endl;
	while (q--)
	{
		x=read(),y=read();
		x=a[x],y=a[y];
		if (gf(x)==gf(y)) puts("0");
		else if (E.count({min(f[x],f[y]),max(f[x],f[y])})) puts("1");
		else puts("2");
	}
}
/*

*/