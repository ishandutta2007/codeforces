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
#define Fll(i,a,b) for(ll i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define pll pair<ll,ll>
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
const int MAXN = 100010;
vector<pii >g[114514];
pii qwq[114514];
int now,n,m,p[114514],f[114514];
ll d[MAXN];
pll fuck[5000002];
int ccf;
inline void ins(ll x,ll y){
	fuck[++ccf]=make_pair(x,y);
}
#define pushup(x) 
struct LCT_for_t {
	int ch[MAXN][2], fa[MAXN],tag[MAXN],v[MAXN];
	inline bool getch(int x) {
		return (ch[fa[x]][1] == x);
	}
	inline bool isroot(int x) {
		return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
	}
	inline void pushdown(int x) {
		if(tag[x]){
			tag[ch[x][0]]=tag[ch[x][1]]=v[ch[x][0]]=v[ch[x][1]]=tag[x];
			tag[x]=0;
		}
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
		for (int f = 0; x; f = x, x = fa[x]) splay(x), ch[x][1] = f;
	}
	inline void modify(int x,int vv){
		access(x);
		splay(x);
		tag[x]=v[x]=vv;
	}
	inline ll query(int pos){
		splay(pos);
		if(v[pos]==0)return 0;
		return d[pos]+v[pos];
	}
}sto;
struct LCT {
	int ch[MAXN][2], fa[MAXN];
	inline bool getch(int x) {
		return (ch[fa[x]][1] == x);
	}
	inline bool isroot(int x) {
		return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
	}
	#define pushdown(x) 
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
		for (int f = 0; x; f = x, x = fa[x]){
			splay(x);
			if(f){
				ins(sto.query(x)+1,now+d[x]);
				ch[x][1] = f;
			}
		}
	}
}orz;
inline void dfs(int pos,int fa){
	f[pos]=fa;
	for(pii i:g[pos]){
		if(i.first!=fa){
			p[pos]=i.first;
			orz.fa[i.first]=sto.fa[i.first]=pos;
			d[i.first]=d[pos]+i.second;
			dfs(i.first,pos);
		}
	}
}
priority_queue<ll,vector<ll>,greater<ll> >q;
int main() {
	cin>>n>>m;
	F(i,2,n){
		int t1=read(),t2=read(),t3=read();
		g[t1].push_back(make_pair(t2,t3));
		g[t2].push_back(make_pair(t1,t3));
	}
	dfs(1,0);
	F(i,1,m){
		read(qwq[i].second);
		read(qwq[i].first);
	}
	sort(qwq+1,qwq+m+1);
	F(i,1,n)orz.ch[i][1]=p[i];
	F(i,1,m){
		now=qwq[i].first;
		orz.access(qwq[i].second);
		if(qwq[i].second!=1)sto.modify(f[qwq[i].second],qwq[i].first);
	}
	sort(fuck+1,fuck+ccf+1);
	int ans=0;
	fuck[ccf+1].first=1e18;
	F(i,1,ccf){
		q.push(fuck[i].second);
		Fll(j,fuck[i].first,fuck[i+1].first-1){
			if(q.top()<j){
				write(q.top(),' ');ll qt=q.top();
				ans=0;
				F(qwq,1,ccf)if(fuck[qwq].second<qt)++ans;
				write(ans);
				return 0;
			}
			q.pop();
			++ans;
			if(q.empty())break;
		}
	}
	write(-1,' ');
	write(ans,'\n');
	return 0;
}
/*
9 5
1 2 1
2 3 1
3 4 1
4 5 1
1 6 1
2 7 1
3 8 1
4 9 1
6 1
2 1
3 1
4 1
5 1
*/