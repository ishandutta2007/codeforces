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
ll n,x[102],y[102],m;
vector<vector<ll> >a;
inline int solve(vector<vector<ll> >a,ll n){
	if(n==1){
		if(a[0][0]==0)return 0;
		return (m&1)?1:-1;
	}
	vector<vector<ll> >temp(a);
	F(i,0,n-1)F(j,0,n-1)F(k,0,m){
		temp[i+x[k]&n-1][j+y[k]&n-1]^=a[i][j];
	}
	vector<vector<ll> >b[2][2];
	F(i,0,1)F(j,0,1){
		b[i][j].resize(n>>1);
		F(k,0,(n>>1)-1)b[i][j][k].resize(n>>1);
	}
	F(i,0,n-1)F(j,0,n-1){
		b[i&1][j&1][i>>1][j>>1]=temp[i][j];
	}
	int rt=0,$=0;
	F(i,0,1)F(j,0,1){
		$=solve(b[i][j],n>>1);
		if($==-1)return -1;
		rt+=$;
	}
	return rt;
}
int main() {
	cin>>n;
	n=(1<<n);
	a.resize(n);F(i,0,n-1)a[i].resize(n);
	F(i,0,n-1){
		F(j,0,n-1){
			read(a[i][j]);
		}
	}
	cin>>m;
	F(i,1,m){
		read(x[i]);read(y[i]);
	}
	cout<<solve(a,n);
	return 0;
}