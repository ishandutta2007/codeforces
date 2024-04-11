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
#define N 3000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
vector<int>li,E[N];
struct node
{
	int l,r;
};
vector<node>G[N];
int n,m,ans,dis[N],s[N],ls[N],vis[N];
vector<pa>B[N],C[N];
set<int>S;
void ad(int x,int y)
{
	if (x==y) return;
	E[y].push_back(x);
}
signed main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		node x;
		int y=read();
		x.l=read(),x.r=read();
		G[y].push_back(x);
		li.push_back(x.l),li.push_back(x.r);
	}
	sort(li.begin(),li.end());
	for (int i=1;i<=n;i++)
		for (auto x:G[i])
		{
			x.l=lower_bound(li.begin(),li.end(),x.l)-li.begin()+1;
			x.r=lower_bound(li.begin(),li.end(),x.r)-li.begin()+1;
			B[x.l].push_back({i,1});
			C[x.r+1].push_back({i,-1});
		}
	m=li.size();
	for (int i=1;i<=m;i++)
	{
		for (auto v:C[i])
		{
			s[v.fi]+=v.se;
			if (s[v.fi]==0)
			{
				S.erase(v.fi);
			}
		}
		for (auto v:B[i])
		{
			s[v.fi]+=v.se;
			if (s[v.fi]==1)
			{
				if (S.size()!=0){
				auto it=S.lower_bound(v.fi);
				if (it!=S.end())
				{
					ad(v.fi,(*it));
				}
				if (it!=S.begin())
				{
					it--;
					ad((*it),v.fi);
				}}
				S.insert(v.fi);
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		dis[i]=1;ls[i]=i;
		for (auto u:E[i])
		{
			if (dis[u]+1>dis[i]) dis[i]=dis[u]+1,ls[i]=u;
		}
		if (dis[ans]<dis[i]) ans=i;
	}
	writeln(n-dis[ans]);
	while (ls[ans]!=ans)
	{
		vis[ans]=1;
		ans=ls[ans];
	}
	vis[ans]=1;
	for (int i=1;i<=n;i++) if (!vis[i]) writesp(i);
	
	
}
/*

*/