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

const int MAXDIM = 1000;
const int MAXQ = 10000;

int h, w, nq;
int qx[MAXQ], qy[MAXQ];
ll qans[MAXQ];

vector<pair<int, int>> diag[MAXDIM][MAXDIM];
int len[MAXDIM + MAXDIM];
set<int> dblocked[MAXDIM + MAXDIM];
set<pair<int, int>> allblocked;

void solve() {
	auto calc = [&](int len) { return (ll)len * (len - 1) / 2; };
	FOR(sy, -h, w) {
		int x = 0, y = sy, pos = 0;
		while (x < h) {
			if (y >= 0 && y < w) diag[x][y].PB(MP(sy + h, pos++));
			++y;
			if (y >= 0 && y < w) diag[x][y].PB(MP(sy + h, pos++));
			++x;
		}
		len[sy + h] = pos;
	}
	ll curans = (ll)h * w;
	REP(d, h + w) curans += calc(len[d]);
	REP(i, nq) {
		int x = qx[i], y = qy[i];
		if (allblocked.count(MP(x, y)) == 0) {
			--curans;
			allblocked.insert(MP(x, y));
			for (const auto& z : diag[x][y]) {
				int d = z.first, pos = z.second;
				auto it = dblocked[d].lower_bound(pos);
				int r = it == dblocked[d].end() ? len[d] : *it;
				int l = it == dblocked[d].begin() ? 0 : *prev(it) + 1;
				curans -= calc(r - l);
				curans += calc(pos - l) + calc(r - (pos + 1));
				dblocked[d].insert(pos);
			}
		} else {
			++curans;
			allblocked.erase(MP(x, y));
			for (const auto& z : diag[x][y]) {
				int d = z.first, pos = z.second;
				auto it = dblocked[d].lower_bound(pos);
				int r = next(it) == dblocked[d].end() ? len[d] : *next(it);
				int l = it == dblocked[d].begin() ? 0 : *prev(it) + 1;
				curans -= calc(pos - l) + calc(r - (pos + 1));
				curans += calc(r - l);
				dblocked[d].erase(it);
			}
		}
		qans[i] = curans;
	}
}

void run() {
	scanf("%d%d%d", &h, &w, &nq);
	REP(i, nq) scanf("%d%d", &qx[i], &qy[i]), --qx[i], --qy[i];
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}