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

const int MAXN=100000;

int n,m;
vector<int> adj[MAXN];

bool done[MAXN];
int q[MAXN],qhead,qtail;

int solve() {
	REP(i,n) done[i]=false;
	int ret=m;
	REP(s,n) if(!done[s]) {
		qhead=qtail=0; q[qhead++]=s,done[s]=true; int cnt=0;
		while(qtail<qhead) {
			int at=q[qtail++]; ++cnt;
			REPSZ(i,adj[at]) { int to=adj[at][i]; if(!done[to]) q[qhead++]=to,done[to]=true; }
		}
		ret-=cnt-1;
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}