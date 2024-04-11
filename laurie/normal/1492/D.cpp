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
char ans1[1000002],ans2[1000002];
int main() {
	int a,b,c;
	cin>>a>>b>>c;
	
	swap(a,b);
	if(c==0){
		puts("Yes");
		F(i,1,a)putchar('1');
		F(i,1,b)putchar('0');
		puts("");
		F(i,1,a)putchar('1');
		F(i,1,b)putchar('0');
		return 0;
	}if(c>=a+b-1){
		puts("No");
		return 0;
	}
	if(b==0||a==1){
		puts("No");return 0;
	}F(i,1,a)ans1[i]='1';F(i,1,b)ans1[i+a]='0';F(i,1,a)ans2[i]='1';F(i,1,b)ans2[i+a]='0';
	ans1[a+b+1]='\0';ans2[a+b+1]='\0';
	if(c<a){
		puts("Yes");
		ans2[a+1]='1';
		ans2[a-c+1]='0';
		puts(ans1+1);
		puts(ans2+1);
	}else if(1){
		puts("Yes");
		ans2[2]='0';
		c-=a-2;
		ans2[a+c]='1';
		puts(ans1+1);
		puts(ans2+1);
	}
	return 0;
}