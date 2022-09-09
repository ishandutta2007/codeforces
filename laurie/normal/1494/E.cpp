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
int n,m,ans1,ans2,t1,t2,kkk;
map<int,char>g[200002],in[200002];
map<int,int>tot[200002];
char ch;
inline int mp(char x,char y){
	return x*1331+y;
}
int main() {
	cin>>n>>m;
	F(i,1,m) {
		cin>>ch;
		if(ch=='+') {
			read(t1);
			read(t2);
			cin>>ch;
			g[t1][t2]=ch;
		//	in[t2][t1]=cj;
			if(g[t2].count(t1)) {
				kkk++;
				char temp=g[t2][t1];
				if(temp==ch) {
					ans1++;
				}
				ans2+=tot[t2][mp(ch,temp)];
				ans2+=tot[t1][mp(temp,ch)];
				tot[t2][mp(ch,temp)]++;
				tot[t1][mp(temp,ch)]++;
			}

		} else if(ch=='-') {
			read(t1);
			read(t2);
			ch=g[t1][t2];
			if(g[t2].count(t1)) {
				kkk--;
				char temp=g[t2][t1];
				if(temp==ch) {
					ans1--;
				}
				tot[t2][mp(ch,temp)]--;
				tot[t1][mp(temp,ch)]--;
				ans2-=tot[t2][mp(ch,temp)];
				ans2-=tot[t1][mp(temp,ch)];
			}
			g[t1].erase(t2);
		} else {
			read(t1);
			if(t1==2){
				if(ans1)puts("YES");else puts("NO");
			}else{
				if(t1&1){if(ans1||kkk)puts("YES");else puts("NO");}
				else {if(ans1)puts("YES");else puts("NO");}
			}
		}
	}
	return 0;
}