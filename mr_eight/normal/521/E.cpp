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
vector<int>g[200002];
int n,m,t1,t2,fa[200002],dp[200002],T,sta[200002],tot;
pii v[200002],O;
bool vis[200002];
inline void play(int x){
	sta[++tot]=x;
	vis[x]=true;
	if(x==T)return;
	for(int i:g[x])if(!vis[i]&&i!=T){
		play(i);
		return;
	}
	for(int i:g[x])if(i==T){
		play(i);
		return;
	}
}
void getans(int a,int b,int c,int d){
	puts("YES");
	if(dp[a]<dp[b])swap(a,b);
	if(dp[c]<dp[d])swap(c,d);
	memset(vis,0,sizeof(vis));
	F(i,1,n)g[i].clear();
	g[a].push_back(b);
	g[b].push_back(a);
	g[c].push_back(d);
	g[d].push_back(c);
	for(int i=a;i!=b;i=fa[i]){
		if(!vis[i]){
			vis[i]=true;
			g[i].push_back(fa[i]);
			g[fa[i]].push_back(i);
		}
	}
	for(int i=c;i!=d;i=fa[i]){
		if(!vis[i]){
			vis[i]=true;
			g[i].push_back(fa[i]);
			g[fa[i]].push_back(i);
		}
	}
	a=0;
	F(i,1,n)if(g[i].size()==3){
		if(a)b=i;
		else a=i;
	}
	T=b;
	memset(vis,0,sizeof(vis));
	F(i,1,3){
		vis[a]=vis[b]=tot=0;
		play(a);write(tot,' ');F(i,1,tot)write(sta[i],' ');puts("");
	}
	exit(0);
}
inline void dfs(int pos) {
	dp[pos]=dp[fa[pos]]+1;
	vis[pos]=true;
	for(int i:g[pos]) {
		if(i!=fa[pos]&&!vis[i]) {
			fa[i]=pos;
			dfs(i);
		}else if(i!=fa[pos]&&dp[i]<dp[pos]){
			for(int p=pos;p!=i;p=fa[p]){
				if(v[p]==O)v[p]=make_pair(pos,i);
				else{
					getans(v[p].first,v[p].second,pos,i);
				}
			}
		}
	}
}
int main() {
	cin>>n>>m;
	F(i,1,m) {
		read(t1);
		read(t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	F(i,1,n) {
		if(!vis[i]) {
			dfs(i);
		}
	}
	cout<<"NO";
	return 0;
}