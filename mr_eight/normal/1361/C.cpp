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
int n,u[1200002],v[1200002],ans,ed[1200002],cnt,o[1200002];
multiset<int>g[1200002],p[1200002];vector<int>gg[1200002];
bool vis[1200002];
inline void dfs(ri pos) {
	vis[pos]=1;
	for(auto i:gg[pos])if(!vis[i])dfs(i);
}
inline void getans(ri pos) {
	while(!p[pos].empty()) {
		ri op=*p[pos].begin(),nxt=op-1;if(op&1)nxt+=2;
		p[pos].erase(p[pos].begin());
		p[o[nxt]].erase(p[o[nxt]].find(nxt));
		g[pos].erase(g[pos].find(o[nxt]));
		g[o[nxt]].erase(g[o[nxt]].find(pos));
		getans(o[nxt]);
		write(nxt,' ');
		write(op,' ');
	}

}
int main() {
	cin>>n;
	F(i,1,n)read(u[i]),read(v[i]);
	F(i,1,20) {
		ri S=(1<<i)-1;
		F(i,0,S)gg[i].clear();
		F(i,0,S)ed[i]=0;
		F(i,1,n)ed[u[i]&S]++,gg[u[i]&S].push_back(v[i]&S);
		F(i,1,n)ed[v[i]&S]++,gg[v[i]&S].push_back(u[i]&S);
		F(i,0,S)if(ed[i]&1)goto fuckccf;
		memset(vis,0,sizeof(vis));
		cnt=0;
		dfs(u[1]&S);
		F(i,1,n)if(!vis[u[i]&S])goto fuckccf;
		ans=i;
fuckccf:
		;

	}
	cout<<ans<<endl;
	ri S=(1<<ans)-1;
	F(i,0,S)ed[i]=0;
	F(i,1,n)ed[u[i]&S]++,g[u[i]&S].insert(v[i]&S),p[u[i]&S].insert(2*i-1),o[2*i-1]=u[i]&S;
	F(i,1,n)ed[v[i]&S]++,g[v[i]&S].insert(u[i]&S),p[v[i]&S].insert(2*i),o[2*i]=v[i]&S;
	memset(vis,0,sizeof(vis));
	cnt=0;
	getans(u[1]&S);
	return 0;
}