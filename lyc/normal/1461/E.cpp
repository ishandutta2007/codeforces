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
//#define N
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int now,l,r,T,x,y,r1,b[1000005];
signed main()
{
	now=read(),l=read(),r=read(),T=read(),x=read(),y=read();
	if (x>y)
	{
		r1=r-y;
		if (now>r1)
		{
			now-=((now-r1-1)/x+1)*x;
			if (now<l) return puts("No"),0;
			T-=((now-r1-1)/x+1);
			if (T<0) return puts("Yes"),0;
//			cout<<now<<" "<<T<<" "<<(now-l+1)/(x-y)+((now-l+1)%(x-y)>0)<<endl;
			if (T<(now-l+1)/(x-y)+((now-l+1)%(x-y)>0)) return puts("Yes"),0; else return puts("No"),0;
		} else
		{
			if (T<(now-l+1)/(x-y)+((now-l+1)%(x-y)>0)) return puts("Yes"),0; else return puts("No"),0;
		}
	} else
	if (x==y)
	{
		if (now+y<=r)
		{
			return puts("Yes"),0;
		} else
		{
			now-=x;
			if (now<l) return puts("No"),0;
			T--;
			while (T)
			{
				if (now+y<=r) now+=y;
				now-=x;
				if (now<l) return puts("No"),0;
			}
			puts("Yes");
		}
	} else
	if (x<y)
	{
		now-=l;
		while (T>0) 
		{
			T-=(now)/x;
			now%=x;
//			cout<<now+l<<endl;
			if (b[now]) 
			{
				return puts("Yes"),0;
			}
			b[now]=1;
			if (T<=0) return puts("Yes"),0;
			if (now+y+l>r) return puts("No"),0;
			now+=y;
		}
		puts("Yes");
	}
}
/*
k-2
1 10
k+y k+y-x
k-x k-x+y

2 7 9
*/