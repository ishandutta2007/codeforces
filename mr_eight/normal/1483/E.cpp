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
char c[1000002];
ll m,h,now,up,temp,cnt=1;
inline bool check() {
	scanf("%s",c);
	if(c[0]=='L'||c[0]=='l')return 1;
	return 0;
}
inline bool play(ll n) {
	if(n>100000000000000ll)return 0;
//	n=min(n,100000000000000ll);
	printf("? %lld\n",n);
	fflush(stdout);cerr<<++cnt<<endl;
	if(check()) {
		now+=n;
		return 1;
	} else {
		now-=n;
		return 0;
	}
}
inline ll getnxt(ll m){
	
	return m+m;
}
int main() {
	F(qwqwqw,1,read()) {
		m=0;
		printf("? 1\n");
		fflush(stdout);
		if(!check()) {
			printf("! 0\n");
			fflush(stdout);
			continue;
		}
		m=1;
		now=2;
		while(1) {if(m>3e13)break;
			while(now<getnxt(m))play(m);
			if(play(getnxt(m))) {
				m=getnxt(m);
			} else break;
		}
		up=m+m-1,temp;
		if(up>5e13)up=100000000000000ll;
		while(m<up) {cerr<<'k';
			for(temp=1; temp+m<=up; temp*=3);
			temp/=3;
			if(m+temp>up)continue;
			while(now<(m+temp))play(m);
			if(play(m+temp)) {
				m+=temp;
			}else{
				up=m+temp-1;
			}
		}
		cout<<"!"<<' '<<m<<'\n';
		fflush(stdout);
nxt:
		;
	}
	return 0;
}