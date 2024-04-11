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
int change[10]={0,1,5,-10000,-10000,2,-10000,-10000,8,-10000},a,b,c,d;
inline bool check(int a,int b,int c,int d){
	if(a<=0)c=change[c];
	else c=change[c%10]*10+change[c/10];
	#define a b
	#define c d
	if(a<=0)c=change[c];
	else c=change[c%10]*10+change[c/10];
	#undef a
	#undef c
	if(0<=d&&d<a&&0<=c&&c<b)return 1;return 0;
}
int main() {
	F(qwq,1,read()){
		cin>>a>>b;read(c);read(d);
		while(114514){
			
			if(check(a,b,c,d)){
				if(a<=0)write(c);
				else if(c>=10)write(c);
				else{
				putchar('0');
				write(c);
				
				}
				putchar(':');	
				#define a b
				#define c d
				if(a<=0)write(c);
				else if(c>=10)write(c);
				else{
				putchar('0');
				write(c);
				
				}
				putchar('\n');
				#undef a
				#undef c
				break;
			}
			d++;
			if(d==b)d=0,c++;
			if(c==a)c=0;
		}
	}
	return 0;
}