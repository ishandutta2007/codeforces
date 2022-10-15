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
#define N 1005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int dep[N],fac[N],inv[N],n,x,y,f[N][N],ans;
vector<int>G[N],P[N];
ll quickPower(int x,int y)
{
	ll res=1;x%=mod;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return res;
}
void ad(int x,int y)
{
	G[x].push_back(y);
}
ll C(int x,int y)
{
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void dfs(int rt,int k,int fa)
{
	P[k].clear();
	dep[k]=dep[fa]+1;
	P[k].push_back(k);
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(rt,u,k);
		for (auto v:P[u])
		{
			for (auto now:P[k]) 
			{
				if (now>v) ans+=f[dep[now]-dep[k]][dep[v]-dep[k]],ans%=mod;
				else ans+=f[dep[v]-dep[k]][dep[now]-dep[k]],ans%=mod;
			}
		}
		for (auto v:P[u]) P[k].push_back(v);
	}
}
signed main()
{
	n=read();
	fac[0]=1,inv[0]=1;
	for (int i=1;i<=2*n;i++) fac[i]=fac[i-1]*i%mod,inv[i]=quickPower(fac[i],mod-2);
	for (int i=1;i<n;i++)
	{
		x=read(),y=read();
		ad(x,y);
		ad(y,x);
	}
	for (int i=1;i<=n;i++) f[0][i]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=0;k<j;k++)
				f[i][j]=f[i][j]+quickPower(2,mod-1-i-k)*C(i+k-1,k)%mod,f[i][j]%=mod;
	for (int rt=1;rt<=n;rt++)
	{
		dfs(rt,rt,0);
	}
	writeln(ans*quickPower(n,mod-2)%mod);		
}
/*

*/