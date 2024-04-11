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

const int MAXN=200000;

int n,m;
vector<int> adj[MAXN];

int comp[MAXN],ncomp;
int q[MAXN],qhead,qtail;

int compcnt[MAXN];
bool compok[MAXN];

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }

	ncomp=0; REP(i,n) comp[i]=-1;
	REP(i,n) if(comp[i]==-1) {
		qhead=qtail=0; q[qhead++]=i; comp[i]=ncomp++;
		while(qtail<qhead) { int at=q[qtail++]; REPSZ(i,adj[at]) { int to=adj[at][i]; if(comp[to]!=-1) continue; comp[to]=comp[at]; q[qhead++]=to; } }
	}
	//printf("comp:"); REP(i,n) printf(" %d",comp[i]); puts("");

	REP(i,ncomp) compcnt[i]=0; REP(i,n) ++compcnt[comp[i]];
	REP(i,ncomp) compok[i]=compcnt[i]>=3; REP(i,n) if(SZ(adj[i])!=2) compok[comp[i]]=false;
	int ret=0; REP(i,ncomp) if(compok[i]) ++ret; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}