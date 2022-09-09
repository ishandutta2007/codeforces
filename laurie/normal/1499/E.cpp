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
#define mod 998244353
ll f[1002][1002],g[1002][1002],n,m,ans;
char x[1002],y[1002];
int main() {
	scanf("%s",x+1);
	scanf("%s",y+1);
	n=strlen(x+1);
	m=strlen(y+1);
	F(i,1,n){
		if(x[i]!=x[i-1])f[i][1001]=f[i-1][1001]+1;
		else f[i][1001]=1;
	}
	F(j,1,m){
		if(y[j]!=y[j-1])g[1001][j]=g[1001][j-1]+1;
		else g[1001][j]=1;
	}
	F(i,1,n){
		F(j,1,m){
			if(x[i]!=x[i-1])f[i][j]+=f[i-1][j];
			if(x[i]!=y[j])f[i][j]+=g[i-1][j]+g[1001][j];
			if(y[j]!=y[j-1])g[i][j]+=g[i][j-1];
			if(x[i]!=y[j])g[i][j]+=f[i][j-1]+f[i][1001];
			f[i][j]%=mod;
			g[i][j]%=mod;
			ans+=f[i][j];
			ans+=g[i][j];
		}
	}
	write(ans%mod);
	return 0;
}