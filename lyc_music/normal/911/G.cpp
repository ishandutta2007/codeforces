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
#define N 20000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int Tree[N],lson[N],rson[N],rt[105],cnt,n,a[N],q,l,r,x,y;
void push_up(int k){Tree[k]=Tree[lson[k]]+Tree[rson[k]];}
int merge(int x,int y)
{
	if (!x||!y) return x|y;
	lson[x]=merge(lson[x],lson[y]);
	rson[x]=merge(rson[x],rson[y]);
	push_up(x),push_up(y);
	return x;
}
void modify(int &RT,int l,int r,int p)
{
	if (!RT) RT=++cnt;
	if (l==r) return (void)(Tree[RT]=1);
	if (p<=l+(r-l)/2) modify(lson[RT],l,l+(r-l)/2,p); else modify(rson[RT],l+(r-l)/2+1,r,p);
	push_up(RT);
}
void update(int &RT,int &RT1,int l,int r,int l1,int r1)
{
	if (!RT) return;
	if (l>=l1&&r<=r1)
	{
		RT1=merge(RT,RT1),RT=0;
		return;
	}
	if (!RT1) RT1=++cnt;
	if (l1<=l+(r-l)/2) update(lson[RT],lson[RT1],l,l+(r-l)/2,l1,r1);
	if (r1>l+(r-l)/2) update(rson[RT],rson[RT1],l+(r-l)/2+1,r,l1,r1);
	push_up(RT),push_up(RT1);	
}
int query(int &RT,int l,int r,int p)
{
	if (!RT) return 0;
	if (l==r) return Tree[RT];
	int res=0;
	if (p<=l+(r-l)/2) res=query(lson[RT],l,l+(r-l)/2,p); else res=query(rson[RT],l+(r-l)/2+1,r,p);
	push_up(RT);return res;
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),modify(rt[a[i]],1,n,i);
	q=read();
	while (q--)
	{
		l=read(),r=read(),x=read(),y=read();
		if (x!=y)
		{
			update(rt[x],rt[y],1,n,l,r);
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=100;j++)
			if (query(rt[j],1,n,i)) writesp(j);
	}
}
/*

*/