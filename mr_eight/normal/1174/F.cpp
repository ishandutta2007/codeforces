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
int D,mmax[200002],sz[200002],fa[200002],a[200002],t[200002],f[200002],big[200002],num,n,m,t1,t2,dp[200002],size[200002],head[200002];
vector<int>g[200002],c[200002],ch[200002];
bool vis[200002];
inline void make_tree(int pos){	
	vis[pos]=1;dp[pos]=dp[f[pos]]+1;
	F(i,0,g[pos].size()-1)
		if(!vis[g[pos][i]]){
			f[g[pos][i]]=pos;
			c[pos].push_back(g[pos][i]);
			make_tree(g[pos][i]);
		}
}
inline void getsize(int pos){
	F(i,0,c[pos].size()-1){
		getsize(c[pos][i]);
		size[pos]+=size[c[pos][i]];
	}size[pos]++;
}
inline int lca(int x,int y){
	while(head[x]!=head[y]){
		if(dp[head[x]]<dp[head[y]]){
			y=f[head[y]];
		}else{
			x=f[head[x]];
		}
	}
	if(dp[x]<dp[y])return x;
	else return y;
}
void dfs(int pos,bool isbig){
	if(isbig)head[pos]=head[f[pos]];
	else head[pos]=pos;
	t[pos]=++num;
	ri mmax=0,mpos=0;
	F(i,0,c[pos].size()-1){
		if(size[c[pos][i]]>mmax){
			mpos=c[pos][i];
			mmax=size[c[pos][i]];
		}
	}big[pos]=mpos;
	if(c[pos].size())dfs(mpos,1);
	F(i,0,c[pos].size()-1)if(c[pos][i]!=mpos)dfs(c[pos][i],0);
}
inline void getmax(int pos,int fa){
	sz[pos]=1;
	F(i,0,g[pos].size()-1){
		if(g[pos][i]!=fa&&!vis[g[pos][i]]){
			getmax(g[pos][i],pos);
			sz[pos]+=sz[g[pos][i]];
		}
	}
}
inline int findh(int pos,int fa,int tot){
	ri rt=pos;mmax[pos]=tot-sz[pos];
	F(i,0,g[pos].size()-1){
		if(!vis[g[pos][i]]&&g[pos][i]!=fa)mmax[pos]=max(mmax[pos],sz[g[pos][i]]);
	}
	F(i,0,g[pos].size()-1){
		if(!vis[g[pos][i]]&&g[pos][i]!=fa){
			ri nxt=findh(g[pos][i],pos,tot);
			if(mmax[rt]>mmax[nxt])rt=nxt;
		}
	}return rt;
}
inline int dfg(int pos){
	getmax(pos,0);
	ri h=findh(pos,0,sz[pos]);
	vis[h]=1;
	F(i,0,g[h].size()-1)if(!vis[g[h][i]])fa[dfg(g[h][i])]=h;
	return h;
}
inline int query1(int pos){
	putchar('d');putchar(' ');write(pos,'\n');fflush(stdout);return read();
}
inline int query2(int pos){
	putchar('s');putchar(' ');write(pos,'\n');fflush(stdout);return read();
}
inline void solve(int pos){
	if(ch[pos].empty()){
		putchar('!');putchar(' ');write(pos,'\n');fflush(stdout);exit(0);
	}
	int qwq;
	if(pos==1||((qwq=query1(pos))==D-dp[pos])){
		if(!qwq&&pos!=1){
			putchar('!');putchar(' ');write(pos,'\n');fflush(stdout);exit(0);
		}
		int p=query2(pos);
		for(int i:ch[pos]){
			if(lca(i,p)==p){
				solve(i);
			}
		}
	}else{
		for(int i:ch[pos]){
			if(lca(i,pos)!=pos){
				solve(i);
			}
		}
	}
}
int main() {dp[0]=-1;
	cin>>n;
    F(i,2,n){
    	t1=read(),t2=read();
    	g[t1].push_back(t2);
    	g[t2].push_back(t1);
	}make_tree(1);
	getsize(1);
	dfs(1,0);
	memset(vis,0,sizeof(vis));
	dfg(1);
	F(i,1,n)ch[fa[i]].push_back(i);
	D=query1(1);
	if(D==0){
		putchar('!');putchar(' ');write(1,'\n');
		return 0;
	}
	solve(ch[0][0]);
	return 0;
}