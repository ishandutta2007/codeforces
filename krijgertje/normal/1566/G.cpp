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

const int MAXN = 100000;
const int MAXM = 100000;
const int MAXQ = 100000;

int n, m;
int e[MAXM + MAXQ][3];
int nq;
int qkind[MAXQ], q[MAXQ][3];
ll qans[MAXQ + 1];

int qid[MAXQ];

ll localsum[MAXN];
set<pair<int, int>> localbest[MAXN];
set<pair<int, int>> localother[MAXN];
set<pair<int, int>> globalbest;
set<pair<ll, int>> starbest;

void updateglobal(int id) {
	int a = e[id][0], b = e[id][1], c = e[id][2];
	bool want = localbest[a].count(MP(c, id)) && localbest[b].count(MP(c, id));
	if (want) {
		globalbest.insert(MP(c, id));
	} else {
		globalbest.erase(MP(c, id));
	}
}

void updatelocal(int x) {
	starbest.erase(MP(localsum[x], x));
	while (SZ(localbest[x]) < 3 && SZ(localother[x]) > 0) {
		auto it = localother[x].begin();
		int id = it->second;
		localbest[x].insert(*it);
		localsum[x] += e[id][2];
		localother[x].erase(it);
		updateglobal(id);
	}
	while (SZ(localbest[x]) > 0 && SZ(localother[x]) > 0 && prev(localbest[x].end())->first > localother[x].begin()->first) {
		auto bestit = prev(localbest[x].end());
		auto othit = localother[x].begin();
		int othid = othit->second, bestid = bestit->second;
		localbest[x].insert(*othit);
		localsum[x] += e[othid][2];
		localother[x].erase(othit);
		localother[x].insert(*bestit);
		localbest[x].erase(bestit);
		localsum[x] -= e[bestid][2];
		updateglobal(bestid);
		updateglobal(othid);
	}
	if (SZ(localbest[x]) == 3) starbest.insert(MP(localsum[x], x));
}

void addlocal(int x, int c, int id) {
	localother[x].insert(MP(c, id));
	updatelocal(x);
}

void addedge(int id) {
	int a = e[id][0], b = e[id][1], c = e[id][2];
	addlocal(a, c, id);
	addlocal(b, c, id);
}

void remlocal(int x, int c, int id) {
	localother[x].erase(MP(c, id));
	if (localbest[x].count(MP(c, id))) starbest.erase(MP(localsum[x], x)), localsum[x] -= e[id][2];
	localbest[x].erase(MP(c, id));
	updatelocal(x);
}

void remedge(int id) {
	int a = e[id][0], b = e[id][1], c = e[id][2];
	globalbest.erase(MP(c, id));
	remlocal(a, c, id);
	remlocal(b, c, id);
}

ll calcdisjoint() {
	ll ret = LLONG_MAX;
	if (SZ(globalbest) == 0) return ret;
	auto it = globalbest.begin();
	int id = it->second;
	int a = e[id][0], b = e[id][1], c = e[id][2];
	for (auto it2 = globalbest.begin(); it2 != globalbest.end(); ++it2) {
		int id2 = it2->second;
		int a2 = e[id2][0], b2 = e[id2][1], c2 = e[id2][2];
		if (a2 == a || a2 == b || b2 == a || b2 == b) continue;
		ret = min(ret, (ll)c + c2);
		break;
	}
	for (auto it3 = localbest[a].begin(); it3 != localbest[a].end(); ++it3) {
		int id3 = it3->second;
		int a3 = e[id3][0], b3 = e[id3][1], c3 = e[id3][2];
		for (auto it4 = localbest[b].begin(); it4 != localbest[b].end(); ++it4) {
			int id4 = it4->second;
			int a4 = e[id4][0], b4 = e[id4][1], c4 = e[id4][2];
			if (a4 == a3 || a4 == b3 || b4 == a3 || b4 == b3) continue;
			ret = min(ret, (ll)c3 + c4);
		}
	}
	return ret;
}

ll calcstar() {
	if (SZ(starbest) == 0) return LLONG_MAX;
	return starbest.begin()->first;
}

ll calc() {
	return min(calcdisjoint(), calcstar());
}

void solve() {
	globalbest.clear(), starbest.clear();
	REP(i, n) localsum[i] = 0, localbest[i].clear(), localother[i].clear();

	map<pair<int, int>, int> eid;
	REP(i, m) { int a = e[i][0], b = e[i][1]; auto key = MP(min(a, b), max(a, b)); assert(!eid.count(key)); eid[key] = i; }
	int mm = m;
	REP(i, nq) {
		if (qkind[i] == 1) {
			int a = q[i][0], b = q[i][1], c = q[i][2];
			auto key = MP(min(a, b), max(a, b)); assert(!eid.count(key)); eid[key] = mm; qid[i] = mm;
			e[mm][0] = a, e[mm][1] = b, e[mm][2] = c, ++mm;
		} else {
			int a = q[i][0], b = q[i][1];
			auto key = MP(min(a, b), max(a, b)); assert(eid.count(key)); qid[i] = eid[key]; eid.erase(key);
		}
	}
	REP(i, m) addedge(i);
	qans[0] = calc();
	REP(i, nq) {
		if (qkind[i] == 1) {
			addedge(qid[i]);
		} else {
			remedge(qid[i]);
		}
		qans[i + 1] = calc();
	}
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) scanf("%d%d%d", &e[i][0], &e[i][1], &e[i][2]), --e[i][0], --e[i][1];
	scanf("%d", &nq);
	REP(i, nq) { scanf("%d%d%d", &qkind[i], &q[i][0], &q[i][1]), --q[i][0], --q[i][1]; if (qkind[i] == 1) scanf("%d", &q[i][2]); }
	solve();
	REPE(i, nq) printf("%lld\n", qans[i]);
}

ll qansstupid[MAXQ + 1];

void solvestupid() {
	int mm = m;
	vector<bool> alive(mm, true);
	auto disjoint = [&](int x, int y) { int a = e[x][0], b = e[x][1], c = e[y][0], d = e[y][1]; return a != c && a != d && b != c && b != d; };
	auto star = [&](int x, int y, int z) {
		if (disjoint(x, y)) return false;
		int a = e[x][0], b = e[x][1], c = e[y][0], d = e[y][1], f = e[z][0], g = e[z][1];
		if (a == d) swap(c, d); else if (b == c) swap(a, b); else if (b == d) swap(a, b), swap(c, d);
		assert(a == c);
		return f == a || g == a;
	};
	auto calc = [&]() {
		ll ret = LLONG_MAX;
		REP(i, mm) if(alive[i]) FOR(j, i + 1, mm) if (alive[j]) if (disjoint(i, j)) ret = min(ret, (ll)e[i][2] + e[j][2]);
		REP(i, mm) if (alive[i]) FOR(j, i + 1, mm) if (alive[j]) FOR(k, j + 1, mm) if (alive[k]) if (star(i, j, k)) ret = min(ret, (ll)e[i][2] + e[j][2] + e[k][2]);
		return ret;
	};
	qansstupid[0] = calc();
	REP(i, nq) {
		if (qkind[i] == 1) {
			int a = q[i][0], b = q[i][1], c = q[i][2];
			e[mm][0] = a, e[mm][1] = b, e[mm][2] = c, ++mm; alive.PB(true);
		} else {
			int a = q[i][0], b = q[i][1];
			REP(j, mm) if (e[j][0] == a && e[j][1] == b) alive[j] = false;
		}
		qansstupid[i + 1] = calc();
	}
}

void stress() {
	REP(rep, 10000) {
		n = 10;
		m = rnd() % 10;
		nq = rnd() % 10;
		set<pair<int, int>> have;
		REP(i, m) while (true) { int a = rnd() % n, b = rnd() % n, c = rnd() % 100 + 1; if (a > b) swap(a, b); if (a == b || have.count(MP(a, b))) continue; have.insert(MP(a, b)); e[i][0] = a, e[i][1] = b, e[i][2] = c; break; }
		REP(i, nq) while(true) {
			qkind[i] = rnd() % 2 + 1;
			if (qkind[i] == 1) {
				while (true) { int a = rnd() % n, b = rnd() % n, c = rnd() % 100 + 1; if (a > b) swap(a, b); if (a == b || have.count(MP(a, b))) continue; have.insert(MP(a, b)); q[i][0] = a, q[i][1] = b, q[i][2] = c; break; }
				break;
			} else {
				if (SZ(have) == 0) continue;
				while (true) { int a = rnd() % n, b = rnd() % n; if (a > b) swap(a, b); if (!have.count(MP(a, b))) continue; have.erase(MP(a, b)); q[i][0] = a, q[i][1] = b; break; }
				break;
			}
		}
		solve();
		solvestupid();
		bool ok = true; REPE(i, nq) if (qans[i] != qansstupid[i]) ok = false;
		if (ok) { printf("."); continue; }
		printf("err\n");
		printf("have:"); REPE(i, nq) printf(" %lld", qans[i]); puts("");
		printf("want:"); REPE(i, nq) printf(" %lld", qansstupid[i]); puts("");
		printf("%d %d\n", n, m);
		REP(i, m) printf("%d %d %d\n", e[i][0] + 1, e[i][1] + 1, e[i][2]);
		printf("%d\n", nq);
		REP(i, nq) { printf("%d %d %d", qkind[i], q[i][0] + 1, q[i][1] + 1); if (qkind[i] == 1) printf(" %d", q[i][2]); puts(""); }
	}
}

int main() {
	run();
	//stress();
	return 0;
}