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
int n,m,a[102][102],q[20000002],l=1,r,sum[202];
bool mark[202];
inline int getpos(){
	F(i,1,n)if(sum[i]<0)return i;
	F(i,1,m)if(sum[i+n]<0)return i+n;
	return 0;
}
int main() {
	cin>>n>>m;
	F(i,1,n)F(j,1,m)read(a[i][j]);
	F(i,1,n){
		F(j,1,m)sum[i]+=a[i][j];
	}
	F(i,1,m){
		F(j,1,n){
			sum[i+n]+=a[j][i];
		}
	}
	while(true){
		ri pos=getpos();
		if(!pos)break;
		mark[pos]^=1;
		sum[pos]=-sum[pos];
		if(pos<=n){
			F(j,1,m){
				a[pos][j]=-a[pos][j];
				sum[n+j]+=(a[pos][j]<<1);
			}
		}else{
			pos-=n;
			F(i,1,n){
				a[i][pos]=-a[i][pos];
				sum[i]+=(a[i][pos]<<1);
			}
		}
	}
	int cnt=0;
	F(i,1,n)cnt+=mark[i];
	write(cnt,' ');
	F(i,1,n)if(mark[i])write(i,' ');
	putchar('\n');
	cnt=0;
	F(i,1,m)cnt+=mark[i+n];
	write(cnt,' ');
	F(i,1,m)if(mark[i+n])write(i,' ');
	return 0;
}