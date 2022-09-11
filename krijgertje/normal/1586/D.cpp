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

const int MAXN = 100;

int n;
int ans[MAXN];

int prv[MAXN], nxt[MAXN];
int perm[MAXN];

bool local = false;
int alocal[MAXN];
int nq;

int query(vector<int> q) {
	++nq;
	if (!local) {
		printf("?"); REPSZ(i, q) printf(" %d", q[i]); puts(""); fflush(stdout);
		int ret; scanf("%d", &ret); return ret == 0 ? -1 : ret - 1;
	} else {
		//printf("?"); REPSZ(i, q) printf(" %d", q[i]); puts(""); fflush(stdout);
		map<int, int> seen;
		assert(SZ(q) == n);
		REP(i, n) {
			int x = alocal[i] + q[i];
			auto it = seen.find(x);
			if (it == seen.end()) { seen[x] = i; continue; }
			return it->second;
		}
		return -1;
	}
}

void solve() {
	REP(i, n) prv[i] = nxt[i] = -1;
	for (int i = n - 1; i >= 0; --i) {
		if (nxt[i] == -1) {
			vector<int> plus(n, 1); plus[i] = 2;
			int plusidx = query(plus);
			if (plusidx != -1) {
				assert(plusidx < i && prv[plusidx] == -1);
				//printf("%d before %d\n", i, plusidx);
				nxt[i] = plusidx, prv[plusidx] = i;
			}
		}
		if (prv[i] == -1) {
			vector<int> min(n, 2); min[i] = 1;
			int minidx = query(min);
			if (minidx != -1) {
				assert(minidx < i && nxt[minidx] == -1);
				//printf("%d before %d\n", minidx, i);
				prv[i] = minidx, nxt[minidx] = i;
			}
		}
	}
	int root = -1;
	REP(i, n) if (prv[i] == -1) { assert(root == -1); root = i; }
	assert(root != -1);
	int at = 0;
	for (int x = root; x != -1; x = nxt[x]) perm[at++] = x;
	REP(i, n) ans[perm[i]] = i;
	assert(at == n);
}

void run() {
	scanf("%d", &n);
	solve();
	printf("!"); REP(i, n) printf(" %d", ans[i] + 1); puts(""); fflush(stdout);
}

void stress() {
	local = true;
	REP(rep, 1000) {
		n = rnd() % 10 + 1;
		REP(i, n) { alocal[i] = i; int idx = rnd() % (i + 1); swap(alocal[i], alocal[idx]); }
		nq = 0;
		solve();
		bool ok = nq <= 2 * n;
		REP(i, n) if (ans[i] != alocal[i]) ok = false;
		if (ok) { printf("."); continue; }
		printf("err\n");
		printf("want:"); REP(i, n) printf(" %d", alocal[i]); puts("");
		printf("have:"); REP(i, n) printf(" %d", ans[i]); puts("");
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}