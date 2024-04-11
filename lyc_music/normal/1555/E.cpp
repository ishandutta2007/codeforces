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
#define N 2000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,Ans,po[N],L,R,ans;
struct node
{
	int l,r,w;
}a[N];
struct
{
	int ans,tag;
}tr[N*5];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
void pushdown(int k)
{
	if (!tr[k].tag) return;
	tr[k<<1].ans+=tr[k].tag;
	tr[k<<1|1].ans+=tr[k].tag;
	tr[k<<1].tag+=tr[k].tag;
	tr[k<<1|1].tag+=tr[k].tag;
	tr[k].tag=0;
}
void pushup(int k)
{
	tr[k].ans=min(tr[k<<1].ans,tr[k<<1|1].ans);
}
void update(int k,int l,int r,int L,int R,int del)
{
	if (L<=l&&r<=R)
	{
		tr[k].ans+=del;
		tr[k].tag+=del;
		return;
	}
	pushdown(k);
	if (L<=l+(r-l)/2) update(k<<1,l,l+(r-l)/2,L,R,del);
	if (R>l+(r-l)/2) update(k<<1|1,l+(r-l)/2+1,r,L,R,del);
	pushup(k);
}
void ins(int k)
{
	int l=a[k].l,r=a[k].r;
//	cout<<l<<","<<r<<endl;
	update(1,1,m,l,r-1,1);
}
void del(int k)
{
	int l=a[k].l,r=a[k].r;
	update(1,1,m,l,r-1,-1);
}
signed main()
{
	n=read();m=read()-1;
	for (int i=1;i<=n;i++)
	{
		a[i].l=read(),a[i].r=read(),a[i].w=read();
	}
	sort(a+1,a+n+1,cmp);
	int p=1;
	R=0;ans=0;Ans=1e18;
	for (int L=1;L<=n;L++)
	{
		while (R<n&&tr[1].ans<=0)
		{
			R++;
			if (R>n) break;
			ins(R);
		}
		if (tr[1].ans<=0) break;
		Ans=min(Ans,a[R].w-a[L].w);
		del(L);
	}
	writeln(Ans);
}
/*

*/