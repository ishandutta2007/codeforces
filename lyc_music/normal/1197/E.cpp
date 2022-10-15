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
#define mid (l+(r-l)/2)
#define N 300005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,u,v,l,r,now,dis[N],cnt[N],ans,sum;
vector<pa>G[N];
pa a[N];
void ad(int x,int y,int z)
{
	G[x].push_back({y,z});
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) u=read(),v=read(),a[i]={v,u};
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		ad(i-1,i,a[i].fi-a[i-1].fi);
		l=1,r=n;
		now=-1;
		while (l<=r)
		{
			if (a[l+(r-l)/2].fi>=a[i].se) now=l+(r-l)/2,r=mid-1;
			else l=mid+1;
		}
		if (~now) ad(i,now,a[now].fi-a[i].se);
	}
	memset(dis,0x3f,sizeof(dis));
	dis[0]=0,cnt[0]=1;
	for (int i=0;i<=n;i++)
	{
		for (auto u:G[i])
		{
			if (dis[i]+u.se<dis[u.fi]) dis[u.fi]=dis[i]+u.se,cnt[u.fi]=cnt[i];
			else if (dis[i]+u.se==dis[u.fi]) cnt[u.fi]+=cnt[i],cnt[u.fi]%=mod;
		}
	}
	ans=inf;
	for (int i=1;i<=n;i++)
		if (a[i].se>a[n].fi) ans=min(ans,dis[i]);
	for (int i=1;i<=n;i++)
		if (a[i].se>a[n].fi&&dis[i]==ans) sum=(sum+cnt[i])%mod;
	writeln(sum);
		
}
/*

*/