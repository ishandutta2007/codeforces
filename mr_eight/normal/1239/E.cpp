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
int n,a[52],tot,c1=1,c2,t1[52],t2[52];
bitset<1250002>dp[52][25];
int main() {
	cin>>n;
	n<<=1;
	F(i,1,n)read(a[i]);
	sort(a+1,a+n+1);
	dp[2][0]=1;
	F(i,3,n){
		tot+=a[i];
		F(j,0,(n>>1)-1)dp[i][j]=dp[i-1][j];
		F(j,1,(n>>1)-1)dp[i][j]|=(dp[i-1][j-1]<<a[i]);
	}
	t1[1]=a[1];
	ri x=0;
	F(i,0,1250000){
		if(dp[n][(n>>1)-1][i]&&max(i,tot-i)<max(x,tot-x))x=i;
	}
	ri now=(n>>1)-1;
	UF(i,n,3){
		if(dp[i-1][now][x]){
			t1[++c1]=a[i];
		}else{
			t2[++c2]=a[i];
			x-=a[i];
			--now;
		}
	}
	t2[++c2]=a[2];
	sort(t1+1,t1+c1+1);
	sort(t2+1,t2+c2);
	reverse(t2+1,t2+c2);
	F(i,1,c1)write(t1[i],' ');
	puts("");
	F(i,1,c2)write(t2[i],' ');
	return 0;
}