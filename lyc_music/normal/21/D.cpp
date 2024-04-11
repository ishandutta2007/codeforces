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
#define inf 1000000000000000005
#define mod 998244353
#define int ll
#define N 16
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,f[N][N],du[N],dp[(1ll<<N)],x,y,z,ans;
vector<pair<int,int> >G;
signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			f[i][j]=((i^j)>0)*inf;
	for (int i=1;i<=m;i++)
	{
		x=read(),y=read(),z=read();
		f[x][y]=f[y][x]=min(f[x][y],z);
		du[x-1]++,du[y-1]++;
		ans+=z;
		G.push_back({x,y});
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			if (k!=i)
				for (int j=1;j<=n;j++)
					if (k!=j&&i!=j)
						f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
	for (int i=1;i<=m;i++)
		if (f[1][G[i-1].fi]>=inf&&f[1][G[i-1].se]>=inf)
		{
			puts("-1");
			return 0;
		}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for (int i=0;i<=(1ll<<n)-1;i++)
	{
		bool bl=1;
		for (int j=0;j<n;j++)
			if (((1ll<<j)&i)&&(du[j]&1)) {bl=0;break;}
//		cout<<i<<" "<<bl<<endl;
		if (bl) dp[i]=0;
		else
		{
			for (int j=0;j<n;j++)
				for (int k=0;k<n;k++)
					if (j!=k&&((1ll<<j)&i)&&((1ll<<k)&i)&&(du[j]&1)&&(du[k]&1))
						dp[i]=min(dp[i],dp[i^(1ll<<k)^(1ll<<j)]+f[j+1][k+1]);
//						cout<<i<<" "<<j<<" "<<k<<endl;
		}
	}
	if (dp[(1ll<<n)-1]>1e16) puts("-1"); else writeln(ans+dp[(1ll<<n)-1]);
		
}
/*

*/