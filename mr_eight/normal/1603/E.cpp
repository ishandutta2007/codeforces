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
long long mod,n,fac[100002],ifac[100002],inv[100002],ans;
inline long long pw(long long x,long long p){
    long long res=1;
    for(;p;p>>=1,x=x*x%mod)
        if(p&1)res=res*x%mod;
    return res;
}
inline long long getm(long long top,long long bot) {
	return (top*pw(bot,mod-2))%mod;
}
inline long long C(long long top,long long bot){
	if(top<bot||top<0||bot<0)return 0;
	return fac[top]*ifac[bot]%mod*ifac[top-bot]%mod;
}
int dp[202][202][25];
//     num, sum, max
int main() {
	cin>>n>>mod;
	fac[0]=1;
	#define n 100000
	F(i,1,n)fac[i]=fac[i-1]*i%mod;
	ifac[n]=getm(1,fac[n]);
	UF(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%mod;
	F(i,1,n)inv[i]=ifac[i]*fac[i-1]%mod;
	#undef n
	F(o,max(1,int(n-sqrt(n+n))),n+1){//cerr<<o<<endl;
		int mmax=n+1-o;
		memset(dp,0,sizeof(dp));
		dp[0][0][mmax+1]=fac[n];
		F(i,0,n){//num
			UF(k,mmax,1){//sum
				F(j,i*k,o){//max
					if(k==1||n+2-(k+o)<=i){
						F(cnt,0,min(i,j/k)){
							dp[i][j][k]=(dp[i][j][k]+dp[i-cnt][j-cnt*k][k+1]*ifac[cnt])%mod;
							//cerr<<i<<" "<<j<<" "<<k<<" "<<cnt<<" "<<dp[i][j][k]<<endl;
						}
					}
				}
			}
		}
		F(i,0,n-1)F(j,0,o)ans+=ifac[n-i]*dp[i][j][1]%mod;
	}
	cout<<ans%mod;
	return 0;
}