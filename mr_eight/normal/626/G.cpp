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
#define ld long double
int n,q,t,p[200002],l[200002];
long double ans;
#define S pair<long double,int> 
inline long double orz(int i,int t){
	if(t>l[i])return 0;
	return (1.0L*t/(t+l[i])-1.0L*(t-1)/(t+l[i]-1))*p[i];
}
int now[200002];
set<S >lst,nxt;
inline void add(int pos){//cerr<<"add "<<pos<<endl;
	ans+=orz(pos,++now[pos]);
	if(now[pos]!=1)lst.erase({orz(pos,now[pos]-1),pos});
	nxt.erase({orz(pos,now[pos]),pos});
	lst.insert({orz(pos,now[pos]),pos});
	nxt.insert({orz(pos,now[pos]+1),pos});
}
inline void mns(int pos){//cerr<<"mns "<<pos<<endl;
	ans-=orz(pos,now[pos]--);
	lst.erase({orz(pos,now[pos]+1),pos});
	nxt.erase({orz(pos,now[pos]+2),pos});
	if(now[pos])lst.insert({orz(pos,now[pos]),pos});
	nxt.insert({orz(pos,now[pos]+1),pos});
}
inline void modify(int pos,int x){//cerr<<pos<<" "<<now[pos]<<endl;
	if(now[pos])lst.erase({orz(pos,now[pos]),pos});
	nxt.erase({orz(pos,now[pos]+1),pos});
	ans-=1.0L*min(now[pos],l[pos])/(min(now[pos],l[pos])+l[pos])*p[pos];
	l[pos]+=x;
	ans+=1.0L*min(now[pos],l[pos])/(min(now[pos],l[pos])+l[pos])*p[pos];
	if(now[pos])lst.insert({orz(pos,now[pos]),pos});
	nxt.insert({orz(pos,now[pos]+1),pos});
}
int main() {
	cin>>n>>t>>q;
	F(i,1,n)read(p[i]);
	F(i,1,n)read(l[i]);
	F(i,1,n)nxt.insert({orz(i,1),i});
	F(i,1,t){
		add(nxt.rbegin()->second);
	}
	F(i,1,q){
		if(read()==1)modify(read(),1);
		else modify(read(),-1);
		while(*nxt.rbegin()>*lst.begin()){
			int b=nxt.rbegin()->second,a=lst.begin()->second;
			mns(a),add(b);
		}
		printf("%.10Lf\n",ans);
	}
	return 0;
}