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
#define inf 1e18
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n[5],a[5][N],m,u,v,ans;
vector<int>G[5][N];
multiset<int>S;
signed main()
{
	ans=inf;
	for (int i=1;i<=4;i++) n[i]=read();
	for (int i=1;i<=4;i++)
	{
		for (int j=1;j<=n[i];j++)
			a[i][j]=read();
	}
	for (int j=1;j<=n[4];j++) S.insert(a[4][j]);
	m=read();
	for (int i=1;i<=m;i++)
	{
		u=read(),v=read();
		G[1][u].push_back(v);
	}
	m=read();
	for (int i=1;i<=m;i++)
	{
		u=read(),v=read();
		G[2][u].push_back(v);
	}
	m=read();
	for (int i=1;i<=m;i++)
	{
		u=read(),v=read();
		G[3][u].push_back(v);
	}
	for (int i=3;i>=1;i--)
	{
//		writeln(i);
		for (int j=1;j<=n[i];j++)
		{
			for (auto now:G[i][j])
			{
				if (a[i+1][now]!=inf) S.erase(S.find(a[i+1][now]));
			}
			if (S.empty()) a[i][j]=inf; else a[i][j]+=*S.begin();
			for (auto now:G[i][j])
			{
				if (a[i+1][now]!=inf) S.insert(a[i+1][now]);
			}
		}
		S.clear();
		for (int j=1;j<=n[i];j++)
		{
			if (a[i][j]!=inf) S.insert(a[i][j]);
		}
	}
	for (int i=1;i<=n[1];i++) ans=min(ans,a[1][i]);
	if (ans==inf) puts("-1"); else writeln(ans);
			
}
/*

*/