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
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 200000;
const int MAXQ = 200000;
struct Block { int lpos, rpos; int best, best2; };

int n, m, nq;
int scost[MAXN];
vector<pair<int, int>> adj[MAXN];
int qidx[MAXQ], qdelta[MAXQ];
ull qans[MAXQ + 1];

ll d[MAXN];
int par[MAXN];
int pos[MAXN], ord[MAXN], nord;
bool done[MAXN];
int suffpos[MAXN];


ull ccost[MAXN];
map<int, Block> blocks;
set<int> bestchanges;

int totcount[MAXN + 1];
vector<int> ch[MAXN];

int best2count(int lpos, int rpos, int at) {
	if (at == 0) return 0;
	int r = upper_bound(ch[at].begin(), ch[at].end(), rpos) - ch[at].begin();
	int l = lower_bound(ch[at].begin(), ch[at].end(), lpos) - ch[at].begin();
	return r - l;
}
int bestcount(int lpos, int rpos, int at) {
	return totcount[rpos + 1] - totcount[lpos] - best2count(lpos, rpos, at);
}
ull calc(const Block& b) {
	int cnt = totcount[b.rpos + 1] - totcount[b.lpos];
	if (cnt == 0) return 0;
	assert(b.best != -1);
	ull ret = cnt * ccost[b.best];
	if (b.best != 0) {
		assert(b.best2 != -1);
		ret += (ccost[b.best2] - ccost[b.best]) * best2count(b.lpos, b.rpos, b.best);
	}
	//printf("\tcalc(%d..%d:%d/%d) = %llu\n", b.lpos, b.rpos, b.best, b.best2, ret);
	return ret;
}


void solve() {
	REP(i, n) d[i] = LLONG_MAX;
	priority_queue<pair<ll, int>> pq;
	auto relax = [&](int at, int to, ll val) { if (val >= d[to]) return; d[to] = val; par[to] = at; pq.push(MP(-val, -to)); };
	relax(-1, 0, 0);
	nord = 0;
	while (!pq.empty()) {
		int at = -pq.top().second; ll val = -pq.top().first; pq.pop();
		if (val != d[at]) continue;
		pos[at] = nord, ord[nord] = at, ++nord;
		REPSZ(i, adj[at]) {
			int to = adj[at][i].first; ll nval = val + adj[at][i].second;
			relax(at, to, nval);
		}
	}
	assert(nord == n);
	REP(at, n) { done[at] = at == 0; REPSZ(i, adj[at]) { int to = adj[at][i].first; int len = adj[at][i].second; if (to != par[at] && d[to] + len == d[at]) done[at] = true; } }
	REP(i, n) { int at = ord[i]; suffpos[at] = i == 0 ? 0 : suffpos[ord[i - 1]]; while (suffpos[at] < n && d[ord[suffpos[at]]] <= d[at]) ++suffpos[at]; }
	totcount[0] = 0; REP(i, n) totcount[i + 1] = totcount[i] + (!done[ord[i]] ? 1 : 0);
	REP(i, n) ch[i].clear();
	REP(i, n) { int at = ord[i]; if (!done[at] && par[at] != -1) ch[par[at]].PB(i); }
	//printf("ord:"); REP(i, n) printf(" %d", ord[i] + 1); puts("");
	//printf("d:"); REP(i, n) printf(" %lld", d[ord[i]]); puts("");
	//printf("suffpos:"); REP(i, n) printf(" %d", suffpos[ord[i]]); puts("");
	//printf("done:"); REP(i, n) printf(" %c", done[ord[i]] ? '.' : 'x'); puts("");
	//printf("par:"); REP(i, n) printf(" %d", par[ord[i]] + 1); puts("");

	REP(i, n) ccost[i] = scost[i];
	REP(i, nq) ccost[qidx[i]] += qdelta[i];
	{
		blocks.clear();
		bestchanges.clear();
		Block b; b.lpos = 0, b.best = b.best2 = -1;
		bestchanges.insert(0);
		REP(i, n) {
			int at = ord[i];
			if (b.best2 != -1 && ccost[at] >= ccost[b.best2]) continue;
			b.rpos = suffpos[at] - 1;
			if (b.lpos <= b.rpos) blocks[b.lpos] = b;
			b.lpos = suffpos[at];
			if (b.best == -1 || ccost[at] < ccost[b.best]) b.best2 = b.best, b.best = at, bestchanges.insert(b.lpos); else b.best2 = at;
		}
		b.rpos = n - 1;
		if (b.lpos <= b.rpos) blocks[b.lpos] = b;
	}

	ull curans = 0;
	for (const auto& p : blocks) { const auto& b = p.second; curans += calc(b); }
	qans[nq] = curans;
	for (int i = nq - 1; i >= -1; --i) {
		//printf("q%d:\n", i);
		//printf("ccost:"); REP(j, n) printf(" %llu", ccost[ord[j]]); puts("");
		//printf("blocks:"); for (const auto& p : blocks) printf(" [%d..%d:%d/%d]", p.second.lpos, p.second.rpos, p.second.best, p.second.best2); puts("");
		//printf("bestchanges:"); for (const auto& z : bestchanges) printf(" %d", z); puts("");
		if (i == -1) break;
		int at = qidx[i];
		ull ocost = ccost[at], ncost = ccost[at] - qdelta[i];
		auto it = prev(blocks.lower_bound(suffpos[at] + 1));
		if (suffpos[at] < n && (it->second.best == at || it->second.best2 == at || it->second.best2 == -1 || ncost < ccost[it->second.best2])) {
			if (it->first != suffpos[at]) {
				Block b = it->second;
				it->second.rpos = suffpos[at] - 1;
				b.lpos = suffpos[at];
				it = blocks.insert(MP(suffpos[at], b)).first;
			}
			if (it->second.best == at) {
				auto jt = bestchanges.upper_bound(suffpos[at]);
				int topos = jt == bestchanges.end() ? n : *jt;
				//printf("reduce [%d..%d]\n", suffpos[at], topos - 1);
				curans -= (ull)qdelta[i] * bestcount(suffpos[at], topos - 1, at);
				it = topos == n ? blocks.end() : blocks.find(topos);
			}

			auto update = [&](Block& b) {
				assert(b.best != at);
				if (b.best2 == at) { if (ncost < ccost[b.best]) swap(b.best, b.best2); return true; }
				if (b.best2 != -1 && ncost >= ccost[b.best2]) return false;
				if (b.best == -1 || ncost < ccost[b.best]) b.best2 = b.best, b.best = at; else b.best2 = at;
				return true;
			};
			while (it != blocks.end()) {
				//printf("pos=%d\n", it->first);
				curans -= calc(it->second);
				bool change = update(it->second);
				ccost[at] = ncost; curans += calc(it->second); ccost[at] = ocost;
				if (!change) break;
				if (it != blocks.begin()) {
					auto pt = prev(it);
					if (pt->second.best == it->second.best) bestchanges.erase(it->first); else bestchanges.insert(it->first);
					if (pt->second.best == it->second.best && pt->second.best2 == it->second.best2) {
						pt->second.rpos = it->second.rpos;
						blocks.erase(it);
						it = pt;
					}
				}
				++it;
			}
		}
		ccost[at] = ncost;
		qans[i] = curans;
	}
}

void run() {
	scanf("%d%d%d", &n, &m, &nq);
	REP(i, n) scanf("%d", &scost[i]);
	REP(i, m) { int a, b, c; scanf("%d%d%d", &a, &b, &c); --a, --b; adj[a].PB(MP(b, c)); adj[b].PB(MP(a, c)); }
	REP(i, nq) scanf("%d%d", &qidx[i], &qdelta[i]), --qidx[i];
	solve();
	REPE(i, nq) printf("%llu\n", qans[i]);
}

ull qansstupid[MAXQ];

void solvestupid() {
	vector<vector<ll>> d(n, vector<ll>(n, LLONG_MAX));
	REP(i, n) d[i][i] = 0;
	REP(at, n) for (const auto& e : adj[at]) { int to = e.first, len = e.second; d[at][to] = d[to][at] = len; }
	REP(k, n) REP(i, n) REP(j, n) if (d[i][k] != LLONG_MAX && d[k][j] != LLONG_MAX) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	REP(i, n) assert(d[0][i] != LLONG_MAX);
	REP(i, n) par[i] = -1, done[i] = i == 0;
	REP(at, n) for (const auto& e : adj[at]) { int to = e.first, len = e.second; if (d[0][to] == d[0][at] + len) { if (par[to] == -1) par[to] = at; else done[to] = true; } }

	REP(i, n) ccost[i] = scost[i];
	REPE(i, nq) {
		qansstupid[i] = 0;
		REP(to, n) if (!done[to]) {
			ull best = ccost[0];
			FOR(at, 1, n) if (d[0][at] < d[0][to] && at != par[to]) best = min(best, ccost[at]);
			qansstupid[i] += best;
		}
		if (i == nq) break;
		ccost[qidx[i]] += qdelta[i];
	}
}

void stress() {
	std::mt19937 rnd(1234);
	int nmx = 100, cmx = 4, qmx = 10, costmx = 10;
	REP(rep, 100000) {
		n = rnd() % nmx + 1;
		m = n - 1 + rnd() % (n * (n - 1) / 2 - (n - 1) + 1);
		REP(i, n) scost[i] = rnd() % costmx + 1;
		vector<int> col(n); REP(i, n) col[i] = i;
		set<pair<int, int>> edges;
		REP(i, n - 1) while (true) { int a = rnd() % n, b = rnd() % n; if (col[a] == col[b]) continue; int ocol = col[b]; REP(j, n) if (col[j] == ocol) col[j] = col[a]; edges.insert(MP(min(a, b), max(a, b))); break; }
		REP(i, m - (n - 1)) while (true) { int a = rnd() % n, b = rnd() % n; if (a > b) swap(a, b); if (a == b || edges.count(MP(a, b))) continue; edges.insert(MP(a, b)); break; }
		vector<pair<int, int>> elst(edges.begin(), edges.end());
		vector<int> ecost;
		shuffle(elst.begin(), elst.end(), rnd);
		REP(i, n) adj[i].clear();
		for (const auto& e : elst) { int a = e.first, b = e.second, c = rnd() % cmx + 1; adj[a].PB(MP(b, c)); adj[b].PB(MP(a, c)); ecost.PB(c); }
		nq = rnd() % (qmx + 1);
		REP(i, nq) qidx[i] = rnd() % n, qdelta[i] = rnd() % costmx + 1;
		solve();
		solvestupid();
		bool ok = true; REPE(i, nq) if (qans[i] != qansstupid[i]) ok = false;
		if (ok) { if (rep % 100 == 99) printf("."); continue; }
		printf("err rep=%d\n", rep);
		printf("have:"); REPE(i, nq) printf(" %llu", qans[i]); puts("");
		printf("want:"); REPE(i, nq) printf(" %llu", qansstupid[i]); puts("");
		printf("%d %d %d\n", n, m, nq); REP(i, n) { if (i != 0) printf(" "); printf("%d", scost[i]); } puts(""); REPSZ(i, elst) { printf("%d %d %d\n", elst[i].first + 1, elst[i].second + 1, ecost[i]); } REP(i, nq) printf("%d %d\n", qidx[i] + 1, qdelta[i]);
		nmx = max(1, n - 1);
		qmx = max(0, nq - 1);
	}
}

int main() {
	run();
	//stress();
	return 0;
}