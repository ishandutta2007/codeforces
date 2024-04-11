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
#define ld long double
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
int n,m,t1,t2;
ld t3,t4;
#define mid (l+r>>1)
struct node{
	long double v;
	node *lc,*rc;
	node(){
		v=1;
		lc=rc=NULL;
	}
	inline void add(int l,int r,int ql,int qr,ld vv){
		if(ql<=l&&qr>=r){
			v*=vv;
			return;
		}if(ql<=mid){
			if(!lc)lc=new node;
			lc->add(l,mid,ql,qr,vv);
		}if(qr>mid){
			if(!rc)rc=new node;
			rc->add(mid+1,r,ql,qr,vv);
		}
	}
	inline long double query(int l,int r,int q){
		if(l==r)return v;
		if(q<=mid){
			if(!lc)lc=new node;
			return v*lc->query(l,mid,q);
		}else{
			if(!rc)rc=new node;
			return v*rc->query(mid+1,r,q);
		}
	}
}L,R;
set<int>fk;
ld ans;
int main() {
	cin>>n>>m;
	F(i,1,n){
		read(t1);read(t2);read(t3);read(t4);
		t3/=100;
		t4/=100;
		L.add(-1000000000,1000000000,max(t1-t2,-1000000000),max(t1-1,-1000000000),1-t3);
		R.add(-1000000000,1000000000,min(t1+1,1000000000),min(t1+t2,1000000000),1-t4);
	}F(i,1,m){
		read(t1);read(t2);
		ans+=t2*L.query(-1000000000,1000000000,t1)*R.query(-1000000000,1000000000,t1);
	}cout<<fixed<<setprecision(20)<<ans;
	return 0;
}