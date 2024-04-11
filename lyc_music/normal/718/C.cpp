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
#define mod 1000000007
#define int ll
#define N 1000005
#define M 3
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
struct Matrix
{
	int a[M][M],n,m;
	void init()
	{
		memset(a,0,sizeof(a));
	}
	void init1()
	{
		memset(a,0,sizeof(a));
		for (int i=0;i<2;i++) a[i][i]=1;
	}
}S[N],Tag[N];
int Tg[N],a[N],n,m,x,y,opt;
Matrix mul(Matrix X,Matrix Y)
{
	Matrix z;
	z.init();
	for (int i=0;i<X.n;i++)
		for (int j=0;j<Y.m;j++)
			for (int k=0;k<X.m;k++)
			{
				z.a[i][j]=(z.a[i][j]+X.a[i][k]*Y.a[k][j]%mod)%mod;
			}
	z.n=X.n;
	z.m=Y.m;
	return z;
}
Matrix add(Matrix X,Matrix Y)
{
	Matrix z;
	z.init();
	for (int i=0;i<X.n;i++)
		for (int j=0;j<X.m;j++)
			{
				z.a[i][j]=(X.a[i][j]+Y.a[i][j])%mod;
			}
	z.n=X.n;
	z.m=X.m;
	return z;
}
Matrix MPow(int k)
{
	Matrix P,X;
	P.init();
	P.n=2,P.m=2;
	P.a[0][1]=P.a[1][0]=P.a[1][1]=1;
	X=P;
	k--;
	while (k>0)
	{
		if (k&1) P=mul(P,X);
		X=mul(X,X);
		k>>=1;
	}
	return P;
}
void pushup(int k)
{
	S[k]=add(S[k<<1],S[k<<1|1]);
}
void pushdown(int k)
{
	if (!Tg[k]) return;
	S[k<<1]=mul(S[k<<1],Tag[k]);
	S[k<<1|1]=mul(S[k<<1|1],Tag[k]);
	Tag[k<<1]=mul(Tag[k<<1],Tag[k]);
	Tag[k<<1|1]=mul(Tag[k<<1|1],Tag[k]);
	Tag[k].init1();
	Tg[k]=0;
	Tg[k<<1]=1,Tg[k<<1|1]=1;
}
void build(int k,int l,int r)
{
	if (l==r)
	{
		Matrix now=MPow(a[l]-1),P;
		P.init();
		P.a[0][0]=0,P.a[0][1]=1;P.n=1,P.m=2;
		if (a[l]!=1) P=mul(P,now);
		S[k]=P;Tag[k].init1();
	}
	else
	{
		build(k<<1,l,l+(r-l)/2);
		build(k<<1|1,l+(r-l)/2+1,r);
		pushup(k);Tag[k].init1();
	}
	Tg[k]=0;Tag[k].n=Tag[k].m=2;
}
void modify(int k,int L,int R,int l,int r,Matrix del)
{
	if (l<=L&&R<=r)
	{
		S[k]=mul(S[k],del);
		Tag[k]=mul(Tag[k],del);
		Tg[k]=1;
		return;
	}
	pushdown(k);
	if (l<=L+(R-L)/2) modify(k<<1,L,L+(R-L)/2,l,r,del);
	if (r>L+(R-L)/2) modify(k<<1|1,L+(R-L)/2+1,R,l,r,del);
	pushup(k);
}
Matrix query(int k,int L,int R,int l,int r)
{
	if (l<=L&&R<=r) return S[k];
	Matrix res;
	res.init();res.n=1,res.m=2;
	pushdown(k);
	if (l<=L+(R-L)/2) res=add(res,query(k<<1,L,L+(R-L)/2,l,r));
	if (r>L+(R-L)/2) res=add(res,query(k<<1|1,L+(R-L)/2+1,R,l,r));
	pushup(k);
	return res;
}
signed main()
{
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	while (m--)
	{
		opt=read(),x=read(),y=read();
		if (opt==1)
		{
			modify(1,1,n,x,y,MPow(read()));
		} else
		{
			writeln(query(1,1,n,x,y).a[0][1]);
		}
	}
	
}
/*

*/