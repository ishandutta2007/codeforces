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
#include <random>
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
int n,m,k,a[1002],b[1002],c[1002],d[1002],buf[20000002];
inline int &f(int i,int j,int l){
	if(i>n)i=n;
	return buf[(i+1)*(m+1)*(k+k+1)+(j-i)*(m+1)+l];
}
inline void ckmax(int &x,int y){
	x=max(x,y);
}
int main(){
	cin>>n>>m>>k;
	F(i,1,read())++a[read()];
	F(i,1,read())++b[read()];
	F(i,1,n){
		c[i]=c[i-1]+(a[i]&&!b[i]);
		d[i]=d[i-1]+(b[i]&&!a[i]);
		a[i]+=a[i-1];
		b[i]+=b[i-1];
	}
	if(m>=2*((n+k-1)/k)){
		cout<<a[n]+d[n];
		return 0;
	}
	F(i,0,n)F(j,0,n)if(abs(i-j)<=k)F(l,0,m){//cerr<<i<<" "<<j<<" "<<l<<" "<<f(i,j,l)<<endl;
		if(i<=j){
			ckmax(f(i+1,j,l),f(i,j,l));
			if(l!=m)ckmax(f(i+k,j,l+1),f(i,j,l)+c[j]-c[i]+a[min(i+k,n)]-a[j]);
		}
		if(i>=j){
			ckmax(f(i,j+1,l),f(i,j,l));
			if(l!=m)ckmax(f(i,j+k,l+1),f(i,j,l)+d[i]-d[j]+b[min(j+k,n)]-b[i]);
		}
	}
	cout<<*max_element(buf,buf+20000001);
    return 0;
}