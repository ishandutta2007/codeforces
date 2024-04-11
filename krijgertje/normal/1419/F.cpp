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
struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };
bool operator<(const P& a, const P& b) { if (a.x != b.x) return a.x < b.x; return a.y < b.y; }
bool operator==(const P& a, const P& b) { return a.x == b.x && a.y == b.y; }

int n;
P p[MAXN];

vector<int> optadj[MAXN];

vector<pair<P, vector<int>>> opt;
map<P, int> optmp;

vector<int> adj[MAXN];
int col[MAXN], ncol;
int q[MAXN], qhead, qtail;

int dist(const P& a, const P& b) { return abs(a.x - b.x) + abs(a.y - b.y); }

bool can(int mxdist) {
	REP(i, n) adj[i].clear();
	REP(at, n) REPSZ(i, optadj[at]) {
		int to = optadj[at][i];
		int d = dist(p[at],p[to]);
		if (d <= mxdist) adj[at].PB(to);
	}
	ncol = 0;
	REP(i, n) col[i] = -1;
	REP(i, n) if (col[i] == -1) {
		col[i] = ncol++; qhead = qtail = 0; q[qhead++] = i;
		while (qtail < qhead) {
			int at = q[qtail++];
			REPSZ(j, adj[at]) { int to = adj[at][j]; if (col[to] == -1) col[to] = col[at], q[qhead++] = to; }
		}
	}
	//printf("%d -> %d colors\n", mxdist, ncol);
	if (ncol == 1) return true;
	assert(ncol >= 2);
	if (ncol >= 5) return false;
	REPSZ(i, opt) {
		int seen = 0;
		P a = opt[i].first;
		REPSZ(j, opt[i].second) {
			int id = opt[i].second[j];
			P b = p[id];
			if (dist(a, b) <= mxdist) seen |= 1 << col[id];
		}
		//printf("(%d,%d) -> %x\n", a.x, a.y, seen);
		if (seen == (1 << ncol) - 1) return true;
	}

	return false;
}

P mid(const P& a, const P& b) { return P((a.x + b.x) / 2, (a.y + b.y) / 2); }
void addopt(P cur, int a, int b,bool rev) {
	if (rev) swap(cur.x, cur.y);
	if (optmp.count(cur) == 0) { optmp[cur] = SZ(opt); opt.PB(MP(cur, vector<int>())); }
	int idx = optmp[cur];
	opt[idx].second.PB(a); opt[idx].second.PB(b);
}

int solve() {
	REP(i, n) optadj[i].clear();
	opt.clear();
	optmp.clear();
	REP(rep,2) {
		map<int, vector<int>> byx; REP(i, n) byx[p[i].x].PB(i);
		for (auto it = byx.begin(); it != byx.end(); ++it) {
			vector<int> lst = it->second;
			sort(lst.begin(), lst.end(), [&](const int a, const int b) { return p[a].y < p[b].y; });
			FORSZ(i, 1, lst) { int a = lst[i - 1], b = lst[i]; optadj[a].PB(b); optadj[b].PB(a); if (p[b].y - p[a].y >= 2) addopt(mid(p[a], p[b]), a, b, rep == 1); }
		}
		REP(i, n) REP(j, n) if (p[i].x != p[j].x && p[i].y != p[j].y) addopt(P(p[i].x, p[j].y), i, j, rep == 1);
		REP(i, n) swap(p[i].x, p[i].y);
	}
	REPSZ(i, opt) { sort(opt[i].second.begin(), opt[i].second.end()); opt[i].second.erase(unique(opt[i].second.begin(), opt[i].second.end()), opt[i].second.end()); }
	//REPSZ(i, opt) { printf("opt%d: (%d,%d) ->", i, opt[i].first.x, opt[i].first.y); REPSZ(j, opt[i].second) printf(" (%d,%d)", p[opt[i].second[j]].x, p[opt[i].second[j]].y); puts(""); }

	int xmn = INT_MAX, xmx = INT_MIN, ymn = INT_MAX, ymx = INT_MIN;
	REP(i, n) xmn = min(xmn, p[i].x), xmx = max(xmx, p[i].x), ymn = min(ymn, p[i].y), ymx = max(ymx, p[i].y);
	int lo = 0, hi = max(xmx - xmn, ymx - ymn);
	if (!can(hi)) return -1;
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		if (can(mi)) hi = mi; else lo = mi;
	}
	return hi;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}