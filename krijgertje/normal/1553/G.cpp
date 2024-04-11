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
#include <chrono>
#include <random>
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
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 150000;
const int MAXQ = 300000;
const int MAXVAL = 1000000 + 1;
const int MAXSIDE = MAXVAL + 1;
const int MAXNODE = 2 * MAXSIDE;

int n, nq;
int a[MAXN];
int qs[MAXQ], qt[MAXQ];
int qans[MAXQ];

int pmn[MAXVAL + 1];
bool alive[MAXNODE];
vector<int> adj[MAXNODE];
int comp[MAXNODE]; int ncomp;

void solve() {
	REPE(i, MAXVAL) pmn[i] = -1;
	FORE(i, 2, MAXVAL) if (pmn[i] == -1) for (int j = i; j <= MAXVAL; j += i) if (pmn[j] == -1) pmn[j] = i;
	REP(i, MAXNODE) adj[i].clear(), alive[i] = false;
	REP(i, n) alive[a[i]] = true;
	FORE(i, 2, MAXVAL) if (pmn[i] == i) alive[MAXSIDE + i] = true;
	FORE(i, 2, MAXVAL) {
		int x = i;
		while (x != 1) {
			int p = pmn[x];
			while (x % p == 0) x /= p;
			adj[i].PB(MAXSIDE + p);
			adj[MAXSIDE + p].PB(i);
		}
	}
	ncomp = 0;
	REP(i, MAXNODE) comp[i] = -1;
	REP(i, MAXNODE) if (comp[i] == -1 && alive[i]) {
		queue<int> q;
		comp[i] = ncomp++;
		q.push(i);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			for (int to : adj[at]) {
				if (!alive[to]) continue;
				if (comp[to] != -1) { assert(comp[to] == comp[at]); continue; }
				comp[to] = comp[at];
				q.push(to);
			}
		}
	}
	set<pair<int, int>> one;
	REP(i, n) {
		vector<int> lst;
		lst.PB(comp[a[i]]);
		for (int x : adj[a[i] + 1]) lst.PB(comp[x]);
		sort(lst.begin(), lst.end());
		lst.erase(unique(lst.begin(), lst.end()), lst.end());
		REPSZ(j, lst) FORSZ(k, j + 1, lst) one.insert(MP(lst[j], lst[k]));
	}


	REP(i, nq) {
		int s = comp[a[qs[i]]], t = comp[a[qt[i]]];
		if (s > t) swap(s, t);
		if (s == t) qans[i] = 0; else if (one.count(MP(s, t))) qans[i] = 1; else qans[i] = 2;
	}

}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nq) scanf("%d%d", &qs[i], &qt[i]), --qs[i], --qt[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}