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
ll v[10000002],tag[10000002],h[300002],b[300002],l[300002],r[300002];
int sta[300002],cnt;
#define mid (l+r>>1)
inline void add(int pos,int l,int r,int ql,int qr,ll vv){
	if(qr<l||ql>r)return;
	if(ql<=l&&qr>=r){
		tag[pos]=max(tag[pos],vv);
		v[pos]=max(v[pos],vv);
		return;
	}
	tag[pos<<1]=max(tag[pos<<1],tag[pos]);
	tag[pos<<1|1]=max(tag[pos<<1|1],tag[pos]);
	v[pos<<1]=max(v[pos<<1],tag[pos]);
	v[pos<<1|1]=max(v[pos<<1|1],tag[pos]);
	add(pos<<1,l,mid,ql,qr,vv);
	add(pos<<1|1,mid+1,r,ql,qr,vv);
	v[pos]=max(v[pos<<1],v[pos<<1|1]);
}
inline ll query(int pos,int l,int r,int ql,int qr){
	if(qr<l||ql>r)return -LLONG_MAX;
	if(ql<=l&&qr>=r){
		return v[pos];
	}
	tag[pos<<1]=max(tag[pos<<1],tag[pos]);
	tag[pos<<1|1]=max(tag[pos<<1|1],tag[pos]);
	v[pos<<1]=max(v[pos<<1],tag[pos]);
	v[pos<<1|1]=max(v[pos<<1|1],tag[pos]);
	return max(query(pos<<1,l,mid,ql,qr),query(pos<<1|1,mid+1,r,ql,qr));
}
int n;
int main() {
	memset(v,-0x3f,sizeof(v));
	memset(tag,-0x3f,sizeof(tag));
	cin>>n;
	add(1,0,n,0,0,0);
	F(i,1,n)read(h[i]);
	F(i,1,n)read(b[i]);
	sta[cnt=1]=0;
	F(i,1,n){
		while(h[i]<h[sta[cnt]])--cnt;
		l[i]=sta[cnt];
		sta[++cnt]=i;
	}
	cnt=1;
	sta[cnt]=n+1;
	UF(i,n,1){
		while(h[i]<h[sta[cnt]])--cnt;
		r[i]=sta[cnt];
		sta[++cnt]=i;
	}
	F(i,1,n){
		ll qwq=query(1,0,n,l[i],i-1);
		qwq+=b[i];
		add(1,0,n,i,r[i]-1,qwq);
	}write(query(1,0,n,n,n));
	return 0;
}