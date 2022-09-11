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

const int MAXN = 12;

int n, m, alph;
vector<int> adj[MAXN];

ll solve() {
	vector<vector<vector<int>>> mark(1 << n, vector<vector<int>>(n, vector<int>(n, -1)));
	int curmark = -1;

	ll ret = 0;

	map<unsigned int, bool> mem;

	auto norm = [&](vector<int> col, int ncol) {
		REPSZ(i, col) assert(col[i] >= 0 && col[i] < ncol);
		vector<int> mp(ncol, -1);
		int nxt = 0;
		REPSZ(i, col) {
			int x = col[i];
			if (mp[x] == -1) mp[x] = nxt++;
			col[i] = mp[x];
		}
		REP(i, ncol) assert(mp[i] != -1);
		return col;
	};

	auto valid = [&](auto self, vector<int> col,int ncol) {
		unsigned int key = 0;
		REPSZ(i, col) key = key * 6 + col[i];
		if (false) return false;
		if (mem.count(key)) return mem[key];

		vector<int> cnt(ncol, 0);
		REPSZ(i, col) ++cnt[col[i]];
		REP(i, ncol) if (cnt[i] >= 4) {
			int first = -1;
			REPSZ(j, col) if (col[j] == i) { first = j; break; }
			assert(first != -1);
			FORSZ(j, first + 1, col) if (col[j] == i) {
				col[first] = col[j] = ncol;
				if (self(self, norm(col, ncol + 1), ncol + 1)) return mem[key] = true;
				col[first] = col[j] = i;
			}
			return mem[key] = false;
		}

		++curmark;
		//printf("cm=%d\n", curmark);
		//printf("col: "); REPSZ(i, col) printf("%c", 'a' + col[i]); puts("");
		queue<pair<int, pair<int, int>>> q;
		auto found = [&](int mask, int a, int b) { if (a > b) swap(a, b); if (mark[mask][a][b] == curmark) return; mark[mask][a][b] = curmark; q.push(MP(mask, MP(a, b))); };
		REP(a, n) for (int b : adj[a]) if (col[b] == col[a]) found((1 << a) | (1 << b), a, b);
		while (!q.empty()) {
			int mask = q.front().first, a = q.front().second.first, b = q.front().second.second; q.pop();
			if (mask == (1 << n) - 1) { /*printf("ok\n");*/ return mem[key] = true; }
			for (int aa : adj[a]) if ((mask & (1 << aa)) == 0) for (int bb : adj[b]) if ((mask & (1 << bb)) == 0 && bb != aa && col[bb] == col[aa]) found(mask | (1 << aa) | (1 << bb), aa, bb);
		};
		return mem[key] = false;
	};

	vector<ll> fac(alph + 1); fac[0] = 1; FORE(i, 1, alph) fac[i] = (ll)fac[i - 1] * i;
	auto calc = [&](vector<int> col, int ncol) {
		if (ncol > alph) return 0LL;
		return fac[alph] / fac[alph - ncol];
	};

	auto rec = [&](auto self, vector<int> col, int c) {
		int last = -1; REPSZ(i, col) if (col[i] == c) last = i;
		if (last == -1) {
			int first = -1; REPSZ(i, col) if (col[i] == -1) { first = i; break; }
			if (first == -1) {
				if (valid(valid, col, c)) ret += calc(col, c);
				return;
			}
			FORSZ(j, first + 1, col) if (col[j] == -1) {
				col[first] = col[j] = c;
				self(self, col, c);
				col[first] = col[j] = -1;
			}
		} else {
			FORSZ(i, last + 1, col) if (col[i] == -1) FORSZ(j, i + 1, col) if (col[j] == -1) {
				col[i] = col[j] = c;
				self(self, col, c);
				col[i] = col[j] = -1;
			}
			self(self, col, c + 1);
		}
	};
	rec(rec, vector<int>(n, -1), 0);
	return ret;
}

void run() {
	scanf("%d%d%d", &n, &m, &alph);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%lld\n", solve());
}

void research() {
	int cnt;
	auto rec = [&](auto self, vector<int> col, int c) {
		int last = -1; REPSZ(i, col) if (col[i] == c) last = i;
		if (last == -1) {
			int first = -1; REPSZ(i, col) if (col[i] == -1) { first = i; break; }
			if (first == -1) { ++cnt; return; }
			FORSZ(j, first + 1, col) if(col[j]==-1) {
				col[first] = col[j] = c;
				self(self, col, c);
				col[first] = col[j] = -1;
			}
		} else {
			FORSZ(i, last + 1, col) if (col[i] == -1) FORSZ(j, i + 1, col) if (col[j] == -1) {
				col[i] = col[j] = c;
				self(self, col, c);
				col[i] = col[j] = -1;
			}
			self(self, col, c + 1);
		}
	};
	for (int n = 2; n <= 12; n += 2) {
		cnt = 0;
		rec(rec, vector<int>(n, -1), 0);
		printf("%d=%d\n", n, cnt);
	}
}

int main() {
	//research();
	run();
	return 0;
}