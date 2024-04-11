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
#define fi fiRsont
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 1000000007
//#define int ll
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int Rt[9000005],sum[9000005],Lson[9000005],Rson[9000005],cnt,n,x,y,cnt1,q,now;
ll ans;
void pushup(int p)
{
	sum[p]=min(sum[Lson[p]],sum[Rson[p]]);
}
void update(int &rt,int l,int r,int p,int dlt)
{
	if (!rt) rt=++cnt;
	if (l==r)
	{
		sum[rt]+=dlt;
		return;
	}
	int mid=(l+r)>>1;
	if (p<=mid) update(Lson[rt],l,mid,p,dlt);
	else update(Rson[rt],mid+1,r,p,dlt);
	pushup(rt);
}
inline ll quickPower(int x,int y)
{
	ll res=1;
	while (y)
	{
		if (y&1)res=(res*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return res;
}
void work(int x,int y)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
		{
			cnt1=0;
			while(x%i==0) ++cnt1,x/=i;
			now=sum[Rt[i]];
			update(Rt[i],1,n,y,cnt1);
			if(sum[Rt[i]]>now) ans=1ll*ans*quickPower(i,sum[Rt[i]]-now)%mod;
		} 
	if(x>1)
	{
		cnt1=1;
		now=sum[Rt[x]];
		update(Rt[x],1,n,y,cnt1);
		if(sum[Rt[x]]>now) ans=1ll*ans*quickPower(x,sum[Rt[x]]-now)%mod;
	}
}
signed main()
{
	n=read(),q=read();
	ans=1;
	for(int i=1;i<=n;++i)
	{
		x=read();
		work(x,i);
	}
	while(q--)
	{
		x=read(),y=read();
		work(y,x);
		writeln(ans);
	}
}

/*

*/