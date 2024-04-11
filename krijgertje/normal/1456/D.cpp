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

const int MAXN = 5000 + 1;

int n;
ll t[MAXN], x[MAXN];

bool can[MAXN][MAXN];
ll dclone[MAXN];
priority_queue<pair<ll, pair<int, int>>> pq;

void setpossible(int a, int b) {
	assert(a >= 0 && a < n);
	assert(b >= 0 && b < n);
	if (can[a][b]) return;
	can[a][b] = true;
	pq.push(MP((ll)-t[a], MP(a, b)));
}

void relaxclone(int b, ll cost) {
	assert(b >= 0 && b < n);
	if (cost >= dclone[b]) return;
	dclone[b] = cost;
	pq.push(MP(-cost, MP(-1, b)));
}

bool solve() {
	REP(i, n) REP(j, n) can[i][j] = false;
	REP(i, n) dclone[i] = LLONG_MAX;
	pq = priority_queue<pair<ll, pair<int, int>>>();
	setpossible(0, 0);
	can[0][0] = true; 
	while (!pq.empty()) {
		ll cost = -pq.top().first; int a = pq.top().second.first; int b = pq.top().second.second; pq.pop();
		if (a == -1 && cost != dclone[b]) continue;
		//printf("(%d,%d)=%lld\n", a, b, cost);
		if (a != -1) {
			assert(cost == t[a]);
			if (b == 0) {
				if (a == n - 1) return true;
				// we visit next and place no clone
				if (a + 1 < n && t[a] + abs(x[a + 1] - x[a]) <= t[a + 1]) setpossible(a + 1, 0);
				// we visit next and place a clone
				FOR(c, a + 2, n) if (t[a] + abs(x[c] - x[a]) + abs(x[c] - x[a + 1]) <= t[a + 1]) setpossible(a + 1, c);
				// we place a clone for next
				if (a + 1 < n && t[a] + abs(x[a + 1] - x[a]) <= t[a + 1]) relaxclone(a + 1, t[a] + abs(x[a + 1] - x[a]));
			} else if (a + 1 < b) {
				// we visit next and keep clone
				if (a + 1 < n && t[a] + abs(x[a + 1] - x[a]) <= t[a + 1]) setpossible(a + 1, b);
			} else {
				assert(a + 1 == b);
				if (b == n - 1) return true;
				// we visit the one after next and place no clone
				if (a + 2 < n && t[a] + abs(x[a + 2] - x[a]) <= t[a + 2]) setpossible(a + 2, 0);
				// we visit the one after next and place a clone
				FOR(c, a + 3, n) if (max(t[a] + abs(x[c] - x[a]), t[a + 1]) + abs(x[c] - x[a + 2]) <= t[a + 2]) setpossible(a + 2, c);
				// we place a clone for the one after next
				if (a + 2 < n && t[a] + abs(x[a + 2] - x[a]) <= t[a + 2]) relaxclone(a + 2, max(t[a] + abs(x[a + 2] - x[a]), t[a + 1]));
			}
		} else {
			if (b == n - 1) return true;
			// we visit next and place no clone
			if (b + 1 < n && cost + abs(x[b] - x[b + 1]) <= t[b + 1]) setpossible(b + 1, 0);
			// we visit next and place a clone
			FOR(c, b + 2, n) if (max(cost + abs(x[c] - x[b]), t[b]) + abs(x[c] - x[b + 1]) <= t[b + 1]) setpossible(b + 1, c);
			// we place a clone for next
			if (b + 1 < n && cost + abs(x[b] - x[b + 1]) <= t[b + 1]) relaxclone(b + 1, max(cost + abs(x[b] - x[b + 1]), t[b]));
		}
	}
	return false;
}

void run() {
	scanf("%d", &n);
	t[0] = x[0] = 0; ++n;
	FOR(i, 1, n) scanf("%lld%lld", &t[i], &x[i]);
	printf("%s\n", solve() ? "YES" : "NO");
}

bool solvestupid() {
	int tmx = t[n - 1];
	int xmx = 0, xmn = 0; REP(i, n) xmx = max((ll)xmx, x[i]), xmn = min((ll)xmn, x[i]);
	vector<vector<vector<bool>>> can(tmx + 1, vector<vector<bool>>(xmx - xmn + 1, vector<bool>(xmx - xmn + 1, false)));
	queue<pair<int, pair<int, int>>> q;
	can[0][0 - xmn][0 - xmn] = true; q.push(MP(0, MP(0, 0)));
	vector<int> need(tmx + 1, -1); REP(i, n) need[t[i]] = i;
	//printf("%d\n", (tmx + 1) * (xmx - xmn + 1) * (xmx - xmn + 1));
	while (!q.empty()) {
		int tt = q.front().first, me = q.front().second.first, cl = q.front().second.second; q.pop();
		//printf("%d %d %d (x=%d..%d)\n", tt, me, cl, xmn, xmx);
		if (tt == tmx) return true;
		REP(changeclone, 2) FORE(dx, -1, +1) {
			int nme = me + dx; if (nme<xmn || nme>xmx) continue;
			int ncl = changeclone ? me : cl;
			if (need[tt + 1] != -1 && nme != x[need[tt + 1]] && ncl != x[need[tt + 1]]) continue;
			if (can[tt + 1][nme - xmn][ncl - xmn]) continue;
			can[tt + 1][nme - xmn][ncl - xmn] = true, q.push(MP(tt + 1, MP(nme, ncl)));
		}
	}
	return false;
}

void stress() {
	std::mt19937 rnd(12312);
	REP(rep, 100000) {
		n = rnd() % 100 + 1;
		t[0] = x[0] = 0;
		set<int> seen;
		int lim = rnd() % 10 + 1;
		FOR(i, 1, n) { t[i] = t[i - 1] + rnd() % lim + 1; int dt = t[i] - t[i - 1]; while (true) { x[i] = x[i - 1] + rnd() % (2 * dt + 1) - 1 * dt; ++dt; if (seen.count(x[i])) continue; seen.insert(x[i]); break; } }
		//if (rep != 737) continue;
		bool have = solve();
		bool want = solvestupid();
		if (have == want) { printf("%c", have ? '.' : ','); continue; }
		printf("err%d: have=%d want=%d\n", rep, have ? 1 : 0, want ? 1 : 0);
		printf("%d\n", n - 1); FOR(i, 1, n) printf("%lld %lld\n", t[i], x[i]);
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}