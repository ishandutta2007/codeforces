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

const int MAXN = 1000;
const int MAXM = 100000;
const int MAXTEST = 2000;
const int MAXMODIFICATION = 4242;
const int MAXQ = 20;
string readstring() { char buff[100]; scanf("%s", buff); return string(buff); }
struct Modification { char kind; int a, b; Modification() {} Modification(char kind, int a, int b) :kind(kind), a(a), b(b) {} };

int n, m, ntest;
int e[MAXM][2];
vector<Modification> modifications;

vector<int> adj[MAXN];
vector<int> revadj[MAXN];
int outdeg[MAXN];

vector<int> grundy; // grundy[i] = node which will get grundy number i
int grundyval[MAXN];
int grundymask[MAXN];

int who[1 << MAXQ];

void solvemodifications() {
	REP(i, n) adj[i].clear(), revadj[i].clear();
	REP(i, m) { int a = e[i][0], b = e[i][1]; adj[a].PB(b), revadj[b].PB(a); }
	REP(i, n) outdeg[i] = SZ(adj[i]);
	queue<int> q;
	REP(i, n) if (outdeg[i] == 0) q.push(i);
	int want = min(n, MAXQ);
	grundy.clear();
	while (!q.empty() && SZ(grundy) < want) {
		int at = q.front(); q.pop();
		grundy.PB(at);
		REPSZ(i, revadj[at]) { int to = revadj[at][i]; if (--outdeg[to] == 0) q.push(to); }
	}
	assert(SZ(grundy) == want);
	REP(i, n) grundyval[i] = -1;
	REPSZ(i, grundy) grundyval[grundy[i]] = i;
	REP(at, n) { grundymask[at] = 0; REPSZ(i, adj[at]) { int to = adj[at][i]; if (grundyval[to] != -1) grundymask[at] |= 1 << grundyval[to]; } }

	modifications.clear();
	REPSZ(i, grundy) {
		int at = grundy[i];
		assert(grundymask[at] < (1 << i));
		REP(j, i) if ((grundymask[at] & (1 << j)) == 0) { modifications.PB(Modification('+', grundy[i], grundy[j])); grundymask[at] |= 1 << j; }
	}
	REP(at, n) if (grundyval[at] == -1) modifications.PB(Modification('+', at, at));

	vector<int> diffopt;
	diffopt.PB(0);
	int rem = n;
	vector<bool> done(n, false); REP(at, n) if (grundyval[at] != -1) done[at] = true, --rem;
	REP(mask, 1 << SZ(grundy)) who[mask] = -1;
	while (true) {
		REP(at, n) if (!done[at]) {
			REPSZ(i, diffopt) {
				int nmask = grundymask[at] ^ diffopt[i];
				if (who[nmask] != -1) continue;
				REPSZ(j, grundy) if (diffopt[i] & (1 << j)) modifications.PB(Modification(grundymask[at] & (1 << j) ? '-' : '+', at, grundy[j])), grundymask[at] ^= 1 << j;
				assert(grundymask[at] == nmask);
				done[at] = true;
				who[nmask] = at;
				--rem;
				break;
			}
		}
		if (rem == 0) break;
		vector<int> ndiffopt;
		REPSZ(i, diffopt) REPSZ(j, grundy) if (diffopt[i] < (1 << j)) ndiffopt.PB(diffopt[i] | (1 << j));
		swap(diffopt, ndiffopt);
	}
}

bool local = false;
int localans;
int localgrundy[MAXN];
vector<int> localadj[MAXN];
vector<int> localrevadj[MAXN];
int localoutdeg[MAXN];

string query(vector<int> q) {
	if (!local) {
		printf("? %d", SZ(q)); REPSZ(i, q) printf(" %d", q[i] + 1); puts(""); fflush(stdout);
		string ret = readstring();
		if (ret == "Slow") exit(0);
		return ret;
	} else {
		q.PB(localans);
		int sum = 0;
		int ncyc = 0;
		REPSZ(i, q) {
			int at = q[i];
			if (localgrundy[at] != -1) sum ^= localgrundy[at]; else ++ncyc;
		}
		if (ncyc == 0) return sum == 0 ? "Lose" : "Win";
		if (ncyc >= 2) return "Draw";
		REPSZ(i, q) {
			int at = q[i];
			if (localgrundy[at] != -1) continue;
			REPSZ(j, localadj[at]) { int to = localadj[at][j]; if (localgrundy[to] != -1 && localgrundy[to] == sum) return "Win"; }
		}
		return "Draw";
	}
}

int solvetest() {
	int winmask = 0;
	REPSZ(i, grundy) {
		string s = query({ grundy[i] });
		if (s == "Draw") continue;
		else if (s == "Win") winmask |= 1 << i;
		else if (s == "Lose") return grundy[i];
		else assert(false);
	}
	return who[winmask];
}


void run() {
	scanf("%d%d%d", &n, &m, &ntest);
	REP(i, m) REP(j, 2) scanf("%d", &e[i][j]), --e[i][j];
	solvemodifications();
	printf("%d\n", SZ(modifications));
	REPSZ(i, modifications) printf("%c %d %d\n", modifications[i].kind, modifications[i].a + 1, modifications[i].b + 1);
	fflush(stdout);
	REP(i, ntest) {
		int ans = solvetest();
		printf("! %d\n", ans + 1);
		fflush(stdout);
		string s = readstring();
		if (s != "Correct") exit(0);
	}
}

void precalclocal() {
	map<pair<int, int>,int> have;
	REP(i, m) { int a = e[i][0], b = e[i][1]; assert(!have.count(MP(a, b))); have[MP(a, b)] = 1; }
	REPSZ(i, modifications) { 
		char kind = modifications[i].kind; int a = modifications[i].a, b = modifications[i].b;  
		if (kind == '+') have[MP(a, b)]++;
		if (kind == '-') assert(have[MP(a, b)] >= 1), --have[MP(a, b)];
	}
	REP(i, n) localadj[i].clear(), localrevadj[i].clear();
	for (auto it = have.begin(); it != have.end(); ++it) REP(k, it->second) { int a = it->first.first, b = it->first.second; localadj[a].PB(b), localrevadj[b].PB(a); }
	REP(i, n) localoutdeg[i] = SZ(localadj[i]);
	//printf("localoutdeg:"); REP(i, n) printf(" %d", localoutdeg[i]); puts("");
	//printf("grundy:"); REPSZ(i, grundy) printf(" %d", grundy[i]); puts("");
	queue<int> q;
	REP(i, n) if (localoutdeg[i] == 0) q.push(i);
	REP(i, n) localgrundy[i] = -2;
	while (!q.empty()) {
		int at = q.front(); q.pop();
		set<int> opt; REPSZ(i, localadj[at]) { int to = localadj[at][i]; assert(localgrundy[to] >= 0); opt.insert(localgrundy[to]); }
		localgrundy[at] = 0;
		while (opt.count(localgrundy[at])) ++localgrundy[at];
		//printf("%d: %d\n", at, localgrundy[at]);
		REPSZ(i, localrevadj[at]) { int to = localrevadj[at][i]; if (--localoutdeg[to] == 0) q.push(to); }
	}
	REP(at, n) if (localgrundy[at] == -2) {
		localgrundy[at] = -1;
		bool found = false; REPSZ(i, localadj[at]) { int to = localadj[at][i]; if (to == at) found = true; } assert(found);
	}

}

void stress() {
	local = true;
	REP(rep, 100) {
		n = rnd() % MAXN + 1;
		//n = rnd() % 30 + 1;
		m = rnd() % (min(MAXM, n * (n - 1) / 2) + 1);
		//n = 60, m = n * (n - 1) / 2;
		vector<int> top(n); REP(i, n) top[i] = i; REP(i, n) { int idx = rnd() % (i + 1); swap(top[i], top[idx]); }
		set<pair<int, int>> seen; REP(i, m) while (true) { int a = rnd() % n, b = rnd() % n; if (a > b) swap(a, b); if (a == b || seen.count(MP(a, b))) continue; seen.insert(MP(a, b)); e[i][0] = top[a], e[i][1] = top[b]; break; }
		solvemodifications();
		printf("%d modifications\n", SZ(modifications));
		//REPSZ(i, modifications) printf("%c %d %d\n", modifications[i].kind, modifications[i].a + 1, modifications[i].b + 1);
		precalclocal();
		ntest = rnd() % min(MAXTEST, n) + 1;
		set<int> seentest;
		REP(i, ntest) {
			while (true) { localans = rnd() % n; if (seentest.count(localans)) continue; seentest.insert(localans); break; }
			int have = solvetest();
			assert(have == localans);
			printf(".");
		}
		puts("!");
	}
}

int main() {
	run();
	//stress();
	return 0;
}