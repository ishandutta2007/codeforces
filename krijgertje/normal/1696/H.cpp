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

const int MAXN = 600;
const int MOD = 1000000007;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { if ((a -= b) < 0) a += MOD; }
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret * x % MOD; if ((n >>= 1) == 0) return ret; x = (ll)x * x % MOD; } }
int calcinv(int x) { return pw(x, MOD - 2); }

int n, sz;
int a[MAXN];

int solve() {
	vector<int> pos, neg;
	REP(i, n) if (a[i] >= 0) pos.PB(a[i]); else neg.PB(-a[i]);
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());
	int npos = SZ(pos), nneg = SZ(neg);
	vector<int> invpos(npos); REP(i, npos) invpos[i] = pos[i] == 0 ? 0 : calcinv(pos[i]);
	vector<int> invneg(nneg); REP(i, nneg) invneg[i] = neg[i] == 0 ? 0 : calcinv(neg[i]);
	vector<vector<int>> posprod(npos);
	{
		vector<int> suffprod(sz + 1, 0);
		inc(suffprod[0], 1);
		for (int i = npos - 1; i >= 0; --i) {
			int lim = min(sz, npos - i);
			posprod[i] = vector<int>(lim + 1, 0);
			FORE(j, 1, lim) posprod[i][j] = (ll)pos[i] * suffprod[j - 1] % MOD;
			FORE(j, 1, lim) inc(suffprod[j], posprod[i][j]);
		}
	}
	vector<vector<int>> negprod(nneg);
	{
		vector<int> suffprod(sz + 1, 0);
		inc(suffprod[0], 1);
		for (int i = nneg - 1; i >= 0; --i) {
			int lim = min(sz, nneg - i);
			negprod[i] = vector<int>(lim + 1, 0);
			FORE(j, 1, lim) negprod[i][j] = (ll)neg[i] * suffprod[j - 1] % MOD;
			FORE(j, 1, lim) inc(suffprod[j], negprod[i][j]);
		}
	}
	vector<vector<int>> negprefprod(nneg);
	{
		vector<int> prefprod(sz + 1, 0);
		inc(prefprod[0], 1);
		REP(i, nneg) {
			int lim = min(sz, i + 1);
			negprefprod[i] = vector<int>(lim + 1, 0);
			FORE(j, 1, lim) negprefprod[i][j] = (ll)neg[i] * prefprod[j - 1] % MOD;
			FORE(j, 1, lim) inc(prefprod[j], negprefprod[i][j]);
		}
	}
	vector<int> cntbeforepos(npos, 0);
	REP(i, npos) { cntbeforepos[i] = i; REP(j, nneg) if (neg[j] < pos[i]) ++cntbeforepos[i]; }
	vector<int> cntbeforeneg(nneg, 0);
	REP(i, nneg) { cntbeforeneg[i] = i; REP(j, npos) if (pos[j] <= neg[i]) ++cntbeforeneg[i]; }
	vector<vector<int>> cntbefore(npos, vector<int>(nneg, 0));
	REP(i, npos) REP(j, nneg) {
		REP(k, npos) if (k < i && pos[k] <= neg[j]) ++cntbefore[i][j];
		REP(k, nneg) if (k < j && neg[k] < pos[i]) ++cntbefore[i][j];
	}
	vector<vector<int>> cntbeforepos2(npos, vector<int>(nneg, 0));
	REP(i, npos) REP(j, nneg) {
		REP(k, npos) if (k < i) ++cntbeforepos2[i][j];
		REP(k, nneg) if (k < j && neg[k] < pos[i]) ++cntbeforepos2[i][j];
	}
	vector<vector<int>> cntbeforeneg2(npos, vector<int>(nneg, 0));
	REP(i, npos) REP(j, nneg) {
		REP(k, npos) if (k < i && pos[k] <= neg[j]) ++cntbeforeneg2[i][j];
		REP(k, nneg) if (k < j) ++cntbeforeneg2[i][j];
	}
	vector<int> p2(n + 1); p2[0] = 1; FORE(i, 1, n) p2[i] = (ll)p2[i - 1] * 2 % MOD;

	int ret = 0;
	// largest sz all pos
	REP(i, npos) if (sz < SZ(posprod[i])) ret = (ret + (ll)p2[cntbeforepos[i]] * posprod[i][sz]) % MOD;
	// largest sz all neg
	if (sz % 2 == 0) {
		REP(j, nneg) if (sz < SZ(negprod[j])) ret = (ret + (ll)p2[cntbeforeneg[j]] * negprod[j][sz]) % MOD;
	} else {
		// all neg
		REP(j, nneg) if (sz < SZ(negprefprod[j])) ret = (ret + (ll)p2[nneg - j - 1] * (MOD - negprefprod[j][sz])) % MOD;
		// some pos
		REP(j, nneg) if (sz < SZ(negprod[j])) REP(ii, npos) if (pos[ii] <= neg[j]) {
			ret = (ret + (ll)p2[cntbeforeneg2[ii][j]] * negprod[j][sz] % MOD * pos[ii] % MOD * invneg[j]) % MOD;
		}
	}
	// largest sz both pos+neg
	vector<vector<ll>> posval(npos, vector<ll>(npos)); REP(ii, npos) REP(i, npos) posval[i][ii] = (ll)pos[ii] * pos[i];
	vector<vector<ll>> negval(nneg, vector<ll>(nneg)); REP(jj, nneg) REP(j, nneg) negval[j][jj] = (ll)neg[jj] * neg[j];
	vector<vector<int>> posp2(npos, vector<int>(n + 1)); REP(i, npos) { posp2[i][0] = pos[i] % MOD; REP(j, n) { posp2[i][j + 1] = posp2[i][j]; inc(posp2[i][j + 1], posp2[i][j]); } }
	vector<vector<int>> negp2(nneg, vector<int>(n + 1)); REP(i, nneg) { negp2[i][0] = neg[i] % MOD; REP(j, n) { negp2[i][j + 1] = negp2[i][j]; inc(negp2[i][j + 1], negp2[i][j]); } }
	vector<int> neglim(npos, 0); REP(i, npos) REP(j, nneg) if (neg[j] < pos[i]) neglim[i] = j + 1;
	vector<int> poslim(nneg, 0); REP(j, nneg) REP(i, npos) if (pos[i] <= neg[j]) poslim[j] = i + 1;
	REP(i, npos) REP(j, nneg) {
		vector<int> sumprodlargest(2, 0);
		FORE(k, 1, sz - 1) if (sz - k < SZ(posprod[i]) && k < SZ(negprod[j])) sumprodlargest[k % 2] = (sumprodlargest[k % 2] + (ll)posprod[i][sz - k] * negprod[j][k]) % MOD;
		//printf("%d %d: %d/%d\n", i, j, sumprodlargest[0], sumprodlargest[1]);
		ret = (ret + (ll)p2[cntbefore[i][j]] * sumprodlargest[0]) % MOD;
		ret = (ret + MOD - sumprodlargest[1]) % MOD;

		REP(jj, j) if (neg[jj] < pos[i]) ret = (ret + (ll)p2[jj] * sumprodlargest[1] % MOD * neg[jj] % MOD * invpos[i]) % MOD;
		REP(ii, i) if (pos[ii] <= neg[j]) ret = (ret + (ll)p2[ii] * sumprodlargest[1] % MOD * pos[ii] % MOD * invneg[j]) % MOD;
		{
			int jjmx = 0;
			int sum = 0;
			int jjlim = min(j, neglim[i]);
			REP(ii, i) {
				if (pos[ii] > neg[j]) break;
				while (jjmx < jjlim && posval[i][ii] >= negval[j][jjmx]) ++jjmx;
				inc(sum, posp2[ii][ii + jjmx]); dec(sum, posp2[ii][ii]);
			}
			ret = (ret + (ll)sum * sumprodlargest[1] % MOD * invneg[j]) % MOD;
		}
		{
			int iimx = 0;
			int sum = 0;
			int iilim = min(i, poslim[j]);
			REP(jj, j) {
				if (neg[jj] >= pos[i]) break;
				while (iimx < iilim && posval[i][iimx] < negval[j][jj]) ++iimx;
				inc(sum, negp2[jj][iimx + jj]); dec(sum, negp2[jj][jj]);
			}
			ret = (ret + (ll)sum * sumprodlargest[1] % MOD * invpos[i]) % MOD;
		}
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &sz);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int solvestupid() {
	int ret = 0;
	REP(mask, 1 << n) {
		int cnt = 0;
		REP(i, n) if (mask & (1 << i)) ++cnt;
		if (cnt < sz) continue;
		ll best = LLONG_MIN;
		for (int sub = 0;; sub = (sub + (1 << n) - mask) & mask) {
			int cnt = 0;
			REP(i, n) if (sub & (1 << i)) ++cnt;
			if (cnt == sz) {
				ll cur = 1;
				REP(i, n) if (sub & (1 << i)) cur *= a[i];
				best = max(best, cur);
			}
			if (sub == mask) break;
		}
		assert(best != LLONG_MIN);
		ret = (ret + (best % MOD) + MOD) % MOD;
	}
	return ret;
}

void stress() {
	int mxn = 10, mxabsval = 10;
	REP(rep, 1000) {
		n = rnd() % mxn + 1;
		sz = rnd() % n + 1;
		REP(i, n) a[i] = rnd() % (2 * mxabsval + 1) - mxabsval;
		int have = solve();
		int want = solvestupid();
		if (have == want) { printf("."); continue; }
		printf("err rep=%d have=%d want=%d\n", rep, have, want);
		printf("%d %d\n", n, sz); REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); } puts("");
	}
}

void stresslarge() {
	printf("large\n");
	int mxabsval = 1000000000;
	REP(rep, 1) {
		n = MAXN, sz = 182; // n / 2; // rnd() % n + 1;
		REP(i, n) a[i] = rnd() % (2 * mxabsval + 1) - mxabsval;
		solve();
		printf(".");
	}
}

int main() {
	//stress();
	//stresslarge();
	run();
	return 0;
}