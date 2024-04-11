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
vector<int>g[300002];
int n,t1,t2,cnt;
char c[300002];

inline void dfs(int pos){
	cnt++;
	F(i,0,g[pos].size()-1)if(c[g[pos][i]]==1)c[pos]=2;
	if(!c[pos])c[pos]=1;
	F(i,0,g[pos].size()-1)if(!c[g[pos][i]])dfs(g[pos][i]);
}
int main() {
F(qwq,1,read()){
	read(n);cnt=1;
	F(i,1,n)g[i].clear(),c[i]=0;
	F(qwqwq,1,read()){
		read(t1),read(t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	c[1]=1;
	F(i,0,g[1].size()-1)if(!c[g[1][i]])dfs(g[1][i]);
	if(cnt==n){
		puts("YES");cnt=0;F(i,1,n)if(c[i]==1)cnt++;write(cnt,'\n');
		F(i,1,n)if(c[i]==1)write(i,' ');puts("");
	}else puts("NO");
}
	return 0;
}