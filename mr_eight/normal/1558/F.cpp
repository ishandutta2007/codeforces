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
#define vi vector<int>
#define ull unsigned long long
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
int n,mmax[800002],tag[800002],a[200002];
inline void pushdown(int pos){
	tag[pos<<1]+=tag[pos];
	tag[pos<<1|1]+=tag[pos];
	mmax[pos<<1]+=tag[pos];
	mmax[pos<<1|1]+=tag[pos];
	tag[pos]=0;
}
#define pushup(pos) mmax[pos]=max(mmax[pos<<1],mmax[pos<<1|1])
#define mid ((l+r)>>1)
inline void add(int pos,int l,int r,int ql,int qr,int v){
	if(ql<=l&&qr>=r){
		mmax[pos]+=v;
		tag[pos]+=v;
		return;
	}
	if(ql>r||qr<l)return;
	pushdown(pos);
	add(pos<<1,l,mid,ql,qr,v);
	add(pos<<1|1,mid+1,r,ql,qr,v);
	pushup(pos);
}
set<int>s;
inline void update(int pos){
	s.erase(pos);
	if(pos>1)add(1,1,n,1,pos-1,1);
	add(1,1,n,pos,n,-1);
	add(1,1,n,pos,pos,1e9);
}
inline int query(int pos,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r)return mmax[pos];
	if(ql>r||qr<l)return 0;
	pushdown(pos);
	return max(query(pos<<1,l,mid,ql,qr),query(pos<<1|1,mid+1,r,ql,qr));
	
}
inline int query(){
	return query(1,1,n,*s.begin(),n);
}
int main() {
	F(iakioi,1,read()){
		s.clear();
		read(n);
		a[n+1]=1919810;
		F(i,1,n)a[read()]=i;
		F(i,1,n<<2)mmax[i]=-1e9,tag[i]=0;
		F(i,1,n)add(1,1,n,i,i,i+(i&1)),s.insert(i);
		int ans=0;
		F(i,1,n-1){
			update(a[i]);
			ans=max(ans,query());
		}
		write(ans,'\n');
	}
	return 0;
}
/*
1
7
1 5 2 6 7 3 4
*/