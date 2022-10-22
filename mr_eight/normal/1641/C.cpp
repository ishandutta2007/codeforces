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
int n,q,x[200002],y[200002],m,tag[200002],res[200002],mmin[800009];
set<int>S;
#define mid ((l+r)>>1)
inline void add(int pos,int l,int r,int q,int v){
	mmin[pos]=min(mmin[pos],v);
	if(l==r){
		return;
	}
	if(q<=mid)add(pos<<1,l,mid,q,v);
	else add(pos<<1|1,mid+1,r,q,v);
}
inline int query(int pos,int l,int r,int ql,int qr){
	if(ql>r||qr<l)return INT_MAX;
	if(ql<=l&&qr>=r)return mmin[pos];
	return min(query(pos<<1,l,mid,ql,qr),query(pos<<1|1,mid+1,r,ql,qr));
}
int main() {
	memset(mmin,0x3f,sizeof(mmin));
	cin>>n>>q;
	F(i,0,n+1)S.insert(i);
	F(i,1,q) {
		if(read()==0) {
			int l=read(),r=read(),xx=read();
			if(xx==0) {
				auto ed=S.upper_bound(r);
				for(auto i=S.lower_bound(l); i!=ed;) {
					auto j=i++;
					S.erase(j);
				}
			} else {
				add(1,0,n+1,l,r);
			}
		} else {
			int x=read();
			auto i=S.lower_bound(x);
			if(*i!=x)puts("NO");
			else{
				auto j=i--;
				++j;
				if(query(1,0,n+1,(*i)+1,x)<*j)puts("YES");
				else puts("N/A");
			}
		}

	}
	return 0;
}