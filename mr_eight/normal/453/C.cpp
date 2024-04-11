//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
//#pra gma G CC opti mize(3)
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
namespace fastIO {
	template<class T>
	inline void read(T &x) {
		x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		if(fu)x=-x;
	}
	inline int read() {
		int x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		return fu?-x:x;
	}
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
	}
	char _n_u_m_[40];
	template<class T>
	inline void write(T x ) {
		if(x==0){
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		register int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
}
using namespace fastIO;
int n,m,t1,t2,a[100002],cnt;
bool vis[100002];
vector<int>g[100002],c[100002],ans;
inline void dfs(int pos){
	++cnt;
	vis[pos]=true;
	for(int i:g[pos]){
		if(!vis[i]){
			c[pos].push_back(i);
			dfs(i);
		}
	}
}
#define vec ans
inline void solve(int pos){
	for(int i:c[pos]){
		vec.push_back(pos);
		a[pos]^=1;
		solve(i);
	}
	vec.push_back(pos);
	a[pos]^=1;
	for(int i:c[pos])if(a[i]){
		vec.push_back(i);
		vec.push_back(pos);
		a[pos]^=1;
	}
}
inline void getans(int pos){
	solve(pos);
	if(a[pos])ans.pop_back();
	write(ans.size(),'\n');
	for(int i:ans)write(i,' ');
}
inline bool check(){
	F(i,1,n)if(a[i]&&!vis[i])return false;
	return true;
}
int main() {
	cin>>n>>m;
	F(i,1,m){
		read(t1);read(t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	F(i,1,n)read(a[i]);
	F(i,1,n)if(a[i]){
		dfs(i);
		if(check())getans(i);
		else puts("-1");
		return 0;
	}
	puts("0");
	return 0;
}