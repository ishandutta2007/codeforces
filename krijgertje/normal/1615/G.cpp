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
#include <functional>
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

namespace MaxGeneralMatching {

	vector<int> solve(int n, vector<pair<int, int>> edges, vector<int> matches) {
		vector<bool> ismatched(SZ(edges), false);
		vector<int> match(n, -1);
		for (int id : matches) match[edges[id].first] = match[edges[id].second] = id, ismatched[id] = true;
		vector<vector<int>> adj(n);
		REPSZ(id, edges) adj[edges[id].first].PB(id), adj[edges[id].second].PB(id);
		while (true) {
			vector<int> parid(n, -1);
			vector<int> col(n, -1);
			bool found = false;
			REP(start, n) if (match[start] == -1) {
				parid[start] = -1;
				col[start] = 0;
				vector<pair<int, int>> stck;
				stck.PB(MP(start, 0));
				while (!stck.empty()) {
					int at = stck.back().first, idx = stck.back().second; stck.pop_back();
					if (idx >= SZ(adj[at])) continue;
					stck.PB(MP(at, idx + 1));
					int id = adj[at][idx];
					if (id == match[at]) continue;
					assert(col[at] == 0);
					int to = edges[id].first ^ edges[id].second ^ at;
					if (col[to] == 0) {
						vector<int> pathnodes;
						vector<int> pathedges;
						for (int x = at;;) {
							pathnodes.PB(x);
							if (x == to) break;
							int xid = parid[x];
							pathedges.PB(xid);
							x ^= edges[xid].first ^ edges[xid].second;
						}
						pathedges.PB(id);
						//printf("pathnodes:"); for (int x : pathnodes) printf(" %d", x); puts("");
						//printf("pathedges:"); for (int x : pathedges) printf(" %d", x); puts("");
						vector<int> mp(n, -1);
						int subn = 1;
						for (int x : pathnodes) mp[x] = 0;
						REP(x, n) if (mp[x] == -1) mp[x] = subn++;
						vector<pair<int, int>> subedges;
						vector<int> edgemp(SZ(edges), -1);
						vector<int> revedgemp;
						REPSZ(i, edges) if (mp[edges[i].first] != mp[edges[i].second]) edgemp[i] = SZ(subedges), revedgemp.PB(i), subedges.PB(MP(mp[edges[i].first], mp[edges[i].second]));
						vector<int> submatches;
						REP(x, n) if (match[x] != -1 && x == edges[match[x]].first && edgemp[match[x]] != -1) submatches.PB(edgemp[match[x]]);
						//printf("subedges:"); for (auto e : subedges) printf(" %d-%d", e.first, e.second); puts("");
						//printf("submatches:"); for (int x : submatches) printf(" %d-%d", subedges[x].first, subedges[x].second); puts("");
						submatches = solve(subn, subedges, submatches);
						//printf("sub->"); for (int x : submatches) printf(" %d-%d", subedges[x].first, subedges[x].second); puts("");
						vector<int> ret;
						for (int x : submatches) ret.PB(revedgemp[x]);
						REP(x, n) match[x] = -1;
						for (int x : ret) match[edges[x].first] = match[edges[x].second] = x;
						REPSZ(i, pathnodes) if (match[pathnodes[i]] != -1) {
							rotate(pathnodes.begin(), pathnodes.begin() + i, pathnodes.end());
							rotate(pathedges.begin(), pathedges.begin() + i, pathedges.end());
							break;
						}
						//printf("pathnodes:"); for (int x : pathnodes) printf(" %d", x); puts("");
						//printf("pathedges:"); for (int x : pathedges) printf(" %d", x); puts("");
						for (int i = 1; i < SZ(pathedges); i += 2) ret.PB(pathedges[i]);
						return ret;
					}
					if (col[to] == 1) {
						continue;
					}
					col[to] = 1;
					parid[to] = id;
					if (match[to] == -1) {
						vector<int> pathnodes;
						vector<int> pathedges;
						for (int x = to;;) {
							pathnodes.PB(x);
							int xid = parid[x];
							if (xid == -1) break;
							pathedges.PB(xid);
							x ^= edges[xid].first ^ edges[xid].second;
						}
						//printf("pathnodes:"); for (int x : pathnodes) printf(" %d", x); puts("");
						//printf("pathedges:"); for (int x : pathedges) printf(" %d", x); puts("");
						assert(SZ(pathedges) % 2 == 1);
						REPSZ(i, pathedges) assert(ismatched[pathedges[i]] == (i % 2 == 1));
						for (int id : pathedges) ismatched[id] = !ismatched[id];
						for (int i = 1; i < SZ(pathedges); i += 2) {
							int x = pathnodes[i], y = pathnodes[i + 1];
							assert(match[x] == pathedges[i] && match[y] == pathedges[i]);
						}
						for (int i = 0; i < SZ(pathedges); i += 2) {
							int x = pathnodes[i], y = pathnodes[i + 1];
							match[x] = match[y] = pathedges[i];
						}
						found = true;
						break;
					} else {
						int matchid = match[to];
						int nxt = edges[matchid].first ^ edges[matchid].second ^ to;
						assert(col[nxt] == -1);
						col[nxt] = 0;
						parid[nxt] = matchid;
						stck.PB(MP(nxt, 0));
					}
				}
				if (found) break;
			}
			if (!found) {
				vector<int> ret;
				REPSZ(i, edges) if (ismatched[i]) ret.PB(i);
				return ret;
			}
		}
	}

	vector<int> solve(int n, vector<pair<int, int>> edges) {
		//printf("solve:"); REPSZ(i, edges) printf(" %d-%d", edges[i].first, edges[i].second); puts("");
		vector<int> ret = solve(n, edges, vector<int>());
		//printf("->"); for (int i : ret) printf(" %d-%d", edges[i].first, edges[i].second); puts("");
		return ret;
	}
};

struct UF {
	int n; vector<int> par, sz;
	void init(int _n) { n = _n; par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1; }
	int find(int x) { if (par[x] != x) par[x] = find(par[x]); return par[x]; }
	bool unite(int x, int y) { x = find(x), y = find(y); if (x == y) return false; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; return true; }
};

const int MAXN = 300000;
struct Seg { int l, r, x, y; Seg(int l, int r, int x, int y) :l(l), r(r), x(x), y(y) {} };
struct OddEdge { int to, pos, id; OddEdge(int to, int pos, int id) :to(to), pos(pos), id(id) {} };


int n;
int a[MAXN];
int ans[MAXN];

bool have[MAXN];


vector<OddEdge> oddadj[MAXN];
bool oddbeen[MAXN];
int oddcomp[MAXN];

void dfsodd(int at) {
	if (oddbeen[at]) return; else oddbeen[at] = true;
	for (auto e : oddadj[at]) {
		if (!have[e.to]) {
			ans[e.pos] = e.to;
			have[e.to] = true;
		}
		dfsodd(e.to);
	}
}
void dfscomp(int at, int c) {
	if (oddcomp[at] != -1) return; else oddcomp[at] = c;
	for (auto e : oddadj[at]) dfscomp(e.to, c);
}
int dfscycle(int at, int parid) {
	if (oddbeen[at]) return at; else oddbeen[at] = true;
	for (auto e : oddadj[at]) {
		if (e.id == parid) continue;
		int sub = dfscycle(e.to, e.id);
		if (sub == -1) return -1;
		if (sub >= 0) {
			ans[e.pos] = e.to;
			have[e.to] = true;
			return sub == at ? -1 : sub;
		}
	}
	return -2;
}

void solve() {
	REP(i, n) ans[i] = a[i];
	REP(i, n) have[i] = false;
	REP(i, n - 1) if (a[i] >= 0 && a[i + 1] >= 0 && a[i] == a[i + 1]) have[a[i]] = true;

	vector<Seg> odd, evn;
	for (int l = 0, r = l; l < n; l = r) {
		while (r < n && a[r] == -1) ++r;
		int cnt = r - l;
		if (cnt == 0) { ++r; continue; }
		Seg s(l, r - 1, l == 0 ? -1 : a[l - 1], r == n ? -1 : a[r]);
		if (s.x == -1 && s.y != -1 && cnt % 2 == 1) ans[s.r] = s.y, have[s.y] = true, --s.r, --cnt;
		if (s.y == -1 && s.x != -1 && cnt % 2 == 1) ans[s.l] = s.x, have[s.x] = true, ++s.l, --cnt;
		if ((s.x == -1 || s.y == -1) && cnt % 2 == 1) { assert(s.x == -1 && s.y == -1); ans[s.r] = n - 1, --s.r, --cnt; }
		if (cnt % 2 == 0) evn.PB(s); else odd.PB(s);
	}

	REP(i, n) oddadj[i].clear();
	REPSZ(i, odd) {
		Seg s = odd[i];
		oddadj[s.x].PB(OddEdge(s.y, s.r, i));
		oddadj[s.y].PB(OddEdge(s.x, s.l, i));
	}
	REP(i, n) oddbeen[i] = false;
	REP(i, n) if (have[i]) dfsodd(i);
	REP(i, n) oddcomp[i] = -1;
	REP(i, n) if (oddcomp[i] == -1) dfscomp(i, i);
	REP(i, n) if (oddcomp[i] == i) dfscycle(i, -1);
	REP(i, n) oddbeen[i] = false;
	REP(i, n) if (have[i]) dfsodd(i);


	vector<Seg> nodd;
	for (auto s : odd) {
		assert(have[s.x] == have[s.y]);
		if (!have[s.x]) {
			assert(ans[s.l] == -1 && ans[s.r] == -1);
			nodd.PB(s);
		} else {
			if (s.l == s.r) {
				if (ans[s.l] == -1) ans[s.l] = n - 1;
			} else {
				assert(ans[s.l] == -1 || ans[s.r] == -1);
				if (ans[s.r] != -1) --s.r;
				else if (ans[s.l] != -1) ++s.l;
				else ans[s.r] = n - 1, --s.r;
				evn.PB(s);
			}
		}
	}
	//printf("odd:"); for (auto s : odd) printf(" %d..%d [%d %d]", s.l, s.r, s.x, s.y); puts("");
	//printf("evn:"); for (auto s : evn) printf(" %d..%d [%d %d]", s.l, s.r, s.x, s.y); puts("");
	odd = nodd;
	REP(i, n) oddadj[i].clear();
	REPSZ(i, odd) {
		Seg s = odd[i];
		oddadj[s.x].PB(OddEdge(s.y, s.r, i));
		oddadj[s.y].PB(OddEdge(s.x, s.l, i));
	}

	UF uf;
	uf.init(n);
	for (auto s : odd) assert(uf.unite(s.x, s.y));
	vector<Seg> boring, interesting;
	for (auto s : evn) {
		if (s.x == -1 || have[s.x] || s.y == -1 || have[s.y] || uf.find(s.x) == uf.find(s.y)) boring.PB(s); else interesting.PB(s);
	}

	vector<int> id(n, -1); int nid = 0;
	vector<pair<int, int>> evnedges;
	for (auto s : interesting) {
		if (id[uf.find(s.x)] == -1) id[uf.find(s.x)] = nid++;
		if (id[uf.find(s.y)] == -1) id[uf.find(s.y)] = nid++;
		evnedges.PB(MP(id[uf.find(s.x)], id[uf.find(s.y)]));
	}
	assert(nid <= 600);
	vector<int> match = MaxGeneralMatching::solve(nid, evnedges);
	for (int i : match) {
		auto &s = interesting[i];
		assert(!have[s.x] && !have[s.y] && s.x != s.y && s.l != s.r);
		ans[s.l] = s.x, have[s.x] = true, ++s.l;
		ans[s.r] = s.y, have[s.y] = true, --s.r;
	}
	for (auto s : interesting) if (s.l <= s.r) boring.PB(s);

	REP(i, n) if (have[i]) dfsodd(i);
	REP(i, n) if (!have[i]) { have[i] = true; dfsodd(i); have[i] = false; }
	for (auto s : odd) {
		if (s.l == s.r) {
			if (ans[s.l] == -1) ans[s.l] = n - 1;
		} else {
			assert(ans[s.l] == -1 || ans[s.r] == -1);
			if (ans[s.r] != -1) --s.r;
			else if (ans[s.l] != -1) ++s.l;
			else ans[s.r] = n - 1, --s.r;
			boring.PB(s);
		}
	}

	int nxt = 0;
	for (auto s : boring) {
		for (int pos = s.l; pos <= s.r; pos += 2) {
			while (have[nxt]) ++nxt;
			assert(ans[pos] == -1 && ans[pos + 1] == -1);
			ans[pos] = ans[pos + 1] = nxt, have[nxt] = true;
		}
	}
	//REP(i, n) assert(ans[i] != -1);
}


void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

void stress() {
	std::mt19937 rnd(123213);
	int mxn = 50;
	REP(rep, 1000000) {
		n = rnd() % mxn + 1;
		REP(i, n) a[i] = -1;
		int cnt = rnd() % (n + 1);
		int lim = rnd() % n;
		REP(i, cnt) while (true) { int idx = rnd() % n; if (a[idx] != -1) continue; a[idx] = rnd() % (lim + 1); break; }
		//if (rep != 75) continue;
		//printf("rep=%d\n", rep);
		//printf("%d\n", n); REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i] + 1); } puts("");
		solve();
		if (rep % 1000 == 999) { printf("."); fflush(stdout); }
	}
}

int main() {
	run();
	//stress();
	return 0;
}