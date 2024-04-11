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
int n,m;
namespace fw {
	ll sum1[100002],sum2[100002];
	inline void add(int pos,int v) {
		ll temp=1ll*pos*v;
		while(pos<=n) {
			sum1[pos]+=temp;
			sum2[pos]+=v;
			pos+=(-pos&pos);
		}
	}
	inline void add(int l,int r,int v) {
		add(l,v);
		add(r+1,-v);
	}
	inline ll query(int pos) {
		ll t1=0,t2=0;int p=pos;
		while(pos) {
			t1+=sum1[pos];
			t2+=sum2[pos];
			pos-=(-pos&pos);
		}
		return t2*(p+1)-t1;
	}
	inline ll query(int l,int r) {
		return query(r)-query(l-1);
	}
}
using fw::add;
using fw::query;
struct node {
	mutable int l,r,v;
	inline bool operator<(const node &b)const {
		return l<b.l;
	}
};
set<node>S;
#define iter set<node>::iterator
inline iter cutl(iter it,int p){
	if(it->r<=p)return it;
	node temp={p+1,it->r,it->v};
	it->r=p;
	S.insert(temp);
	return it;
}
inline iter cutr(iter it,int p){
	if(it->l>=p)return it;
	node temp={it->l,p-1,it->v};
	it->l=p;
	S.insert(temp);
	return it;
}
inline iter getit(int x){
	return --S.upper_bound({x,0,0});
}
inline int ab(int x){
	return x>0?x:-x;
}
inline void modify(int l,int r,int v) {
	iter x=cutr(getit(l),l),y=cutl(getit(r),r);
	for(iter it=x;it!=y;++it){
		add(it->l,it->r,ab(it->v-v));
	}
	add(y->l,y->r,ab(y->v-v));
	S.erase(x,++y);
	S.insert({l,r,v});
}
int main() {
	cin>>n>>m;
	F(i,1,n)S.insert({i,i,i});
	F(i,1,m){
		if(read()==1){
			int l=read(),r=read(),v=read();
			modify(l,r,v);
		}else{
			int l=read(),r=read();
			write(query(l,r),'\n');
		}
	}
	return 0;
}