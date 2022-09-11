#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

struct UF {
	int n; vector<int> par,sz;
	vector<int> ops;
	void init(int _n) { n=_n; par=sz=vector<int>(n); REP(i,n) par[i]=i,sz[i]=1; ops.clear(); }
	int gettime() { return SZ(ops); }
	void restore(int time) { /*printf("restore to %d\n",time);*/ while(SZ(ops)>time) { int b=ops[SZ(ops)-1]; ops.pop_back(); int a=par[b]; par[b]=b,sz[a]-=sz[b]; } }
	int find(int a) { if(par[a]==a) return a; return find(par[a]); }
	void unite(int a,int b) { /*printf("%d: unite(%d,%d)\n",SZ(ops)+1,a+1,b+1);*/ a=find(a),b=find(b); if(a==b) return; if(sz[a]<sz[b]) swap(a,b); ops.PB(b); par[b]=a,sz[a]+=sz[b]; }
	bool areconnected(int a,int b) { /*printf("test %d %d\n",a+1,b+1);*/ return find(a)==find(b); }
};

const int MAXN=200000;
const int MAXQ=200000;
const int MAXID=2*MAXQ;

int n,nq;
int qkind[MAXQ],qx[MAXQ],qy[MAXQ]; bool qans[MAXQ];

int qid[MAXQ][2]; int nid;
map<pair<int,int>,int> mp;

int qactid[MAXQ],qactx[MAXQ],qacty[MAXQ];
bool inside[MAXID];
int cnt[MAXID];
UF uf;

void rec(int l,int r,const vector<int> &alive,int &last) {
	//printf("rec(%d..%d) last=%d alive:",l,r,last); REPSZ(i,alive) printf(" %d",alive[i]); puts("");
	if(l==r) {
		int idx=l;
		qactid[idx]=qid[idx][last];
		qactx[idx]=(qx[idx]+last)%n,qacty[idx]=(qy[idx]+last)%n;
		//printf("%d: %d=(%d,%d)\n",idx,qactid[idx],qactx[idx]+1,qacty[idx]+1);
		if(qkind[idx]==2) { 
			int time=uf.gettime();
			REPSZ(i,alive) { int idx=alive[i],x=qactx[idx],y=qacty[idx],id=qactid[idx]; uf.unite(x,y); }
			qans[idx]=uf.areconnected(qactx[idx],qacty[idx]); last=qans[idx]?1:0; 
			uf.restore(time);
		}
	} else {
		int time=uf.gettime();
		FORE(i,l,r) if(qkind[i]==1) REP(v,2) inside[qid[i][v]]=true;
		vector<int> lalive; REPSZ(i,alive) { int idx=alive[i],x=qactx[idx],y=qacty[idx],id=qactid[idx]; if(inside[id]) lalive.PB(idx); else uf.unite(x,y); }
		FORE(i,l,r) if(qkind[i]==1) REP(v,2) inside[qid[i][v]]=false;
		int m=l+(r-l)/2;
		rec(l,m,lalive,last);
		REPSZ(i,lalive) { int idx=lalive[i],id=qactid[idx]; ++cnt[id]; }
		FORE(i,l,m) if(qkind[i]==1) { int idx=i,id=qactid[idx]; ++cnt[id]; }
		vector<int> ralive;
		REPSZ(i,lalive) { int idx=lalive[i],id=qactid[idx]; if(cnt[id]%2==1) ralive.PB(idx); cnt[id]=0; }
		FORE(i,l,m) if(qkind[i]==1) { int idx=i,id=qactid[idx]; if(cnt[id]%2==1) ralive.PB(idx); cnt[id]=0; }
		rec(m+1,r,ralive,last);
		uf.restore(time);
	}
}

void solve() {
	nid=0; mp.clear(); REP(i,nq) REP(v,2) { int x=(qx[i]+v)%n,y=(qy[i]+v)%n; if(x>y) swap(x,y); pair<int,int> key=MP(x,y); if(mp.count(key)) qid[i][v]=mp[key]; else qid[i][v]=nid++,mp[key]=qid[i][v]; }

	int last=0;
	REP(i,nid) inside[i]=false,cnt[i]=false;
	uf.init(n);
	rec(0,nq-1,vector<int>(),last);
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,nq) { scanf("%d%d%d",&qkind[i],&qx[i],&qy[i]),--qx[i],--qy[i]; }
	solve();
	REP(i,nq) if(qkind[i]==2) printf("%d",qans[i]?1:0); puts("");
}

int main() {
	run();
	return 0;
}