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
#define N 400005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int ST[N][25],f[N],dep[N],id,q,n,m,val[N],us[N];
ll ans;
vector<int>G[N];
struct node
{
	int x,y,z,id;
}a[N];
bool Cmp(node x,node y)
{
	return x.z<y.z;
}
bool Cmp1(node x,node y)
{
	return x.id<y.id;
}
void ad(int x,int y)
{
	G[x].push_back(y);
}
int gf(int x)
{
	if (f[x]==x) return x;
	f[x]=gf(f[x]);
	return f[x];
}
void dfs(int k,int fa)
{
	ST[k][0]=fa;dep[k]=dep[fa]+1;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
	}
}
inline int LCA(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=19;i>=0;i--)
	  if (dep[x]-(1<<i)>=dep[y])
	    x=ST[x][i];
	if (x==y) return x;
	for (register int i=19;i>=0;i--)
	{
		if (!(ST[x][i]==ST[y][i]))
		  x=ST[x][i],y=ST[y][i];
	}
	return ST[x][0];
}		
signed main()
{
	n=read(),m=read();for (int i=1;i<=2*n-1;i++) f[i]=i;
	for (int i=1;i<=m;i++)
	{
		a[i].x=read(),a[i].y=read(),a[i].z=read();a[i].id=i;
	}
	sort(a+1,a+m+1,Cmp);
	int l=n-1;
	id=n;
	for (int i=1;i<=m;i++)
	{
		if (!l) break;
		int x=a[i].x,y=a[i].y,z=a[i].z;
		if (gf(x)!=gf(y))
		{
			int p=++id;
			ad(p,f[x]),ad(p,f[y]);
			val[p]=z;
			f[f[x]]=p,f[f[y]]=p;
			l--;
			us[a[i].id]=1;ans+=z;
		}
	}
	for (int i=1;i<=id;i++)
		if (gf(i)==i) dfs(i,0);
	for(re int i=1;(1<<i)<=id;++i)
      for(re int j=1;j<=id;++j)
        ST[j][i]=ST[ST[j][i-1]][i-1];
	sort(a+1,a+m+1,Cmp1);
	for (int i=1;i<=m;i++)
	{
		if (!us[i])
		{
			writeln(ans-val[LCA(a[i].x,a[i].y)]+a[i].z);
		} else writeln(ans);
	}
}
/*

*/