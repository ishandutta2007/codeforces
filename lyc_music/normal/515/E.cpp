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
int n,q,d[N],p[N],h[N],SM[N],ST[N],M,l,r,x,y,sm[N],st[N],ans;
void build(int k,int l,int r)
{
	if (l==r)
	{
		sm[k]=l,st[k]=l;
	}
	else
	{
		build(k<<1,l,l+(r-l)/2);
		build(k<<1|1,l+(r-l)/2+1,r);
		if (SM[sm[k<<1]]<SM[sm[k<<1|1]]) sm[k]=sm[k<<1|1];
		else sm[k]=sm[k<<1];
		if (ST[st[k<<1]]>ST[st[k<<1|1]]) st[k]=st[k<<1|1];
		else st[k]=st[k<<1];
	}
}
int queryM(int k,int l,int r,int l1,int r1)
{
	if (l1<=l&&r<=r1)
	{
		return sm[k];
	}
	int res=0;
	if (l1<=l+(r-l)/2) res=queryM(k<<1,l,l+(r-l)/2,l1,r1);
	if (r1>l+(r-l)/2) 
	{
		if (!res) res=queryM(k<<1|1,l+(r-l)/2+1,r,l1,r1);
		else
		{
			int t=queryM(k<<1|1,l+(r-l)/2+1,r,l1,r1);
			if (SM[t]>SM[res]) res=t;
		}
	}
	return res;
}
int queryT(int k,int l,int r,int l1,int r1)
{
	if (l1<=l&&r<=r1)
	{
		return st[k];
	}
	int res=0;
	if (l1<=l+(r-l)/2) res=queryT(k<<1,l,l+(r-l)/2,l1,r1);
	if (r1>l+(r-l)/2) 
	{
		if (!res) res=queryT(k<<1|1,l+(r-l)/2+1,r,l1,r1);
		else
		{
			int t=queryT(k<<1|1,l+(r-l)/2+1,r,l1,r1);
			if (ST[t]<ST[res]) res=t;
		}
	}
	return res;
}
	
signed main()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++) d[i]=read();
	for (int i=n+1;i<=2*n;i++) d[i]=d[i-n];
	for (int i=1;i<=2*n;i++) p[i+1]=p[i]+d[i];
	for (int i=1;i<=n;i++) h[i]=h[i+n]=read();
	M=n*2;
	for (int i=1;i<=M;i++) SM[i]=h[i]*2+p[i],ST[i]=-h[i]*2+p[i];
	build(1,1,M);
	while (q--)
	{
		l=read(),r=read();
		if (r<l) r+=n; 
		x=queryM(1,1,M,r+1,l+n-1);
		y=queryT(1,1,M,r+1,l+n-1);
		ans=0;
		if (x!=y) ans=SM[x]-ST[y];
		else
		{
			if (r+1!=x)
			{
				y=queryM(1,1,M,r+1,x-1);
				ans=max(ans,SM[y]-ST[x]);
				y=queryT(1,1,M,r+1,x-1);
				ans=max(ans,SM[x]-ST[y]);
			}
			if (x!=l+n-1)
			{
				y=queryM(1,1,M,x+1,l+n-1);
				ans=max(ans,SM[y]-ST[x]);
				y=queryT(1,1,M,x+1,l+n-1);
				ans=max(ans,SM[x]-ST[y]);
			}
		}
		writeln(ans);
	}
				
				
			
}
/*

*/