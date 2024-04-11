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
#define inf 1e18
#define mod 998244353
#define int ll
#define N 155
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
struct Matrix
{
	bitset<155>a[155];
	Matrix operator *(const Matrix x)
	{
		Matrix res;
		F(k,1,150)
			F(i,1,150)
					if (a[i][k]) 
						res.a[i]|=x.a[k];
		return res;
	}
}ST,nowST,ST1;
int n,m,now,F[N][N],f[N][N],ans;
struct edge
{
	int s,t,v;
}e[N<<1];
bool Cmp(edge x,edge y)
{
	return x.v<y.v;
}
signed main()
{
	n=read(),m=read();ans=inf;
	for (int i=1;i<=m;i++) 
		e[i].s=read(),e[i].t=read(),e[i].v=read();
	sort(e+1,e+m+1,Cmp);
	for (int i=1;i<=n;i++)
		ST.a[i][i]=1;
	memset(F,0x3f,sizeof(F));
	for (int i=1;i<=n;i++) F[i][i]=0;
	for (int i=1;i<=m;i++)
	{
		now=e[i].v-e[i-1].v;
		Matrix nowST;
		for (int u=1;u<i;u++)	nowST.a[e[u].s][e[u].t]=1;
		while (now)
		{
			if (now&1)
			{
				ST=ST*nowST;
			}
			nowST=nowST*nowST;
			now>>=1;
		}
		F[e[i].s][e[i].t]=1;
		memcpy(f,F,sizeof(f));
		for (int k=1;k<=n;k++)
			for (int u=1;u<=n;u++)
				for (int v=1;v<=n;v++)
				f[u][v]=min(f[u][v],f[u][k]+f[k][v]);
		for (int u=1;u<=n;u++)
			if (ST.a[1][u])
				ans=min(ans,e[i].v+f[u][n]);
	}
	if (ans==inf) puts("Impossible");
	else
	writeln(ans);
}
/*

*/