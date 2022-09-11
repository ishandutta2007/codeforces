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

const int MAXPAIR = 100000;
const int MAXDIM = 250;

int npair, dim;
pair<int, int> p[MAXPAIR][2];

int solve() {
	int n = (dim + 1) * (dim + 1);
	vector<map<int, int>> w(n);
	vector<bool> t(n);
	REPE(x, dim) REPE(y, dim) {
		t[x * (dim + 1) + y] = x == 0 || x == dim || y == 0 || y == dim;
		FORE(dx, -1, +1) FORE(dy, -1, +1) if (dx * dx + dy * dy == 1) {
			int nx = x + dx, ny = y + dy;
			if (nx<0 || nx>dim || ny<0 || ny>dim) continue;
			w[x * (dim + 1) + y][nx * (dim + 1) + ny] = 0;
		}
	}

	REP(i, npair) REP(rep,2) {
		int x1 = p[i][0].first, y1 = p[i][0].second, x2 = p[i][1].first, y2 = p[i][1].second;
		if (rep == 1) x1 = dim - x1 - 1, y1 = dim - y1 - 1, x2 = dim - x2 - 1, y2 = dim - y2 - 1;
		if (x1 > x2 || y1 > y2) swap(x1, x2), swap(y1, y2);
		pair<int, int> a, b;
		if (x1 == x2) {
			assert(y2 == y1 + 1);
			a = MP(x1, y2), b = MP(x1 + 1, y2);
		} else {
			assert(y1 == y2 && x2 == x1 + 1);
			a = MP(x2, y1), b = MP(x2, y1 + 1);
		}
		++w[a.first * (dim + 1) + a.second][b.first * (dim + 1) + b.second];
		++w[b.first * (dim + 1) + b.second][a.first * (dim + 1) + a.second];
	}

	vector<int> d(n, INT_MAX);
	priority_queue<pair<int, int>> pq;
	auto relax = [&](int to, int val) { if (val >= d[to]) return; d[to] = val; pq.push(MP(-d[to], to)); };
	relax((dim / 2)*(dim + 1) + (dim / 2), 0);
	while (!pq.empty()) {
		int cost = -pq.top().first, at = pq.top().second; pq.pop();
		if (d[at] != cost) continue;
		//printf("(%d,%d) = %d\n", at / (dim + 1), at % (dim + 1), cost);
		if (t[at]) return npair - cost;
		for (auto z : w[at]) {
			int to = z.first, ncost = cost + z.second;
			//printf("\t(%d,%d) = %d\n", to / (dim + 1), to % (dim + 1), ncost);
			relax(to, ncost);
		}
	}
	assert(false);
	return -1;
}

void run() {
	scanf("%d%d", &npair, &dim);
	REP(i, npair) REP(j, 2) scanf("%d%d", &p[i][j].first, &p[i][j].second), --p[i][j].first, --p[i][j].second;
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}