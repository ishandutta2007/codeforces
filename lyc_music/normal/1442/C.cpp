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
#define go(i,x) for (int i=head[x];i;i=Next[i])
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
#define inf (1e18)
#define mod 998244353
#define int ll
#define N 400005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll a){if(a<0){a=-a; putchar('-');}write(a); putchar(' ');}
inline void writeln(ll a){if(a<0){a=-a; putchar('-');}write(a); puts("");}
ll quickPower(int x,int y)
{
	int ans=1;x%=mod;
	while (y>0)
	{
		if (y&1) (ans*=x)%=mod;
		(x*=x)%=mod;
		y>>=1;
	}
	return ans;
}
int n,m,dis[19][N],dis1[N],u,v,ans,vis[N];
vector<int>G[N][2];
vector<pair<int,int> >G1[N];
struct wcr
{
	int x,y;
	bool operator <(const wcr &A) const
	{
		return dis[x][y]>dis[A.x][A.y];
	}
};
priority_queue<wcr>q;
priority_queue<pair<int,int> >q1;
wcr now;
pair<int,int>now1;
signed main()
{
	n=read(),m=read();
	F(i,0,18)
		F(j,1,n)
			dis[i][j]=inf;
	F(i,1,n) G1[i].push_back(mp(i+n,10000000)),G1[i+n].push_back(mp(i,10000000));
	F(i,1,m) 
	{
		u=read(),v=read();
		G[u][0].push_back(v);
		G[v][1].push_back(u);
		G1[u].push_back(mp(v,1));
		G1[v+n].push_back(mp(u+n,1));
	}
	q.push({0,1});
	dis[0][1]=0;
	while (!q.empty())
	{
		now=q.top();
//		cout<<now.x<<" "<<now.y<<" "<<dis[now.x][now.y]<<" "<<G[now.y][now.x%2].size()<<endl;
		q.pop();
		if (now.x<=17)
		{
			if (dis[now.x+1][now.y]>dis[now.x][now.y]+(1ll<<now.x))
			{
				dis[now.x+1][now.y]=dis[now.x][now.y]+(1ll<<now.x);
				q.push({now.x+1,now.y});
			}
		}
		R(i,0,G[now.y][now.x%2].size())
		{
//			cout<<dis[now.x][G[now.y][now.x%2][i]]<<endl;
			if (dis[now.x][G[now.y][now.x%2][i]]>dis[now.x][now.y]+1)
			{
				dis[now.x][G[now.y][now.x%2][i]]=dis[now.x][now.y]+1;
				q.push({now.x,G[now.y][now.x%2][i]});
			}
		}
	}
	ans=inf;
	F(i,0,18) ans=min(ans,dis[i][n]);
//	cout<<ans<<endl;
	if (ans!=inf) writeln(ans%mod); else
	{
		F(i,1,2*n+5) dis1[i]=inf;
		dis1[1]=0;
		q1.push(mp(0,1));
		while (!q1.empty())
		{
			now1=q1.top();q1.pop();
//			cout<<-now1.first<<" "<<now1.second<<endl;
			if (vis[now1.second]) continue;
			vis[now1.second]=1;
			R(i,0,G1[now1.second].size())
			{
				if (dis1[G1[now1.second][i].first]>dis1[now1.second]+G1[now1.second][i].second)
				{
					dis1[G1[now1.second][i].first]=dis1[now1.second]+G1[now1.second][i].second;
					q1.push(mp(-dis1[G1[now1.second][i].first],G1[now1.second][i].first));
				}
			}
		}
//		cout<<dis1[n]<<" "<<dis1[n+n]<<endl;
		writeln((quickPower(2,(min(dis1[n],dis1[n+n])/(10000000)))-1+mod+(min(dis1[n],dis1[n+n])%(10000000)))%mod);
	}	
}