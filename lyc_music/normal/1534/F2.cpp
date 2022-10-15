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
int n,m,bel[N],l,r,ans,cnt,a[N],Po[N];
int low[N],dfn[N],sta[N],tp,l_dfn,SCC[N],SCC_sum,len,L;
multiset<int>S,SS[N];
bool bol[N];
pa q[N];
vector<int>E[N];
string st[N];
vector<pa>P;
void ad(int x,int y){
	E[x].push_back(y);}
int id(int x,int y)
{
	return (x-1)*m+y;
}
void tarjan(int x)
{
	dfn[x]=++l_dfn;
	sta[++tp]=x;
	bol[x]=1;
	low[x]=dfn[x];
	for (int i=0;i<E[x].size();i++)
	{
		int v=E[x][i];
		if (!dfn[v])
		{
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else
		if (bol[v]) low[x]=min(low[x],dfn[v]);
	}
	if (low[x]==dfn[x])
	{
		++SCC_sum;
		while (sta[tp]!=x)
		{
			SCC[sta[tp]]=SCC_sum;
			bol[sta[tp]]=0;
			tp--;
		}
		SCC[sta[tp]]=SCC_sum;
			bol[sta[tp]]=0;
		tp--;
	}
}
struct
{
	int ru[N],q[N],l,r,L[N],R[N];
	bool col[N];
	vector<int>E[N];
	int n;
	void init()
	{
		for (int i=1;i<=n;i++) L[i]=inf,R[i]=-inf;
	}
	void ad(int x,int y)
	{
		E[x].push_back(y);ru[y]++;
	}
	void dfs(int k)
	{
		for (auto u:E[k])
		{
			if (col[u]) continue;
			col[u]=1;
			dfs(u);
		}
	}
	void topo()
	{
		l=1;r=0;
		for (int i=1;i<=n;i++)
			if (!ru[i]) q[++r]=i;
		while (l<=r)
		{
			int u=q[l++];
			for (auto v:E[u])
			{
				L[v]=min(L[v],L[u]);
				R[v]=max(R[v],R[u]);
				ru[v]--;
				if (!ru[v]) q[++r]=v;
			}
		}
	}
}DAG,DAG1;
	
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>st[i];st[i]=' '+st[i];
	}
	for (int i=1;i<=m;i++) 
	{
		cin>>a[i];
		int t=0;
		for (int j=n;j>=1;j--)
			if (st[j][i]=='#') 
			{
				t++;
				if (t==a[i]) Po[i]=id(j,i);
			}
	}
	vector<vector<int>>b;
	b.resize(n+5);
	for (int i=1;i<=n+4;i++)
		b[i].resize(m+5);
	for (int i=n;i>=1;i--)
		for (int j=1;j<=m;j++)
		{
			if (st[i][j]=='#') b[i][j]=i;
			else b[i][j]=b[i+1][j];
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		if (st[i][j]=='#')
		{
			if (i>1)
			{
				if (st[i-1][j]=='#') ad(id(i,j),id(i-1,j));
			}
			if (b[i+1][j]) ad(id(i,j),id(b[i+1][j],j));
			if (j>1) if (b[i][j-1]) ad(id(i,j),id(b[i][j-1],j-1));
			if (j<m) if (b[i][j+1]) ad(id(i,j),id(b[i][j+1],j+1));
		}
	for (int i=1;i<=n*m;i++)
		if (!SCC[i]&&st[(i-1)/m+1][(i-1)%m+1]=='#')
		{
			tarjan(i);
		}
	for (int i=1;i<=n*m;i++)
		for (int j=0;j<E[i].size();j++)
			if (SCC[i]!=SCC[E[i][j]]) DAG.ad(SCC[i],SCC[E[i][j]]),DAG1.ad(SCC[E[i][j]],SCC[i]);
	DAG.n=SCC_sum;DAG1.n=SCC_sum;
	DAG1.init();
	for (int i=1;i<=m;i++)
		if (a[i])
		DAG.dfs(SCC[Po[i]]);
	for (int i=1;i<=m;i++)
		if (a[i])
		{
			if (!DAG.col[SCC[Po[i]]]&&DAG1.L[SCC[Po[i]]]==inf)
			{
				++len;
				DAG1.L[SCC[Po[i]]]=DAG1.R[SCC[Po[i]]]=len;
			}
		}
	DAG1.topo();
	for (int i=1;i<=DAG1.n;i++)
	{
		if (DAG1.L[i]!=inf)
			SS[DAG1.L[i]].insert(DAG1.R[i]);
	}
	for (auto u:SS[1]) S.insert(u);
	L=1;
	while (L<=len)
	{
		if (!S.size()) return puts("nmsl"),0;
		int u=*S.rbegin();
		S.erase(--S.end());
		while (L<u+1)
		{
			L++;			
			for (auto u:SS[L]) S.insert(u);
		}
		ans++;
	}
	writeln(ans);

}
/*

3 3
.##
#.#
..#
1 0 1
*/