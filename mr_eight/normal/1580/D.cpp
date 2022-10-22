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
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
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
int ch[4002][2],orz[4002],sto[4002],n,m,a[4002],sta[4002],cnt,sz[4002];
ll dp[4002][4002];
inline void dfs(int pos){//cerr<<pos<<' '<<ch[pos][0]<<' '<<ch[pos][1]<<endl;
	if(ch[pos][0]&&ch[pos][1]){
		dfs(ch[pos][0]);
		dfs(ch[pos][1]);
		sz[pos]=sz[ch[pos][0]]+sz[ch[pos][1]]+1;
		int x=ch[pos][0],y=ch[pos][1];
		F(i,0,sz[x]){
			F(j,0,sz[y]){
				dp[pos][i+j]=max(dp[pos][i+j],dp[x][i]+dp[y][j]-i*j*2ll*a[pos]);
				dp[pos][i+j+1]=max(dp[pos][i+j+1],dp[x][i]+dp[y][j]+1ll*(m-(i+1)*(j+1)*2+1ll)*a[pos]);
			}
		}
	}else if(ch[pos][0]){
		dfs(ch[pos][0]);
		int x=ch[pos][0];
		sz[pos]=sz[x]+1;
		F(i,0,sz[x]){
			dp[pos][i]=max(dp[pos][i],dp[x][i]);
			dp[pos][i+1]=max(dp[pos][i+1],dp[x][i]+1ll*(m-i*2-1ll)*a[pos]);
		}
	}else if(ch[pos][1]){
		dfs(ch[pos][1]);
		int x=ch[pos][1];
		sz[pos]=sz[x]+1;
		F(i,0,sz[x]){
			dp[pos][i]=max(dp[pos][i],dp[x][i]);
			dp[pos][i+1]=max(dp[pos][i+1],dp[x][i]+1ll*(m-i*2-1ll)*a[pos]);
		}
	}else{
		dp[pos][0]=0;
		dp[pos][1]=1ll*(m-1)*a[pos];
		sz[pos]=1;
	}
}
int main() {
	memset(dp,-0x3f,sizeof(dp));
	cin>>n>>m;
	F(i,1,n)read(a[i]);
	F(i,1,n){
		while(cnt&&a[i]<a[sta[cnt]])--cnt;
		orz[i]=sta[cnt];
		sta[++cnt]=i;
	}
	cnt=0;
	sta[0]=n+1;
	UF(i,n,1){
		while(cnt&&a[i]<=a[sta[cnt]])--cnt;
		sto[i]=sta[cnt];
		sta[++cnt]=i;
	}
	F(i,1,n){
		if(a[orz[i]]<a[sto[i]]){
			ch[sto[i]][0]=i;
		}else{
			ch[orz[i]][1]=i;
		}
	}
	int r=min_element(a+1,a+n+1)-a;
	dfs(r);
	write(dp[r][m]);
	return 0;
}