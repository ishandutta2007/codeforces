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
namespace bcj {
	int fa[200002],w[200002];
	inline int findf(int x) {
		if(x==fa[x])return x;
		findf(fa[x]);
		w[x]^=w[fa[x]];
		return fa[x]=fa[fa[x]];
	}
	inline bool merge(int x,int y,int ww) {//cerr<<"merge "<<x<<" "<<y<<" "<<ww<<endl;
		findf(x);
		findf(y);
		ww^=w[x],ww^=w[y];
		x=fa[x],y=fa[y];
		if(x==y){
			if(ww)return false;
			else return true;
		}
		fa[x]=y;
		w[x]=ww;
		return true;
	}
	inline void clear(int n) {
		F(i,1,n)fa[i]=i,w[i]=0;
	}
}
int n,m,x,y,v[200002],f[200002];
vector<int>g[200002],c[200002];
inline void dfs(int pos,int fa){f[pos]=fa;
	for(int i=0;i<g[pos].size();++i)if(g[pos][i]!=fa){
		dfs(g[pos][i],pos);
		if(c[pos][i]!=-1)bcj::merge(pos,g[pos][i],__builtin_popcount(c[pos][i])&1),v[g[pos][i]]=c[pos][i];
	}
}
int main() {
	F(iakioi,1,read()) {
		read(n,m)
		;F(i,1,n)g[i].clear(),c[i].clear();bcj::clear(n);memset(v,0xff,sizeof(v));
		F(i,2,n) {
			read(x);read(y);
			g[x].push_back(y);
			g[y].push_back(x);
			int v=read();//if(v!=-1)v=__builtin_popcount(v)&1;
			c[x].push_back(v);
			c[y].push_back(v);
		}
		dfs(1,0);bool flag=false;
		F(i,1,m){
			read(x);read(y);
			if(!bcj::merge(x,y,read()))flag=true;
		}
		if(flag)puts("NO");
		else{
			puts("YES");
			F(i,1,n)bcj::findf(i);
			F(i,2,n)write(i,' '),write(f[i],' '),write(v[i]!=-1?v[i]:(bcj::w[i]^bcj::w[f[i]]),'\n');
		}
	}
	return 0;
}