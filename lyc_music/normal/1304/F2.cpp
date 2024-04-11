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
#define inf 1e13
#define mod 998244353
#define int ll
#define N 100005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
struct Segmentree_VAL
{
	int lson[500000],rson[500000],Ans[500000],Lazy[500000],cnt,RT;
	void init()
	{
		for (int i=1;i<500000;i++) Ans[i]=-inf;
		RT=1;
	}
	inline void push_up(int rt)
	{
		Ans[rt]=max(Ans[rt<<1],Ans[rt<<1|1]);
	}
	inline void modify(int rt,int l,int r,int val,int ad)
	{
		if (l==r)
		{
			Ans[rt]=ad;
			return;
		}
		int mid=l+(r-l)/2;
		if (val<=mid) modify(rt<<1,l,mid,val,ad);
		else modify(rt<<1|1,mid+1,r,val,ad);
		push_up(rt);
	}
	inline int query(int rt,int l,int r,int vall,int valr)
	{
		if (valr<vall) return -inf;
		if (vall<=l&&r<=valr) return Ans[rt];
		int mid=l+(r-l)/2,retans=-inf;
		if (vall<=mid) retans=max(retans,query(rt<<1,l,mid,vall,valr));
		if (valr>mid) retans=max(retans,query(rt<<1|1,mid+1,r,vall,valr));
		push_up(rt);
		return retans;
	}
}Tree[5];
int n,m,K,a[52][N],f[N];
signed main()
{
	n=read();m=read(),K=read();
	for (int i=1;i<=3;i++) Tree[i].init();
	swap(n,m);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++) a[i][j]=read()+a[i][j-1];
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j+K-1<=n;j++)
		{
			f[j]=max(0ll,max(Tree[3].query(Tree[3].RT,1,n,1,j-K),
			Tree[3].query(Tree[3].RT,1,n,j+K,n)));
			f[j]=max(f[j],Tree[1].query(Tree[1].RT,1,n,j-K+1,j)+a[i][j-1]);
			f[j]=max(f[j],Tree[2].query(Tree[2].RT,1,n,j+1,j+K)-a[i][j+K-1]);
		}
		for (int j=1;j+K-1<=n;j++)
		{
			f[j]=f[j]+a[i][j+K-1]-a[i][j-1]
				  +a[i+1][j+K-1]-a[i+1][j-1];
			Tree[1].modify(Tree[1].RT,1,n,j,f[j]-a[i+1][j+K-1]);
			Tree[2].modify(Tree[2].RT,1,n,j,f[j]+a[i+1][j-1]);
			Tree[3].modify(Tree[3].RT,1,n,j,f[j]);
		}
	}
		writeln(Tree[3].query(Tree[3].RT,1,n,1,n));
}
/*

*/