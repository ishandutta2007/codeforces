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
#define N 200005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,a[N],lg[N],f[N][20],f1[N][20],l,r,ans,mid,t;
int query(int l,int r)
{
	t=trunc(log2(r-l+1));
	return max(f[l][t],f[r-(1<<t)+1][t]);
}
int query1(int l,int r)
{
	t=trunc(log2(r-l+1));
	return min(f1[l][t],f1[r-(1<<t)+1][t]);
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();ans=0;
		lg[0]=-1;
		for (int i=1;i<=n;i++)	a[i]=read(),lg[i]=lg[i/2]+1,f[i][0]=f1[i][0]=a[i];
		for (int i=1;(1<<i)<=n;i++)
			for (int j=1;j+(1<<i)-1<=n;j++)
			{
				f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
				f1[j][i]=min(f1[j][i-1],f1[j+(1<<(i-1))][i-1]);
			}
		for (int i=1;i<=n-2;i++)
		{
			l=i+1;r=n-1;ans=0;
			while (l<=r)
			{
				mid=l+(r-l)/2;
				if (query(1,i)<query1(i+1,mid)) l=mid+1;
				else 
				if (query(1,i)>query1(i+1,mid)) r=mid-1;
				else
				{
					if (query(1,i)==query(mid+1,n)) 
					{
						ans=mid;
						break;
					}
					if (query(1,i)<query(mid+1,n)) l=mid+1; else r=mid-1;
				}
			}
			if (ans)
			{
				puts("YES");
				writesp(i),writesp(ans-i),writeln(n-ans);
				break;
			}
		}
		if (!ans) puts("NO");
	}
}
/*

*/