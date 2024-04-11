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
int s[N],Tag[N],a[N],n,ans;
pa b[N];
void pushup(int k){s[k]=min(s[k<<1],s[k<<1|1]);}
void pushdown(int k)
{
	if (!Tag[k]) return;
	s[k<<1]+=Tag[k];
	s[k<<1|1]+=Tag[k];
	Tag[k<<1]+=Tag[k];
	Tag[k<<1|1]+=Tag[k];
	Tag[k]=0;
}
int query(int k,int l,int r,int l1,int r1)
{
	if (l>=l1&&r<=r1) return s[k];
	int res=inf;
	pushdown(k);
	int mid=l+(r-l)/2;
	if (l1<=mid) res=min(res,query(k<<1,l,mid,l1,r1));
	if (r1>mid) res=min(res,query(k<<1|1,mid+1,r,l1,r1));
	pushup(k);
	return res;
}
void update(int k,int l,int r,int l1,int r1,int p)
{
	if (l>=l1&&r<=r1)
	{
		s[k]+=p;
		Tag[k]+=p;
		return;
	}
	pushdown(k);
	int mid=l+(r-l)/2;
	if (l1<=mid) update(k<<1,l,mid,l1,r1,p);
	if (r1>mid) update(k<<1|1,mid+1,r,l1,r1,p);
	pushup(k);
}	
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) 
	{
		a[i]=read();
	}
	for (int i=1;i<=n;i++)
	{
		b[i]={a[i],i};
	}
	sort(b+1,b+n+1);
	for(int i=n;i>=1;i--)
	{
		int u=b[i].se;
		if (query(1,1,n,u,n)+b[i].fi>=0) 
		{
			ans+=1;
			update(1,1,n,u,n,b[i].fi);
		}
	}
	writeln(ans);
}
/*

*/