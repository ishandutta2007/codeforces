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
int n,m,a[1000002],b[1000002],t[1000002],c[1000002],p[1000002],mmin[5000002],tag[5000002];
inline void ins(int pos){
	while(pos<=n){
		++c[pos];
		pos+=(-pos&pos);
	}
}
inline int qry(int pos){
	int rt=0;
	while(pos){
		rt+=c[pos];
		pos-=(-pos&pos);
	}
	return rt;
}
inline bool cmp(int x,int y){
	return a[x]<a[y];
}
#define mid ((l+r)>>1)
inline void build(int pos,int l,int r){
	mmin[pos]=l;
	tag[pos]=0;
	if(l!=r)build(pos<<1,l,mid),build(pos<<1|1,mid+1,r);
}
inline void add(int pos,int l,int r,int ql,int qr,int v){//if(pos==1)cerr<<ql<<" "<<qr<<" "<<v<<endl;
	if(ql<=l&&qr>=r){
		mmin[pos]+=v;
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
	mmin[pos]=min(mmin[pos<<1],mmin[pos<<1|1]);
}
int main() {
	F(iak,1,read()){
		read(n);read(m);
		F(i,1,n)read(a[i]),c[i]=0,t[i]=a[i],p[i]=i;
		F(i,1,m)read(b[i]);
		sort(b+1,b+m+1);
		sort(t+1,t+n+1);
		ll ans=0;
		F(i,1,n){int qwq=lower_bound(t+1,t+n+1,a[i])-t;
			ins(qwq);
			ans+=i-qry(qwq);
		}
		int now1=0,now2=0;
		sort(p+1,p+n+1,cmp);
		build(1,0,n);
		F(i,1,m){
			while(now1<n&&a[p[now1+1]]<b[i]){
				++now1;
				add(1,0,n,0,p[now1]-1,1);
			}
			while(now2<n&&a[p[now2+1]]<=b[i]){
				++now2;
				add(1,0,n,p[now2],n,-1);
			}
			ans+=mmin[1];//cerr<<mmin[1]<<"    "<<ans<<endl;
		}
		write(ans,'\n');
	}
	return 0;
}