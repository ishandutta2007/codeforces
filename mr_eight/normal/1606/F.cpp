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
#include <random>
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
struct f{
	int k,b;
	inline f operator+(const f &y)const{
		return (f){k+y.k,b+y.b};
	}
	inline bool operator<(const f &y)const{
		return 1ll*b*y.k<1ll*y.b*k;
	}
	inline bool operator!=(const f &y)const{
		return k!=y.k||b!=y.b;
	}
	inline double t(){
		return -b/(double)k;
	}
}now[200002];
const int MAXN = 200010;
#define MAKE_ROOT
struct LCT {
	int ch[MAXN][2], fa[MAXN];
	f v[MAXN], tag[MAXN];
#ifdef MAKE_ROOT
	bool rev[MAXN];
#endif
	inline bool getch(int x) {
		return ch[fa[x]][1] == x;
	}
	inline bool isroot(int x) {
		return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
	}
	inline void pushup(int x) {}
	inline void pushdown(int x) {
		#define pos x
		if(tag[pos].k||tag[pos].b){
			tag[ch[pos][0]]=tag[ch[pos][0]]+tag[pos];
			tag[ch[pos][1]]=tag[ch[pos][1]]+tag[pos];
			v[ch[pos][0]]=v[ch[pos][0]]+tag[pos];
			v[ch[pos][1]]=v[ch[pos][1]]+tag[pos];
			tag[pos].k=tag[pos].b=0;
		}
		#undef pos
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
		for (int f = 0; x; f = x, x = fa[x]) splay(x), ch[x][1] = f, pushup(x);
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
#define pfi pair<f,int>
priority_queue<pfi,vector<pfi>,greater<pfi> >q;
inline void ins(int x){
	q.push(make_pair(now[x],x));
}
int n,fa[200002],t1,t2,m,temp,s[200002],ans[200002];
vector<int>g[200002],c[200002];
bool vis[200002];
pii query[200002];
inline int getmax(){
	while(true){
		int pos=q.top().second;
		if(vis[pos]||q.top().first!=now[pos]){
			q.pop();
			continue;
		}
		vis[pos]=true;
		q.pop();
		return pos;
	}
}
inline void dfs(int pos,int ff){
	fa[pos]=lct.fa[pos]=ff;
	for(int i:g[pos])if(i!=ff)c[pos].push_back(i),dfs(i,pos);
}
inline void getans(int x,int orz){
	int pos=s[x];
	lct.splay(pos);
	f qwq=lct.v[pos];
	++qwq.k;
	++qwq.b;
	ans[x]=1ll*orz*qwq.k+qwq.b;
}
struct bcj{
	int fa[200002];
	bcj(){
		F(i,1,200000)fa[i]=i;
	}
	inline int findf(int x){
		return fa[x]==x?x:(fa[x]=findf(fa[x]));
	}
	inline void merge(int x,int y){
		if(findf(x)!=findf(y))fa[fa[x]]=fa[y];
	}
}A;
inline void chai(int pos){
	int nxt=A.findf(fa[pos]);
	A.fa[pos]=nxt;
	now[nxt]=now[nxt]+now[pos];
	if(nxt!=1)q.push(make_pair(now[nxt],nxt));
	vis[pos]=true;
	lct.split(fa[pos],nxt);
	lct.tag[nxt]=lct.tag[nxt]+now[pos];
	lct.v[nxt]=lct.v[nxt]+now[pos];
}
inline bool cmp(pii x,pii y){
	return x.first>y.first;
}
int main() {
	cin>>n;
	F(i,2,n){
		read(t1);
		read(t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	dfs(1,0);
	F(i,1,n)lct.v[i]=now[i]={-1,(int)c[i].size()-1};
	cin>>m;
	F(i,1,m)read(s[i]),read(query[i].first),query[i].second=i;
	sort(query+1,query+m+1,cmp);
	F(i,2,n)ins(i);
	F(i,2,n){
		int pos=getmax();//cerr<<pos<<endl;
		double qwq=now[pos].t();
		while(temp<m&&query[temp+1].first>qwq){
			++temp;
			getans(query[temp].second,query[temp].first);
		}
		chai(pos);
	}
	while(temp<m){
		++temp;
		getans(query[temp].second,query[temp].first);
	}
	F(i,1,m)write(ans[i],'\n');
	return 0;
}