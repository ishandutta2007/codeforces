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
int n,m,num[1<<20];
char c[52][22];
ll orz[1<<20];
long double dp[1<<20];
int main() {
	cin>>n;if(n==1){
		cout<<0;return 0;
	}
	F(i,0,n-1){
		scanf("%s",c[i]);
	}
	m=strlen(c[0]);
	F(i,0,n-1){
		F(j,0,n-1)if(i!=j){
			int S=0;
			F(k,0,m-1){
				if(c[i][k]==c[j][k])S|=(1<<k);
			}
			orz[S]|=(1ll<<(ll)i);
		}
		
	}
	UF(i,(1<<m)-1,0){
		F(j,0,m-1)if(!(i>>j&1))orz[i]|=orz[i|(1<<j)];
		num[i]=__builtin_popcountll(orz[i]);
		dp[i]=1;
		if(num[i]){
			int res=m-__builtin_popcount(i);
			F(j,0,m-1)if(!(i>>j&1))dp[i]+=1.0L/res*num[i|(1<<j)]/num[i]*dp[i|(1<<j)];
		}
	}
	cout<<fixed<<setprecision(114)<<dp[0];
	return 0;
}