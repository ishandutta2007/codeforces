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
//#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1e18
#define mod 998244353
//#define int ll
#define N 1000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int pre[N],suf[N],M[N],n,m,ans=1e18,P=0;
vector<int>L,H;
map<int,int>Mp[N];
int query(int x,int y,int z)
{
	if (Mp[x][y]) return Mp[x][y];
	cout<<"? "<<x<<" "<<y<<endl;
	int p;
	cin>>p;
	Mp[x][y]=p;
	return p;
}
void del(int x)
{
	if (pre[x]!=-1)
		suf[pre[x]]=suf[x]; else P=suf[x];
	pre[suf[x]]=pre[x];
}
vector<int> reduce(vector<int>X,vector<int>Y)
{
	for (int i=0;i<Y.size();i++) pre[i]=i-1,suf[i]=i+1;
	int x=0,y=0;
	P=0;
	for (int nmsl=Y.size()-X.size();nmsl>0;nmsl--)
	{
		if (query(X[x],Y[y],0)>query(X[x],Y[suf[y]],0))
		{
			y=suf[y];
			del(pre[y]);
			if (x) y=pre[y],x--;
		} else
		{
			if (x==X.size()-1) del(suf[y]);
			else
			{
				y=suf[y];
				x++;
			}
		}
	}
	vector<int>ret;
	for (int i=P;i!=Y.size();i=suf[i])	ret.push_back(Y[i]);
	return ret;
}
void Solve(vector<int>X,vector<int>Y)
{
	Y=reduce(X,Y);
	if (X.size()==1)
	{
		M[X[0]]=Y[0];
		return;
	}
	vector<int>Z;
	for (int i=0;i<X.size();i++)
		if (!(i%2)) Z.push_back(X[i]);
	Solve(Z,Y);
	for (int i=0;i<X.size();i++)
	{
		if (!(i%2)) continue;
		int l=lower_bound(Y.begin(),Y.end(),M[X[i-1]])-Y.begin();
		int r=0;
		if (i==X.size()-1) r=Y.size()-1;
		else 
		{
			r=lower_bound(Y.begin(),Y.end(),M[X[i+1]])-Y.begin();
		}
		M[X[i]]=Y[l];
		while (l<r)
		{
			l++;
			if (query(X[i],Y[l],1)<query(X[i],M[X[i]],1)) M[X[i]]=Y[l];
		}
	}
}
signed main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		H.push_back(i);
	}
	for (int i=1;i<=m;i++) L.push_back(i);
	Solve(H,L);
	for (int i=1;i<=n;i++)
		ans=min(ans,query(i,M[i],1));
	cout<<"! "<<ans<<endl;
	 
}
/*

*/