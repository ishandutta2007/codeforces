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
#define mid (l+(r-l)/2)
#define mod 998244353
#define int ll
#define N 1500005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int lst[N],fst[N],suf[N],pre1[N],Pre[N],Suf[N],len[N],Tag[N],n,m,l,r,d,a[N];
void push_up(int k,int l,int r)
{
	lst[k]=lst[k<<1|1];
	fst[k]=fst[k<<1];
	suf[k]=suf[k<<1|1];
	pre1[k]=pre1[k<<1];
	Pre[k]=Pre[k<<1];
	Suf[k]=Suf[k<<1|1];
	len[k]=max(len[k<<1],len[k<<1|1]);
	if (lst[k<<1]<fst[k<<1|1]&&suf[k<<1|1]==r-mid)
		suf[k]+=suf[k<<1];
	if (lst[k<<1]>fst[k<<1|1]&&pre1[k<<1]==mid-l+1)
		pre1[k]+=pre1[k<<1|1];
	
	if (lst[k<<1]>fst[k<<1|1]&&Pre[k<<1]==mid-l+1) Pre[k]+=pre1[k<<1|1];
	if (lst[k<<1]<fst[k<<1|1]&&suf[k<<1]==mid-l+1) Pre[k]=max(suf[k<<1]+Pre[k<<1|1],Pre[k]);
	if (lst[k<<1]<fst[k<<1|1]&&Suf[k<<1|1]==r-mid) Suf[k]+=suf[k<<1];
	if (lst[k<<1]>fst[k<<1|1]&&pre1[k<<1|1]==r-mid) Suf[k]=max(Suf[k],pre1[k<<1|1]+Suf[k<<1]); 
	if (lst[k<<1]>fst[k<<1|1]) len[k]=max(len[k],Suf[k<<1]+pre1[k<<1|1]);
	if (lst[k<<1]<fst[k<<1|1]) len[k]=max(len[k],suf[k<<1]+Pre[k<<1|1]);
	len[k]=max(len[k],max(Suf[k],Pre[k]));
}
void push_down(int k)
{
	if (!Tag[k]) return;
	lst[k<<1]+=Tag[k];
	fst[k<<1]+=Tag[k];
	lst[k<<1|1]+=Tag[k];
	fst[k<<1|1]+=Tag[k];
	Tag[k<<1]+=Tag[k];
	Tag[k<<1|1]+=Tag[k];
	Tag[k]=0;
}
void build(int k,int l,int r)
{
	if (l==r)
	{
		suf[k]=1;
		pre1[k]=1;
		len[k]=1;
		lst[k]=a[l];
		fst[k]=a[l];
		Suf[k]=1;
		Pre[k]=1;
	}else
	{
		build(k<<1,l,l+(r-l)/2);
		build(k<<1|1,l+(r-l)/2+1,r);
		push_up(k,l,r);
	}
}
void modify(int k,int l,int r,int l1,int r1,int d)
{
	if (l1<=l&&r<=r1)
	{
		lst[k]+=d;
		fst[k]+=d;
		Tag[k]+=d;
		return;
	}
	push_down(k);
	if (l1<=mid) modify(k<<1,l,mid,l1,r1,d);
	if (r1>mid) modify(k<<1|1,mid+1,r,l1,r1,d);
	push_up(k,l,r);
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	m=read();
	for (int i=1;i<=m;i++)
	{
		l=read(),r=read(),d=read();
		modify(1,1,n,l,r,d);
		writeln(len[1]);
	}
}
/*
7 8 7 5 5
*/