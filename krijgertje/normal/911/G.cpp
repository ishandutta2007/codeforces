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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int calcmxbit(unsigned int x) { x = x | (x >> 1); x = x | (x >> 2); x = x | (x >> 4); x = x | (x >> 8); x = x | (x >> 16); return x^(x>>1); }
struct SegTrieNode { int key; int lft,rgt; };
struct SegTrie {
	vector<SegTrieNode> nodes;
	vector<int> pool;
	
	void init() { nodes.clear(); pool.clear(); }
	int create(int key) { if(pool.size()==0) { pool.push_back((int)nodes.size()); nodes.push_back(SegTrieNode()); } int ret=pool.back(); pool.pop_back(); nodes[ret].key=key,nodes[ret].lft=nodes[ret].rgt=-1; return ret; }
	void release(int a) { pool.push_back(a); }

	int merge(int a,int b) {
		if(a==-1) return b; else if(b==-1) return a;
		if(nodes[a].key>nodes[b].key) swap(a,b);
		int kdiff=nodes[a].key^nodes[b].key;
		int achdiff=nodes[a].lft==-1?0:nodes[nodes[a].lft].key^nodes[nodes[a].rgt].key;
		int bchdiff=nodes[b].lft==-1?0:nodes[nodes[b].lft].key^nodes[nodes[b].rgt].key;
		int tobit=calcmxbit(achdiff|bchdiff|kdiff);
		if(tobit==0) { release(b); return a; }
		bool adone=(achdiff&tobit)!=0,bdone=(bchdiff&tobit)!=0;
		bool abit=(nodes[a].key&tobit)!=0,bbit=(nodes[b].key&tobit)!=0;
		if(adone&&bdone) { int x=merge(nodes[a].lft,nodes[b].lft); nodes[a].lft=x; int y=merge(nodes[a].rgt,nodes[b].rgt); nodes[a].rgt=y; release(b); return a; }
		if(adone) { if(!bbit) { int x=merge(nodes[a].lft,b); nodes[a].lft=x; } else { int y=merge(nodes[a].rgt,b); nodes[a].rgt=y; } return a; }
		if(bdone) { assert(!abit); nodes[b].key=nodes[a].key; int x=merge(nodes[b].lft,a); nodes[b].lft=x; return b; }
		assert(abit==0&&bbit==1); int c=create(nodes[a].key); nodes[c].lft=a; nodes[c].rgt=b; return c;
	}

	pair<int,int> split(int a,int key) {
		if(a==-1) return MP(-1,-1);
		int kdiff=nodes[a].key^key;
		int achdiff=nodes[a].lft==-1?0:nodes[nodes[a].lft].key^nodes[nodes[a].rgt].key;
		int tobit=calcmxbit(achdiff|kdiff);
		if(tobit==0) return make_pair(-1,a);
		bool adone=(achdiff&tobit)!=0;
		bool abit=(nodes[a].key&tobit)!=0,kbit=(key&tobit)!=0;
		if(adone&&!kbit) { 
			int b,c; tie(b,c)=split(nodes[a].lft,key); 
			if(c==-1) { c=nodes[a].rgt; release(a); return make_pair(b,c); }
			nodes[a].key=nodes[c].key; nodes[a].lft=c; return make_pair(b,a);
		}
		if(adone&&kbit) {
			int b,c; tie(b,c)=split(nodes[a].rgt,key);
			if(b==-1) { b=nodes[a].lft; release(a); return make_pair(b,c); }
			nodes[a].rgt=b; return make_pair(a,c);
		}
		return !kbit?make_pair(-1,a):make_pair(a,-1);
	}
};



const int MAXN=200000;
const int MAXQ=200000;
const int MAXVAL=100;

int n;
int a[MAXN];
int nq;
int ql[MAXQ],qr[MAXQ],qx[MAXQ],qy[MAXQ];
int ans[MAXN];

SegTrie strie;
int root[MAXVAL+1];

void solve() {
	strie.init();
	FORE(i,1,MAXVAL) root[i]=-1;
	REP(i,n) { int v=a[i]; int x=strie.create(i); root[v]=strie.merge(root[v],x); }
	REP(i,nq) {
		int l=ql[i],r=qr[i],x=qx[i],y=qy[i];
		int a,b=root[x],c;
		tie(a,b)=strie.split(b,l);
		tie(b,c)=strie.split(b,r+1);
		root[x]=strie.merge(a,c);
		root[y]=strie.merge(root[y],b);
	}
	FORE(v,1,MAXVAL) {
		int cur=root[v];
		while(cur!=-1) { int idx=strie.nodes[cur].key; assert(0<=idx&&idx<n); ans[idx]=v; int tmp; tie(tmp,cur)=strie.split(cur,idx+1); }
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d%d%d",&ql[i],&qr[i],&qx[i],&qy[i]),--ql[i],--qr[i];
	solve();
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}