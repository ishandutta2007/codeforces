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
int n,a[200002],v[800002];
#define mid ((l+r)>>1)
inline void build(int pos,int l,int r){
	if(l==r){
		v[pos]=a[l];
		return;
	}
	build(pos<<1,l,mid);
	build(pos<<1|1,mid+1,r);
	v[pos]=__gcd(v[pos<<1],v[pos<<1|1]);
}
inline int query(int pos,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r)return v[pos];
	if(ql>mid)return query(pos<<1|1,mid+1,r,ql,qr);
	if(qr<=mid)return query(pos<<1,l,mid,ql,qr);
	return __gcd(query(pos<<1,l,mid,ql,qr),query(pos<<1|1,mid+1,r,ql,qr));
}
inline int orz(int pos){
	int l=1,r=pos;
	while(l<r){
		if(query(1,1,n,mid,pos)<pos-mid+1)l=mid+1;
		else r=mid;
	}
	if(query(1,1,n,l,pos)==pos-l+1)return l;
	else return 0;
}
int l[200002],dp[200002],q[200002],qr,ql;
int main() {
	cin>>n;
	F(i,1,n)read(a[i]);
	build(1,1,n);
	int mmin=1e9;
	UF(i,n,1){
		l[i]=orz(i);
	}
	q[ql=qr=1]=0;
	F(i,1,n){//cerr<<l[i]<<endl;
		if(l[i]){
			while(q[ql]<l[i]-1)++ql;
			dp[i]=dp[q[ql]]+1;
		}else{
			dp[i]=dp[i-1];
		}
		while(ql<=qr&&dp[i]<=dp[qr])--qr;
		q[++qr]=i;
	}
	F(i,1,n)write(dp[i],' ');
	return 0;
}