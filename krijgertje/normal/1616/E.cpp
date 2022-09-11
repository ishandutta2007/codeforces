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

struct BIT {
	int n; vector<int> val;
	void init(int _n) { n = _n; val = vector<int>(n + 1, 0); }
	int get(int idx) { int ret = 0; ++idx; while (idx > 0) { ret += val[idx]; idx -= idx & -idx; } return ret; }
	void mod(int idx, int by) { ++idx; while (idx <= n) { val[idx] += by, idx += idx & -idx; } }
	int get(int l, int r) { return get(r) - get(l - 1); }
};

const int MAXN = 100000;
const int ALPH = 26;

int n;
char s[MAXN + 1];
char t[MAXN + 1];

int nxtsame[MAXN];
int fst[ALPH];
bool used[MAXN];
BIT bit;

ll solve() {
	REP(i, ALPH) fst[i] = -1;
	for (int i = n - 1; i >= 0; --i) {
		int x = s[i] - 'a';
		nxtsame[i] = fst[x];
		fst[x] = i;
	}

	int si = 0, ti = 0;
	REP(i, n) used[i] = false;
	ll ret = LLONG_MAX;
	ll sofar = 0;
	bit.init(n);
	REP(i, n) bit.mod(i, +1);
	int last = -1;
	bool increasing = true;
	while (true) {
		while (si < n && used[si]) ++si;
		if (si >= n || ti >= n) { assert(si == n && ti == n); break; }
		int x = s[si] - 'a', y = t[ti] - 'a';
		if (x < y) { ret = min(ret, sofar); break; }
		if (increasing && x < last) { increasing = false; ret = min(ret, sofar + 1); }
		if (x == y) { last = x; fst[x] = nxtsame[si]; ++si, ++ti; continue; }
		if (!increasing) break;
		int upto = max(last, y);
		REP(z, upto) {
			int pos = fst[z];
			if (pos == -1) continue;
			assert(pos > si && !used[pos]);
			int between = bit.get(si, pos) - 2;
			ll cur = sofar + between + (z < y ? 1 : 2);
			ret = min(ret, cur);
		}
		{
			int pos = fst[y];
			if (pos == -1) break;
			assert(pos > si && !used[pos]);
			int between = bit.get(si, pos) - 2;
			sofar += between + 1;
			used[pos] = true;
			bit.mod(pos, -1);
			fst[y] = nxtsame[pos];
			if (increasing && y < last) { increasing = false; ret = min(ret, sofar + 1); }
			last = y; ++ti;
		}
	}

	return ret == LLONG_MAX ? -1 : ret;
}

void run() {
	scanf("%d", &n);
	scanf("%s", s);
	scanf("%s", t);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}