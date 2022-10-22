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
int n,p[200002],t[200002],a[200002];
long double v[200002],w[200002];
inline bool cmp(int x,int y){
	return 1ll*p[x]*t[y]==1ll*p[y]*t[x]?p[x]<p[y]:1ll*p[x]*t[y]>1ll*p[y]*t[x];
}
inline bool cmp2(int x,int y){
	return p[x]==p[y]?v[x]>v[y]:p[x]<p[y];
}
inline bool qwq(int x,int y){
	return 1ll*p[x]*t[y]==1ll*p[y]*t[x];
}
int main() {
	cin>>n;
	ll sum=0,now=0;
	F(i,1,n)read(p[i]);
	F(i,1,n)read(t[i]),sum+=t[i];
	F(i,1,n)a[i]=i;
	sort(a+1,a+n+1,cmp);
	F(i,1,n){
		now+=t[a[i]];
		if(i==1||!qwq(a[i],a[i-1]))v[a[i]]=1.0L*now/sum;
		else v[a[i]]=v[a[i-1]]+1.0L*(t[a[i]]-t[a[i-1]])/sum;
	}
	UF(i,n,1){
		if(i==n||!qwq(a[i],a[i+1]))w[a[i]]=1.0L*now/sum;
		else w[a[i]]=w[a[i+1]];
		now-=t[a[i]];
	}
	sort(a+1,a+n+1,cmp2);
	long double c=1;
	F(i,1,n-1)if(p[a[i]]!=p[a[i+1]]){//cerr<<(p[a[i+1]]-p[a[i]])/(p[a[i+1]]*w[a[i+1]]-p[a[i]]*v[a[i]])<<endl;
		if(p[a[i+1]]*w[a[i+1]]>p[a[i]]*v[a[i]])c=min(c,(p[a[i+1]]-p[a[i]])/(p[a[i+1]]*w[a[i+1]]-p[a[i]]*v[a[i]]));
	}
	cout<<fixed<<setprecision(20)<<c;
	return 0;
}