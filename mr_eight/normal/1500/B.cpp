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
//#pra gma G CC opti mize(3)
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
	char _n_u_m_[40];
	template<class T>
	inline void write(T x ) {
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
ll n,m,a[500002],b[500002],p[1000002],mns[1000002],g,l,k,ans;
inline ll gcd(ll x,ll y) {
	return y?gcd(y,x%y):x;
}
int main() {
	cin>>n>>m>>k;
	g=gcd(m,n);
	l=n*m/g;
	F(i,1,n)read(a[i]);
	F(i,1,m)read(b[i]);
	if(n<m) {
		swap(n,m);
		F(i,1,500000)swap(a[i],b[i]);
	}
	F(i,1,n)p[a[i]]=i;
	F(i,1,m) {
		if(p[b[i]]) {
			mns[(p[b[i]]-i+n)%n]++;
		}
	}
	ll tot=0;
	for(ri i=0; i<n; i+=g)tot+=m-mns[i];
	ans=(k-1)/tot*l;
	k-=(k-1)/tot*tot;
	a[0]=a[n];
	for(ri i=0;; i=(i+m)%n) {
		if(k>m-mns[i]) {
			k-=m-mns[i];
			ans+=m;
		} else {
			F(j,1,m) {
				if(a[(j+i)%n]!=b[j])k--;
				if(!k) {

					cout<<ans+j;
					return 0;

				}
			}
			return 0;
		}
	}
	return 0;
}