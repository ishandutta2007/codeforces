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
	char num[40];
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
			num[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(num[ -- cnt ]) ;
	}
}
using namespace fastIO;
ll k,l,r,t,x,y,qwqwq;
int ok[2000002];
int main() {read(k),read(l),read(r),read(t),read(x),read(y);
	k-=l;
	r-=l;
	l=0;
	if(k<0||k>r)return 0;
	if(x>=y) {
		if(k+y>r)k-=y;
		x-=y;
		if(log2(x)+log2(t)<=60&&k>=x*t) {
			puts("Yes");
			return 0;
		} else {
			puts("No");
			return 0;
		}
	} else {
		if(r>=x+y) {
			puts("Yes");
			return 0;
		}
		if(y>r) {
			if(log2(x)+log2(t)<=60&&k>=x*t) {
				puts("Yes");
				return 0;
			} else {
				puts("No");
				return 0;
			}
		}
		//F(i,r-y+1,x-1)ok[i]=1;
		//cout<<k<<' '<<y<<' '<<x<<endl;
		for(ri orz=1; orz<=100000000; orz++) {
			if(t<=0)break;
			if(k<x&&k+y>r) {
				puts("No");
				return 0;
			}
			if(k<x)k+=y;
			if(log2(x)+log2(t)>60||k<x*t) {

				t-=k/x;
				k%=x;
			} else break;
		}
		puts("Yes");
	}
	return 0;
}