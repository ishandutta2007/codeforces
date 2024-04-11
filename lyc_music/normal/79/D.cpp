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
//#define N
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
bool debug=false;
 
template<typename T> ostream& operator<<(ostream& o,vector<T> vec){
	o<<"{";
	for(int i=0;i<vec.size();i++){
		o<<vec[i]<<" ";
	}
	o<<"}";
	return o;
}
 
int n,k,l;
int x[15],a[105];
 
vector<int> nei[10005];
vector<int> token;
 
bool shit[10005];
 
int dist[25][10005];
 
int dp[(2<<21)];
 
void bfs(int st,int index){
	queue<int> q;
	q.push(st);
	dist[index][st]=0;
	
	while(!q.empty()){
		int last=q.front();
		q.pop();
		
		
		for(int i=0;i<nei[last].size();i++){
			if(dist[index][nei[last][i]]==-1){
				dist[index][nei[last][i]]=dist[index][last]+1;
				q.push(nei[last][i]);
			}
		}
	}
	
}
 
signed main()
{
	memset(dist,-1,sizeof(dist));
	cin>>n>>k>>l;
	n++;
	
	for(int i=0;i<k;i++){
		cin>>x[i];
		shit[x[i]-1]=true;
	}
	
	for(int i=0;i<l;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<l;j++){
			int dest=i+a[j];
			if(dest<n){
				nei[dest].push_back(i);
				nei[i].push_back(dest);
			}
		}
	}
	if(shit[0]){
		token.push_back(0);
	}
	for(int i=1;i<n;i++){
		if(shit[i]!=shit[i-1]){
			token.push_back(i);
		}
	}
	for(int i=0;i<token.size();i++){
		bfs(token[i],i);
	}
	for(int i=0;i<(1<<token.size());i++){
		dp[i]=1e9;
	}
	dp[0]=0;
	for(int i=0;i<(1<<token.size());i++){
		int lastzero=0;
		while((i>>lastzero)&1==1){
			lastzero++;
		}
		if(lastzero==token.size()){
			break;
		}
		for(int j=lastzero+1;j<token.size();j++){
			if((i&(1<<j))==0 && dist[lastzero][token[j]]!=-1){
				dp[i|(1<<j)|(1<<lastzero)]=min(dp[i|(1<<j)|(1<<lastzero)],dp[i]+dist[lastzero][token[j]]);
			}
		}
	}
	
	int x=dp[(1<<token.size())-1];
	cout<<(x==1e9?-1:x);
	
	return 0;
}
/*

*/