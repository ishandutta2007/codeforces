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

const int MAXN = 100000;
const int MAXLIM = 20;

int n, m, lim;
vector<pair<int, int>> adj[MAXN];
ll ans[MAXN];

void dijkstra() {
	set<pair<ll, int>> q;
	REP(i, n) if (ans[i] != LLONG_MAX) q.insert(MP(ans[i], i));
	while (!q.empty()) {
		int at = q.begin()->second; q.erase(q.begin());
		for (const auto& e : adj[at]) {
			int to = e.first, cost = e.second;
			if (ans[at] + cost < ans[to]) {
				q.erase(MP(ans[to], to));
				ans[to] = ans[at] + cost;
				q.insert(MP(ans[to], to));
			}
		}
	}
}

ll best[MAXN];
pair<ll, int > opt[MAXN];
pair<ll, int> q[MAXN]; int qhead, qtail;

ll eval(const pair<ll, int>& o, int i) { return o.first + (ll)o.second * i; }
ll takeover(const pair<ll, int>& a, const pair<ll, int>& b) {
	assert(a.second < b.second);
	if (a.first < b.first) return 0;
	ll num = a.first - b.first; int den = b.second - a.second;
	return (num + den - 1) / den;
}

void flyright() {
	REP(i, n) opt[i] = MP(ans[i] + (ll)i * i, -2 * i);
	// best[i] = min(best[i], i^2+min(j<i, opt[j].first+i*opt[j].second))
	qhead = qtail = 0;
	REP(i, n) {
		while (qhead - qtail >= 2 && eval(q[qtail + 1], i) <= eval(q[qtail], i)) ++qtail;
		if (qhead - qtail >= 1) best[i] = min(best[i], (ll)i * i + eval(q[qtail], i));
		if (ans[i] == LLONG_MAX) continue;
		while (qhead - qtail >= 2 && takeover(q[qhead - 1], q[qhead - 2]) >= takeover(opt[i], q[qhead - 1])) --qhead;
		q[qhead++] = opt[i];
	}
}
void flyleft() {
	REP(i, n) opt[i] = MP(ans[i] + (ll)(n - i - 1) * (n - i - 1), -2 * (n - i - 1));
	qhead = qtail = 0;
	for (int i = n - 1; i >= 0; --i) {
		while (qhead - qtail >= 2 && eval(q[qtail + 1], n - i - 1) <= eval(q[qtail], n - i - 1)) ++qtail;
		if (qhead - qtail >= 1) best[i] = min(best[i], (ll)(n - i - 1) * (n - i - 1) + eval(q[qtail], n - i - 1));
		if (ans[i] == LLONG_MAX) continue;
		while (qhead - qtail >= 2 && takeover(q[qhead - 1], q[qhead - 2]) >= takeover(opt[i], q[qhead - 1])) --qhead;
		q[qhead++] = opt[i];
	}
}

void fly() {
	REP(i, n) best[i] = ans[i];
	flyright();
	flyleft();
	REP(i, n) ans[i] = best[i];
}

void solve() {
	REP(i, n) ans[i] = i == 0 ? 0 : LLONG_MAX;
	dijkstra();
	REP(i, lim) {
		fly();
		dijkstra();
	}
}

void run() {
	scanf("%d%d%d", &n, &m, &lim);
	REP(i, m) { int a, b, c; scanf("%d%d%d", &a, &b, &c), --a, --b; adj[a].PB(MP(b, c)); adj[b].PB(MP(a, c)); }
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%lld", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}