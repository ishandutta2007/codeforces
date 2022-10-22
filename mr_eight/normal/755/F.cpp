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
int n,k,v[1000002],cnt,p[1000002],m,res,orz;
bool vis[1000002];
int ak[1000002];
inline void dfs(int pos){
	if(vis[pos])return;vis[pos]=1;
	++cnt;
	dfs(p[pos]);
}
bitset<1000002>dp,temp;
inline void ksm(int n,int num){
	ri i=1;
	temp=dp|(dp<<i*num);
	while(i*2<=n){
		temp|=(temp<<i*num);
		i<<=1;
	}
	if(i!=n)temp|=(temp<<(n-i)*num);
}
inline bool check(){
	dp[0]=1;
	F(i,1,n){
		if(ak[i])ksm(ak[i],i),
		dp=temp;
	}//cerr<<dp<<endl;
	return dp[k];
}
int main() {
	cin>>n>>k;
	F(i,1,n)read(p[i]);
	F(i,1,n)if(!vis[i])dfs(i),v[++m]=cnt,ak[cnt]++,orz+=(cnt&1),cnt=0;
	write(check()?k:k+1);
	putchar(' ');
	if(k<=(n-orz)/2)write(k*2);
	else write(min(n,n-orz+(k-(n-orz)/2)));
	return 0;
}