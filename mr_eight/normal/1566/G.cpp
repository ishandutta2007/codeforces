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
int n,m,q,t1,t2,t3;
struct edge{
	int x,y,w;
	edge(int xx,int yy,int ww){
		if(xx>yy)swap(xx,yy);
		x=xx,y=yy,w=ww;
	}
	inline bool operator<(const edge &b)const{
		return w!=b.w?w<b.w:(x!=b.x?x<b.x:y<b.y);
	}
};
inline bool ok(edge a,edge b){
	return a.x!=b.x&&a.x!=b.y&&a.y!=b.x&&a.y!=b.y;
}
#define N 100002
set<edge>now[N],res[N],tot;
map<pii,int>w;
inline void ins(int pos,edge a){
	if(now[pos].size()<3){
		now[pos].insert(a);
		if(now[a.x^a.y^pos].count(a))tot.insert(a);
		return;
	}
	if(a<*now[pos].rbegin()){
		edge temp=*--now[pos].end();
		now[pos].erase(temp);
		if(tot.count(temp))tot.erase(temp);
		res[pos].insert(temp);
		now[pos].insert(a);
		if(now[a.x^a.y^pos].count(a))tot.insert(a);
		return;
	}
	res[pos].insert(a);
}
inline void era(int pos,edge a){
	if(now[pos].count(a)){
		now[pos].erase(a);
		if(tot.count(a))tot.erase(a);
		if(!res[pos].empty()){
			edge temp=*res[pos].begin();
			res[pos].erase(temp);
			now[pos].insert(temp);
			if(now[temp.x^temp.y^pos].count(temp))tot.insert(temp);
		}
		return;
	}
	res[pos].erase(a);
}
inline ll sum(int pos){
	if(now[pos].size()<3)return 1e18;
	ll rt=0;
	for(edge a:now[pos])rt+=a.w;
	return rt;
}
inline void getans(){
	edge A=*tot.begin();
	int x=A.x,y=A.y;
	ll ans=min(sum(x),sum(y));
	for(edge a:now[x])for(edge b:now[y])if(ok(a,b))ans=min(ans,0ll+a.w+b.w);
	for(edge a:tot){
		if(ok(A,a)){
			ans=min(ans,0ll+A.w+a.w);
			break;
		}
	}
	write(ans,'\n');
}
int main() {
	cin>>n>>m;
	F(i,1,m){
		read(t1);read(t2);read(t3);
		if(t1>t2)swap(t1,t2);
		w[make_pair(t1,t2)]=t3;
		edge a(t1,t2,t3);
		ins(t1,a);ins(t2,a);
	}
	getans();
	F(link_ak_ioi,1,read()){
		if(read()==0){
			read(t1);read(t2);
			if(t1>t2)swap(t1,t2);
			edge a(t1,t2,w[make_pair(t1,t2)]);
			era(t1,a);era(t2,a);
		}else{
			read(t1);read(t2);read(t3);
			if(t1>t2)swap(t1,t2);
			w[make_pair(t1,t2)]=t3;
			edge a(t1,t2,t3);
			ins(t1,a);ins(t2,a);	
		}
		getans();
	}
	return 0;//I AK IOI
}