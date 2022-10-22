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
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
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
	inline void write(T x) {
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
const int MAXN = 200010;
int n,N,c[400002],m;
inline void add(int pos,int v){
	while(pos<=N){
		c[pos]+=v;
		pos+=(-pos&pos);
	}
}
inline int query(int pos){
	int rt=0;
	while(pos){
		rt+=c[pos];
		pos-=(-pos&pos);
	}
	return rt;
}
#define MAKE_ROOT
struct LCT {
	int ch[MAXN][2], fa[MAXN];
#ifdef MAKE_ROOT
	bool rev[MAXN];
	int sz[MAXN],tag[MAXN],v[MAXN];
#endif
	inline bool getch(int x) {
		return ch[fa[x]][1] == x;
	}
	inline bool isroot(int x) {
		return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
	}
	inline void pushup(int x) {
		sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
	}
	inline void pushdown(int x) {
		if(tag[x]){
			if(ch[x][0]){
				v[ch[x][0]]=tag[x];
				tag[ch[x][0]]=tag[x];
			}
			if(ch[x][1]){
				v[ch[x][1]]=tag[x];
				tag[ch[x][1]]=tag[x];
			}
			tag[x]=0;
		}
#ifdef MAKE_ROOT
		if (rev[x]) {
			if (ch[x][0]) rev[ch[x][0]] ^= 1, swap(ch[ch[x][0]][0], ch[ch[x][0]][1]);
			if (ch[x][1]) rev[ch[x][1]] ^= 1, swap(ch[ch[x][1]][0], ch[ch[x][1]][1]);
			rev[x] = 0;
		}
#endif
	}
	inline void update(int x) {
		if (!isroot(x)) update(fa[x]);
		pushdown(x);
	}
	inline void rotate(int x) {
		int y = fa[x], z = fa[y], chx = getch(x), chy = getch(y);
		fa[x] = z;
		if (!isroot(y)) ch[z][chy] = x;
		ch[y][chx] = ch[x][chx ^ 1];
		fa[ch[x][chx ^ 1]] = y;
		ch[x][chx ^ 1] = y;
		fa[y] = x;
		pushup(y);
		pushup(x);
	}
	inline void splay(int x) {
		update(x);
		for (int f = fa[x]; f = fa[x], !isroot(x); rotate(x))
			if (!isroot(f)) rotate(getch(x) == getch(f) ? f : x);
	}
	inline void access(int x) {
		int p=0;
		for (; x; p = x, x = fa[x]) splay(x), add(v[x],-sz[ch[x][0]]-1), ch[x][1] = p, pushup(x);
		v[p]=tag[p]=++n;
		add(n,sz[p]);
	}
	inline int find(int x) {
		access(x);
		splay(x);
		while (ch[x][0]) x = ch[x][0];
		splay(x);
		return x;
	}
#ifdef MAKE_ROOT
	inline void make_root(int x) {
		access(x);
		splay(x);
		swap(ch[x][0], ch[x][1]);
		rev[x] ^= 1;
	}
	inline void link(int x,int y){
		make_root(x);
		fa[x]=y;
	}
	inline void split(int x,int y){
		make_root(x);
		access(y);
		splay(y);
	}
	inline void cut(int x,int y){
		split(x,y);
		fa[x]=ch[y][0]=0;
		pushup(y);
	}
#endif
} lct;
char ch;
int root,deg[200002],t[200002];
vector<int>g[200002];
priority_queue<int,vector<int>,greater<int>>q;
inline void dfs(int pos,int fa){
	lct.fa[pos]=fa;
	for(int i:g[pos])if(i!=fa)dfs(i,pos),++deg[pos];
}
int main() {
	cin>>n>>m;
	N=n+m;
	F(i,2,n){
		int t1=read(),t2=read();
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	dfs(n,0);
	F(i,1,n)if(deg[i]==0)q.push(i);
	int n=0;
	while(!q.empty()){
		int pos=q.top();
		q.pop();
		t[pos]=++n;
		--deg[lct.fa[pos]];
		if(!deg[lct.fa[pos]])q.push(lct.fa[pos]);
	}
	F(i,1,n)lct.tag[i]=lct.v[i]=t[i],add(i,1),lct.sz[i]=1;
	root=n;
	F(i,1,m){
		while((ch=getchar())!='u'&&ch!='w'&&ch!='c');
		if(ch=='u'){
			int nxt=read();
			lct.make_root(nxt);
			root=nxt;
		}else if(ch=='w'){
			int pos=read();
			lct.splay(pos);
			write(query(lct.v[pos])-lct.sz[lct.ch[pos][0]],'\n');
		}else{
			int pos=read();
			lct.splay(pos);
			int x=query(lct.v[pos])-lct.sz[lct.ch[pos][0]];
			int poss=read();
			lct.splay(poss);
			int y=query(lct.v[poss])-lct.sz[lct.ch[poss][0]];
			if(x<y)write(pos,'\n');
			else write(poss,'\n');
		}
	}
	return 0;
}
/*
5 2
1 5
1 2
1 3
4 3
up 1
compare 1 5
*/