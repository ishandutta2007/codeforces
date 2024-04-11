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
#define vi vector<int>
#define ull unsigned long long
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
int n,x[5002],y[5002],dis[5002][5002];
#define abs fuck_ccf
constexpr inline int abs(int x){
	return x>0?x:-x;
}
int w,now;
int col[5002];
inline bool dfs(int pos){
	int *d=dis[pos];
	F(i,1,n)if(d[i]>now){
		if(!col[i]){
			col[i]=col[pos]^2;
			if(!dfs(i))return 0;
		}else if(col[i]==col[pos])return 0;
	}
	return 1;
}
inline bool check(int x){
	now=x;int ww=0;
	memset(col,0,sizeof(col));
	F(i,1,n)if(!col[i]){
		col[i]=1;++ww;
		if(!dfs(i))return 0;
	}
	w=ww;
	return 1;
}
int main() {
	cin>>n;
	F(i,1,n)read(x[i],y[i]);
	F(i,1,n)F(j,1,n)dis[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
	int l=0,r=9999;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	cout<<l<<endl;
	int ans=1;
	F(iakioi,1,w)ans=(ans<<1)%1000000007;
	cout<<ans;
	return 0;
}