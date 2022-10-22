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
int mmin[30000002],mmax[30000002],lc[30000002],rc[30000002],tag[30000002],cnt;
inline int new_node(int l,int r){
	mmin[++cnt]=l;
	mmax[cnt]=r;
	return cnt;
}
#define mid ((l+r)>>1)
inline void pushup(int pos){
	mmin[pos]=mmin[lc[pos]];
	mmax[pos]=mmax[rc[pos]];
}
inline void pushdown(int pos){
	if(tag[pos]){
		int x=tag[pos];
		tag[lc[pos]]+=x;
		tag[rc[pos]]+=x;
		mmin[lc[pos]]+=x;
		mmin[rc[pos]]+=x;
		mmax[lc[pos]]+=x;
		mmax[rc[pos]]+=x;
		tag[pos]=0;
	}
}
inline void modify(int pos,int l,int r,int ql,int qr,int v){
	if(ql<=l&&qr>=r){
		tag[pos]+=v;
		mmin[pos]+=v;
		mmax[pos]+=v;
		return;
	}
	if(!lc[pos])lc[pos]=new_node(l,mid);
	if(!rc[pos])rc[pos]=new_node(mid+1,r);
	pushdown(pos);
	if(ql<=mid)modify(lc[pos],l,mid,ql,qr,v);
	if(qr>mid)modify(rc[pos],mid+1,r,ql,qr,v);
	pushup(pos);
}
inline int query(int pos,int l,int r,int q){
	if(l==r)return mmin[pos];
	if(!lc[pos])lc[pos]=new_node(l,mid);
	if(!rc[pos])rc[pos]=new_node(mid+1,r);
	pushdown(pos);
	if(q<=mid)return query(lc[pos],l,mid,q);
	else return query(rc[pos],mid+1,r,q);
}
inline int find_first(int pos,int l,int r,int q){
	if(l==r)return l;
	if(!lc[pos])lc[pos]=new_node(l,mid);
	if(!rc[pos])rc[pos]=new_node(mid+1,r);
	pushdown(pos);
	if(mmax[lc[pos]]>=q)return find_first(lc[pos],l,mid,q);
	else return find_first(rc[pos],mid+1,r,q);
}
inline int find_last(int pos,int l,int r,int q){
	if(l==r)return l;
	if(!lc[pos])lc[pos]=new_node(l,mid);
	if(!rc[pos])rc[pos]=new_node(mid+1,r);
	pushdown(pos);
	if(mmin[rc[pos]]>q)return find_last(lc[pos],l,mid,q);
	else return find_last(rc[pos],mid+1,r,q);
}
int lstans;
#define orz 1,0,1000000000
int main() {
	new_node(0,1000000000);
	F(iakioi,1,read()){
		int x=read();
		int a=find_last(orz,x-1),b=find_first(orz,x+1);
		if(mmin[1]<x)modify(orz,0,a,1);
		if(mmax[1]>x)modify(orz,b,1000000000,-1);
		F(IAKIOI,1,read()){
			int x=(read()+lstans)%1000000001;
			write(lstans=query(orz,x),'\n');
		}
	}
	return 0;
}