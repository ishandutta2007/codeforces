//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
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
#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
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
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
#define int long long
using namespace std;
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
	inline void write(T x) {
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
int f[5002],n,t[5002],x[5002];
bool g[5002][5002];
inline constexpr int a(int x){
	return x>0?x:-x;
}
inline int d(int u,int v){
	return a(x[u]-x[v]);
}
signed main() {
	cin>>n;
	F(i,1,n)read(t[i],x[i]);
	memset(f,0x3f,sizeof(f));
	f[1]=x[1];
	F(i,2,n)if(a(x[i])+d(i,1)<=t[1])g[1][i]=true;
	F(i,1,n){
		if(f[i]<=t[i]){
			f[i+1]=min(f[i+1],max(f[i]+d(i,i+1),t[i]));
			F(j,i+2,n)if(max(f[i]+d(i,j),t[i])+d(j,i+1)<=t[i+1])g[i+1][j]=true;
		}
		if(g[i][i+1]){
			f[i+2]=min(f[i+2],max(t[i+1],t[i]+d(i,i+2)));
			F(j,i+3,n)if(max(t[i]+d(i,j),t[i+1])+d(j,i+2)<=t[i+2])g[i+2][j]=true;
		}
		F(j,i+2,n)if(g[i][j]&&t[i]+d(i,i+1)<=t[i+1])g[i+1][j]=true;
	}
	if(f[n]<=t[n]||g[n-1][n])puts("YES");
	else puts("NO");
	return 0;
}