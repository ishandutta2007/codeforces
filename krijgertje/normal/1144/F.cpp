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

const int MAXN=200000;
const int MAXM=200000;

int n,m;
int e[MAXM][2];
vector<int> adj[MAXN];
bool ans[MAXM];

int col[MAXN];
int q[MAXN],qhead,qtail;

bool solve() {
	REP(i,n) col[i]=-1;
	REP(i,n) if(col[i]==-1) {
		qhead=qtail=0; col[i]=0,q[qhead++]=i;
		while(qtail<qhead) {
			int at=q[qtail++];
			REPSZ(j,adj[at]) { int to=adj[at][j]; if(col[to]==-1) col[to]=1-col[at],q[qhead++]=to; if(col[to]==col[at]) return false; }
		}
	}
	// 0=only out,1=only in
	REP(i,m) {
		int a=e[i][0],b=e[i][1];
		assert(col[a]!=col[b]);
		ans[i]=col[a]==1;
	}
	return true;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; e[i][0]=a,e[i][1]=b; adj[a].PB(b),adj[b].PB(a); }
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n"); REP(i,m) printf("%d",ans[i]?1:0); puts("");
}

int main() {
	run();
	return 0;
}