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
int f3[N],fac[N],inv[N],ans,ans1,n;
inline ll quickPower(int x,int y)
{
	ll res=1;
	while (y)
	{
		if (y&1)res=(res*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return res;
}
inline ll C(int x,int y)
{
	return x<y?0:(1LL*inv[y]%mod*inv[x-y]%mod*fac[x]%mod)%mod;
}
signed main()
{
	n=read();
	ans=0;
	f3[0]=1;
	for (int i=1;i<=n;i++) f3[i]=(f3[i-1]*3)%mod;
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=(fac[i-1]*i)%mod;
	inv[0]=1;
	ans1=1;
	for (int i=1;i<=n;i++) inv[i]=quickPower(fac[i],mod-2);
	for (int i=1;i<=n;i++)
	{
		ans1*=-1;
		ans=(ans+ans1*quickPower(3,n*(n-i)+i)*C(n,i)%mod+mod)%mod;
    }
	ans=ans*2%mod;
	ans=(ans+quickPower(3,n*n))%mod;
	ans1=-1; 
	for (int i=0;i<n;i++)     
	{
		ans1*=-1; 
		ans=(ans+ans1*C(n,i)*((quickPower(1-f3[i]+mod,n)-quickPower(-f3[i]+mod,n)+mod)%mod)*3+mod)%mod;
	}
	ans=(quickPower(3,n*n)-ans+mod)%mod;
	writeln(ans);
}
/*
*/