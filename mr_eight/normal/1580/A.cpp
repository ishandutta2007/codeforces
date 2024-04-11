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
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
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
int n,m,ans,pre[402][402],h[402][402],l[402][402];
char c[402][402];
short dp[402][402][402];
#define he h
int main() {
	F(iakioi,1,read()){
		read(n,m);
		F(i,0,n)F(x,0,m)F(y,0,m)dp[i][x][y]=10000;
		ans=INT_MAX;
		F(i,1,n){
			scanf("%s",c[i]+1);	
			F(j,1,m)pre[i][j]=(pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+(c[i][j]=='1')),
			h[i][j]=he[i][j-1]+(c[i][j]=='1'),l[i][j]=l[i-1][j]+(c[i][j]=='1');
		}
		F(i,4,n){
			F(x,1,m)F(y,x+3,m){
				dp[i][x][y]=dp[i-1][x][y]+h[i][y-1]-h[i][x]+(c[i][x]=='0')+(c[i][y]=='0');
				dp[i][x][y]=min((int)dp[i][x][y],(y-1-x-(h[i-3][y-1]-h[i-3][x]))+pre[i][y-1]-pre[i][x]-pre[i-3][y-1]+pre[i-3][x]+6-(l[i][x]-l[i-3][x]+l[i][y]-l[i-3][y]));
				ans=min(ans,dp[i-1][x][y]+(y-1-x-(h[i][y-1]-h[i][x])));
			}
		}
		write(ans,'\n');
	}
	return 0;
}