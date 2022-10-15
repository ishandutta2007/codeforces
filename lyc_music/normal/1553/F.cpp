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
#define N 300005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],mx;
ll ans;
int B=255;
ll b[N];
int B1=455,From[N];
struct
{
	ll c[N],S[N];
	inline ll query(int x)
	{
		return S[From[x]-1]+c[x];
	}
	inline void update(int x,int y)
	{
		for (int j=From[x];j<=From[mx];j++) S[j]+=y;
		for (int j=x;j<=min(mx,From[x]*B1);j++) c[j]+=y;
	}
}S,S1;
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) 
	{
		a[i]=read(),mx=max(mx,a[i]);
	}
	for (int i=1;i<=mx;i++) From[i]=(i-1)/B1+1;
	for (int j=1;j<=n;j++)
	{
		for (int l=1,r;l<=a[j];)
		{
			r=min(a[j],a[j]/(a[j]/l));
			ans+=a[j]*(S1.query(r)-S1.query(l-1))-(S.query(r)-S.query(l-1))*(a[j]/l);
			l=r+1;
		}
		ans+=(S1.query(mx)-S1.query(a[j]))*a[j];
		if (a[j]<=B) ans+=b[a[j]];
		else
		{
			ans+=S.query(a[j]-1);
			for (int k=a[j];k<=mx;k+=a[j])
			{
				ans+=(S.query(min(mx,k+a[j]-1))-S.query(k-1))-(S1.query(min(mx,k+a[j]-1))-S1.query(k-1))*k;
			}
		}
		writesp(ans);
		S1.update(a[j],1);
		S.update(a[j],a[j]);
		for (int k=1;k<=B;k++)
			b[k]+=a[j]%k;
	}
		
}
/*

*/