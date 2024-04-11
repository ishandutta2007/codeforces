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
int n;
ll dp[202][202],v[202][202],w[202][202],p[202][202];
inline void solve(int l,int r,int fa){
	if(l>r)return;
	#define i l
	#define j r
	solve(l,p[i][j]-1,p[i][j]);
	write(fa,' ');
	solve(p[i][j]+1,r,p[i][j]);
	#undef i
	#undef j
}
int main() {
	cin>>n;
	F(i,1,n)F(j,1,n)read(v[i][j]);
	F(i,1,n)F(j,i,n){
		F(k,i,j)w[i][j]+=v[k][j];
		w[i][j]+=w[i][j-1];
	}
	UF(i,n,1)F(j,i,n){
		dp[i][j]=1e18;
		F(k,i,j){//cerr<<i<<" "<<j<<" "<<k<<" "<<dp[i][k-1]+dp[k+1][j]+w[i][k]-w[i][k-1]+w[k][j]-w[k+1][j]+(w[i][j]-w[i][k]-w[k][j])*2<<endl;
			if(dp[i][k-1]+dp[k+1][j]+w[1][j]-w[1][i-1]+w[i][n]-w[j+1][n]-w[i][j]*2<dp[i][j]){
				dp[i][j]=dp[i][k-1]+dp[k+1][j]+w[1][j]-w[1][i-1]+w[i][n]-w[j+1][n]-w[i][j]*2;
				p[i][j]=k;
			}
		}
	}
	solve(1,n,0);//cerr<<endl<<dp[1][n]<<endl;
	return 0;
}