//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
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
//#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define cp complex<double>
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
using namespace std;
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
	inline void write(T x) {
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
struct pii{
	int first,second,p;
};
ll dp[77][77],n,k,p[77];
pii a[77];bool vis[77];
inline bool cmp(pii x,pii y){
	return x.second<y.second;
}
int main() {
	F(iakioi,1,read()){
		memset(dp,0,sizeof(dp));memset(a,0,sizeof(a));memset(vis,0,sizeof(vis));
		cin>>n>>k;
		F(i,1,n)read(a[i].first,a[i].second),a[i].p=i;
		sort(a+1,a+n+1,cmp);
		F(i,1,n)p[i]=a[i].p;
		memset(dp,-0x3f,sizeof(dp));
		dp[0][0]=0;
		F(i,1,n){
			dp[i][0]=dp[i-1][0]+(k-1)*a[i].second;
			F(j,1,n)dp[i][j]=max(dp[i-1][j]+(k-1)*a[i].second,dp[i-1][j-1]+(j-1)*a[i].second+a[i].first);
		}
		int now=k;
		UF(i,n,1){
			if(now&&dp[i-1][now]+(k-1)*a[i].second<dp[i-1][now-1]+(now-1)*a[i].second+a[i].first)vis[i]=true,--now;
		}
		write(n+n-k,'\n');now=0;
		F(i,1,n)if(vis[i]&&(++now)!=k)write(p[i],' ');
		F(i,1,n)if(!vis[i])write(p[i],' '),write(-p[i],' ');
		UF(i,n,1)if(vis[i]){write(p[i],'\n');break;}
	}
	return 0;
}