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
//#define int ll
#define N 100005
#define M 100001
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,qq;
ll h[N],ans[N];
int c,p,opt;
priority_queue<pa>q;
vector<int>G[N];
queue<int>Q[M+5];
struct
{
	int u,v,w;
}e[N];
void dijk()
{
	for (int i=1;i<=n;i++) h[i]=inf;
	h[1]=0; 
	q.push({0,1});
	while (!q.empty())
	{
		int u=q.top().se;
		q.pop();
		for (auto v:G[u])
		{
			if (h[e[v].v]>h[u]+e[v].w)
			{
				h[e[v].v]=h[u]+e[v].w;
				q.push({-h[e[v].v],e[v].v});
			}
		}
	}
}
void fakedijk()
{
	for (int i=1;i<=n;i++) h[i]=inf;
	h[1]=0;
	Q[0].push(1);
	int mx=0;
	for (int i=0;i<=mx;i++)
	{
		while (!Q[i].empty())
		{
			int u=Q[i].front();
			Q[i].pop();
			if (h[u]<i) continue;
			for (auto v:G[u])
			{
				if (h[e[v].v]>h[u]+e[v].w)
				{
					h[e[v].v]=h[u]+e[v].w;
					if (h[e[v].v]<=min(c,n-1)) 
					{
						Q[h[e[v].v]].push(e[v].v);
						mx=max(mx,(int)h[e[v].v]);
					}
				}
			}
		}
	}
}
signed main()
{
	n=read(),m=read();qq=read();
	for (int i=1;i<=m;i++)
	{
		e[i].u=read(),e[i].v=read(),e[i].w=read();
		G[e[i].u].push_back(i);
	}
	dijk();
	for (int i=1;i<=m;i++)
	{
		e[i].w=h[e[i].u]-h[e[i].v]+e[i].w;
	}
	for (int i=1;i<=n;i++) ans[i]=h[i];
	while (qq--)
	{
		opt=read();
		if (opt==1)
		{
			int u=read();
			if (ans[u]<inf)
			writeln(ans[u]); else puts("-1");
		}
		else
		{
			c=read();int C=c;
			while (c--)
			{
				p=read();
				e[p].w+=1;
			}
			c=C;
			
			fakedijk();
			for (int i=1;i<=m;i++)
			{
				e[i].w=h[e[i].u]-h[e[i].v]+e[i].w;
			}
			for (int i=1;i<=n;i++) ans[i]=min((ll)inf,ans[i]+h[i]);
		}
	}
}
/*

*/