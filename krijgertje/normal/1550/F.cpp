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

const int MAXROCK = 200000;
const int MAXQ = 200000;

int nrock, nq, startidx; ll basedist;
ll a[MAXROCK];
int qidx[MAXQ], qrange[MAXQ]; bool qans[MAXQ];

ll when[MAXROCK];

ll best[MAXROCK][4];

void solve() {
	REP(i, nrock) when[i] = LLONG_MAX;
	REP(i, nrock) REP(j, 4) best[i][j] = LLONG_MAX;

	queue<int> q;
	priority_queue<pair<ll, pair<int, pair<int, int>>>> pq;
	set<pair<ll, int>> todo;
	REP(i, nrock) if (i != startidx) todo.insert(MP(a[i], i));
	q.push(startidx);
	ll currange = 0;
	auto relax = [&](int at, int x, int y) {
		ll pos = a[at] + x * basedist;
		auto it = todo.lower_bound(MP(pos, INT_MIN));
		if (y == +1) {
			if (it == todo.end()) return false;
		} else {
			if (it == todo.begin()) return false;
			it = prev(it);
		}
		int to = it->second;
		int key = (x == -1 ? 0 : 2) + (y == -1 ? 0 : 1);
		ll dist = abs(a[to] - pos);
		if (dist > best[to][key]) return false; else best[to][key] = dist;
		if (dist > currange) {
			pq.push(MP(-dist, MP(at, MP(x, y))));
			return false;
		} else {
			todo.erase(it);
			q.push(to);
			return true;
		}
	};
	while (!q.empty() || !pq.empty()) {
		if (!q.empty()) {
			int at = q.front(); q.pop();
			//printf("visit %d\n", at);
			when[at] = currange;
			for (int x = -1; x <= +1; x += 2) for (int y = -1; y <= +1; y += 2) while (true) if (!relax(at, x, y)) break;
		} else {
			ll dist = -pq.top().first; int at = pq.top().second.first, x = pq.top().second.second.first, y = pq.top().second.second.second; pq.pop();
			//printf("processing (%d,%d,%d) at %lld\n", at, x, y, dist);
			currange = dist;
			while (true) if (!relax(at, x, y)) break;
		}
	}

	//printf("when:"); REP(i, nrock) printf(" %lld", when[i]); puts("");
	REP(i, nq) qans[i] = when[qidx[i]] <= qrange[i];
}

void run() {
	scanf("%d%d%d%lld", &nrock, &nq, &startidx, &basedist); --startidx;
	REP(i, nrock) scanf("%lld", &a[i]);
	REP(i, nq) scanf("%d%d", &qidx[i], &qrange[i]), --qidx[i];
	solve();
	REP(i, nq) printf("%s\n", qans[i] ? "Yes" : "No");
}

void hack() {
	nrock = MAXROCK;
	int nl = nrock / 2, nr = nrock - nl;
	startidx = nl;
	basedist = (ll)3 * nl * nr;
	REP(i, nl) a[i] = i == 0 ? 0 : a[i - 1] + nr + 1;
	REP(i, nr) a[nl + i] = a[nl + i - 1] + (i == 0 ? basedist + 2 * nr : 1);
	a[nrock - 1] = a[nrock - 2] + basedist;
	nq = 0;
	printf("%d %d %d %lld\n", nrock, nq, startidx + 1, basedist);
	//REP(i, nrock) { if (i != 0) printf(" "); printf("%lld", a[i]); } puts("");
	solve();

}

int main() {
	run();
	//hack();
	return 0;
}