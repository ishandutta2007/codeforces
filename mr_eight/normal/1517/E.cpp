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
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
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
ll a[200002],n,pre[200002],jk[200002],tot,ans;
int main() {
	F(iakioi,1,read()) {
		cin>>n;
		ans=0;
		F(i,1,n)read(a[i]),pre[i]=a[i]+pre[i-1];
		jk[1]=a[1];
		F(i,2,n)jk[i]=a[i]+jk[i-2];
		tot=pre[n]/2;
		if(pre[n]%2==0)--tot;
		F(i,1,n) {
			ri l=-1,r=(n-i)/2;
			while(l<r) {
				ri mid=(l+r+1)/2;
				if(pre[i]+jk[i+mid*2]-jk[i]<=tot)l=mid;
				else r=mid-1;
			}
			ans+=l+1;
			if(i>n-3)continue;
			l=-1,r=(n-3-i)/2;
			while(l<r) {
				ri mid=(l+r+1)/2;
				if(pre[i]+jk[i+mid*2]-jk[i]+a[n]<=tot)l=mid;
				else r=mid-1;
			}
			ans+=l+1;
		}
		F(i,2,n) {
			ri l=-1,r=(n-i)/2;
			while(l<r) {
				ri mid=(l+r+1)/2;
				if(pre[i]+jk[i+mid*2]-jk[i]-a[1]<=tot)l=mid;
				else r=mid-1;
			}ans+=l+1; l=-1,r=(n-3-i)/2;if(i>n-3)continue;
			while(l<r) {
				ri mid=(l+r+1)/2;
				if(pre[i]+jk[i+mid*2]-jk[i]-a[1]+a[n]<=tot)l=mid;
				else r=mid-1;
			}
			ans+=l+1;
		}UF(i,n,3)ans+=(pre[n]-pre[i-1]<=tot);
		write((ans+1)%998244353,'\n');
	}

	return 0;
}