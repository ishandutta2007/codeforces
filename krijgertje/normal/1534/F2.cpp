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

const int DX[] = { -1,0,+1,0 }, DY[] = { 0,+1,0,-1 };

int h, w;
vector<string> board;
vector<int> need;

int nsand;
vector<vector<int>> sandid;

vector<vector<int>> out;
vector<vector<int>> down;

vector<int> comp; int ncomp;
vector<int> id, mnid; int nid;
vector<int> stck;

vector<vector<int>> compout;
vector<bool> compmarked;
vector<bool> compdead;
vector<int> targetcomps;
vector<vector<int>> compin;
vector<int> firsttarget, lasttarget;
vector<int> endpoint;

void tarjan(int at) {
	id[at] = mnid[at] = nid++;
	stck.PB(at);
	for (int to : out[at]) {
		if (comp[to] != -1) continue;
		if (id[to] == -1) {
			tarjan(to);
			mnid[at] = min(mnid[at], mnid[to]);
		} else {
			mnid[at] = min(mnid[at], id[to]);
		}
	}
	if (mnid[at] == id[at]) {
		while (comp[at] == -1) comp[stck.back()] = ncomp, stck.pop_back();
		++ncomp;
	}
}

int solve() {
	nsand = 0;
	sandid = vector<vector<int>>(h, vector<int>(w, -1));
	REP(x, h) REP(y, w) if (board[x][y] == '#') sandid[x][y] = nsand++;
	//REP(x, h) { REP(y, w) printf("%2d ", sandid[x][y]); puts(""); }
	
	out = vector<vector<int>>(nsand);
	down = sandid;
	for (int x = h - 2; x >= 0; --x) REP(y, w) if (down[x][y] == -1) down[x][y] = down[x + 1][y];
	REP(x, h) REP(y, w) if (board[x][y] == '#') {
		REP(k, 4) {
			int nx = x + DX[k], ny = y + DY[k];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			int at = sandid[x][y], to = down[nx][ny];
			if (to == -1 || to == at) continue;
			//printf("%d->%d\n", at, to);
			out[at].PB(to);
		}
	}

	ncomp = 0, nid = 0; comp = id = mnid = vector<int>(nsand, -1); stck = vector<int>();
	REP(i, nsand) if (comp[i] == -1) tarjan(i);
	//printf("comp:"); REP(i, nsand) printf(" %d", comp[i]); puts("");

	compout = vector<vector<int>>(ncomp);
	REP(at, nsand) for (int to : out[at]) if (comp[to] != comp[at]) compout[comp[at]].PB(comp[to]);
	REP(i, ncomp) { sort(compout[i].begin(), compout[i].end()); compout[i].erase(unique(compout[i].begin(), compout[i].end()), compout[i].end()); }
	//REP(i, ncomp) { printf("comp%d:", i); for (int j : compout[i]) printf(" %d", j); puts(""); }

	compmarked = vector<bool>(ncomp, false);
	REP(y, w) {
		int rem = need[y];
		if (rem == 0) continue;
		for (int x = h - 1; x >= 0; --x) if (board[x][y] == '#') {
			--rem;
			if (rem == 0) {
				compmarked[comp[sandid[x][y]]] = true;
				break;
			}
		}
		assert(rem == 0);
	}

	compdead = vector<bool>(ncomp, false);
	queue<int> q;
	auto killcomp = [&](int to) { if (compdead[to]) return; compdead[to] = true; q.push(to); };
	REP(at, ncomp) if (compmarked[at]) for (int to : compout[at]) killcomp(to);
	while (!q.empty()) {
		int at = q.front(); q.pop();
		for (int to : compout[at]) killcomp(to);
	}

	targetcomps.clear();
	vector<bool> seencomp(ncomp, false);
	REP(y, w) {
		int rem = need[y];
		if (rem == 0) continue;
		for (int x = h - 1; x >= 0; --x) if (board[x][y] == '#') {
			--rem;
			if (rem == 0) {
				int c = comp[sandid[x][y]];
				if (!compdead[c] && (targetcomps.empty() || c != targetcomps.back())) {
					assert(!seencomp[c]);
					seencomp[c] = true;
					targetcomps.PB(c);
				}
				break;
			}
		}
		assert(rem == 0);
	}
	//printf("targetcomps:"); REPSZ(i, targetcomps) printf(" %d", targetcomps[i]); puts("");

	compin = vector<vector<int>>(ncomp);
	REP(at, ncomp) for (int to : compout[at]) compin[to].PB(at);
	firsttarget = vector<int>(ncomp, INT_MAX);
	REPSZ(i, targetcomps) {
		queue<int> q;
		auto relax = [&](int to) { if (firsttarget[to] != INT_MAX) return; firsttarget[to] = i; q.push(to); };
		relax(targetcomps[i]);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			for (int to : compin[at]) relax(to);
		}
	}
	lasttarget = vector<int>(ncomp, INT_MIN);
	for (int i = SZ(targetcomps) - 1; i >= 0; --i) {
		queue<int> q;
		auto relax = [&](int to) { if (lasttarget[to] != INT_MIN) return; lasttarget[to] = i; q.push(to); };
		relax(targetcomps[i]);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			for (int to : compin[at]) relax(to);
		}
	}
	//REP(i, ncomp) if (firsttarget[i] <= lasttarget[i]) printf("%d: %d..%d\n", i, firsttarget[i], lasttarget[i]);
	//REP(x, h) { REP(y, w) if (sandid[x][y] == -1) printf("xx "); else  printf("%2d ", comp[sandid[x][y]]); puts(""); }

	endpoint = vector<int>(SZ(targetcomps), INT_MIN);
	REP(i, ncomp) if (firsttarget[i] <= lasttarget[i]) endpoint[firsttarget[i]] = max(endpoint[firsttarget[i]], lasttarget[i]);

	int ret = 0, have = INT_MIN, best = INT_MIN;
	REPSZ(i, targetcomps) {
		best = max(best, endpoint[i]);
		if (i > have) {
			assert(best >= i);
			++ret;
			have = best;
		}
	}
	return ret;
}

void run() {
	scanf("%d%d", &h, &w);
	board = vector<string>(h);
	REP(x, h) cin >> board[x];
	need = vector<int>(w);
	REP(y, w) scanf("%d", &need[y]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}