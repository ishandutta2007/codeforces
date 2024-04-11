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
int dp[100002][2],n,m,nxt[100005][26][2],lst[26][2];
char s[100002],t[100002];
int main() {
F(awdfasd,1,read()){
	scanf("%s",s+1);scanf("%s",t+1);
	n=strlen(s+1);m=strlen(t+1);
	F(i,0,25)lst[i][0]=lst[i][1]=n+1;
	F(i,1,n+2)F(j,0,25)F(k,0,1)nxt[i][j][k]=1e9;
	F(i,1,m)F(j,0,1)dp[i][j]=1e9;
	UF(i,n,1){
		lst[s[i]-'a'][i&1]=i;
		F(j,0,25)F(k,0,1)nxt[i][j][k]=lst[j][k];
	}
	dp[1][0]=lst[t[1]-'a'][0];dp[1][1]=lst[t[1]-'a'][1];
	F(i,2,m){
		if(dp[i-1][1]<=n)dp[i][0]=nxt[dp[i-1][1]+1][t[i]-'a'][0];
		if(dp[i-1][0]<=n)dp[i][1]=nxt[dp[i-1][0]+1][t[i]-'a'][1];
	}
	puts(dp[m][n&1]<=n?"YES":"NO");
}
	return 0;
}