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
int now[2002],x,y,n;
double p[2002],q[2002],ans;
priority_queue<pair<double,int> >a,b,c,d,e,f;
// a: a _
// b: b _
// c: b<-a
// d: a<-b
// e: b a
// f: a b
int main() {
	cin>>n>>x>>y;
	F(i,1,n)scanf("%lf",p+i);
	F(i,1,n)scanf("%lf",q+i);
	F(i,1,n)a.push(make_pair(p[i],i)),b.push(make_pair(q[i],i));
	a.push(make_pair(-1e9,0));
	b.push(make_pair(-1e9,0));
	c.push(make_pair(-1e9,0));
	d.push(make_pair(-1e9,0));
	e.push(make_pair(-1e9,0));
	f.push(make_pair(-1e9,0));
	F(i,1,x+y){
		if(x&&y){
			now[0]=0;
			while(now[a.top().second]!=0)a.pop();
			while(now[b.top().second]!=0)b.pop();
			now[0]=2;
			while(now[e.top().second]!=2)e.pop();
			now[0]=1;
			while(now[f.top().second]!=1)f.pop();
			pair<double,int> temp[4]={a.top(),b.top(),e.top(),f.top()};//cerr<<temp[0].second<<endl;
			int qwq=max_element(temp,temp+4)-temp;//cerr<<qwq<<endl;
			if(qwq==0){
				--x;
				ans+=temp[0].first;
				now[temp[0].second]=1;
				d.push(make_pair(q[temp[0].second]-p[temp[0].second],temp[0].second));
				f.push(make_pair(q[temp[0].second]-p[temp[0].second]*q[temp[0].second],temp[0].second));
				a.pop();
			}else if(qwq==1){
				--y;
				ans+=temp[1].first;
				now[temp[1].second]=2;
				c.push(make_pair(p[temp[1].second]-q[temp[1].second],temp[1].second));
				e.push(make_pair(p[temp[1].second]-p[temp[1].second]*q[temp[1].second],temp[1].second));
				b.pop();
			}else{
				ans+=temp[qwq].first;
				now[temp[qwq].second]=3;
				if(qwq==2)e.pop(),--x;else f.pop(),--y;
			}
		}else if(x){
			now[0]=0;
			while(now[a.top().second]!=0)a.pop();
			while(now[b.top().second]!=0)b.pop();
			now[0]=2;
			while(now[c.top().second]!=2)c.pop();
			while(now[e.top().second]!=2)e.pop();
			now[0]=1;
			while(now[f.top().second]!=1)f.pop();
			double temp[4]={a.top().first,b.top().first+c.top().first,e.top().first,f.top().first+c.top().first};
			int qwq=max_element(temp,temp+4)-temp;
			if(qwq==0){
				--x;
				ans+=temp[0];
				int orz=a.top().second;
				now[orz]=1;
				d.push(make_pair(q[orz]-p[orz],orz));
				f.push(make_pair(q[orz]-p[orz]*q[orz],orz));
				a.pop();
			}else if(qwq==2){
				ans+=temp[2];
				now[e.top().second]=3;
				e.pop(),--x;
			}else if(qwq==1){//cerr<<"A";
				ans+=temp[1];
				int orz=b.top().second,sto=c.top().second;
				b.pop();c.pop();
				now[orz]=2;now[sto]=1;
				c.push(make_pair(p[orz]-q[orz],orz));
				e.push(make_pair(p[orz]-p[orz]*q[orz],orz));
				d.push(make_pair(q[sto]-p[sto],sto));
				f.push(make_pair(q[sto]-p[sto]*q[sto],sto));
				--x;
			}else{//cerr<<"B";
				ans+=temp[3];
				int orz=f.top().second,sto=c.top().second;
				f.pop();c.pop();
				now[orz]=3;now[sto]=1;
				d.push(make_pair(q[sto]-p[sto],sto));
				f.push(make_pair(q[sto]-p[sto]*q[sto],sto));
				--x;
			}
		}else{
			now[0]=0;
			while(now[a.top().second]!=0)a.pop();
			while(now[b.top().second]!=0)b.pop();
			now[0]=2;
			while(now[e.top().second]!=2)e.pop();
			now[0]=1;
			while(now[d.top().second]!=1)d.pop();
			while(now[f.top().second]!=1)f.pop();
			double temp[4]={a.top().first+d.top().first,b.top().first,e.top().first+d.top().first,f.top().first};
			int qwq=max_element(temp,temp+4)-temp;
			if(qwq==1){
				--y;
				ans+=temp[1];
				int orz=b.top().second;
				now[orz]=1;
				c.push(make_pair(p[orz]-q[orz],orz));
				e.push(make_pair(p[orz]-p[orz]*q[orz],orz));
				b.pop();
			}else if(qwq==3){
				ans+=temp[3];
				now[f.top().second]=3;
				f.pop(),--y;
			}else if(qwq==0){//cerr<<"C";
				ans+=temp[0];
				int orz=a.top().second,sto=d.top().second;
				a.pop();d.pop();
				now[orz]=1;now[sto]=2;
				d.push(make_pair(q[orz]-p[orz],orz));
				f.push(make_pair(q[orz]-p[orz]*q[orz],orz));
				c.push(make_pair(p[sto]-q[sto],sto));
				e.push(make_pair(p[sto]-p[sto]*q[sto],sto));
				--y;
			}else{//cerr<<"D";
				ans+=temp[2];
				int orz=e.top().second,sto=d.top().second;
				e.pop();d.pop();
				now[orz]=3;now[sto]=2;
				c.push(make_pair(p[sto]-q[sto],sto));
				e.push(make_pair(p[sto]-p[sto]*q[sto],sto));
				--y;
			}
		}
		/*	now[0]=0;
			while(now[a.top().second]!=0)a.pop();
			while(now[b.top().second]!=0)b.pop();
			now[0]=2;
			while(now[c.top().second]!=2)c.pop();
			while(now[e.top().second]!=2)e.pop();
			now[0]=1;
			while(now[f.top().second]!=1)f.pop();
			while(now[d.top().second]!=1)d.pop();
		F(j,1,n)cerr<<now[j]<<" ";cerr<<endl;
		cerr<<a.size()-1<<" "<<b.size()-1<<" "<<c.size()-1<<" "<<d.size()-1<<" "<<e.size()-1<<" "<<f.size()-1<<endl;
		cerr<<a.top().first<<" "<<b.top().first<<" "<<c.top().first<<" "<<d.top().first<<" "<<e.top().first<<" "<<f.top().first<<endl;
		cerr<<x<<" "<<y<<endl<<ans<<endl;*/
	}
	cout<<fixed<<setprecision(10)<<ans;
	return 0;
}
/*
9 7 3
            a     a           a     a     a
0.295 0.017 0.687 0.949 0.210 0.456 0.991 0.381 0.016
            b           b                 b
0.990 0.511 0.968 0.492 0.594 0.964 0.589 0.842 0.271
*/