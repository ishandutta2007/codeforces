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
typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

// Partitions a set of numbers into two sets such that |sum(a)-sum(b)| is minimal
ll partition_numbers(const vector<ll> &v,int n, bool nonempty=true) {
	int na = n / 2, nb = n - na; ll suma = 0, sumb = 0;
	vector<ll> a(1 << na, 0LL);
	REP(i, na) { int x = (1 << na) - (1 << i), y = (1 << na) - (1 << i); suma += v[i]; while (x < (1 << na) || y < (1 << na)) if (x < (1 << na) && (y >= (1 << na) || a[x] - v[i] <= a[y] + v[i])) a[x + y - (1 << na)] = a[x] - v[i], ++x; else a[x + y - (1 << na)] = a[y] + v[i], ++y; }
	vector<ll> b(1 << nb, 0LL);
	REP(i, nb) { int x = (1 << nb) - (1 << i), y = (1 << nb) - (1 << i); int j = na + i; sumb += v[j]; while (x < (1 << nb) || y < (1 << nb)) if (x < (1 << nb) && (y >= (1 << nb) || b[x] - v[j] <= b[y] + v[j])) b[x + y - (1 << nb)] = b[x] - v[j], ++x; else b[x + y - (1 << nb)] = b[y] + v[j], ++y; }
	ll ret=LLONG_MAX;
	auto upd = [&](int ai, int bi) { ll cur = abs(a[ai] + b[bi]); ret = min(ret, cur); };
	int bi = SZ(b); // a[ai] + b[bi] >= 0
	bool skipnone = nonempty, skipall = nonempty;
	REPSZ(ai, a) {
		while (bi - 1 >= 0 && a[ai] + b[bi - 1] >= 0) --bi;
		if (bi < SZ(b)) { int ci = bi; if (skipnone && a[ai] == -suma && b[ci] == -sumb) ++ci, skipnone = false; else if (skipall && a[ai] == +suma && b[ci] == +sumb) ++ci, skipall = false; if (ci < SZ(b)) upd(ai, ci); }
		if (bi - 1 >= 0) { int ci = bi - 1; if (skipnone && a[ai] == -suma && b[ci] == -sumb) --ci, skipnone = false; else if (skipall && a[ai] == +suma && b[ci] == +sumb) --ci, skipall = false; if (ci >= 0) upd(ai, ci); }
	}
	return ret;
}

struct SubsetConvolution {
	int n;
	vector<int> cnt;
	SubsetConvolution(int _n) { n = _n; cnt = vector<int>(1 << n); cnt[0] = 0; FOR(mask, 1, 1 << n) cnt[mask] = cnt[mask >> 1] + (mask & 1); }

	void transform(vector<int>& v) { for (int step = 1 << (n - 1); step >= 1; step >>= 1) for (int base = 0; base < (1 << n); base += step << 1) REP(offset, step) v[base + step + offset] += v[base + offset]; }
	void invtransform(vector<int>& v) { for (int step = 1 << (n - 1); step >= 1; step >>= 1) for (int base = 0; base < (1 << n); base += step << 1) REP(offset, step) v[base + step + offset] -= v[base + offset]; }

	int maxDisjointSets(vector<bool> can) {
		vector<vector<int>> one(n + 1, vector<int>(1 << n, 0)); int mnone = INT_MAX; REP(mask, 1 << n) if (can[mask]) ++one[cnt[mask]][mask], mnone = min(mnone,cnt[mask]); assert(mnone >= 1); if (mnone == INT_MAX) return 0; FORE(k, mnone, n) transform(one[k]);
		vector<vector<int>> cur = one; int mncur = mnone, ret = 1;
		vector<vector<int>> nxt(n + 1, vector<int>(1 << n, 0));
		while (true) {
			FORE(k, mncur + mnone, n) REP(mask, 1<<n) nxt[k][mask] = 0;
			FORE(k, mncur + mnone, n) FORE(j, mncur, k - mnone) REP(mask, 1 << n) nxt[k][mask] += cur[j][mask] * one[k - j][mask];
			int mnnxt = INT_MAX; FORE(k, mncur + mnone, n) { vector<int> z = nxt[k]; invtransform(z); REP(mask, 1 << n) if (cnt[mask] == k && z[mask] != 0) { mnnxt = k; break; } if (mnnxt != INT_MAX) break; } if (mnnxt == INT_MAX) return ret;
			swap(cur, nxt); mncur = mnnxt; ++ret;
		}
	}
};

const int MAXN=20;

int n;
ll a[MAXN];

ll b[MAXN]; int nb;

int solve() {
	nb = 0; REP(i, n) if (a[i] != 0) b[nb++] = a[i];
	vector<bool> can(1 << nb, false);
	vector<ll> v(n);
	REP(mask, 1 << nb) {
		if (!can[mask]) {
			int nv = 0; ll vsum = 0; REP(i, nb) if (mask&(1 << i)) v[nv++] = b[i], vsum += b[i]; if (nv <= 1 || (vsum + nv - 1) % 2 != 0) continue;
			can[mask] = partition_numbers(v, nv, true) <= nv - 1;
		}
		if (can[mask]) REP(i, nb) can[mask | (1 << i)] = true;
	}

	SubsetConvolution sc(nb);
	int save = sc.maxDisjointSets(can);
	return nb - save;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%lld",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}