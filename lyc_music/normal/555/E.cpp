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
#define w 200005 
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');} 
int n,m,Q,cnt,tot,top,sz;
int st[w],fir[w<<1],nxt[w<<2],to[w<<2];
int up[w<<1][20],low[w],dfn[w],dep[w<<1];
int u[w<<1],dw[w<<1],bl[w];
void add(int x,int y)
{
	nxt[++cnt]=fir[x];fir[x]=cnt;
	to[cnt]=y;
}
void dfs(int x,int fa)
{
	low[x]=dfn[x]=++tot;
	st[++top]=x;
	for(int i=fir[x];i;i=nxt[i])
	if((i+1)/2!=fa)
	{
		if(!dfn[to[i]])
		{
			dfs(to[i],(i+1)/2);
			low[x]=min(low[x],low[to[i]]);
		}
		else low[x]=min(dfn[to[i]],low[x]);
	}
	if(low[x]==dfn[x])
	{
		sz++;
		while(st[top]!=x) bl[st[top--]]=sz;
		bl[st[top--]]=sz;
	}
}
void dfs2(int x)
{
	dep[x]=dep[up[x][0]]+1;
	for(int i=1;i<=18;i++)
	up[x][i]=up[up[x][i-1]][i-1];
	for(int i=fir[x];i;i=nxt[i])
	if(to[i]!=up[x][0])
	{
		up[to[i]][0]=x;
		dfs2(to[i]);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=18;~i;i--)
	if(dep[up[x][i]]>=dep[y]) x=up[x][i];
	if(x==y) return x;
	for(int i=18;~i;i--)
	if(up[x][i]!=up[y][i]) x=up[x][i],y=up[y][i];
	return up[x][0];
}
void calc(int x)
{
	for(int i=fir[x];i;i=nxt[i])
	if(to[i]!=up[x][0])
	{
		calc(to[i]);
		u[x]+=u[to[i]];
		dw[x]+=dw[to[i]];
	}
	if(u[x]&&dw[x])
	{
		puts("No");
		exit(0);
	}
//	cout<<x<<" "<<u[x]<<" "<<dw[x]<<endl;
}
int main()
{
	n=read(),m=read(),Q=read();
	for(int i=1;i<=m;i++)
	{
		int x,y;
		x=read(),y=read();
		add(x,y);add(y,x);
	}
	sz=n;
	for(int i=1;i<=n;i++)
	if(!dfn[i]) dfs(i,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=fir[i];j;j=nxt[j])
		if(bl[i]!=bl[to[j]])
		add(bl[i],bl[to[j]]);
	//	cout<<" "<<i<<" "<<bl[i]<<endl;
	}
	for(int i=n+1;i<=sz;i++)
	if(!dep[i]) dfs2(i);
	while(Q--)
	{
		int x,y;
		x=read(),y=read();
		x=bl[x],y=bl[y];
		int k=lca(x,y);
		if(!k)
		{
			puts("No");
			return 0;
		}
		u[x]++,u[k]--;dw[y]++;dw[k]--;
	}
	for(int i=n+1;i<=sz;i++)
	if(dep[i]==1)
	calc(i);
	puts("Yes");
	return 0;
}
/*

*/