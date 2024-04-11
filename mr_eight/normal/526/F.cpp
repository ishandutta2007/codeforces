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
int n,mmin[1200002],tag[1200002],num[1200002],a[300002],sta1[300002],cnt1,sta2[300002],cnt2;
ll ans;
inline void pd(int pos){
	if(tag[pos]){
		mmin[pos<<1]+=tag[pos];
		mmin[pos<<1|1]+=tag[pos];
		tag[pos<<1]+=tag[pos];
		tag[pos<<1|1]+=tag[pos];
		tag[pos]=0;
	}
}
inline void pu(int pos){
	if(mmin[pos<<1]<mmin[pos<<1|1])mmin[pos]=mmin[pos<<1],num[pos]=num[pos<<1];
	else if(mmin[pos<<1]>mmin[pos<<1|1])mmin[pos]=mmin[pos<<1|1],num[pos]=num[pos<<1|1];
	else mmin[pos]=mmin[pos<<1],num[pos]=num[pos<<1]+num[pos<<1|1];
}
#define mid ((l+r)>>1)
inline void build(int pos,int l,int r){
	num[pos]=r-l+1;
	if(l!=r)build(pos<<1,l,mid),build(pos<<1|1,mid+1,r);
}
inline void add(int pos,int l,int r,int ql,int qr,int v){
	if(ql<=l&&qr>=r){
		mmin[pos]+=v;
		tag[pos]+=v;
		return;
	}
	pd(pos);
	if(ql<=mid)add(pos<<1,l,mid,ql,qr,v);
	if(qr>mid)add(pos<<1|1,mid+1,r,ql,qr,v);
	pu(pos);
}
inline int query(int pos){
	return mmin[1]?0:num[1]-pos+1;
}
int main() {
	cin>>n;
	F(i,1,n)a[read()]=read();
	//F(i,1,n)cerr<<a[i]<<" ";cerr<<endl;
	build(1,1,n);
	sta1[0]=sta2[0]=n+1;
	UF(i,n,1){
		if(i!=n)add(1,1,n,i+1,n,-1);
		while(cnt1&&a[sta1[cnt1]]<a[i]){
			add(1,1,n,sta1[cnt1],sta1[cnt1-1]-1,a[i]-a[sta1[cnt1]]);
			--cnt1;
		}
		sta1[++cnt1]=i;
		while(cnt2&&a[sta2[cnt2]]>a[i]){
			add(1,1,n,sta2[cnt2],sta2[cnt2-1]-1,a[sta2[cnt2]]-a[i]);
			--cnt2;
		}
		sta2[++cnt2]=i;
		ans+=query(i);//cerr<<ans<<endl;
	}
	cout<<ans;
	return 0;
}