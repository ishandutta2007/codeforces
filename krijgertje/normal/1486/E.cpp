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
const int MAXC = 50;

int n, m;
vector<pair<int, int>> e[MAXN];
ll ans[MAXN];

ll d[MAXN][MAXC + 1];

void solve() {
	REP(i, n) REPE(j, MAXC) d[i][j] = LLONG_MAX;
	priority_queue<pair<ll, pair<int, int>>> pq;
	auto relax = [&](int at, int sofar, ll cost) { if (cost >= d[at][sofar]) return; d[at][sofar] = cost, pq.push(MP(-cost, MP(at, sofar))); };
	relax(0, 0, 0);
	while (!pq.empty()) {
		ll cost = -pq.top().first; int at = pq.top().second.first, sofar = pq.top().second.second; pq.pop();
		REPSZ(i,e[at]) {
			int to = e[at][i].first, c = e[at][i].second;
			int nsofar = sofar == 0 ? c : 0; ll ncost = sofar == 0 ? cost : cost + (sofar + c) * (sofar + c);
			relax(to, nsofar, ncost);
		}
	}
	REP(i, n) ans[i] = d[i][0] == LLONG_MAX ? -1 : d[i][0];
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b, c; scanf("%d%d%d", &a, &b, &c); --a, --b; e[a].PB(MP(b, c)); e[b].PB(MP(a, c)); }
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%lld", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}