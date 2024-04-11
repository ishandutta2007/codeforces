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
		if(x==0) {
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
#define mod 1000000007ll
ll n,k,fac[10000002],ifac[10000002],inv[10000002],ans,f,qwq;
il long long pw(long long x,long long p) {
	if(p<0)return 0;
	long long res=1;
	for(; p; p>>=1,x=x*x%mod)
		if(p&1)res=res*x%mod;
	return res;
}
il long long getm(long long top,long long bot) {
	return (top*pw(bot,mod-2))%mod;
}
il long long C(int n,int m) {
	if(n<m)return 0;
	ll rt=1;
	UF(i,n,n-m+1)rt=rt*i%mod;
	return rt*ifac[m]%mod;
}
long long c1,c2,p2;
int main() {
	n=10000000;
	fac[0]=1;
	F(i,1,n)fac[i]=fac[i-1]*i%mod;
	ifac[n]=getm(1,fac[n]);
	UF(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%mod;
	F(i,1,n)inv[i]=ifac[i]*fac[i-1]%mod;
	cin>>n>>k;
	if(n<=10000000){
		F(i,1,n){
			ans+=fac[n]*ifac[i]%mod*ifac[n-i]%mod*pw(i,k);
			ans%=mod;
		}cout<<ans;
		return 0;
	}
	f=1;qwq=getm(1,2);
	c1=C(n,min(n,k));
	c2=C(n-min(n,k),k-min(n,k)+1);
	p2=pw(2,n-min(n,k));
	UF(s,min(n,k),0) {
		ans+=c1*pw(s,k)%mod*p2%mod*f;
		p2=p2*2%mod;
		ans%=mod;
		c1*=getm(s,n-s+1);
		c1%=mod;
		f=qwq*f+c2*pw(-qwq,k-s+1);
		c2*=getm(n-s+1,k-s+2);
		c2%=mod;
		f%=mod;
	}
	if(ans<0)ans+=mod;
	cout<<ans%mod;
	return 0;
}