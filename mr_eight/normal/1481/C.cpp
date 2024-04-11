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
int n,m,a[100002],b[100002],c[100002],ans[100002],qwq;
int vis[100002];
vector<int>res[100002];
int main() {
	F(qwqfgd,1,read()) {
		read(n);
		read(m);
		F(i,1,n)vis[i]=0,res[i].clear();
		F(i,1,n)read(a[i]);
		F(i,1,n)read(b[i]),vis[b[i]]=i;
		F(i,1,n) {
			if(a[i]!=b[i]) {
				res[b[i]].push_back(i);
			}
		}
		F(i,1,m-1)read(c[i]);
		read(qwq);
		F(i,1,m-1) {

			if(res[c[i]].size()) {
				ans[i]=res[c[i]][res[c[i]].size()-1];
				res[c[i]].pop_back();
			} else if(res[qwq].size())ans[i]=res[qwq][0];
			else ans[i]=vis[qwq];
		}
		if(!vis[qwq])puts("no");
		else {
			if(res[qwq].size()) {
				ans[m]=res[qwq][res[qwq].size()-1];
				res[qwq].pop_back();
			} else ans[m]=vis[qwq];
			F(i,1,n) {
				if(res[i].size()) {
					puts("no");
					goto orz;
				}
			}
			puts("yes");
			F(i,1,m)write(ans[i],' ');puts("");

		}orz:
			;
	}
	return 0;
}