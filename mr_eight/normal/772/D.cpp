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
#define mod 1000000007
struct S{
	int a,b,c;
	inline void operator+=(const S &z){
		c=(1ll*a*z.c+2ll*b*z.b+1ll*c*z.a)%mod;
		b=(1ll*a*z.b+1ll*b*z.a)%mod;
		a=1ll*a*z.a%mod;
	}
}orz[1000002];
int temp;
int ans[1000002];
int main() {
	F(i,0,999999)orz[i].a=1;
	F(zhqwqwqwqwqwqwqwqakioi,1,read()){
		read(temp);
		orz[temp]+=(S){2,temp,int(1ll*temp*temp%mod)};
	}
	for(ri i=1;i<=999999;i*=10){
		UF(j,999999,0){
			if((j/i)%10!=9)orz[j]+=orz[j+i];
		}
	}
	F(i,0,999999)ans[i]=orz[i].c;
	for(ri i=1;i<=999999;i*=10){
		F(j,0,999999){
			if((j/i)%10!=9)ans[j]=(ans[j]-ans[j+i]+mod)%mod;
		}
	}
	ll res=0;
	F(i,1,999999){
		res^=(1ll*i*ans[i]);
	}
	cout<<res;
	return 0;
}