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
#define pii pair<long double,long double>
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
pii a[10002],v,O;
long double sum,x,y,eps,pre[10002],A0;
int n,q;
inline long double operator*(pii x,pii y){
	return 1ll*x.first*y.second-1ll*y.first*x.second;
}
inline pii operator+(pii x,pii y){
	return make_pair(x.first+y.first,x.second+y.second);
}
inline pii operator-(pii x,pii y){
	return make_pair(x.first-y.first,x.second-y.second);
}
inline pii operator*(pii x,long double y){
	return make_pair(x.first*y,x.second*y);
}
inline long double angle(pii v){
	return atan2(v.second,v.first);
}
inline long double angle(long double x,long double y){
	return atan2(y,x);
}
inline long double A(long double x){
	return x>=0?x:-x;
}
inline bool cmp(pii x,pii y){
	long double X=(a[0]-v)*x,Y=(a[0]-v)*y;
	if((X>=0)!=(Y>=0))return X>Y;
	if(X==0&&Y==0){
		return (x.first-y.first)*(a[0]-v).first+(x.second-y.second)*(a[0]-v).second>0;
	}
	return x*y>0;
}
inline long double check(long double D){
	pii d=make_pair(cos(D),sin(D));
	if(A0>=D&&A0-0.01<=D)d=a[0]-v;
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(cmp(a[mid]-v,d))l=mid+1;
		else r=mid;
	}
	int p1=l;
	l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(cmp(a[mid]-v,O-d))l=mid+1;
		else r=mid;
	}
	int p2=l;
	long double res;
	if(p2>=p1)res=pre[p2-1]-pre[p1];
	else res=pre[p2-1]+sum-pre[p1];
	double s1=(d*(a[p1]-v))/((a[p1-1]-v)*d+d*(a[p1]-v)),s2=((a[p2-1]-v)*(O-d))/((a[p2-1]-v)*(O-d)+(O-d)*(a[p2]-v));
	res+=(a[p1-1]*a[p1]*s1);//cerr<<(a[p1-1]-v).first<<" "<<(a[p1-1]-v).second<<" "<<d.first<<" "<<d.second<<endl;
	res+=(a[p2-1]*a[p2]*s2);
	res+=(a[p2-1]*(1-s2)+a[p2]*s2)*(a[p1-1]*s1+a[p1]*(1-s1));
//	cerr<<res<<endl;
	return res-(sum-res);
}
void debug(){
	cin>>a[0].first>>a[0].second;
	while(true){
		pii x,y;
		cin>>x.first>>x.second>>y.first>>y.second;
		if(cmp(x,y))puts("x<y");
		else puts("x>y");
	}
}
inline long double r(long double a){
	return a/Pi*180;
}
int main() {
//	freopen("cookie.in","r",stdin);
//	freopen("cookie.out","w",stdout);
//	debug();
	cin>>n>>q;
	F(i,0,n-1)a[i].first=read(),a[i].second=read();
	reverse(a,a+n);
	a[n]=a[0];
	F(i,0,n-1)pre[i+1]=pre[i]+a[i]*a[i+1];
	sum=pre[n];
	eps=1e-6*sum;
	F(iakioi,1,q){
		x=read(),y=read();
		v=make_pair(x,y);
		long double a0=angle(a[0]-v),a1=a0+Pi;A0=a0;
		long double temp=check(a0);
	//	cerr<<check(a0)<<" "<<check(a1)<<endl;
		if(A(temp)<=eps){
			while(a0<0)a0+=Pi;
			while(a0>=Pi)a0-=Pi;
			if(a0>=3.14159)a0=0;
			printf("%.10Lf\n",a0);//cerr<<fixed<<setprecision(10)<<r(a0)<<endl;
			continue;
		}
		while(true){
			long double mid=(a0+a1)/2;
			long double v=check(mid);
			if(A(v)<=eps){
				while(mid<0)mid+=Pi;
				while(mid>=Pi)mid-=Pi;
				if(mid>=3.14159)mid=0;
				printf("%.10Lf\n",mid);//cerr<<fixed<<setprecision(10)<<r(mid)<<endl;
				break;
			}
			if((v>=0)==(temp>=0))a0=mid;
			else a1=mid;
		}
	}
	return 0;
}