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
	inline ll read() {
		ll x=0;
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
long double s[1000002],tot,temp;
bool mark[1000002];
int mmax,zero;
map<long double,int>mp;
int main() {
	F(i,2,1000000) {
		if(!mark[i]) {

			temp=sin(i);
			tot+=temp;
			for(ri j=i; j<=1e6; j+=i) {
				mark[j]=1;
				ri k=j;
				re bool x=0;
				while(k%i==0) {
					x=!x;
					k/=i;
				}
				if(x)s[j]+=temp;
			}
		}
	}
	
	F(qwq,1,read()) {mmax=zero=0;
		mp.clear();
		F(i,1,read()) {
			mp[s[read()]]++;
		}
		for(auto i=mp.begin(); i!=mp.end(); ++i) {
			mmax=max(mmax,i->second);
			if(i->first!=0&&((i->second)&1));
			else {
				zero+=i->second;
			}
		}
		F(qwqwq,1,read()) {
			if(read()==0) {
				write(mmax,'\n');
			} else {
				write(max(mmax,zero),'\n');
			}
		}
	}
	return 0;
}