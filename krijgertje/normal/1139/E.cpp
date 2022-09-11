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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXSTUD=5000;
const int MAXCLUB=5000;
const int MAXQ=MAXSTUD;
const int MAXPOT=4999;

int nstud,nclub;
int pot[MAXSTUD],club[MAXSTUD];
int nq;
int qleave[MAXQ],qans[MAXQ];

bool alive[MAXSTUD];
vector<int> lazy[MAXPOT+2]; // lazy[i] = alive students who have potential i, but not yet added to graph
int ans,atlazy;

vector<int> adj[MAXCLUB];
bool done[MAXCLUB];
int lmatch[MAXCLUB];
int rmatch[MAXPOT+1];

bool augment(int at) {
	if(done[at]) return false; else done[at]=true;
	REPSZ(i,adj[at]) { 
		int to=adj[at][i];
		if(rmatch[to]==-1||augment(rmatch[to])) {
			lmatch[at]=to;
			rmatch[to]=at;
			return true;
		}
	}
	return false;
}

void addedge(int a,int b) {
	adj[a].PB(b);
	REP(j,nclub) done[j]=false;
	REP(i,nclub) if(lmatch[i]==-1&&augment(i)) {
		++ans;
		REP(j,nclub) done[j]=false;
	}
}

void addstud(int idx) {
	if(pot[idx]<atlazy) addedge(club[idx],pot[idx]); else lazy[pot[idx]].PB(idx);
}

void update() {
	while(atlazy<=ans) {
		REPSZ(i,lazy[atlazy]) { int idx=lazy[atlazy][i]; addedge(club[idx],pot[idx]); }
		++atlazy;
	}
}

void solve() {
	REP(i,nstud) alive[i]=true;
	REP(i,nq) alive[qleave[i]]=false;
	ans=atlazy=0;
	REP(i,nclub) lmatch[i]=-1; REPE(i,MAXPOT) rmatch[i]=-1;
	REP(i,nstud) if(alive[i]) addstud(i);
	for(int i=nq-1;i>=0;--i) {
		update();
		qans[i]=ans;
		addstud(qleave[i]);
	}
}

void run() {
	scanf("%d%d",&nstud,&nclub);
	REP(i,nstud) scanf("%d",&pot[i]);
	REP(i,nstud) scanf("%d",&club[i]),--club[i];
	scanf("%d",&nq);
	REP(i,nq) scanf("%d",&qleave[i]),--qleave[i];
	solve();
	REP(i,nq) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}