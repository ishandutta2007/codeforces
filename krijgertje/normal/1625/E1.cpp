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
	int n; vector<ll> bit;
	void init(int _n) { n = _n; bit = vector<ll>(n, 0); }
	void add(int idx, ll val) { while (idx < n) { bit[idx] += val; idx |= idx + 1; } }
	ll get(int idx) { ll ret = 0; while (idx >= 0) { ret += bit[idx]; idx = (idx & (idx + 1)) - 1; } return ret; }
	ll get(int lidx, int ridx) { return get(ridx) - get(lidx - 1); }
};

const int MAXN = 300000;
const int MAXQ = 300000;

int n, nq;
char s[MAXN + 1];
int qkind[MAXQ], ql[MAXQ], qr[MAXQ];
ll qans[MAXQ];

int match[MAXN];
int par[MAXN];
int stck[MAXN], nstck;

int cnt[2 * MAXN];
int idx[MAXN];

BIT globalbit;
BIT localbit[2 * MAXN];

ll calc(int x) { return (ll)x * (x + 1) / 2; }

void solve() {
	REP(i, n) match[i] = -1, par[i] = idx[i] = -1;

	nstck = 0;
	int atroot = n;
	REP(i, n) {
		if (s[i] == '(') {
			par[i] = nstck == 0 ? atroot : stck[nstck - 1];
			stck[nstck++] = i;
		} else {
			if (nstck > 0) {
				int j = stck[--nstck];
				match[i] = j, match[j] = i;
			} else {
				++atroot;
			}
		}
	}
	REP(i, n) {
		if (s[i] == '(' && match[i] == -1) par[i] = -1, ++atroot;
		if (s[i] == '(' && par[i] < n && match[par[i]] == -1) par[i] = atroot;
	}
	++atroot;
	//printf("match:"); REP(i, n) printf(" %d", match[i]); puts("");
	//printf("par:"); REP(i, n) printf(" %d", par[i]); puts("");
	REP(i, n) assert((match[i] != -1 && s[i] == '(') == (par[i] != -1));

	REP(i, atroot) cnt[i] = 0;
	REP(i, n) if (par[i] != -1) idx[i] = cnt[par[i]], ++cnt[par[i]];
	globalbit.init(n);
	REP(i, n) if (par[i] != -1) globalbit.add(i, calc(cnt[i]));
	REP(i, atroot) if (i >= n || par[i] != -1) localbit[i].init(cnt[i]);
	REP(i, nq) {
		int l = ql[i], r = qr[i];
		if (qkind[i] == 1) {
			assert(s[l] == '(' && match[l] == r && s[r] == ')' && match[r] == l);
			assert(cnt[l] == 0);
			ll before = calc(cnt[par[l]]);
			--cnt[par[l]];
			ll after = calc(cnt[par[l]]);
			if (par[l] < n) globalbit.add(par[l], after - before);
			localbit[par[l]].add(idx[l], 1);
		}
		if (qkind[i] == 2) {
			assert(s[l] == '(' && match[l] != -1);
			assert(s[r] == ')' && match[r] != -1);
			assert(par[l] == par[match[r]]);
			qans[i] = 0;
			qans[i] += globalbit.get(l, r);
			int lidx = idx[l], ridx = idx[match[r]];
			int sublen = ridx - lidx + 1;
			sublen -= localbit[par[l]].get(lidx, ridx);
			qans[i] += calc(sublen);
		}
	}

}

void run() {
	scanf("%d%d", &n, &nq);
	scanf("%s", s);
	REP(i, nq) scanf("%d%d%d", &qkind[i], &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) if (qkind[i] == 2) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}