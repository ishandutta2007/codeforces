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
int qwqwq,dd,n,x[500002],y[500002],p[500002],M[500002],t[1000002],cnt;
inline bool cmp(int a,int b){
	if(M[a]!=M[b])return M[a]<M[b];
	return x[a]<x[b];
}
#define mid ((l+r)>>1)
int mmax[4000002],tag[4000002];
#define mmin mmax
inline void add(int pos,int l,int r,int ql,int qr,int v){//if(pos==1)cerr<<ql<<" "<<qr<<" "<<v<<endl;
	if(ql<=l&&qr>=r){
		mmax[pos]+=v;
		tag[pos]+=v;
		return;
	}
	if(tag[pos]){
		tag[pos<<1]+=tag[pos];
		tag[pos<<1|1]+=tag[pos];
		mmin[pos<<1]+=tag[pos];
		mmin[pos<<1|1]+=tag[pos];
		tag[pos]=0;
	}
	if(ql<=mid)add(pos<<1,l,mid,ql,qr,v);
	if(qr>mid)add(pos<<1|1,mid+1,r,ql,qr,v);
	mmax[pos]=max(mmax[pos<<1],mmax[pos<<1|1]);
}
inline void modify(int pos,int l,int r,int q,int v){
	if(l==r){
		mmax[pos]=max(mmax[pos],v);
		return;
	}
	if(tag[pos]){
		tag[pos<<1]+=tag[pos];
		tag[pos<<1|1]+=tag[pos];
		mmin[pos<<1]+=tag[pos];
		mmin[pos<<1|1]+=tag[pos];
		tag[pos]=0;
	}
	if(q<=mid)modify(pos<<1,l,mid,q,v);
	else modify(pos<<1|1,mid+1,r,q,v);
	mmax[pos]=max(mmax[pos<<1],mmax[pos<<1|1]);
}
inline int query(int pos,int l,int r,int q){
	if(l==r)return mmax[pos];
	if(tag[pos]){
		tag[pos<<1]+=tag[pos];
		tag[pos<<1|1]+=tag[pos];
		mmin[pos<<1]+=tag[pos];
		mmin[pos<<1|1]+=tag[pos];
		tag[pos]=0;
	}
	if(q<=mid)return query(pos<<1,l,mid,q);
	return max(mmax[pos<<1],query(pos<<1|1,mid+1,r,q));
}
int main() {
	read(qwqwq,dd);
	while(qwqwq--){
		int temp=read();
		if(temp>=dd){
			x[++n]=temp;
			read(y[n]);
			M[n]=max(x[n],y[n]);
			t[++cnt]=x[n];
			t[++cnt]=y[n];
		}else read();
	}
	F(i,1,n)p[i]=i;
	sort(p+1,p+n+1,cmp);
	sort(t+1,t+cnt+1);
	cnt=unique(t+1,t+cnt+1)-t-1;
	F(i,1,n){
		x[i]=lower_bound(t+1,t+cnt+1,x[i])-t;
		y[i]=lower_bound(t+1,t+cnt+1,y[i])-t;
	}
	F(iakioi,1,n){
		int i=p[iakioi];//cerr<<x[i]<<" "<<y[i]<<endl;
		if(x[i]<=y[i]){
			modify(1,1,cnt,y[i],query(1,1,cnt,x[i])+1);
		}else{
			add(1,1,cnt,y[i]+1,x[i],1);
			modify(1,1,cnt,y[i],query(1,1,cnt,y[i])+1);
		}
	}
	write(mmax[1]);
	return 0;
}
/*
3 0
3 3
3 2
1 3
*/