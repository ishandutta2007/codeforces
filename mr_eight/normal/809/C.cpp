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
ll ak;
constexpr inline ll getqwq(ll qwq){
	return qwq*(qwq-1)/2%mod;
}
inline ll tot(ll x,ll y,ll now){if(x<y)swap(x,y);now^=(now&(x-1));
	if(ak>=max(x,y)+now)return (min(x,y)*getqwq(max(x,y))+now*x%mod*y)%mod;
	else if(ak<now)return mod-x*y;
	else return (min(x,y)*getqwq(ak-now+1)+now*min(x,y)%mod*(ak-now+1)+mod-min(x,y)*(max(x,y)-(ak-now+1)))%mod;
}
inline ll orz(ll x,ll y,ll noww){
	ll now=0,rt=0;
	UF(i,30,0){
		if(y>>i&1){
			rt+=tot(1<<i,x,now^noww);
			now+=(1<<i);
		}
	}return rt%mod;
}
inline ll solve(ll x,ll y){
	ll now=0,rt=0;
	UF(i,30,0){
		if(x>>i&1){
			rt+=orz(1<<i,y,now);
			now+=(1<<i);
		}
	}
	return rt%mod;
}
int main() {
	F(qwq,1,read()){
		ri t1,t2,t3,t4;
		read(t1);read(t2);read(t3);read(t4);read(ak);ak--;
		write((1ll*(t3-t1+1)*(t4-t2+1)+mod+mod+solve(t3,t4)-solve(t1-1,t4)-solve(t3,t2-1)+solve(t1-1,t2-1))%mod,'\n');
	}
	return 0;
}