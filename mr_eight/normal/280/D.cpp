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
int n;
struct S{
	int l,r,v;
	inline bool operator>(const S &b)const{
		return v==b.v?(l==b.l?r<b.r:l>b.l):(v>b.v);
	}
	inline bool operator<(const S &b)const{
		return v==b.v?(l==b.l?r<b.r:l>b.l):(v<b.v);
	}
};
#define max MMAX
#define min MMIN
inline S max(const S &a,const S &b){
	return a>b?a:b;
}
inline S min(const S &a,const S &b){
	return a<b?a:b;
}
struct node{
	S lmax,rmax,mmax,lmin,rmin,mmin;
	int sum;
	bool rev;
}v[400002];
inline node merge(const node &a,const node &b){
	node rt;
	rt.sum=a.sum+b.sum;
	rt.rev=0;
	rt.lmax=max(a.lmax,(S){a.lmax.l,b.lmax.r,a.sum+b.lmax.v});
	rt.rmax=max(b.rmax,(S){a.rmax.l,b.rmax.r,a.rmax.v+b.sum});
	rt.mmax=max(max(a.mmax,b.mmax),(S){a.rmax.l,b.lmax.r,a.rmax.v+b.lmax.v});
	rt.lmin=min(a.lmin,(S){a.lmin.l,b.lmin.r,a.sum+b.lmin.v});
	rt.rmin=min(b.rmin,(S){a.rmin.l,b.rmin.r,a.rmin.v+b.sum});
	rt.mmin=min(min(a.mmin,b.mmin),(S){a.rmin.l,b.lmin.r,a.rmin.v+b.lmin.v});
	return rt;
}
inline void pushup(int x){
	v[x]=merge(v[x<<1],v[x<<1|1]);
}
inline void putrev(int x){
	swap(v[x].lmax,v[x].lmin);
	swap(v[x].rmax,v[x].rmin);
	swap(v[x].mmax,v[x].mmin);
	v[x].lmax.v=-v[x].lmax.v;
	v[x].rmax.v=-v[x].rmax.v;
	v[x].mmax.v=-v[x].mmax.v;
	v[x].lmin.v=-v[x].lmin.v;
	v[x].rmin.v=-v[x].rmin.v;
	v[x].mmin.v=-v[x].mmin.v;
	v[x].sum=-v[x].sum;
	v[x].rev^=1;
}
inline void pushdown(int x){
	if(v[x].rev){
		putrev(x<<1);
		putrev(x<<1|1);
		v[x].rev=false;
	}
}
#define mid ((l+r)>>1)
inline void modify(int pos,int l,int r,int q,int vv){
	if(l==r){
		S temp={l,r,vv};
		v[pos]={temp,temp,temp,temp,temp,temp,vv,false};
		return;
	}
	pushdown(pos);
	if(q<=mid)modify(pos<<1,l,mid,q,vv);
	else modify(pos<<1|1,mid+1,r,q,vv);
	pushup(pos);
}
inline node query(int pos,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r)return v[pos];
	pushdown(pos);
	if(ql<=mid&&qr>mid)return merge(query(pos<<1,l,mid,ql,qr),query(pos<<1|1,mid+1,r,ql,qr));
	if(ql<=mid)return query(pos<<1,l,mid,ql,qr);
	return query(pos<<1|1,mid+1,r,ql,qr);
}
inline void rev(int pos,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		putrev(pos);
		return;
	}
	pushdown(pos);
	if(ql<=mid)rev(pos<<1,l,mid,ql,qr);
	if(qr>mid)rev(pos<<1|1,mid+1,r,ql,qr);
	pushup(pos);
}
inline int query(int l,int r,int res){
	if(!res)return 0;
	S temp=query(1,1,n,l,r).mmax;
	if(temp.v<=0)return 0;
	rev(1,1,n,temp.l,temp.r);
	int rt=temp.v+query(l,r,res-1);
	rev(1,1,n,temp.l,temp.r);
	return rt;
}
inline void build(int pos,int l,int r){
	if(l==r){
		int vv=read();
		S temp={l,r,vv};
		v[pos]={temp,temp,temp,temp,temp,temp,vv,false};
		return;
	}
	build(pos<<1,l,mid);
	build(pos<<1|1,mid+1,r);
	pushup(pos);
}
int main(){
	cin>>n;
	build(1,1,n);
	F(i,1,read()){
		if(read()==0){
			int p=read();
			modify(1,1,n,p,read());
		}else{
			int l=read(),r=read();
			write(query(l,r,read()),'\n');
		}
	}
    return 0;
}