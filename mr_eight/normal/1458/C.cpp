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
int a[1002][1002],n,m,temp[4],b[1002][1002];
char s[1000002];
struct S{
	int tp,v;
}x,y,z;
int main() {
	F(iakioi,1,read()){
		x={1,0};
		y={2,0};
		z={3,0};
		cin>>n>>m;
		F(i,1,n)F(j,1,n)read(a[i][j]);
		scanf("%s",s+1);
		F(i,1,m){
			if(s[i]=='L')y.v--;
			if(s[i]=='R')y.v++;
			if(s[i]=='U')x.v--;
			if(s[i]=='D')x.v++;
			if(s[i]=='I')swap(y,z);
			if(s[i]=='C')swap(x,z);
		}
		x.v=(x.v%n+n)%n;
		y.v=(y.v%n+n)%n;
		z.v=(z.v%n+n)%n;
		F(i,1,n)F(j,1,n){
			temp[1]=i;
			temp[2]=j;
			temp[3]=a[i][j];
			b[(temp[x.tp]+x.v-1)%n+1][(temp[y.tp]+y.v-1)%n+1]=(temp[z.tp]+z.v-1)%n+1;
		}
		F(i,1,n){
			F(j,1,n)write(b[i][j],' ');
			putchar('\n');
		}
	}
	return 0;
}