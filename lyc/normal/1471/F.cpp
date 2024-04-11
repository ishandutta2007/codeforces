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
#define int ll
#define N 300005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,m,u,v,vis[N],col[N],ans,head[N],cnt,q[N*10],tp;
vector<int>G;
struct
{
	int to,nx;
}e[N<<1];
inline void ad(int x,int y)
{
	e[++cnt].to=y;
	e[cnt].nx=head[x];
	head[x]=cnt;
}
inline void bfs(){
	tp++;
	q[tp]=1;
	while(tp>0){
//		cout<<q[tp]<<","<<endl;
		int cur=q[tp];tp--;
		if(vis[cur]==1) continue;
		vis[cur]=1;
//		cout<<cur<<" "<<endl;
		G.push_back(cur);
		for(int i=head[cur];i;i=e[i].nx){
			int x=e[i].to;	
			if(vis[x]!=1)
				for(int j=head[x];j;j=e[j].nx){
					tp++;	
					q[tp]=e[j].to;
				}
			vis[x]=1;
		}
	}
	tp=0;
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read(),m=read();ans=0;G.clear();
		for (int i=1;i<=n;i++) vis[i]=col[i]=0,head[i]=0;
		cnt=0;
		for (int i=1;i<=m;i++)
		{
			u=read(),v=read();
			ad(u,v);
			ad(v,u);
		}
		bfs();
		for (int i=1;i<=n;i++)
		{
			if (vis[i]!=1) ans=-1;
//			cout<<vis[i]<<" "<<i<<endl;/ 
		}
		if (ans==-1)
		{
			puts("NO");
		} else
		{
			puts("YES");
		writeln(G.size());
		for (int i=0;i<G.size();i++)
		{
			writesp(G[i]);
		}puts("");}
	}
}
/*

*/