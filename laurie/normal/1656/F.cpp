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
ll n,a[200002],k[200002],b[200002],sta[200002],cnt;
inline long double p(int x,int y){
	return (b[y]-b[x])/(long double)(k[x]-k[y]);
}
inline ll gety(int x,int y){
	return k[x]*__int128(b[y]-b[x])/(k[x]-k[y])+b[x];
}
int main() {
	F(dasf,1,read()){
		read(n);
		F(i,1,n)read(a[i]);
		sort(a+1,a+n+1);
		ll sum=0;
		F(i,1,n)sum+=a[i];
		ll x=sum+a[1]*(n-2),y=sum+a[n]*(n-2),qwq=0,qaq=0;
		F(i,2,n-1)qaq+=a[i]*a[n];//F(i,1,n-1)qaq+=a[i]*a[n];
		if(x>0||y<0)puts("INF");
		else{
			if(a[1]==a[n])puts("0");
			else if(n==2)write(1ll*a[1]*a[n],'\n');
			else{
			sum+=(n-2)*a[n];
			F(i,1,n-1){
				k[i]=sum;
				b[i]=qwq+qaq+a[1]*a[n];
				qwq+=a[n-i]*a[1];
				qaq-=a[n-i]*a[n];
				sum+=a[1]-a[n];//cerr<<k[i]<<" "<<b[i]<<endl;
			}
			sta[cnt=1]=1;
			F(i,2,n-1){
				while(cnt>1&&p(sta[cnt-1],i)>=p(sta[cnt],i))--cnt;
				sta[++cnt]=i;
			}
			ll ans=-LLONG_MAX;
			F(i,1,cnt-1)ans=max(ans,gety(sta[i],sta[i+1]));
			write(ans,'\n');	
			}
			
		}
	}
	return 0;
}