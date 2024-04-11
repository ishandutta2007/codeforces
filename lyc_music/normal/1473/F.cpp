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
#define inf 10000000005
#define mod 998244353
//#define int ll
#define N 300005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],b[N],ans,bl[N];
struct Graph_Dinic
{
	int q[N<<2],l,r,dis[N],cur[N],head[N],S,T,mch[N],cnt=1,ans,now;
	struct
	{
		int to,nx,val;
	}e[N];
	inline void ad(int x,int y,int val)
	{
		e[++cnt].to=y,e[cnt].nx=head[x],e[cnt].val=val;head[x]=cnt;
		e[++cnt].to=x,e[cnt].nx=head[y],e[cnt].val=0;head[y]=cnt;
	}
	inline bool bfs()
	{
		l=0,r=1;
		q[++l]=S;
		memset(dis,-1,sizeof(dis));
		dis[S]=0;
		memcpy(cur,head,sizeof(head));
		while (l<=r)
		{
			now=q[l];
			l++;
			for (int i=head[now];i;i=e[i].nx)
			{
				if (dis[e[i].to]==-1&&e[i].val!=0)
				{
					dis[e[i].to]=dis[now]+1;
					q[++r]=e[i].to;
				}
			}
		}
		return (dis[T]!=-1);
	}
	inline int dfs(int now,int liu)
	{
		if (now==T)
		{
			return liu;
		}
		int res=liu;
		for (int i=cur[now];i&&res;i=e[i].nx)
		{
			cur[now]=i;
			if (dis[e[i].to]==dis[now]+1&&e[i].val!=0)
			{
				int c=dfs(e[i].to,min(res,e[i].val));
				res-=c;
				e[i].val-=c;
				e[i^1].val+=c;
				if (c!=0&&e[i].to!=T&&now!=S)
				{
					mch[now]=e[i].to;
					mch[e[i].to]=now;
				}
			}
		}
		return liu-res;
	}
	inline void dinic()
	{
		while (bfs())
			ans+=dfs(S,inf);
	}
}G;
signed main()
{
	n=read();
	int cnt=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	G.S=++cnt;
	G.T=++cnt;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=a[i];j++)
			if (a[i]%j==0&&bl[j]) G.ad(i+2,bl[j]+2,inf);
		bl[a[i]]=i;
		if (b[i]>0) G.ad(G.S,i+2,b[i]), ans+=b[i];
		if (b[i]<0) G.ad(i+2,G.T,-b[i]);
	}
	G.dinic();
	writeln(ans-G.ans);
}
/*

*/