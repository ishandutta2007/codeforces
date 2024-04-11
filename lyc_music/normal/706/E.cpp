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
#define id(x, y) (x) * (m + 1) + (y)
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 998244353
//#define int ll
#define N 1005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,q,R[N*N],D[N*N],x,y,X,Y,h,w,now,cnt,now1,Now,NOw,NOW,nOw,Now1,NOw1,NOW1,nOw1;
ll a[N*N];
inline int getnow(int x,int y)
{
	int now=id(0,0);
	for (int i=1;i<=x;i++) now=D[now];
	for (int i=1;i<=y;i++) now=R[now];
	return now;
}
signed main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) 
			{
	scanf("%d",&a[id(i,j)]);}
	for (int i=0;i<=n;i++)
		for (int j=0;j<=m;j++)
		{
			R[id(i,j)]=id(i,j+1);
			D[id(i,j)]=id(i+1,j);
		}
	while (q--)
	{
	scanf("%d%d%d%d%d%d",&x,&y,&X,&Y,&h,&w);
		now=getnow(x-1,y);
		now1=getnow(X-1,Y);
		Now=now;
		for (int i=1;i<=h;i++) Now=D[Now];
		Now1=now1;
		for (int i=1;i<=h;i++) Now1=D[Now1];
		NOW=getnow(x,y-1),NOW1=getnow(X,Y-1);
		nOw=NOW;
		for (int i=1;i<=w;i++) nOw=R[nOw];
		nOw1=NOW1;
		for (int i=1;i<=w;i++) nOw1=R[nOw1];
		for (int i=1;i<=w;i++)
		{
			swap(D[now],D[now1]);
			now=R[now],now1=R[now1];
		}
		for (int i=1;i<=w;i++)
		{
			swap(D[Now],D[Now1]);
			Now=R[Now],Now1=R[Now1];
		}
		for (int i=1;i<=h;i++)
		{
			swap(R[NOW],R[NOW1]);
			NOW=D[NOW],NOW1=D[NOW1];
		}
		for (int i=1;i<=h;i++)
		{
			swap(R[nOw],R[nOw1]);
			nOw=D[nOw],nOw1=D[nOw1];
		}
	}
	now=id(0,1);
	for (int i=1;i<=n;i++)
	{
		now=D[now];now1=now;
		for (int j=1;j<=m;j++)
			writesp(a[now1]),now1=R[now1];
		putchar('\n');
	}
}
/*
4 4 1
1 1 2 2
1 1 2 2
3 3 4 4
3 3 4 4
1 1 3 3 2 2
*/