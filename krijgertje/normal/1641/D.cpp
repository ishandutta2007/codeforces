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
#include <unordered_map>
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

//https://codeforces.com/blog/entry/62393
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

const int MAXN = 100000;
const int MAXK = 5;
struct Z { int a[MAXK], w; };

int n, k;
Z z[MAXN];

int cnt;
struct Node { unordered_map<long long, int, custom_hash> nxt; int sum; };
Node node[MAXN * (1 << MAXK)]; int nnode, root;

int makenode() {
	int ret = nnode++;
	node[ret].nxt.clear();
	node[ret].sum = 0;
	return ret;
}
void reset() {
	cnt = 0;
	nnode = 0;
	root = makenode();
}
void mod(int idx, int by) {
	//printf("mod(%d,%d)\n", idx, by);
	cnt += by;
	auto rec = [&](auto self, int at, int i, int val) -> void {
		if (i == k) {
			if (at != root) {
				node[at].sum += val;
				//printf("\t%d += %d\n", at, val);
			}
		} else {
			self(self, at, i + 1, val);
			auto it = node[at].nxt.find(z[idx].a[i]);
			int to;
			if (it != node[at].nxt.end()) {
				to = it->second;
			} else {
				to = makenode();
				//printf("\t\t%d + %d -> %d\n", at, z[idx].a[i], to);
				node[at].nxt[z[idx].a[i]] = to;
			}
			self(self, to, i + 1, -val);
		}
	};
	rec(rec, root, 0, -by);
}
void add(int idx) {
	mod(idx, +1);
}
void remove(int idx) {
	mod(idx, -1);
}
bool can(int idx) {
	auto rec = [&](auto self, int at, int i) -> int {
		if (i == k) {
			//printf("\t %d = %d\n", at, node[at].sum);
			return node[at].sum;
		} else {
			int ret = self(self, at, i + 1);
			auto it = node[at].nxt.find(z[idx].a[i]);
			if (it != node[at].nxt.end()) {
				int to = it->second;
				ret += self(self, to, i + 1);
			}
			return ret;
		}
	};
	int have = rec(rec, root, 0);
	//printf("can(%d) -> %d vs %d\n", idx, have, cnt);
	return have != cnt;
}

int solve() {
	sort(z, z + n, [&](const Z &p, const Z &q) { return p.w < q.w; });
	REP(i, n) sort(z[i].a, z[i].a + k);
	//REP(i, n) { printf("%d:", i); REP(j, k) printf(" %d", z[i].a[j]); printf(" = %d\n", z[i].w); }
	int l = 0, r = 0;
	reset();
	while (r < n) {
		if (can(r)) break;
		add(r);
		++r;
	}
	if (r == n) return -1;
	while (true) {
		assert(l < r);
		remove(l);
		if (!can(r)) break;
		++l;
	}
	int ret = z[l].w + z[r].w;
	//printf("first = %d and %d\n", l, r);
	reset();
	--l;
	REPE(i, l) add(i);
	while (l >= 0 && r < n) {
		if (!can(r)) {
			++r;
			continue;
		}
		while (true) {
			assert(l >= 0);
			remove(l);
			if (!can(r)) break;
			--l;
		}
		//printf("other = %d and %d\n", l, r);
		ret = min(ret, z[l].w + z[r].w);
		--l, ++r;
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &k);
	REP(i, n) { REP(j, k) scanf("%d", &z[i].a[j]); scanf("%d", &z[i].w); }
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}