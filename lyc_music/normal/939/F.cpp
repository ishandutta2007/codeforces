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
//#define N
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,h,t,q[200005],l[200005],r[200005],dp[105][200005];
void insert(int x,int y)
{
	while(h<=t&&dp[x][q[t]]>=dp[x][y]) t--;
	q[++t]=y;
}
signed main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		l[i]=read();r[i]=read();
	}
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=n;j++) dp[i][j]=dp[i-1][j];
		h=1;t=0;
		for(int j=0;j<=n;j++)
		{
			insert(i-1,j);
			while(h<=t&&q[h]<j-r[i]+l[i]) h++;
			if(h<=t) dp[i][j]=min(dp[i][j],dp[i-1][q[h]]+2);
		}
		h=1;t=0;
		int l1=l[i]+1,r1=r[i]+1;
		for(int j=r[i];j>l[i];j--) insert(i-1,j);
		for(int j=0;j<=n;j++)
		{
			l1--;r1--;
			if(l1>=0) insert(i-1,l1);
			while(h<=t && q[h]>r1) h++;
			if(h<=t) dp[i][j]=min(dp[i][j],dp[i-1][q[h]]+1);
		}
	}
	if(dp[m][n]>=10000) puts("Hungry");
	else printf("Full\n%d\n",dp[m][n]);
}
/*

*/