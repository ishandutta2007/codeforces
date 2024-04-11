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

const int MAXN = 300000;
const int MAXM = 300000;
const int MAXV = MAXN;

int n, m;
int a[MAXN];
int e[MAXM][2];

int v[MAXV], nv;
int cnt[MAXV];
set<pair<int, int>> forbid;

int w[MAXV], nw;
vector<vector<int>> who;

ll calc(const vector<int> &a, const vector<int> &b) {
	int na = SZ(a), nb = SZ(b);
	vector<int> at(na, 0);
	priority_queue<pair<ll, int>> pq;
	pq.push(MP((ll)v[a[0]] + v[b[at[0]]], 0));
	while (!pq.empty()) {
		int idx = pq.top().second; pq.pop();
		int i = a[idx], j = b[at[idx]];
		if (i != j && !forbid.count(MP(i, j))) return (ll)v[i] + v[j];
		++at[idx];
		if (at[idx] < SZ(b)) pq.push(MP((ll)v[a[idx]] + v[b[at[idx]]], idx));
		if (at[idx] == 1 && idx + 1 < SZ(a)) pq.push(MP((ll)v[a[idx + 1]] + v[b[at[idx + 1]]], idx + 1));
	}
	return LLONG_MIN;
}

ll solve() {
	nv = 0;
	REP(i, n) v[nv++] = a[i];
	sort(v, v + nv);
	nv = unique(v, v + nv) - v;
	REP(i, nv) cnt[i] = 0;
	REP(i, n) {
		int idx = lower_bound(v, v + nv, a[i]) - v;
		++cnt[idx];
	}
	forbid.clear();
	REP(i, m) {
		int a = lower_bound(v, v + nv, e[i][0]) - v; assert(a != nv && v[a] == e[i][0]);
		int b = lower_bound(v, v + nv, e[i][1]) - v; assert(b != nv && v[b] == e[i][1]);
		forbid.insert(MP(a, b));
		forbid.insert(MP(b, a));
	}
	nw = 0;
	REP(i, nv) w[nw++] = cnt[i];
	sort(w, w + nw);
	nw = unique(w, w + nw) - w;
	who = vector<vector<int>>(nw);
	REP(i, nv) {
		int idx = lower_bound(w, w + nw, cnt[i]) - w;
		who[idx].PB(i);
	}
	REP(i, nw) reverse(who[i].begin(), who[i].end());
	ll ret = LLONG_MIN;
	REP(i, nw) FOR(j, i, nw) {
		ll cur = calc(who[i], who[j]);
		if (cur == LLONG_MIN) continue;
		cur *= w[i] + w[j];
		ret = max(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, m) REP(j, 2) scanf("%d", &e[i][j]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}