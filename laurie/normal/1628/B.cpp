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
//#include <random>
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
char s[100002][5];
map<int,bool>S,SB;
int main() {
	F(iakioi,1,read()) {
		S.clear();SB.clear();
		int n=read();
		F(i,1,n)scanf("%s",s[i]+1);
		bool flag=false;
		F(i,1,n) {
			if(s[i][2]=='\0'||(s[i][1]==s[i][2]&&s[i][3]=='\0')||(s[i][1]==s[i][3])) {
				flag=true;
				break;
			}
		}
		if(flag)puts("YES");
		else {
			F(i,1,n) {
				if(s[i][3]=='\0') {
					if(S[(int)s[i][2]*1000+(int)s[i][1]]||SB[(int)s[i][2]*1000+(int)s[i][1]]) {
						flag=true;
						break;
					}
					S[(int)s[i][1]*1000+(int)s[i][2]]=true;
				} else {
					if(S[(int)s[i][3]*1000000+(int)s[i][2]*1000+(int)s[i][1]]) {
						flag=true;
						break;
					}
					S[(int)s[i][1]*1000000+(int)s[i][2]*1000+(int)s[i][3]]=true;
					if(S[(int)s[i][3]*1000+(int)s[i][2]]) {
						flag=true;
						break;
					}SB[(int)s[i][1]*1000+(int)s[i][2]]=true;
				}
			}
			puts(flag?"YES":"NO");
		}
	}
	return 0;
}
/*
1
2
ba
aba
*/