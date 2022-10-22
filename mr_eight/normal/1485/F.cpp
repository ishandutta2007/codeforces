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
#define mod 1000000007
ll f[200002],g[200002],h[200002],n,b[200002],pre[200002],fa[200002];
map<ll,ll>lst;
int main() {
	F(qwq,1,read()) {
		cin>>n;
		F(i,1,n) {
			f[i]=g[i]=0;
			read(b[i]);
		}
		F(i,1,n)pre[i]=pre[i-1]+b[i];
		lst.clear();
		F(i,1,n){
			if(pre[i]==0){
				fa[i]=lst[pre[i]];
				lst[pre[i]]=i;
			}else{
				if(lst[pre[i]])fa[i]=lst[pre[i]];
				else fa[i]=-1;
				lst[pre[i]]=i;
			}
		}f[0]=g[0]=1;
		lst.clear();
		F(i,1,n){
			f[i]=f[i-1]*2-g[i-1]+mod;
			f[i]%=mod;
			h[i]=f[i-1];
			if(fa[i]>0)g[i]=f[fa[i]],g[i]%=mod;
			else if(fa[i]==0)g[i]=f[fa[i]],g[i]%=mod;
		}write(f[n],'\n');
	}

	return 0;
}