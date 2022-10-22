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
int m1[1200002],m2[1200002],n1[1200002],n2[1200002],tag[1200002],n,a[300002],p[300002];
inline void pushup(int pos){
	if(m1[pos<<1]<m1[pos<<1|1]){
		m1[pos]=m1[pos<<1];
		n1[pos]=n1[pos<<1];
		if(m2[pos<<1]<m1[pos<<1|1]){
			m2[pos]=m2[pos<<1];
			n2[pos]=n2[pos<<1];
		}else if(m2[pos<<1]>m1[pos<<1|1]){
			m2[pos]=m1[pos<<1|1];
			n2[pos]=n1[pos<<1|1];
		}else{
			m2[pos]=m2[pos<<1];
			n2[pos]=n2[pos<<1]+n1[pos<<1|1];
		}
	}else if(m1[pos<<1]>m1[pos<<1|1]){
		m1[pos]=m1[pos<<1|1];
		n1[pos]=n1[pos<<1|1];
		if(m1[pos<<1]<m2[pos<<1|1]){
			m2[pos]=m1[pos<<1];
			n2[pos]=n1[pos<<1];
		}else if(m1[pos<<1]>m2[pos<<1|1]){
			m2[pos]=m2[pos<<1|1];
			n2[pos]=n2[pos<<1|1];
		}else{
			m2[pos]=m1[pos<<1];
			n2[pos]=n1[pos<<1]+n2[pos<<1|1];
		}
	}else{
		m1[pos]=m1[pos<<1];
		n1[pos]=n1[pos<<1]+n1[pos<<1|1];
		if(m2[pos<<1]<m2[pos<<1|1]){
			m2[pos]=m2[pos<<1];
			n2[pos]=n2[pos<<1];
		}else if(m2[pos<<1]>m2[pos<<1|1]){
			m2[pos]=m2[pos<<1|1];
			n2[pos]=n2[pos<<1|1];
		}else{
			m2[pos]=m2[pos<<1];
			n2[pos]=n2[pos<<1]+n2[pos<<1|1];
		}
	}
}
inline void pushdown(int pos){//if(pos==6)cerr<<tag[pos]<<' '<<m1[pos<<1]<<endl;
	m1[pos<<1]+=tag[pos];
	m2[pos<<1]+=tag[pos];
	m1[pos<<1|1]+=tag[pos];
	m2[pos<<1|1]+=tag[pos];
	tag[pos<<1]+=tag[pos];
	tag[pos<<1|1]+=tag[pos];
	tag[pos]=0;
}
#define mid (l+r>>1)
inline void add(int pos,int l,int r,int ql,int qr,int v){
	if(l>=ql&&r<=qr){
		tag[pos]+=v;
		m1[pos]+=v;
		m2[pos]+=v;
		//if(ql==3&&qr==4&&v==1)cerr<<l<<' '<<r<<' '<<m1[pos]<<' '<<n1[pos]<<' '<<m2[pos]<<' '<<n2[pos]<<endl;
		return;
	}
	pushdown(pos);
	if(ql<=mid)add(pos<<1,l,mid,ql,qr,v);
	if(qr>mid)add(pos<<1|1,mid+1,r,ql,qr,v);
	pushup(pos);
	//if(ql==3&&qr==4&&v==1)cerr<<l<<' '<<r<<' '<<m1[pos]<<' '<<n1[pos]<<' '<<m2[pos]<<' '<<n2[pos]<<endl;
}
inline void add(int ql,int qr,int v){//cerr<<ql<<' '<<qr<<' '<<v<<endl;
	if(ql<=qr)add(1,1,n,ql,qr,v);
}
inline void orz(int pos,int l,int r,int q){
	if(l==r){
		n1[pos]=1;
		m1[pos]=0;
		return;
	}
	pushdown(pos);
	if(q<=mid)orz(pos<<1,l,mid,q);
	else orz(pos<<1|1,mid+1,r,q);
	pushup(pos);
}
int main() {
	memset(m1,0x3f,sizeof(m1));
	memset(m2,0x3f,sizeof(m2));
	cin>>n;
	F(i,1,n)read(a[i]),p[a[i]]=i;
	a[0]=a[n+1]=n+1;
	ll ans=0;
	UF(ii,n,1){ri i=p[ii];
		orz(1,1,n,ii);
		if(a[i-1]>a[i]&&a[i+1]>a[i])add(a[i],min(a[i-1],a[i+1])-1,1);
		else if(a[i-1]>a[i])add(a[i],a[i-1]-1,1);
		else if(a[i+1]>a[i])add(a[i],a[i+1]-1,1);
		else add(a[i],n,1);
		if(a[i-1]>a[i]&&a[i+1]>a[i])add(max(a[i-1],a[i+1]),n,-1);
		if(m1[1]<=2)ans+=n1[1];//,cerr<<m1[1]<<' '<<n1[1]<<' '<<'k';
		if(m2[1]<=2)ans+=n2[1];//,cerr<<m2[1]<<' '<<n2[1]<<' '<<'g';cerr<<endl;
	}
	cout<<ans-n;
	return 0;
}
/*
6
1 4 2 5 3 6
*/