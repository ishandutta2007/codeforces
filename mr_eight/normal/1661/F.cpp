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
#define pii pair<ll,int>
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
int n,a[200002],d[200002];
ll m;
inline ll calc(int x,int y){
	return 1ll*(x/y)*(x/y)*(y-x%y)+1ll*(x/y+1)*(x/y+1)*(x%y);
}
inline ll qwq(int x,int y){
	return calc(x,y-1)-calc(x,y);
}
inline pii check(ll v){
	ll ak=0,ioi=0;
	F(i,1,n){
		int l=1,r=d[i];
		while(l<r){
			int mid=(l+r+1)>>1;
			if(qwq(d[i],mid)>=v)l=mid;
			else r=mid-1;
		}
		ak+=calc(d[i],l),ioi+=l-1;
	}
	return make_pair(ak,ioi);
}
inline pii checkk(ll v){//cerr<<v<<"   ";
	ll ak=0,ioi=0;
	F(i,1,n){
		int l=1,r=d[i];
		while(l<r){
			int mid=(l+r+1)>>1;
			if(qwq(d[i],mid)>=v)l=mid;
			else r=mid-1;
		}
		ak+=calc(d[i],l),ioi+=l-1;
	//	cerr<<l<<" ";
	}//cerr<<endl;
	return make_pair(ak,ioi);
}
int main() {
	cin>>n;
	F(i,1,n)read(a[i]);
	cin>>m;
	F(i,1,n)d[i]=a[i]-a[i-1];
	sort(d+1,d+n+1);
	ll l=0,r=1e18;
	while(l<r){
		ll mid=(l+r+1)>>1;
		if(check(mid).first<=m)l=mid;
		else r=mid-1;//cerr<<l<<" "<<r<<endl;
	}//cerr<<l<<endl;
	if(l==1e18){
		puts("0");return 0;
	}
	pii x=checkk(l),y=checkk(l+1);//cerr<<x.first<<" "<<x.second<<" "<<y.first<<" "<<y.second<<endl;
	ll v=(x.first-y.first)/(x.second-y.second);
	cout<<x.second+(m-x.first)/v;
	return 0;
}