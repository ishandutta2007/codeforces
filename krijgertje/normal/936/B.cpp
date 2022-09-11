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

const int MAXN=100000;

int n,m;
vector<int> adj[MAXN];
int s;

int prv[MAXN][2];

pair<int,int> q[2*MAXN]; int qhead,qtail;

int ret[2*MAXN],nret;

int state[MAXN];
bool dfscyc(int at) {
	state[at]=1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i];
		if(state[to]==2) continue;
		if(state[to]==1) return true;
		if(dfscyc(to)) return true;
	}
	state[at]=2;
	return false;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) { int cnt; scanf("%d",&cnt); REP(j,cnt) { int to; scanf("%d",&to); --to; adj[i].PB(to); } }
	scanf("%d",&s); --s;

	REP(i,n) REP(j,2) prv[i][j]=-1; qhead=qtail=0;
	prv[s][0]=-2; q[qhead++]=MP(s,0);
	while(qtail<qhead) {
		int at=q[qtail].first,t=q[qtail].second; ++qtail;
		REPSZ(i,adj[at]) {
			int to=adj[at][i],nt=1-t; if(prv[to][nt]!=-1) continue;
			prv[to][nt]=at; q[qhead++]=MP(to,nt);
		}
	}
	REP(i,n) if(SZ(adj[i])==0&&prv[i][1]!=-1) {
		printf("Win\n");
		nret=0; for(int at=i,t=1;at!=-2;at=prv[at][t],t=1-t) ret[nret++]=at; reverse(ret,ret+nret);
		REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
		return;
	}

	REP(i,n) state[i]=0;
	if(dfscyc(s)) { printf("Draw\n"); return; }
	printf("Lose\n");
}

int main() {
	run();
	return 0;
}