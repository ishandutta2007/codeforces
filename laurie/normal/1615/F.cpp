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
#define pii pair<int,int>
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
#define mod 1000000007
#define abs orzqazswedx
inline int abs(int x){
	return x>=0?x:-x;
}
int n;
ll f[2002][2002],g[2002][2002];
char a[2002],b[2002];
inline bool oka(int pos,int x){
	return a[pos]=='?'||a[pos]=='0'+x;
}
inline bool okb(int pos,int x){
	return b[pos]=='?'||b[pos]=='0'+x;
}
int main() {
	F(iakioi,1,read()){
		read(n);
		F(i,0,n+1)F(j,0,n+1)f[i][j]=g[i][j]=0;
		scanf("%s",a+1);scanf("%s",b+1);
		for(int i=2;i<=n;i+=2){
			if(a[i]!='?')a[i]^=1;
			if(b[i]!='?')b[i]^=1;
		}
		f[0][0]=1;int now=0;
		while(oka(++now,0))f[now][0]=1;
		now=0;
		while(okb(++now,0))f[0][now]=1;
		F(i,1,n)F(j,1,n){
			if(oka(i,1)&&okb(j,1)){
				f[i][j]=(f[i][j]+f[i-1][j-1])%mod;
				g[i][j]=(g[i][j]+g[i-1][j-1]+f[i-1][j-1]*1ll*abs(i-j))%mod;
			}
			if(oka(i,1)&&okb(j,0)){
				f[i][j]=(f[i][j]+f[i][j-1]-(oka(i,0)?f[i-1][j-1]:0))%mod;
				g[i][j]=(g[i][j]+g[i][j-1]-(oka(i,0)?g[i-1][j-1]:0))%mod;
			}
			if(oka(i,0)&&okb(j,1)){
				f[i][j]=(f[i][j]+f[i-1][j]-(okb(j,0)?f[i-1][j-1]:0))%mod;
				g[i][j]=(g[i][j]+g[i-1][j]-(okb(j,0)?g[i-1][j-1]:0))%mod;
			}
			if(oka(i,0)&&okb(j,0)){
				f[i][j]=(f[i][j]+f[i-1][j-1])%mod;
				g[i][j]=(g[i][j]+g[i-1][j-1])%mod;
			}
		}
		write((g[n][n]+mod)%mod,'\n');
	}
	return 0;
}