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
#define N 1000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,tag[N],s[N],head[N],x,a[N],D[N],dfn[N],ldfn[N],rdfn[N],m,cnt,id;
string st;
struct
{
	int to,nx;
}e[N<<1];
void ad(int x,int y){e[++cnt].to=y;e[cnt].nx=head[x];head[x]=cnt;}
void pushup(int k){s[k]=s[k<<1]+s[k<<1|1];}
void dfs(int k,int fa){dfn[k]=++id;D[id]=k;ldfn[k]=id;for (int i=head[k];i;i=e[i].nx) if (e[i].to!=fa) dfs(e[i].to,k);rdfn[k]=id;}
void build(int k,int l,int r){if (l==r) s[k]=a[D[l]]; else build(k<<1,l,l+(r-l)/2),build(k<<1|1,l+(r-l)/2+1,r),pushup(k);}
void pushdown(int k,int l,int r)
{
	int mid=l+(r-l)/2;
	if (tag[k])
	{
		tag[k<<1]^=1,tag[k<<1|1]^=1;
		s[k<<1]=(mid-l+1)-s[k<<1],s[k<<1|1]=(r-mid)-s[k<<1|1];
	}
	tag[k]=0;
}
int query(int k,int l,int r,int l1,int r1)
{
	if (l>=l1&&r<=r1) return s[k];
	int res=0;
	pushdown(k,l,r);
	int mid=l+(r-l)/2;
	if (l1<=mid) res+=query(k<<1,l,mid,l1,r1);
	if (r1>mid) res+=query(k<<1|1,mid+1,r,l1,r1);
	pushup(k);
	return res;
}
void update(int k,int l,int r,int l1,int r1)
{
	if (l>=l1&&r<=r1)
	{
		tag[k]^=1;
		s[k]=(r-l+1)-s[k];
		return;
	}
	pushdown(k,l,r);
	int mid=l+(r-l)/2;
	if (l1<=mid) update(k<<1,l,mid,l1,r1);
	if (r1>mid) update(k<<1|1,mid+1,r,l1,r1);
	pushup(k);
}	
signed main()
{
	cin>>n;
	for (int i=1;i<n;i++) cin>>x,ad(x,i+1);
	for (int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0);
	build(1,1,n);
	cin>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>st>>x;
		if (st=="get") writeln(query(1,1,n,ldfn[x],rdfn[x])); else update(1,1,n,ldfn[x],rdfn[x]);
	}	 
}
/*

*/