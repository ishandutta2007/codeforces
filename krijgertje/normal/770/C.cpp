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

int n,nneed;
bool needed[MAXN];
vector<int> req[MAXN];
vector<int> rreq[MAXN];
int q[MAXN],qhead,qtail;
int rem[MAXN];
int ret[MAXN],nret;

void run() {
	scanf("%d%d",&n,&nneed);
	REP(i,n) needed[i]=false; REP(i,nneed) { int x; scanf("%d",&x); --x; needed[x]=true; }
	REP(i,n) { int cnt; scanf("%d",&cnt); req[i].clear(); req[i].reserve(cnt); REP(j,cnt) { int x; scanf("%d",&x); --x; req[i].PB(x); rreq[x].PB(i); } }
	qhead=qtail=0; REP(i,n) if(needed[i]) q[qhead++]=i;
	while(qtail<qhead) {
		int at=q[qtail++];
		REPSZ(i,req[at]) { int to=req[at][i]; if(!needed[to]) needed[to]=true,q[qhead++]=to; }
	}
	REP(i,n) rem[i]=SZ(req[i]); qhead=qtail=0; REP(i,n) if(needed[i]&&rem[i]==0) q[qhead++]=i; nret=0;
	while(qtail<qhead) {
		int at=q[qtail++]; ret[nret++]=at;
		REPSZ(i,rreq[at]) { int to=rreq[at][i]; if(--rem[to]==0&&needed[to]) q[qhead++]=to; }
	}
	REP(i,n) if(needed[i]&&rem[i]>0) { printf("-1\n"); return; }
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}