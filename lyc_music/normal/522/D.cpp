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
#define N 500005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,a[N],cnt,Cnt,l,r,now,now1,ST[N][25],L,R;
pa A[N],B[N];
map<int,int>b;
int query(int l,int r)
{
	int t=log2(r-l+1);
	return min(ST[l][t],ST[r-(1<<t)+1][t]);
}
signed main()
{
	n=read(),m=read();int pasddqwdas=n;
	for (int i=1;i<=n;i++) 
	{
		a[i]=read();
		if (!b[a[i]]) b[a[i]]=i;
		else
		{
			if (b[a[i]]>B[Cnt].fi) B[++Cnt]={b[a[i]],i},ST[Cnt][0]=i-b[a[i]];
			b[a[i]]=i;
		}
	}
	n=Cnt;
	for (int i=1;(1<<i)<=n;i++)
		for (int j=1;j+(1<<i)-1<=n;j++)
		{
			ST[j][i]=min(ST[j][i-1],ST[j+(1<<(i-1))][i-1]);
		}
	while (m--)
	{
		L=read(),R=read();
		now=inf,now1=-inf;
		l=1,r=n;
		while (l<=r)
		{
			int mid=l+(r-l)/2;
			if (B[l+(r-l)/2].fi<L) l=mid+1;
			else 
			{
				now=l+(r-l)/2;
				r=mid-1;
			}
		}
		l=1,r=n;
		
		while (l<=r)
		{
			int mid=l+(r-l)/2;
			if (B[l+(r-l)/2].se>R) r=mid-1;
			else 
			{
				now1=l+(r-l)/2;
				l=mid+1;
			}
		}
		if (now1>=now)
		{
			writeln(query(now,now1));
		} else writeln(-1);
	}
}
/*
5 3
1 1 1 1 1 
5 5
*/