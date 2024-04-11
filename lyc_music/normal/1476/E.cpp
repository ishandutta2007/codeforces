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
typedef pair<int,int>pii;
int n,m,l,k;
char a[1000010];
int f[20][1000010];
struct Edge{
	int u,nxt;
}e[5000010];
int ans[3000010],g[3000010],p[5009010];
int b[5000010],num;
void add(int x,int y){
	e[++num]=(Edge){y,p[x]};
	p[x]=num;
}
void dfs(int s){
	if(g[s])return;
	ans[++num]=s;
	g[s]=1;
	for(int i=p[s];i;i=e[i].nxt){
		b[e[i].u]--;
		if(!b[e[i].u])dfs(e[i].u);
	}
}
int main(){
	cin>>n>>m>>l;
	for(int j=1;j<=n;j++){
		int s=0,k=0;
		cin>>(a+1);
		for(int i=1;i<=l;i++){
			if(a[i]=='_')s++;
			else k=(k+a[i]-'a')*26;
			s<<=1;
		}
		f[s>>1][k/26]=j;
	}
	while(m--){
		cin>>(a+1)>>k;
		int p=0;
		for(int i=0;i<16;i++){
			int s=0;
			for(int j=1;j<=l;j++)if(!((1<<l-j)&i))s=(s+a[j]-'a')*26;
			s/=26;
			if(f[i][s]){
				if(f[i][s]!=k){
					add(k,f[i][s]);
					b[f[i][s]]++;
				}else p=1;
			}
		}
		if(!p)return puts("NO"),0;
	}
	num=0;
	for(int i=1;i<=n;i++)
		if(b[i]==0&&g[i]==0)dfs(i);
	if(num<n)puts("NO");
	else{
		puts("YES");
		for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
		puts("");
	}
	return 0;
}
/*

*/