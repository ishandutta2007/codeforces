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
#define mid (l+(r-l)/2)
#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int Val[N],Tag1[N],Tag0[N],Tagr[N],n,m,opt[N],x,y,L[N],R[N],b[N];
void pushup(int k)
{
	Val[k]=Val[k<<1]+Val[k<<1|1];
}
void pushdown(int k,int l,int r)
{
	if (Tag1[k])
	{
		Val[k<<1]=(mid-l+1);
		Tag1[k<<1]=1,Tag0[k<<1]=0,Tagr[k<<1]=0;
		Val[k<<1|1]=(r-mid);
		Tag1[k<<1|1]=1,Tag0[k<<1|1]=0,Tagr[k<<1|1]=0;
	}
	if (Tag0[k])
	{
		Val[k<<1]=0;
		Tag0[k<<1]=1,Tag1[k<<1]=0,Tagr[k<<1]=0;
		Val[k<<1|1]=0;
		Tag0[k<<1|1]=1,Tag1[k<<1|1]=0,Tagr[k<<1|1]=0;
	}
	if (Tagr[k])
	{
		Val[k<<1]=(mid-l+1)-Val[k<<1];
		Tagr[k<<1]^=1;
		Val[k<<1|1]=(r-mid)-Val[k<<1|1];
		Tagr[k<<1|1]^=1;
	}
	Tag1[k]=Tag0[k]=Tagr[k]=0;
}
void build(int k,int l,int r)
{
	if (l==r) Val[k]=0;
	else
	{
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		pushup(k);
	}
}
void reset1(int k,int l,int r,int l1,int r1)
{
	if (l>=l1&&r<=r1)
	{
		Val[k]=(r-l+1);
		Tag1[k]=1,Tagr[k]=0,Tag0[k]=0;
		return;
	}
	pushdown(k,l,r);
	if (l1<=mid) reset1(k<<1,l,mid,l1,r1);
	if (r1>mid) reset1(k<<1|1,mid+1,r,l1,r1);
	pushup(k);
}

void reset0(int k,int l,int r,int l1,int r1)
{
	if (l>=l1&&r<=r1)
	{
		Val[k]=0;
		Tag0[k]=1,Tagr[k]=0,Tag1[k]=0;
		return;
	}
	pushdown(k,l,r);
	if (l1<=mid) reset0(k<<1,l,mid,l1,r1);
	if (r1>mid) reset0(k<<1|1,mid+1,r,l1,r1);
	pushup(k);
}
void reves(int k,int l,int r,int l1,int r1)
{
	if (l>=l1&&r<=r1)
	{
		Val[k]=(r-l+1)-Val[k];
		Tagr[k]^=1;
		return;
	}
	pushdown(k,l,r);
	if (l1<=mid) reves(k<<1,l,mid,l1,r1);
	if (r1>mid) reves(k<<1|1,mid+1,r,l1,r1);
	pushup(k);
}
int query(int k,int l,int r)
{
	if (l==r) return l;
	int res=-1;
	pushdown(k,l,r);
	if (Val[k<<1]<(mid-l+1))
	{
		res=query(k<<1,l,mid);
		return res;
	}
	if (Val[k<<1|1]<(r-mid)) res=query(k<<1|1,mid+1,r);
	pushup(k);
	return res;
}
signed main()
{
	n=read();m=n;b[++b[0]]=1;
	for (int i=1;i<=m;i++)
	{
		opt[i]=read(),L[i]=read(),R[i]=read();
		b[++b[0]]=L[i],b[++b[0]]=R[i];b[++b[0]]=R[i]+1;
	}
	sort(b+1,b+b[0]+1);
	b[0]=unique(b+1,b+b[0]+1)-b;
	n=b[0];
	build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		x=lower_bound(b+1,b+b[0]+1,L[i])-b;
		y=lower_bound(b+1,b+b[0]+1,R[i])-b;
		if (opt[i]==1) reset1(1,1,n,x,y);
		if (opt[i]==2) reset0(1,1,n,x,y);
		if (opt[i]==3) reves(1,1,n,x,y);
		int t=query(1,1,n);
		if (t==-1) writeln(n+1); else writeln(b[t]);
	}
}
/*
10
1 1 9
2 2 10
2 1 10
1 8 10
3 8 10
2 1 8
3 9 10
1 7 10
1 4 10
3 10 10
*/