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
#define pll pair<ll,ll>
#define cp complex<double>
#define vi vector<int>
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
vector<int>g[300002],c[300002];
vector<pll >co[300002];
ll w[300002],t3,t4;
pll up[300002];
pll dp[300002][2][20];
int fa[300002][20],d[300002];
int n,q,t1,t2;
inline pll merge(pll x,pll y){
	return make_pair(min(x.first+y.first,x.second+y.second),min(x.second+y.first,x.first+y.second));
}
inline void make_tree(int pos,int f){
	d[pos]=d[f]+1;
	for(ri i=0;i<g[pos].size();++i){
		if(g[pos][i]!=f){
			fa[g[pos][i]][0]=pos;
			c[pos].push_back(g[pos][i]);
			up[g[pos][i]]=co[pos][i];
			make_tree(g[pos][i],pos);
		}
	}
}
inline void dfs1(int pos){
	for(int i:c[pos]){
		dfs1(i);
		w[pos]=min(w[pos],w[i]+up[i].first+up[i].second);
	}
}
inline void dfs2(int pos){
	if(pos!=1)w[pos]=min(w[pos],w[fa[pos][0]]+up[pos].first+up[pos].second);
	for(int i:c[pos])dfs2(i);
}
inline void dfs(int pos){
	dp[pos][0][0]=make_pair(min(up[pos].first,w[pos]+w[fa[pos][0]]+up[pos].second),min(up[pos].second+w[pos],up[pos].first+w[fa[pos][0]]));
	dp[pos][1][0]=make_pair(min(w[pos]+w[fa[pos][0]]+up[pos].first,up[pos].second),min(up[pos].second+w[fa[pos][0]],up[pos].first+w[pos]));
	F(i,1,18){
		fa[pos][i]=fa[fa[pos][i-1]][i-1];
		dp[pos][0][i]=make_pair(min(dp[pos][0][i-1].first+dp[fa[pos][i-1]][0][i-1].first,dp[pos][0][i-1].second+dp[fa[pos][i-1]][1][i-1].second),
		min(dp[pos][0][i-1].first+dp[fa[pos][i-1]][0][i-1].second,dp[pos][0][i-1].second+dp[fa[pos][i-1]][1][i-1].first));
		dp[pos][1][i]=make_pair(min(dp[pos][1][i-1].first+dp[fa[pos][i-1]][1][i-1].first,dp[pos][1][i-1].second+dp[fa[pos][i-1]][0][i-1].second),
		min(dp[pos][1][i-1].first+dp[fa[pos][i-1]][1][i-1].second,dp[pos][1][i-1].second+dp[fa[pos][i-1]][0][i-1].first));
	}
	for(int i:c[pos])dfs(i);
}
inline pll query(int x,int y,bool tp){
	pll rt=make_pair(0,w[x]);
	UF(i,18,0){
		if(d[fa[x][i]]>=d[y]){
			rt=make_pair(min(rt.first+dp[x][tp][i].first,rt.second+dp[x][!tp][i].second),
			min(rt.second+dp[x][!tp][i].first,rt.first+dp[x][tp][i].second));
			x=fa[x][i];
		}
	}
	return rt;
}
inline int lca(int x,int y){
	if(d[x]<d[y])swap(x,y);
	UF(i,18,0)if(d[fa[x][i]]>=d[y])x=fa[x][i];
	if(x==y)return x;
	UF(i,18,0)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int main() {
	cin>>n;
	F(i,1,n)read(w[i]);
	F(i,2,n){
		read(t1,t2,t3,t4);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
		co[t1].push_back(make_pair(t3,t4));
		co[t2].push_back(make_pair(t3,t4));
	}
	make_tree(1,0);
	dfs1(1);
	dfs2(1);
	dfs(1);
	F(iakioi,1,read()){
		int x,y;
		read(x,y);++x;++y;
		int l=lca(x>>1,y>>1);
		pll t1=query(x>>1,l,x&1),t2=query(y>>1,l,y&1);
		if((x&1)==(y&1))write(min(t1.first+t2.first,t1.second+t2.second),'\n');
		else write(min(t1.first+t2.second,t1.second+t2.first),'\n');
	}
	return 0;
}
/*
5
3 6 15 4 8
1 2 5 4
2 3 5 7
1 4 1 5
1 5 2 1
3
1 2
5 6
2 10
*/