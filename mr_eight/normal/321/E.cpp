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
//#include <random>
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
int a[4002][4002],n,k,dp[802][4002],now;
inline int calc(int l,int r){
	return a[r][r]-(a[l-1][r]<<1)+a[l-1][l-1];
}
inline void solve(int l,int r,int ql,int qr){
	if(l>r)return;//cerr<<now<<" "<<l<<" "<<r<<" "<<ql<<" "<<qr<<endl;
	int mid=(l+r)>>1,p=ql,temp;dp[now][mid]=dp[now-1][ql-1]+calc(ql,mid);
	F(i,p+1,min(mid,qr))if((temp=dp[now-1][i-1]+calc(i,mid))<dp[now][mid]){
		dp[now][mid]=temp;
		p=i;
	}
	solve(l,mid-1,ql,p);
	solve(mid+1,r,p,qr);
}
int main() {
	read(n);
	read(k);
	F(i,1,n)F(j,1,n)read(a[i][j]);
	F(i,1,n)F(j,1,n)a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	F(i,1,k){
		now=i;
		solve(1,n,1,n);
	}
	cout<<dp[k][n]/2;
	return 0;
}