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

const int MAXN = 2000;

int n;
int deg[MAXN];
vector<pair<int, int>> edges;

int ufpar[MAXN], ufsz[MAXN], ufdeg[MAXN];
int uffind(int x) { if (ufpar[x] == x) return x; return ufpar[x] = uffind(ufpar[x]); }
void ufunite(int x, int y) { x = uffind(x), y = uffind(y); if (x != y) { if (ufsz[x] < ufsz[y]) swap(x, y); ufpar[y] = x, ufsz[x] += ufsz[y], ufdeg[x] += ufdeg[y]; } ufdeg[x] -= 2; }

int remdeg[MAXN];
queue<int> qone;
queue<int> qtwo;
queue<int> qodd;
queue<int> qeven;


void addtoqueue(int a) {
	if (ufdeg[a] == 0) return;
	if (ufdeg[a] == 1) qone.push(a);
	else if (ufdeg[a] == 2) qtwo.push(a);
	else if (ufdeg[a] % 2 == 1) qodd.push(a);
	else qeven.push(a);
}
void addedge(int a, int b, bool skip = false) {
	//printf("adding %d-%d\n", a + 1, b + 1);
	--remdeg[a], --remdeg[b];
	edges.PB(MP(a, b));
	ufunite(a, b);
	a = uffind(a);
	assert(uffind(b) == a);
	if (!skip) addtoqueue(a);
	//printf("\trem:"); REP(i, n) if (uffind(i) == i) printf(" [%d,%d,%d]", i + 1, ufsz[i], ufdeg[i]); puts("");
}
int findone(int a) { REP(i, n) if (uffind(i) == a&&remdeg[i] == 1) return i; assert(false); return -1; }
int findtwo(int a) { REP(i, n) if (uffind(i) == a&&remdeg[i] == 2) return i; assert(false); return -1; }
int findtwooreven(int a) { REP(i, n) if (uffind(i) == a&&remdeg[i] % 2 == 0 && remdeg[i] >= 2) return i; assert(false); return -1; }


bool solve() {
	edges.clear();
	REP(i, n) ufpar[i] = i, ufsz[i] = 1, ufdeg[i] = deg[i];
	REP(i, n) remdeg[i] = deg[i];

	qone = qodd = qtwo = qeven = queue<int>();
	REP(i, n) addtoqueue(i);
	while (SZ(qone) > 0) {
		int a = qone.front(); qone.pop();
		a = findone(a);
		if (SZ(qodd) > 0) {
			int b = qodd.front(); qodd.pop();
			assert(ufsz[b] == 1);
			addedge(a, b);
		} else if (SZ(qone) >= 1 && SZ(qeven) > 0) {
			int b = qone.front(); qone.pop();
			b = findone(b);
			int c = qeven.front(); qeven.pop();
			c = findtwooreven(c);
			addedge(a, c, true); addedge(b, c);
		} else if (SZ(qeven) == 0 && SZ(qone) == 1) {
			int c = qone.front(); qone.pop();
			c = findone(c);
			while (SZ(qtwo) > 0) {
				int b = qtwo.front(); qtwo.pop();
				b = findtwo(b);
				addedge(a, b, true);
				a = b;
			}
			addedge(a, c);
			assert(SZ(qone) == 0 && SZ(qtwo) == 0 && SZ(qodd) == 0 && SZ(qeven) == 0);
			return true;
		} else {
			return false;
		}
	}
	while (SZ(qodd) > 0) {
		int a = qodd.front(); qodd.pop();
		assert(ufsz[a] == 1);
		if (SZ(qodd) == 0) return false;
		int b = qodd.front(); qodd.pop();
		assert(ufsz[b] == 1);
		addedge(a, b);
	}
	assert(SZ(qone) == 0 && SZ(qodd) == 0);
	while (SZ(qeven) > 0) {
		if (SZ(qtwo) == 0) return false;
		int a = qtwo.front(); qtwo.pop();
		a = findtwo(a);
		if (SZ(qtwo) == 0) return false;
		int b = qtwo.front(); qtwo.pop();
		b = findtwo(b);
		int c = qeven.front(); qeven.pop();
		c = findtwooreven(c);
		//printf("triangle (rem:%d)\n",SZ(qeven));
		addedge(c, a, true); addedge(a, b, true); addedge(b, c);
		assert(SZ(qone) == 0 && SZ(qodd) == 0);
	}
	if (SZ(qtwo) >= 3) {
		vector<int> cyc;
		while (SZ(qtwo) > 0) {
			int a = qtwo.front(); qtwo.pop();
			a = findtwo(a);
			cyc.PB(a);
		}
		REPSZ(i, cyc) addedge(cyc[i], cyc[(i + 1) % SZ(cyc)], i + 1 < SZ(cyc));
		assert(SZ(qone) == 0 && SZ(qtwo) == 0 && SZ(qodd) == 0 && SZ(qeven) == 0);
	}
	return SZ(qone) == 0 && SZ(qtwo) == 0 && SZ(qodd) == 0 && SZ(qeven) == 0;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &deg[i]);
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", SZ(edges));
	REPSZ(i, edges) printf("%d %d %d\n", 2, edges[i].first + 1, edges[i].second + 1);
}

int main() {
	run();
	return 0;
}