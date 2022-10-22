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
int n;
char c[1114514],ans1[200002],ans2[200002];
bool dp[200002][12][12],op[200002][12][12];
int main() {
	F(qwq,1,read()){
		read(n);
		scanf("%s",c+1);
		dp[0][0][0]=1;
		ri tot=0;
		F(i,1,n)if(c[i]=='1')++tot;
		if(c[1]=='0'||c[n]=='0'||(tot&1))puts("NO");
		else{
			int x=1,y=1;
			ans1[1]=ans2[1]='(';
			ans1[n]=ans2[n]=')';
			ans1[n+1]=ans2[n+1]='\0';
			F(i,2,n-1){
				if(c[i]=='1'){
					if(min(x,y)<1||(x==1&&y==1))++x,++y,ans1[i]=ans2[i]='(';
					else --x,--y,ans1[i]=ans2[i]=')';
				}else{
					if(x>y)--x,++y,ans1[i]=')',ans2[i]='(';
					else --y,++x,ans2[i]=')',ans1[i]='(';
				}
				
			}if(x!=1||y!=1){
				puts("NO");
			}else{
				puts("YES");
				puts(ans1+1);puts(ans2+1);
			}
		}
	}
	return 0;
}