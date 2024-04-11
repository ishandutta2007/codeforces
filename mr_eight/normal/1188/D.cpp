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
#define F(i,a,b) for(ll int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(ll int i=a,i##end=b;i>=i##end;--i)
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
int dp[62][114514],cnt[114514],n;
ll a[114514],NOW,add;
#define now NOW
inline bool cmp(ll x,ll y){
	return (x&now-1)>(y&now-1);
}
int main() {
	read(n);
	F(i,1,n)read(a[i]);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	sort(a+1,a+n+1);
	F(i,1,n)a[i]=a[n]-a[i];
	F(i,1,60){add=0;
		sort(a+1,a+n+1,cmp);//cerr<<i<<' '<<a[1]<<' '<<a[2]<<' '<<a[3]<<endl;
		cnt[0]=cnt[1]=0;
		F(j,1,n)cnt[a[j]>>i-1&1]++;
		dp[i][cnt[1]]=min(dp[i][cnt[1]],cnt[0]+dp[i-1][0]);
		dp[i][0]=min(dp[i][0],cnt[1]+dp[i-1][0]);
		F(j,1,n){
			cnt[a[j]>>i-1&1]--;
			cnt[!(a[j]>>i-1&1)]++;
			if(a[j]>>i-1&1)++add;
			dp[i][add+cnt[1]]=min(dp[i][add+cnt[1]],cnt[0]+dp[i-1][j]);
			dp[i][add]=min(dp[i][add],cnt[1]+dp[i-1][j]);
		}if(!now)now=1;
		NOW<<=1ll;
		
	}write(dp[60][0]);
	return 0;
}