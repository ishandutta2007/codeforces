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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 1000000;

int n, m;
vector<int> adj[MAXN];
vector<int> radj[MAXN];

bool alive[MAXN];
int stck[MAXN], nstck;
bool used[MAXN];
int ret[MAXN], nret;

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); radj[b].PB(a); }

	nstck = nret = 0;
	REP(i, n) alive[i] = true;
	REP(at, n) if (alive[at]) {
		stck[nstck++] = at;
		REPSZ(i, adj[at]) { int to = adj[at][i]; alive[to] = false; }
	}
	while (nstck > 0) {
		int at = stck[--nstck];
		bool any = false; REPSZ(i, radj[at]) { int fr = radj[at][i]; if (used[fr]) any = true; } if (any) continue;
		used[at] = true, ret[nret++] = at;
	}
	printf("%d\n", nret); REP(i, nret) { if (i != 0) printf(" "); printf("%d", ret[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}