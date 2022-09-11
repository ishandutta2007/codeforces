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

const int MAXQ = 300000;
const int MAXT = 1000000;
const int MAXS = 4 * (MAXT + 1);

ll ssum[MAXS];
ll smx[MAXS];

void spull(int x) {
	ssum[x] = ssum[2 * x + 1] + ssum[2 * x + 2];
	smx[x] = max(smx[2 * x + 2], smx[2 * x + 1] + ssum[2 * x + 2]);
}
void sinit(int x, int l, int r) {
	if (l == r) {
		ssum[x] = 0; smx[x] = l;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l,int r, int IDX, int BY) {
	if (l == r) {
		ssum[x] += BY; smx[x] += BY;
	} else {
		int m = l + (r - l) / 2;
		if (IDX <= m) smod(2 * x + 1, l, m, IDX, BY); else smod(2 * x + 2, m + 1, r, IDX, BY);
		spull(x);
	}
}
ll sget(int x, int l, int r, int IDX, ll SOFAR) {
	if (l == r) {
		return max(smx[x], SOFAR + ssum[x]);
	} else {
		int m = l + (r - l) / 2;
		if (IDX <= m) return sget(2 * x + 1, l, m, IDX, SOFAR); else return sget(2 * x + 2, m + 1, r, IDX, max(smx[2 * x + 1], SOFAR + ssum[2 * x + 1]));
	}
}

int nq;
char qkind[MAXQ]; int qt[MAXQ], qid[MAXQ], qd[MAXQ]; bool qcancelled[MAXQ]; ll qans[MAXQ];


void solve() {
	sinit(0, 0, MAXT);
	REP(i, nq) {
		if (qkind[i] == '+') {
			int t = qt[i], d = qd[i]; qcancelled[i] = false;
			smod(0, 0, MAXT, t, +d);
		}
		if (qkind[i] == '-') {
			int id = qid[i]; assert(0 <= id && id < i && qkind[id] == '+' && !qcancelled[id]); int t = qt[id], d = qd[id]; qcancelled[id] = true;
			smod(0, 0, MAXT, t, -d);
		}
		if (qkind[i] == '?') {
			int t = qt[i];
			ll cur = sget(0, 0, MAXT, t, 0);
			//printf("cur=%lld\n", cur);
			qans[i] = cur - t;
		}
	}

}

void run() {
	scanf("%d", &nq);
	REP(i, nq) { scanf(" %c", &qkind[i]); if (qkind[i] == '+') scanf("%d%d", &qt[i], &qd[i]); if (qkind[i] == '-') scanf("%d", &qid[i]), --qid[i]; if (qkind[i] == '?') scanf("%d", &qt[i]); }
	solve();
	REP(i, nq) if (qkind[i] == '?') printf("%lld\n", qans[i]);
}


int main() {
	run();
	return 0;
}