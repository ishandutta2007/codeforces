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
string a,b,c;
int cnt[4],tot[2],n;
inline void solve(string a,string b,char c){
	c+='0';
	ri i=0,j=0;
	while(i<n+n||j<n+n){
		while(i<n+n&&a[i]!=c)putchar(a[i++]);
		while(j<n+n&&b[j]!=c)putchar(b[j++]);
		if(i<n+n||j<n+n){
			putchar(c);
			++i;
			++j;
		}
	}putchar('\n');
}
int main() {
	F(qwqwq,1,read()){
		read(n);
		cin>>a>>b>>c;memset(cnt,0,sizeof(cnt));
		F(i,0,n+n-1){
			if(a[i]=='1')cnt[1]++;
			if(b[i]=='1')cnt[2]++;
			if(c[i]=='1')cnt[3]++;
		}if(cnt[1]>n&&cnt[2]>n){
			solve(a,b,1);
		}
		else if(cnt[1]>n&&cnt[3]>n){
			solve(a,c,1);
		}
		else if(cnt[2]>n&&cnt[3]>n){
			solve(b,c,1);
		}else if(cnt[1]>n){
			solve(b,c,0);
		}else if(cnt[2]>n){
			solve(a,c,0);
		}else{
			solve(a,b,0);
		}
	}
	return 0;
}