//QwQcOrZ yyds!!!
#pragma GCC optimize(2)
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
#define int ll
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
const int N = 505;
int dp[N][N*N/2],f[N],n,mod;
	int b[N*N/2],w[N*N/2],dp1[N*N/2];
void init(){
    dp[1][0]=1;
    for(int i=2;i<=n;i++){
        ll sum=0;
        for(int j=0;j<=i*(i-1)/2;j++){
             sum=(sum+dp[i-1][j])%mod;
             if(j>=i) sum=(sum-dp[i-1][j-i]+mod)%mod;
             dp[i][j]=(sum)%mod;
        }
    }
}
inline int work(int n)
{
	int ans=0;
	if (n<=3) return 0;
	ans=work(n-1)*n%mod;
	
	memset(dp1,0,sizeof(dp1));
	dp1[0]=dp[n-1][0];
	for (int i=1;i<=n*(n-1)/2;i++) dp1[i]=dp[n-1][i]+dp1[i-1],dp1[i]%=mod;
	memset(b,0,sizeof(b));
	b[0]=dp1[0];
    for(int k=1;k<=n*(n-1)/2;k++) b[k]=(b[k-1]+dp1[k])%mod;
    memset(w,0,sizeof(w));
    w[0]=w[1]=0;
    for (int i=2;i<=n*(n-1)/2;i++) w[i]=b[i-2]*dp[n-1][i]%mod,w[i]=(w[i]+w[i-1])%mod;
    for(int k=2;k<=n*(n-1)/2;k++)
    {
   		ans+=(w[k]-(k>n?w[k-n]:0)+mod)%mod;ans%=mod;
   	}
    for(int k=2;k<=n*(n-1)/2;k++)
    {
       	int x=(mod-((k>n)?b[k-n-1]:0ll))%mod,y=dp1[k]-dp1[k-min(k-1,n)]+mod;
       	y%=mod;
       	ans=(ans+x*y%mod)%mod;
    }
    return ans;
}
signed main()
{
	n=read(),mod=read();
	init();
	writeln(work(n)%mod);
}
/*
*/