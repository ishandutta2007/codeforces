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
int mmin[400002],tag[400002];
int n,m;
ll a[100002],sum[100002];
vector<ll>b[100002];
#define mid ((l+r)>>1)
inline void build(int pos,int l,int r){
	if(l==r){
		mmin[pos]=n-l+1;
		return;
	}
	build(pos<<1,l,mid);build(pos<<1|1,mid+1,r);
	mmin[pos]=min(mmin[pos<<1],mmin[pos<<1|1]);
}
inline void add(int pos,int l,int r,int q,int v){
	if(q>=r){
		mmin[pos]+=v;
		tag[pos]+=v;
		return;
	}
	if(tag[pos]){
		tag[pos<<1]+=tag[pos];
		mmin[pos<<1]+=tag[pos];
		tag[pos<<1|1]+=tag[pos];
		mmin[pos<<1|1]+=tag[pos];
		tag[pos]=0;
	}
	add(pos<<1,l,mid,q,v);
	if(q>mid)add(pos<<1|1,mid+1,r,q,v);
	mmin[pos]=min(mmin[pos<<1],mmin[pos<<1|1]);
}
inline bool query(){
	return mmin[1]>=0;
}
int main() {F(iakioi,1,read()){
	cin>>n>>m;
	F(i,1,(n+1)*4)mmin[i]=tag[i]=0;
	F(i,1,m)sum[i]=0,b[i].clear();
	F(i,1,n)read(a[i]);
	sort(a+1,a+n+1);
	build(1,1,n+1);
	F(i,1,m){
		F(j,1,read()){
			b[i].push_back(read());
			sum[i]+=b[i].back();
		}
		add(1,1,n+1,lower_bound(a+1,a+n+1,(sum[i]+(int)b[i].size()-1)/(int)b[i].size())-a,-1);
	}
	F(i,1,m){
		for(ll j:b[i]){
			add(1,1,n+1,lower_bound(a+1,a+n+1,(sum[i]+(int)b[i].size()-1)/b[i].size())-a,1);
			sum[i]-=j;
			add(1,1,n+1,lower_bound(a+1,a+n+1,(sum[i]+(int)b[i].size()-2)/((int)b[i].size()-1))-a,-1);
			putchar('0'+query());
			add(1,1,n+1,lower_bound(a+1,a+n+1,(sum[i]+(int)b[i].size()-2)/((int)b[i].size()-1))-a,1);
			sum[i]+=j;
			add(1,1,n+1,lower_bound(a+1,a+n+1,(sum[i]+(int)b[i].size()-1)/(int)b[i].size())-a,-1);
		}
	}puts("");
}
	
	return 0;
}
/*
2
5 5
1 2 3 4 5
2 1 2
2 2 3
2 3 4
2 4 5
2 1 5
*/