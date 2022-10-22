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
#define mod 1000000007
#define inv2 500000004
const int n=17,N=1<<17;
ll a[1<<17][3],b[1<<17][3],c[1<<17][3],f[1<<17],qwq[18][1<<17],qaq[18][1<<17];
inline void FWT(ll (*a)[3],int len){
	len>>=1;
	if(len!=1){
		FWT(a,len);
		FWT(a+len,len);	
	}
	for(ri i=0;i<len;++i){
		a[i][0]+=a[i+len][0];
		a[i+len][1]+=a[i][1];
		ll temp=a[i][2];
		a[i][2]+=a[i+len][2];
		a[i+len][2]=temp-a[i+len][2];
	}
}
inline void UFWT(ll (*a)[3],int len){
	len>>=1;
	if(len!=1){
		UFWT(a,len);
		UFWT(a+len,len);
	}
	for(ri i=0;i<len;++i){
		a[i][0]-=a[i+len][0];
		a[i+len][1]-=a[i][1];
		ll temp=a[i][2];
		a[i][2]+=a[i+len][2];
		a[i+len][2]=temp-a[i+len][2];
		a[i][2]=a[i][2]*inv2%mod;
		a[i+len][2]=a[i+len][2]*inv2%mod;
	}
}
inline void fwt(ll *a){
	for(int S=1;S<N;S<<=1){
		for(int j=S;j<N;j=(j+1)|S){
			a[j]=(a[j]+a[j^S])%mod;
		}
	}
}
inline void ifwt(ll *a){
	for(int S=1;S<N;S<<=1){
		for(int j=S;j<N;j=(j+1)|S){
			a[j]=(a[j]+mod-a[j^S])%mod;
		}
	}
}
int main() {
	f[1]=1;
	F(i,2,N)f[i]=(f[i-1]+f[i-2])%mod;
	F(i,1,read()){
		int x=read();
		++a[x][0],++a[x][2];++qwq[__builtin_popcount(x)][x];
	}
	F(i,0,17)fwt(qwq[i]);F(i,0,17)F(j,0,17-i)F(k,0,N-1)qaq[i+j][k]=(qaq[i+j][k]+qwq[i][k]*qwq[j][k])%mod;
	F(i,0,17)ifwt(qaq[i]);
	memcpy(b,a,sizeof(a));
	FWT(a,N);
	F(i,0,N-1)F(j,1,2)c[i][j]=a[i][j]%mod*(a[i][j]%mod)%mod;
	UFWT(c,N);
	F(i,0,N-1)b[i][0]=1ll*(b[i][0]%mod)*f[i]%mod,c[i][1]=1ll*qaq[__builtin_popcount(i)][i]*f[i]%mod,c[i][2]=1ll*c[i][2]*f[i]%mod;
	F(i,0,N-1)a[i][0]=c[i][1],c[i][0]=c[i][2];
	FWT(a,N);FWT(b,N);FWT(c,N);
	F(i,0,N-1)c[i][0]=1ll*(a[i][0]%mod)*(b[i][0]%mod)%mod*(c[i][0]%mod)%mod;
	UFWT(c,N);
	ll ans=0;
	F(i,0,16)ans+=c[1<<i][0];
	cout<<(ans%mod+mod)%mod;
	return 0;
}