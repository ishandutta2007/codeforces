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
#define pii pair<int,ll>
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
int n,q,x[300002],w[300002],sta[300002],cnt;
ll ans[300002],mmin[300002];
vector<pii>upd[300002],Q[300002];
inline void ins(int l,int r){
	ll v=(x[r]-x[l])*1ll*(w[l]+w[r]);
	upd[l].push_back(make_pair(r,v));
}
inline void add(int pos,ll v){
	while(pos<=n){
		mmin[pos]=min(mmin[pos],v);
		pos+=(-pos&pos);
	}
}
inline ll query(int pos){
	ll rt=LLONG_MAX;
	while(pos){
		rt=min(rt,mmin[pos]);
		pos-=(-pos&pos);
	}
	return rt;
}
int main() {
	cin>>n>>q;
	F(i,1,n)read(x[i],w[i]);
	F(i,1,n){
		while(cnt&&w[sta[cnt]]>=w[i])ins(sta[cnt--],i);
		sta[++cnt]=i;
	}
	cnt=0;
	UF(i,n,1){
		while(cnt&&w[sta[cnt]]>=w[i])ins(i,sta[cnt--]);
		sta[++cnt]=i;
	}
	memset(mmin,0x3f,sizeof(mmin));
	F(i,1,q){
		int t1=read(),t2=read();
		Q[t1].push_back(make_pair(t2,i));
	}
	UF(i,n,1){
		for(auto j:upd[i])add(j.first,j.second);
		for(auto j:Q[i])ans[j.second]=query(j.first);
	}
	F(i,1,q)write(ans[i],'\n');
	return 0;
}