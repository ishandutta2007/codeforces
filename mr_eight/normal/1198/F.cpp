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
#include <random>
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
int n,a[100002],p[100002],cnt,ans[100002];
pii v[100002];
mt19937 rd(114514);
inline bool cmp(int x,int y){
	return a[x]<a[y];
}
int main(){
	cin>>n;
	int G=0;
	F(i,1,n){
		read(a[i]);
		p[i]=i;
		G=__gcd(G,a[i]);
	}
	if(G!=1){
		puts("NO");
		return 0;
	}
	sort(p+1,p+n+1,cmp);
	F(i,1,n)if(i==1||a[p[i]]!=a[p[i-2]])v[++cnt]={p[i],a[p[i]]};
	while(1.0*clock()/CLOCKS_PER_SEC<=0.45){
		shuffle(v+1,v+cnt+1,rd);
		int g=0,gg=0;
		F(i,1,cnt){
			g=__gcd(g,v[i].second);
			if(g==1){
				F(j,i+1,cnt)gg=__gcd(gg,v[j].second);
				if(gg==1){
					puts("YES");
					F(k,1,i)ans[v[k].first]=1;
					F(i,1,n)write(ans[i]+1,' ');
					return 0;
				}
				break;
			}
		}
	}
	puts("NO");
    return 0;
}