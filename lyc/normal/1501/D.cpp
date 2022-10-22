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
int X,Y,n,m,K,a[N],tp[N],tp1[N],b[N],p,P,XXX,Ans,A[N],Cnt,G2[N];
vector<int>G,G1;
void exgcd(int n,int m,int &X,int &Y)
{
	if (m==0) {X=1;Y=0;return;}
	exgcd(m,n%m,X,Y);
	int k=X,kk=Y;
	X=kk;
	Y=k-n/m*kk;
}
signed main()
{
	n=read(),m=read(),K=read();
	for (int i=1;i<=n;i++) a[i]=read(),tp[a[i]]=i;
	for (int i=1;i<=m;i++) b[i]=read(),tp1[b[i]]=i;
	for (int i=1;i<=2*max(n,m);i++)
		if (tp[i]&&tp1[i]) G.push_back(tp[i]),G1.push_back(tp1[i]);
	p=__gcd(n,m),P=m/p;
	for (int i=0;i<G.size();i++)
	{
		if ((G1[i]-G[i])%p!=0) continue;
		exgcd(n,m,X,Y);
		X=(X*((G1[i]-G[i])/p)%P+P)%P;
		G2[++Cnt]=X*n+G[i];
	}
	sort(G2+1,G2+Cnt+1);
	Ans=(K-1)/(( n/__gcd(n,m)*m) - Cnt)* (n/__gcd(n,m)*m) ;
	K=(K-1)% (n/__gcd(n,m)*m-Cnt) +1;
	for (int i=1;i<=Cnt;i++)
		if (G2[i]-G2[i-1]<K+1) K-=G2[i]-G2[i-1]-1,Ans+=G2[i]-G2[i-1];
		else 
		{
			Ans+=K;K=0;
		}
	writeln(Ans+K);
}
/*

*/