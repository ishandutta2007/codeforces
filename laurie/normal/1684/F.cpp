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
		if(x==0) {
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
vector<int>p[200002],ins[200002],del[200002];
vector<pii >upd[200002];
int a[200002],n,m,t[200002],mmin[800005],mpos[800005],tag[800005];
inline void pushup(int pos) {
	if(mmin[pos<<1]<=mmin[pos<<1|1]) {
		mmin[pos]=mmin[pos<<1];
		mpos[pos]=mpos[pos<<1];
	} else {
		mmin[pos]=mmin[pos<<1|1];
		mpos[pos]=mpos[pos<<1|1];
	}
}
inline void putt(int pos,int v) {
	tag[pos]+=v;
	mmin[pos]+=v;
}
inline void pushdown(int pos) {
	if(tag[pos]) {
		putt(pos<<1,tag[pos]);
		putt(pos<<1|1,tag[pos]);
		tag[pos]=0;
	}
}
#define mid ((l+r)>>1)
inline void build(int pos,int l,int r) {
	if(l==r) {
		mpos[pos]=l;
		return;
	}
	build(pos<<1,l,mid);
	build(pos<<1|1,mid+1,r);
	pushup(pos);
}
inline void add(int pos,int l,int r,int ql,int qr,int v) {
	if(ql<=l&&qr>=r) {//cerr<<pos<<" "<<l<<" "<<r<<endl;
		putt(pos,v);
		return;
	}
	pushdown(pos);
	if(ql<=mid)add(pos<<1,l,mid,ql,qr,v);
	if(qr>mid)add(pos<<1|1,mid+1,r,ql,qr,v);
	pushup(pos);
}
inline void add(int l,int r,int v) {
	if(l<=r)add(1,0,n,max(l,0),min(r,n),v);
}
inline int query() {
	return mmin[1]==0?mpos[1]:1000000000;
}
inline int pre(int a,int pos) {
	return *(upper_bound(p[a].begin(),p[a].end(),pos)-1);
}
inline int suf(int a,int pos) {
	return *lower_bound(p[a].begin(),p[a].end(),pos);
}
int main() {
	F(iasdfs,1,read()) {
		read(n);
		read(m);
		F(i,0,n+1)a[i]=t[i]=0,p[i].clear(),ins[i].clear(),del[i].clear(),upd[i].clear();
		F(i,0,(n+1)<<2)mmin[i]=mpos[i]=tag[i]=0;
		build(1,0,n);
		F(i,1,n)read(a[i]),t[i]=a[i];
		sort(t+1,t+n+1);
		F(i,1,n)a[i]=lower_bound(t+1,t+n+1,a[i])-t;
		F(i,1,n)p[a[i]].push_back(i);
		F(i,1,n)t[i]=i;
		F(i,1,m) {
			int l=read(),r=read();
			ins[r].push_back(r);
			del[l-1].push_back(r);
		}
		priority_queue<int>q,qq;
		UF(i,n,1) {
			for(int j:ins[i])q.push(j);
			for(int j:del[i])qq.push(j);
			while(!q.empty()&&!qq.empty()&&q.top()==qq.top())q.pop(),qq.pop();
			if(!q.empty())t[i]=q.top();
		}
		int r=n,ans=1e9;
		F(i,1,n) {
			int pos=pre(a[i],t[i]);
			if(pos>i)r=min(r,suf(a[i],i+1)),upd[1].push_back({pre(a[i],pos-1)-1,1}),upd[i+1].push_back({pos-1,1});
		}
		F(i,1,r) {
			for(pii j:upd[i])add(0,j.first,1);
			ans=min(ans,query()-i+1);
		}
		write(max(ans,0),'\n');
	}
	return 0;
}