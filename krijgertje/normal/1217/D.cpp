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

const int MAXN=5000;
const int MAXM=5000;
struct E { int a,b; };

int n,m;
E e[MAXM];
int ncol;
int col[MAXM];

int state[MAXN];
vector<int> out[MAXN];

bool dfscyc(int at) {
	state[at]=1;
	REPSZ(i,out[at]) {
		int to=out[at][i];
		if(state[to]==1) return true;
		if(state[to]==2) continue;
		if(dfscyc(to)) return true;
	}
	state[at]=2;
	return false;
}

bool acyclic() {
	REP(i,n) out[i].clear();
	REP(i,m) out[e[i].a].PB(e[i].b);
	REP(i,n) state[i]=0;
	REP(i,n) if(state[i]==0) { bool foundcyc=dfscyc(i); if(foundcyc) return false; }
	return true;
}

void solve() {
	if(acyclic()) {
		ncol=1; REP(i,m) col[i]=0;
	} else {
		ncol=2; REP(i,m) col[i]=e[i].a<e[i].b?0:1;
	}
}


void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) scanf("%d%d",&e[i].a,&e[i].b),--e[i].a,--e[i].b;
	solve();
	printf("%d\n",ncol);
	REP(i,m) { if(i!=0) printf(" "); printf("%d",col[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}