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
#define Endl endl
#define int ll
#define N 2505
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,a[N][N],s[N][N],s1[N][N],dp[N][N][2],dps[N][N][2],po[N][N][2],l,r,k;
string st[N];
void ad(int &x,int y)
{
	x=(x+y)%mod;
}
signed main()
{
//	freopen("box.in","r",stdin);
//	freopen("box.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>st[i];
		for (int j=1;j<=m;j++) a[i][j]=(st[i][j-1]=='.')?0:1;
	}
	if (st[1][0]=='R') return puts("0"),0;
	for (int i=n;i>=1;i--)
		for (int j=m;j>=1;j--) s[i][j]=s[i][j+1]+a[i][j];
	for (int j=m;j>=1;j--)
		for (int i=n;i>=1;i--) s1[i][j]=s1[i+1][j]+a[i][j];
	if (n==1&&m==1) puts("1");
	else
	{
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
			{
				int h=(m-j)-s[i][j+1],h1=(n-i)-s1[i+1][j];
				
				l=1,r=j-1;po[i][j][0]=0;
				if (po[i][j-1][0]) l=po[i][j-1][0];
				while (l<=r&&s[i][l+1]-s[i][j+1]>h)
				{
					l++;	
				}
				po[i][j][0]=l;
				
				l=1,r=i-1;po[i][j][1]=0;
				if (po[i-1][j][1]) l=po[i-1][j][1];
				while (l<=r&&s1[l+1][j]-s1[i+1][j]>h1)
				{
					l++;
				}
				po[i][j][1]=l;
				
			}
			
	dp[1][1][0]=1;
	dps[1][1][0]=1;
	dp[1][1][1]=1;
	dps[1][1][1]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		if (i!=1||j!=1)
		{
			if (po[i][j][0])
				ad(dp[i][j][0],(dps[i][j-1][0]-dps[i][po[i][j][0]-1][0]+mod)%mod);
			
			if (po[i][j][1])
				ad(dp[i][j][1],(dps[i-1][j][1]-dps[po[i][j][1]-1][j][1]+mod)%mod);
			dps[i][j][0]=dps[i][j-1][0];
			ad(dps[i][j][0],dp[i][j][1]);
			dps[i][j][1]=dps[i-1][j][1];
			ad(dps[i][j][1],dp[i][j][0]);
		}
	writeln((dp[n][m][0]+dp[n][m][1])%mod);
	}
}
/*
3 3
.R.
.RR
...




*/