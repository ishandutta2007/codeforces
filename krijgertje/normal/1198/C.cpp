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

const int MAXN=3*100000;
const int INDEP=0;
const int MATCH=1;
const int IMPOSSIBLE=2;

int n,m;
vector<pair<int,int>> adj[MAXN];

int state[MAXN]; // -2 -> in indep set, -1 -> unused, >=0 -> matched with that index

vector<int> match;
vector<int> indep;

int solve() {
	REP(at,n) state[at]=-1;
	int nindep=0,nmatch=0; match.clear();
	int ret=IMPOSSIBLE;
	REP(at,n) {
		REPSZ(i,adj[at]) {
			int to=adj[at][i].first;
			if(state[to]==-2) { state[at]=to,state[to]=at; --nindep,++nmatch,match.PB(adj[at][i].second); break; }
		}
		if(state[at]==-1) { state[at]=-2; ++nindep; }
		if(nindep==n/3) { ret=INDEP; break; }
		if(nmatch==n/3) { ret=MATCH; break; }
	}
	indep.clear(); REP(at,n) if(state[at]==-2) indep.PB(at);
	return ret;
}

void run() {
	scanf("%d%d",&n,&m); n*=3;
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(MP(b,i)); adj[b].PB(MP(a,i)); }
	int ans=solve();
	if(ans==INDEP) { printf("IndSet\n"); REPSZ(i,indep) { if(i!=0) printf(" "); printf("%d",indep[i]+1); } puts(""); }
	if(ans==MATCH) { printf("Matching\n"); REPSZ(i,match) { if(i!=0) printf(" "); printf("%d",match[i]+1); } puts(""); }
	if(ans==IMPOSSIBLE) { printf("IMPOSSIBLE\n"); }
	REP(i,n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}