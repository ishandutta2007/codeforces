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
int n,m,sum[800002],lmax[800002],rmin[800002],
mans[800002],lans[800002],rans[800002],ans[800002];
char c[200002];
#define mid ((l+r)>>1)
inline void tol(int pos){
	sum[pos]=lmax[pos]=mans[pos]=lans[pos]=rans[pos]=ans[pos]=1;
	rmin[pos]=0;
}
inline void tor(int pos){
	sum[pos]=rmin[pos]=-1;
	lmax[pos]=0;
	mans[pos]=lans[pos]=rans[pos]=ans[pos]=1;
}
inline void pushup(int pos){
	sum[pos]=sum[pos<<1]+sum[pos<<1|1];
	lmax[pos]=max(lmax[pos<<1],sum[pos<<1]+lmax[pos<<1|1]);
	rmin[pos]=min(rmin[pos<<1|1],sum[pos<<1|1]+rmin[pos<<1]);
	mans[pos]=max(mans[pos<<1]+sum[pos<<1|1],mans[pos<<1|1]-sum[pos<<1]);
	lans[pos]=max(max(lans[pos<<1],mans[pos<<1]+lmax[pos<<1|1]),-sum[pos<<1]+lans[pos<<1|1]);
	rans[pos]=max(max(rans[pos<<1|1],mans[pos<<1|1]-rmin[pos<<1]),sum[pos<<1|1]+rans[pos<<1]);
	ans[pos]=max(max(ans[pos<<1],ans[pos<<1|1]),max(rans[pos<<1]+lmax[pos<<1|1],lans[pos<<1|1]-rmin[pos<<1]));
}
inline void build(int pos,int l,int r){
	if(l!=r){
		build(pos<<1,l,mid);
		build(pos<<1|1,mid+1,r);
		pushup(pos);
	}else{
		if(c[l]=='('){
			tol(pos);
		}else{
			tor(pos);
		}
	}
}
inline void modify(int pos,int l,int r,int q){
	if(l!=r){
		if(q<=mid)modify(pos<<1,l,mid,q);
		else modify(pos<<1|1,mid+1,r,q);
		pushup(pos);
	}else{
		if(c[l]=='(')tol(pos);
		else tor(pos);
	}
}
int main() {
	cin>>n>>m;n=2*n-2;
	scanf("%s",c+1);
	build(1,1,n);
	write(ans[1],'\n');
	ri t1,t2;
	while(m--){
		read(t1);read(t2);
		swap(c[t1],c[t2]);
		modify(1,1,n,t1);
		modify(1,1,n,t2);
		write(ans[1],'\n');
	}
	return 0;
}
/*
5 0
(()())()
*/