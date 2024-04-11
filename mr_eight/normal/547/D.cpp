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
const int MAXN=1000005,MAXM=1200005;
int head[MAXN],nxt[MAXM],n,m,to[MAXM],x,y,deg[MAXN],sta[MAXN],cnt,k;
bool vis[MAXM>>1],ans[MAXM>>1];
int tp;
inline void dfs1(int pos) {
	for(int &e=head[pos]; e; e=nxt[e]) {
		if(vis[e>>1])continue;
		int temp=e;
		vis[e>>1]=1;
		dfs1(to[e]);
		sta[++cnt]=temp;
		if(pos<=200000&&pos&&to[temp]>200000)ans[temp>>1]=1;
	}
}
int main() {
	// tp==1
	// tp==2
	tp=1;
	cin>>m;
	n=400000;
	F(i,1,m) {
		read(x);
		read(y);
		y+=200000;
		++deg[x],++deg[y];
		to[i<<1]=y;
		nxt[i<<1]=head[x];
		head[x]=(i<<1);
		to[i<<1|1]=x;
		nxt[i<<1|1]=head[y];
		head[y]=(i<<1|1);
	}int M=m;
	F(i,1,n) {
		if(deg[i]&1) {
			x=0,y=i;++m;
			#define i m
			++deg[x],++deg[y];
			to[i<<1]=y;
			nxt[i<<1]=head[x];
			head[x]=(i<<1);
			to[i<<1|1]=x;
			nxt[i<<1|1]=head[y];
			head[y]=(i<<1|1);
			#undef i
		}
	}
	F(i,0,n)dfs1(i);
	F(i,1,M)putchar(ans[i]?'r':'b');
	return 0;
}