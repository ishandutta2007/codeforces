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
#define ld long double
unsigned ll dp[100005],sum[100005];
unsigned ll n,ans[100002];
unsigned ll k;
#define mid (l+r>>1)
int main() {
	n=100002;
	dp[0]=sum[0]=1;
	F(i,1,n) {
		dp[i]=sum[i-1];
		sum[i]=dp[i]+sum[i-1];
	}
	F(iakioi,1,read()) {
		read(n);
		
		read(ans[0]);
		k=ans[0];
		if(n<=63)if(k>dp[n]) {
			puts("-1");
			goto orz;
		}
		F(i,1,n) {
			ri l=1,r=n-i+1;
			while(l<r) {
				if(n-i<=63){if(sum[n-i]-sum[n-i-mid]<k)l=mid+1;else r=mid;
				}
				else r=mid;
			}
			k-=sum[n-i]-sum[n-i+1-mid];
			   ans[i]=l;
			i+=l-1;
		}

		F(i,1,n) {
			F(j,1,ans[i])write(ans[i]+i-j,' ');
			i+=ans[i]-1;
		}
		putchar('\n');
orz:
		;
	}
	return 0;
}