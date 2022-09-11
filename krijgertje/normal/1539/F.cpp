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

const int MAXN = 200000;
const int MAXS = 4 * MAXN;

int n;
int a[MAXN];
int ans[MAXN];


int sval[MAXS];
int slazy[MAXS];

void sapply(int x,int by) { sval[x] += by; slazy[x] += by; }
void spush(int x) { if (slazy[x] != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = 0; }
void spull(int x) { sval[x] = max(sval[2 * x + 1], sval[2 * x + 2]); }
void sinit(int x, int l, int r) {
	slazy[x] = 0;
	if (l == r) {
		sval[x] = 0;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l, int r, int L, int R, int BY) {
	if (L <= l && r <= R) {
		sapply(x, BY);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) smod(2 * x + 1, l, m, L, R, BY);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, BY);
		spull(x);
	}
}
int sget(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2, ret = INT_MIN; spush(x);
		if (L <= m) ret = max(ret, sget(2 * x + 1, l, m, L, R));
		if (m + 1 <= R) ret = max(ret, sget(2 * x + 2, m + 1, r, L, R));
		return ret;
	}
}



void solve() {
	REP(i, n) ans[i] = 0;
	REP(sign, 2) { // sign==1 -> smaller/bigger are swapped
		vector<int> o(n);
		vector<int> bal(n, 1);
		REP(side, 2) { // side==1 -> left/right are swapped
			REP(i, n) o[i] = i;
			sort(o.begin(), o.end(), [&](const int& i, const int& j) { return a[i] > a[j]; });
			sinit(0, 0, n - 1);
			REP(i, n) smod(0, 0, n - 1, i, n - 1, -1);
			for (int l = 0, r = l; l < n; l = r) {
				while (r < n && a[o[r]] == a[o[l]]) ++r;
				FOR(i, l, r) smod(0, 0, n - 1, o[i], n - 1, +2);
				FOR(i, l, r) {
					int pos = o[i];
					int before = sget(0, 0, n - 1, pos, pos) - 1;
					int best = sget(0, 0, n - 1, pos, n - 1);
					int delta = best - before - 1; // excluding pos itself
					//printf("sign=%d side=%d pos=%d -> delta=%d\n", sign, side, pos, delta);
					bal[side == 0 ? pos : n - pos - 1] += delta;
				}
			}
			reverse(a, a + n);
		}
		//printf("bal%d:", sign); REP(i, n) printf(" %d", bal[i]); puts("");
		REP(i, n) {
			if (bal[i] % 2 == 1) {
				ans[i] = max(ans[i], (bal[i] - 1) / 2);
			} else {
				ans[i] = max(ans[i], bal[i] / 2 - sign);
			}
		}

		REP(i, n) a[i] = n - a[i] - 1;
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}