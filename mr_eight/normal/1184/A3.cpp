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
int n,m,a[100002];
ll b[100002];
char s[100002],t[100002];
mt19937 rd(114514);
inline bool isp(int x) {
	F(i,2,sqrt(x))if(x%i==0)return false;
	return true;
}
inline ll pw(ll x,ll p,ll mod) {
	ll rt=1;
	while(p) {
		if(p&1)rt=rt*x%mod;
		x=x*x%mod;
		p>>=1;
	}
	return rt;
}
inline void solve(int x) {
	int p=(m+x-1)/x*x+1;

	memset(b,0,sizeof(b));
	F(i,0,n-1)b[i%x]+=a[i];
	while(p<=200000) {
		while(!isp(p))p+=x;
		int r;
		while((r=pw(rd()%(p-2)+2,(p-1)/x,p))==1);
		for(ll v=r;; v=v*r%p) {
			if(v>=2&&v<=p-2) {
				ll qwq=0;
				UF(i,x-1,0)qwq=(qwq*v+b[i])%p;
				if(qwq==0) {
					write(p,' ');
					write(v,'\n');
					exit(0);
				}
			}
			if(v==1)break;
		}
		p+=x;
	}

}
int main() {
	cin>>n>>m;
	scanf("%s",s);
	scanf("%s",t);
	F(i,0,n-1)a[i]=s[i]-t[i];
	F(i,3,1e9)if(isp(i))solve(i);
	return 0;
}