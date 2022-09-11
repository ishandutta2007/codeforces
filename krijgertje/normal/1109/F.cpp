#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
#include <chrono>
#include <random>
using namespace std;

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

struct ForestDynamicConnectivity {
	int n;
	vector<int> par;
	vector<array<int,2>> ch;
	vector<bool> reverse;
	vector<int> pathmin;
	
	void push(int a) { if(a==-1||!reverse[a]) return; swap(ch[a][0],ch[a][1]); reverse[a]=false; REP(i,2) if(ch[a][i]!=-1) reverse[ch[a][i]]=!reverse[ch[a][i]]; }
	void update(int a) { pathmin[a]=a; REP(i,2) if(ch[a][i]!=-1) pathmin[a]=min(pathmin[a],pathmin[ch[a][i]]); }
	int getside(int a) { if(par[a]!=-1&&ch[par[a]][0]==a) return 0; if(par[a]!=-1&&ch[par[a]][1]==a) return 1; return -1; }
	void connect(int a,int side,int b) { ch[a][side]=b; if(b!=-1) par[b]=a; }
	
	void rotate(int a) {
		int aside=getside(a),b=par[a],bside=getside(b),c=par[b];
		if(bside!=-1) connect(c,bside,a); else par[a]=c;
		connect(b,aside,ch[a][1-aside]);
		connect(a,1-aside,b);
		update(b); update(a);
	}
	void splay(int a) { while(true) { push(par[a]!=-1?par[par[a]]:-1),push(par[a]),push(a); int aside=getside(a); if(aside==-1) break; int b=par[a],bside=getside(b); if(bside!=-1) rotate(bside==aside?b:a); rotate(a); } }
	void expose(int a) { splay(a); ch[a][1]=-1; update(a); while(par[a]!=-1) { int b=par[a]; splay(b); ch[b][1]=a; update(b); splay(a); } }
	void makeroot(int a) { expose(a); reverse[a]=!reverse[a]; }

	void init(int _n) { n=_n; par=vector<int>(n,-1); ch=vector<array<int,2>>(n,{-1,-1}); reverse=vector<bool>(n,false); pathmin=vector<int>(n); REP(i,n) pathmin[i]=i; }
	//pair<int,int> addedge(int a,int b) { expose(a); makeroot(b); assert(par[a]==-1&&!reverse[a]&&ch[a][1]==-1); connect(a,1,b); update(a); return MP(a,b); }
	//void remedge(pair<int,int> e) { int a=e.first,b=e.second; expose(a); splay(b); if(par[b]==a) { par[b]=-1; } else { assert(ch[b][1]==a); ch[b][1]=par[a]=-1; update(b); } }
	//bool areconnected(int a,int b) { expose(a); expose(b); return par[a]!=-1; }
	int forceedge(int a,int b) { // add edge (a,b) to forest. if already connected edge between minimum node on path in direction of b. returns -1 or the disconnected node id.
		makeroot(a); makeroot(b);
		if(par[a]==-1) { par[b]=a; return -1; }
		int c=pathmin[b]; splay(c);
		if(c==b) { int r=ch[c][1]; ch[c][1]=-1; update(c); par[r]=-1; par[c]=a; } else { int l=ch[c][0]; ch[c][0]=-1; update(c); par[l]=a; }
		return c;
	}

	void printrec(int a,bool rev) { printf("["); if(reverse[a]) rev=!rev; int l=ch[a][0],r=ch[a][1]; if(rev) swap(l,r); if(l!=-1) printrec(l,rev); printf("%d",a+1); if(reverse[a]) printf("!"); if(r!=-1) printrec(r,rev); printf("]"); }
	void print() { REP(i,n) if(getside(i)==-1) { printrec(i,false); if(par[i]!=-1) printf("(%d)",par[i]+1); printf(" "); } puts(""); }
};

struct SegTreeMinCounter {
	int n;
	vector<int> smn,smncnt,slazy;
	void sapply(int x,int by) {
		smn[x]+=by; slazy[x]+=by;
	}
	void spush(int x) {
		if(slazy[x]!=0) sapply(2*x+1,slazy[x]),sapply(2*x+2,slazy[x]),slazy[x]=0;
	}
	void spull(int x) {
		smn[x]=min(smn[2*x+1],smn[2*x+2]);
		smncnt[x]=(smn[2*x+1]==smn[x]?smncnt[2*x+1]:0)+(smn[2*x+2]==smn[x]?smncnt[2*x+2]:0);
	}
	void sinit(int x,int l,int r) {
		slazy[x]=0;
		if(l==r) {
			smn[x]=0,smncnt[x]=1;
		} else {
			int m=l+(r-l)/2;
			sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
			spull(x);
		}
	}
	void smod(int x,int l,int r,int L,int R,int BY) {
		if(L<=l&&r<=R) {
			sapply(x,BY);
		} else {
			int m=l+(r-l)/2; spush(x);
			if(L<=m) smod(2*x+1,l,m,L,R,BY);
			if(m+1<=R) smod(2*x+2,m+1,r,L,R,BY);
			spull(x);
		}
	}
	int sget(int x,int l,int r,int L,int R,int VAL) {
		if(L<=l&&r<=R) {
			assert(smn[x]>=VAL);
			return smn[x]==VAL?smncnt[x]:0;
		} else {
			int m=l+(r-l)/2; spush(x); int ret=0;
			if(L<=m) ret+=sget(2*x+1,l,m,L,R,VAL);
			if(m+1<=R) ret+=sget(2*x+2,m+1,r,L,R,VAL);
			return ret;
		}
	}
	
	void init(int _n) { n=_n; smn=smncnt=slazy=vector<int>(4*n); sinit(0,0,n-1); }
	void mod(int l,int r,int by) { smod(0,0,n-1,l,r,by); }
	int get(int l,int r,int val) { return sget(0,0,n-1,l,r,val); }
};

const int MAXH=1000;
const int MAXW=1000;
const int MAXN=200000;
const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};

int h,w,n;
int g[MAXH][MAXW];

pair<int,int> pos[MAXN];
ForestDynamicConnectivity conn;
SegTreeMinCounter segtree;

ll solve() {
	REP(x,h) REP(y,w) pos[g[x][y]]=MP(x,y);
	conn.init(n);
	segtree.init(n);
	ll ret=0;
	int l=0;
	REP(r,n) {
		int rx=pos[r].first,ry=pos[r].second;
		REP(k,4) {
			int nx=rx+DX[k],ny=ry+DY[k]; if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]<l||g[nx][ny]>r) continue;
			l=max(l,conn.forceedge(r,g[nx][ny])+1);
			segtree.mod(0,g[nx][ny],-1);
		}
		segtree.mod(0,r,+1);
		int cur=segtree.get(l,r,1);
		//printf("[%d..%d] -> %d\n",l+1,r+1,cur);
		ret+=cur;
	}
	return ret;
}

void run() {
	scanf("%d%d",&h,&w); n=h*w;
	REP(x,h) REP(y,w) scanf("%d",&g[x][y]),--g[x][y];
	printf("%lld\n",solve());
}

void stress() {
	//std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
	std::mt19937 rnd(1237891);
	REP(rep,100000) {
		h=rnd()%5+1,w=rnd()%5+1,n=h*w; vector<int> v(n); REP(i,n) v[i]=i; REP(i,n) swap(v[i],v[rnd()%(i+1)]); REP(x,h) REP(y,w) g[x][y]=v[x*w+y];
		//printf("%d %d\n",h,w); REP(x,h) { REP(y,w) { if(y!=0) printf(" "); printf("%d",g[x][y]+1); } puts(""); }
		ll have=solve();
		printf(".");
		//printf("have=%lld\n",have);
	}
}

int main() {
	run();
	//stress();
	return 0;
}