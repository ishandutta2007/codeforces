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

const int MAXN = 200000;

int n, stoken;
vector<int> adj[MAXN];
int pinit[MAXN];

int p[MAXN];
bool seen[MAXN];


bool solve() {
	assert(n >= 3);
	int center = -1;
	REP(i, n) if (SZ(adj[i]) == n - 1) { assert(center == -1); center = i; }
	if (center == -1) return true;

	int token = stoken;
	REP(i, n) p[i] = pinit[i];
	if (p[center] != center) {
		if (token == center || token == p[center]) return false;
		int x = -1, y = center;
		REP(i, n) if (p[i] == center) { assert(x == -1); x = i; } assert(x != -1);
		assert(p[x] != token && p[y] != token && x != y);
		swap(p[x], p[y]);
		assert(p[center] == center && token != center);
		token = center;
	}

	vector<int> bad;
	REP(i, n) if (p[i] != i) bad.PB(i);
	if (SZ(bad) == 0) return true;
	if (SZ(bad) == 2) { int x = bad[0], y = bad[1]; assert(p[x] == y && p[y] == x); if (token != x && token != y) return true; }
	
	assert(p[center] == center);
	REP(i, n) seen[i] = false;
	int par = 0;
	REP(i, n) if (!seen[i]) {
		int at = i, len = 0;
		while (!seen[at]) {
			seen[at] = true, ++len;
			at = p[at];
		}
		if (len % 2 == 0) par = 1 - par;
	}
	return par == (token == center ? 1 : 0);
}

void run() {
	scanf("%d%d", &n, &stoken), --stoken;
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	REP(i, n) scanf("%d", &pinit[i]), --pinit[i];
	printf("%s\n", solve() ? "Alice" : "Bob");
	REP(i, n) adj[i].clear();
}

bool solvestupid() {
	vector<int> pp(n); REP(i, n) pp[i] = i;
	vector<vector<int>> lst;
	map<vector<int>, int> mp;
	do { mp[pp] = SZ(lst); lst.PB(pp); } while (next_permutation(pp.begin(), pp.end()));
	int nstate = 2 * n * SZ(lst);
	vector<vector<int>> trans(nstate);
	vector<vector<int>> rtrans(nstate);
	REP(turn, 2) REP(token, n) REPSZ(at, lst) {
		int key = (at * n + token) * 2 + turn;
		auto &p = lst[at];
		if (turn == 0) {
			REP(i, n) FOR(j, i + 1, n) if (p[i] != token && p[j] != token) {
				swap(p[i], p[j]);
				assert(mp.count(p));
				int to = mp[p];
				swap(p[i], p[j]);
				int nkey = (to * n + token) * 2 + (1 - turn);
				trans[key].PB(nkey);
				rtrans[nkey].PB(key);
			}
		} else {
			for (int ntoken : adj[token]) {
				int nkey = (at * n + ntoken) * 2 + (1 - turn);
				trans[key].PB(nkey);
				rtrans[nkey].PB(key);
			}
		}
	}
	vector<bool> win(nstate, false);
	vector<int> need(nstate, 0);
	REP(at, nstate) {
		int turn = at % 2;
		need[at] = turn == 0 ? 1 : SZ(trans[at]);
	}
	queue<int> q;
	REP(token, n) {
		int key = (0 * n + token) * 2 + 0;
		win[key] = true;
		q.push(key);
	}
	while (!q.empty()) {
		int at = q.front(); q.pop();
		int turn = at % 2;
		for (int to : rtrans[at]) {
			--need[to];
			if (!win[to] && need[to] <= 0) win[to] = true, q.push(to);
		}
	}
	vector<int> p(pinit, pinit + n);
	assert(mp.count(p));
	int start = mp[p];
	int startkey = (start * n + stoken) * 2 + 0;
	return win[startkey];
}

void stress() {
	std::mt19937 rnd(12321);
	int mxn = 6;
	REP(rep, 1000) {
		n = rnd() % (mxn - 3 + 1) + 3;
		stoken = rnd() % n;
		FOR(i, 1, n) adj[i].PB(0), adj[0].PB(i);
		REP(i, n) pinit[i] = i;
		REP(i, n) { int idx = rnd() % (i + 1); swap(pinit[i], pinit[idx]); }
		bool have = solve();
		bool want = solvestupid();
		if (have == want) {
			printf(".");
		} else {
			printf("err rep=%d have=%s want=%s\n", rep, have ? "Alice" : "Bob", want ? "Alice" : "Bob");
			printf("%d %d\n", n, stoken + 1); REP(at, n) for (int to : adj[at]) if (at < to) printf("%d %d\n", at + 1, to + 1);
			REP(i, n) { if (i != 0) printf(" "); printf("%d", pinit[i] + 1); } puts("");
		}
		REP(i, n) adj[i].clear();
	}
}

int main() {
	//stress();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}