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
ll mmax[2000002],n,m,tag1[2000002],tag2[2000002],rmax[2000002];
ll v[4][500002],x[500002],y[500002],ans=-LLONG_MAX;
struct S{
	int l,r,v;
}q[500002];
#define mid ((l+r)>>1)
inline bool cmp(const S &x,const S &y){
	return x.r<y.r;
}
inline void pushdown(int pos){
	rmax[pos<<1]=max(rmax[pos<<1],tag1[pos]);
	tag1[pos<<1]=max(tag1[pos<<1],tag1[pos]);
	tag1[pos<<1|1]=max(tag1[pos<<1|1],tag1[pos]);
	tag1[pos<<1|1]=max(tag1[pos<<1|1],mmax[pos<<1]+tag2[pos]);
	rmax[pos<<1|1]=max(rmax[pos<<1|1],tag1[pos<<1|1]);
	tag2[pos<<1]=max(tag2[pos<<1],tag2[pos]);
	tag2[pos<<1|1]=max(tag2[pos<<1|1],tag2[pos]);
	tag1[pos]=tag2[pos]=-1e18;
	mmax[pos<<1]=max(mmax[pos<<1],rmax[pos<<1]);
	mmax[pos<<1|1]=max(mmax[pos<<1|1],rmax[pos<<1|1]);
}
inline void puttag(int pos,ll v,ll k){
	rmax[pos]=max(rmax[pos],v);
	mmax[pos]=max(mmax[pos],v);
	tag1[pos]=max(tag1[pos],v);
	tag2[pos]=max(tag2[pos],k);
}
ll temp;
inline void add(int pos,int l,int r,int ql,int qr,ll &v,ll k){
	if(ql<=l&&qr>=r){
		puttag(pos,v,k);
		v=max(v,mmax[pos]+k);//if(k==-4)cerr<<pos<<" "<<rmax[6]<<endl;
		return;
	}
	pushdown(pos);
	if(ql<=mid)add(pos<<1,l,mid,ql,qr,v,k);
	if(qr>mid)add(pos<<1|1,mid+1,r,ql,qr,v,k);
	mmax[pos]=max(mmax[pos<<1],mmax[pos<<1|1]);
	rmax[pos]=max(rmax[pos<<1],rmax[pos<<1|1]);
//	if(k==-4)cerr<<pos<<" "<<rmax[6]<<endl;
}
inline void build(int pos,int l,int r){
	if(l==r){
		mmax[pos]=x[l+1];
		return;
	}
	build(pos<<1,l,mid);build(pos<<1|1,mid+1,r);
	mmax[pos]=max(mmax[pos<<1],mmax[pos<<1|1]);
}
inline void query(int pos,int l,int r){
	if(l!=r){
		pushdown(pos);
		query(pos<<1,l,mid);query(pos<<1|1,mid+1,r);
	}else ans=max(ans,rmax[pos]+y[l]);//cerr<<l<<" "<<x[l]<<" "<<mmax[pos]<<" "<<y[l]<<endl;
}
inline void upd(int pos,int l,int r,int ql,int qr,ll v){
	if(ql<=l&&qr>=r){
		tag1[pos]=max(tag1[pos],v);
		return;
	}
	if(ql<=mid)upd(pos<<1,l,mid,ql,qr,v);
	if(qr>mid)upd(pos<<1|1,mid+1,r,ql,qr,v);
}
int main() {
	memset(tag1,-0x3f,sizeof(tag1));
	memset(tag2,-0x3f,sizeof(tag2));
	cin>>n>>m;
	F(i,1,3)F(j,1,n)read(v[i][j]);
	F(i,1,3)F(j,1,n)v[i][j]+=v[i][j-1];
	F(i,1,n)x[i]=v[1][i]-v[2][i-1],y[i]=v[2][i]-v[3][i-1]+v[3][n];x[n+1]=-1e18;
	memset(rmax,-0x3f,sizeof(rmax));
	F(i,1,m){
		read(q[i].l);read(q[i].r);read(q[i].v);
	}
	memset(tag1,-0x3f,sizeof(tag1));
	sort(q+1,q+m+1,cmp);
	build(1,0,n);
	F(i,1,m){
		temp=-1e18;
		add(1,0,n,q[i].l-1,q[i].r,temp,-q[i].v);
	//	F(j,1,4)pushdown(j);
	//	cerr<<rmax[8]<<" "<<rmax[9]<<" "<<rmax[5]<<" "<<rmax[6]<<" "<<rmax[7]<<endl;
	}
	query(1,0,n);
	cout<<ans;
	return 0;
}
/*
5 1
-20 -10 -11 -10 1
1 3 3  
14 -20 3 6 2
1 2 2

*/