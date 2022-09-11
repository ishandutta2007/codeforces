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

int sz, n;
int sx, sy, tx, ty;
int px[MAXN], py[MAXN];

int xx[MAXN], yy[MAXN], nxx, nyy;

vector<ll> d;
vector<vector<int>> who;
priority_queue<pair<ll, int>> pq;

ll solve() {
	nxx = 0; REP(i, n) xx[nxx++] = px[i];
	sort(xx, xx + nxx); nxx = unique(xx, xx + nxx) - xx;
	REP(i, n) px[i] = lower_bound(xx, xx + nxx, px[i]) - xx;
	nyy = 0; REP(i, n) yy[nyy++] = py[i];
	sort(yy, yy + nyy); nyy = unique(yy, yy + nyy) - yy;
	REP(i, n) py[i] = lower_bound(yy, yy + nyy, py[i]) - yy;
	d = vector<ll>(nxx + nyy, LLONG_MAX);
	who = vector<vector<int>>(nxx + nyy);
	pq = priority_queue<pair<ll, int>>();
	auto upd = [&](int id, ll val) { if (val < d[id]) d[id] = val, pq.push(MP(-d[id], id)); };
	REP(i, n) who[px[i]].PB(i), who[nxx + py[i]].PB(i), upd(px[i], abs(xx[px[i]] - sx)), upd(nxx + py[i], abs(yy[py[i]] - sy));
	while (!pq.empty()) {
		ll cost = -pq.top().first; int at = pq.top().second; pq.pop();
		if (cost != d[at]) continue;
		REPSZ(i, who[at]) {
			int idx = who[at][i];
			int xid = px[idx], yid = py[idx];
			if (xid - 1 >= 0) upd(xid - 1, d[at] + xx[xid] - xx[xid - 1]);
			upd(xid, d[at]);
			if (xid + 1 < nxx) upd(xid + 1, d[at] + xx[xid + 1] - xx[xid]);
			if (yid - 1 >= 0) upd(nxx + yid - 1, d[at] + yy[yid] - yy[yid - 1]);
			upd(nxx + yid, d[at]);
			if (yid + 1 < nyy) upd(nxx + yid + 1, d[at] + yy[yid + 1] - yy[yid]);
		}
	}
	ll ret = abs(sx - tx) + abs(sy - ty);
	REP(i, n) ret = min(ret, min(d[px[i]], d[nxx + py[i]]) + abs(xx[px[i]] - tx) + abs(yy[py[i]] - ty));
	return ret;
}

void run() {
	scanf("%d%d", &sz, &n);
	scanf("%d%d%d%d", &sx, &sy, &tx, &ty), --sx, --sy, --tx, --ty;
	REP(i, n) scanf("%d%d", &px[i], &py[i]), --px[i], --py[i];
	printf("%lld\n", solve());
}


int main() {
	run();
	return 0;
}