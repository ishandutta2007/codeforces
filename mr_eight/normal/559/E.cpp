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
int n,p[102],l[102],dp[102][102][2];
pii a[102];
inline void dbg(int x,int y,int z){
	printf("dp[%d][%d][%d]=%d;\n",x,y,z,dp[x][y][z]);
}
#ifndef LOCAL
#define dbg(...)
#endif
int main(){
	memset(dp,-0x3f,sizeof(dp));
	cin>>n;
	F(i,1,n)read(a[i].first,a[i].second);
	sort(a+1,a+n+1);
	F(i,1,n)p[i]=a[i].first,l[i]=a[i].second;
	dp[1][1][0]=dp[1][1][1]=l[1];
	F(i,1,n){
		if(i!=1&&p[1]+l[1]>=p[i])dp[i][1][1]=max(dp[i][1][1],p[1]+l[1]-(p[i]-l[i]));
		dp[i][i][0]=max(dp[i][i][0],l[i]);dp[i][i][1]=max(dp[i][i][1],l[i]);
		F(j,1,i){
			F(k,0,1){
				int r=(k?p[j]+l[j]:p[j]),mmax=-1e9,maxp=0;
				dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
				F(x,i+1,n){
					dp[x][x][0]=max(dp[x][x][0],dp[i][j][k]+min(p[x]-r,l[x]));
					dp[x][x][1]=max(dp[x][x][1],dp[i][j][k]+p[x]+l[x]-max(p[x],r));
					if(x!=i+1&&mmax>p[x])dp[x][maxp][1]=max(dp[x][maxp][1],dp[i][j][k]+mmax-max(r,p[x]-l[x]));
					if(mmax<p[x]+l[x])mmax=p[x]+l[x],maxp=x;
				}dbg(i,j,k);
			}
		}
	}
	int ans=0;
	F(i,1,n)ans=max(ans,dp[n][i][0]),ans=max(ans,dp[n][i][1]);
	cout<<ans;
    return 0;
}
/*
5
1 2
3 5
5 1
7 5
9 4
*/