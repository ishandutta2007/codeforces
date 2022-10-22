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
ll a[300002],c[300002],t3,qwq,qaq;
int tp[300002],n,t1,t2;
int ans[1200002],lmax[1200002],rmax[1200002],lans[1200002],rans[1200002];
inline void add(int pos,ll v){
	while(pos<=n){
		c[pos]+=v;
		pos+=(-pos&pos);
	}
}
inline ll query(int pos){
	ll rt=0;
	while(pos){
		rt+=c[pos];
		pos-=(-pos&pos);
	}return rt;
}
#define mid (l+r>>1)
inline void pushup(int pos,int l,int r){
	if(lmax[pos<<1]==mid-l+1)lmax[pos]=mid-l+1+lmax[pos<<1|1];
	else lmax[pos]=lmax[pos<<1];
	if(rmax[pos<<1|1]==r-mid)rmax[pos]=r-mid+rmax[pos<<1];
	else rmax[pos]=rmax[pos<<1|1];
	if(rmax[pos<<1]==mid-l+1)lans[pos]=mid-l+1+lans[pos<<1|1];
	else if(lans[pos<<1]==mid-l+1)lans[pos]=mid-l+1+lmax[pos<<1|1];
	else lans[pos]=lans[pos<<1];
	if(lmax[pos<<1|1]==r-mid)rans[pos]=r-mid+rans[pos<<1];
	else if(rans[pos<<1|1]==r-mid)rans[pos]=r-mid+rmax[pos<<1];
	else rans[pos]=rans[pos<<1|1];
	ans[pos]=max(max(ans[pos<<1],ans[pos<<1|1]),max(rans[pos<<1]+lmax[pos<<1|1],lans[pos<<1|1]+rmax[pos<<1]));
}
inline void build(int pos,int l,int r){
	if(l==r){
		if(tp[l]==1)ans[pos]=rmax[pos]=lans[pos]=rans[pos]=1;
		else if(tp[l]==2)ans[pos]=lmax[pos]=lans[pos]=rans[pos]=1;
	}else{
		build(pos<<1,l,mid);
		build(pos<<1|1,mid+1,r);
		pushup(pos,l,r);
			}
}
inline void modify(int pos,int l,int r,int q){
	if(l==r){
		if(tp[q]==1){
			ans[pos]=rmax[pos]=lans[pos]=rans[pos]=1;
			lmax[pos]=0;
		}else if(tp[q]==2){
			ans[pos]=lmax[pos]=lans[pos]=rans[pos]=1;
			rmax[pos]=0;
		}else{
			ans[pos]=lmax[pos]=rmax[pos]=lans[pos]=rans[pos]=0;
		}
	}else{
		if(q<=mid)modify(pos<<1,l,mid,q);
		else modify(pos<<1|1,mid+1,r,q);
		pushup(pos,l,r);
	}
}
int main() {
	cin>>n;
	if(n==1){
		read();F(i,1,read())puts("1");return 0;
	}
	F(i,1,n){
		read(a[i]);
		add(i,a[i]-a[i-1]);
	}
	F(i,1,n-1){
		if(a[i]<a[i+1])tp[i]=1;
		else if(a[i]>a[i+1])tp[i]=2;
	}
	build(1,1,n-1);
	F(iakioi,1,read()){
		read(t1);read(t2);read(t3);
		add(t1,t3);
		add(t2+1,-t3);
		if(t1>1){
			qwq=query(t1-1);
			qaq=query(t1);
			if(qwq<qaq&&tp[t1-1]!=1){
				tp[t1-1]=1;
				modify(1,1,n-1,t1-1);
			}else if(qwq>qaq&&tp[t1-1]!=2){
				tp[t1-1]=2;
				modify(1,1,n-1,t1-1);
			}else if(qwq==qaq&&tp[t1-1]!=0){
				tp[t1-1]=0;
				modify(1,1,n-1,t1-1);
			}
		}
		#define t1 (t2+1)
		if(t1<=n){
			qwq=query(t1-1);
			qaq=query(t1);
			if(qwq<qaq&&tp[t1-1]!=1){
				tp[t1-1]=1;
				modify(1,1,n-1,t1-1);
			}else if(qwq>qaq&&tp[t1-1]!=2){
				tp[t1-1]=2;
				modify(1,1,n-1,t1-1);
			}else if(qwq==qaq&&tp[t1-1]!=0){
				tp[t1-1]=0;
				modify(1,1,n-1,t1-1);
			}
		}
		#undef t1
		write(ans[1]+1,'\n');
	}
	return 0;
}