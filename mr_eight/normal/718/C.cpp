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
#define mod 1000000007
struct mat{
	ll a,b,c,d;
	inline mat operator*(const mat &y)const{
		return mat{(a*y.a+b*y.c)%mod,(a*y.b+b*y.d)%mod,(c*y.a+d*y.c)%mod,(c*y.b+d*y.d)%mod};
	}
	inline mat operator+(const mat &y)const{
		return mat{(a+y.a)%mod,(b+y.b)%mod,(c+y.c)%mod,(d+y.d)%mod};
	}
};
inline mat pw(mat bot,ll p){
	mat rt=mat{1,0,0,1};
	while(p){
		if(p&1)rt=rt*bot;
		bot=bot*bot;
		p>>=1;
	}return rt;
}
mat v[400002],ORZ,tag[400002];
int n,m,temp,t1,t2,t3;
#define mid (l+r>>1)
inline void build(int pos,int l,int r){
	tag[pos]=mat{1,0,0,1};
	if(l==r){
		v[pos]=pw(mat{1,1,1,0},read());
	}else{
		build(pos<<1,l,mid);
		build(pos<<1|1,mid+1,r);
		v[pos]=v[pos<<1]+v[pos<<1|1];
	}
}
inline void pushdown(int pos){
	v[pos<<1]=v[pos<<1]*tag[pos];
	v[pos<<1|1]=v[pos<<1|1]*tag[pos];
	tag[pos<<1]=tag[pos<<1]*tag[pos];
	tag[pos<<1|1]=tag[pos<<1|1]*tag[pos];
	tag[pos]=mat{1,0,0,1};
}
inline void modify(int pos,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		v[pos]=v[pos]*ORZ;
		tag[pos]=tag[pos]*ORZ;
		return;
	}
	pushdown(pos);
	if(ql<=mid)modify(pos<<1,l,mid,ql,qr);
	if(qr>mid)modify(pos<<1|1,mid+1,r,ql,qr);
	v[pos]=v[pos<<1]+v[pos<<1|1];
}
inline mat query(int pos,int l,int r,int ql,int qr){
	if(ql>r||qr<l)return mat{0,0,0,0};
	if(ql<=l&&qr>=r){
		return v[pos];
	}pushdown(pos);
	return query(pos<<1,l,mid,ql,qr)+query(pos<<1|1,mid+1,r,ql,qr);
}
int main() {
	cin>>n>>m;
	build(1,1,n);
	F(i,1,m){
		if(read()==1){
			read(t1);read(t2);read(t3);
			ORZ=pw(mat{1,1,1,0},t3);
			modify(1,1,n,t1,t2);
		}else{
			read(t1);read(t2);
			write(query(1,1,n,t1,t2).c,'\n');
		}
	}
	return 0;
}