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
//#pra gma G CC opti mize(3)
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
int n,m,a[100002],lg[100002];
struct node {
	int l,r;
	inline bool ok(){
		return l==1&&r==n;
	}
}to[35][17][100002];
inline node operator+(const node &x,const node &y){
	return node{min(x.l,y.l),max(x.r,y.r)};
}
inline node merge(int k, int l, int r) {
	if(l>=r)return {n,1};
	int t=lg[r-l];
	return to[k][t][l]+to[k][t][r-(1<<t)];
}

inline ll query(int l, int r) {
	if(l==1&&r==n)return 0;
	if(!merge(34,l,r).ok())return -1;
	ll rt=0;
	UF(i,34,0){
		node x=merge(i,l,r);
		if(!x.ok())l=x.l,r=x.r,rt+=(1ll<<i);
	}
	return rt+1;
}

int main() {
	cin>>n>>m;
	F(i,1,n)read(a[i]);
	F(i,2,n)lg[i]=lg[i>>1]+1;
	F(k,0,34){
		if(!k)F(i,1,n)to[k][0][i]={min(a[i],a[i+1]),max(a[i],a[i+1])};
		else F(i,1,n)to[k][0][i]=merge(k-1,to[k-1][0][i].l,to[k-1][0][i].r);
		F(t,1,16)F(i,1,n-(1<<t)+1)to[k][t][i]=to[k][t-1][i]+to[k][t-1][i+(1<<(t-1))];
	}
	F(i,1,m){
		int l=read(),r=read();
		write(query(l,r),'\n');
	}
	return 0 ;
}