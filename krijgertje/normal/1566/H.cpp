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

const int MAXLIM = 1000000;

int lim, n;

bool local = false;
int alocal[MAXLIM + 1];
int localsum[MAXLIM + 1];

int pmn[MAXLIM + 1];
vector<int> primes;

vector<int> getpr(int x) {
	vector<int> ret;
	while (x != 1) {
		int p = pmn[x];
		while (x % p == 0) x /= p;
		ret.PB(p);
	}
	return ret;
}

vector<int> query(vector<int> q) {
	int nq = SZ(q);
	vector<int> ret(nq, 0);
	if (!local) {
		printf("%d", nq); REP(i, nq) printf(" %d", q[i]); puts(""); fflush(stdout);
		REP(i, nq) scanf("%d", &ret[i]);
	} else {
		REPSZ(i, q) {
			vector<int> pr = getpr(q[i]);
			REP(mask, 1 << SZ(pr)) {
				int y = 1;
				REPSZ(j, pr) if (mask & (1 << j)) y *= pr[j];
				ret[i] ^= localsum[y];
			}
			//int chk = 0; REP(j, n) if (gcd(alocal[j], q[i]) == 1) chk ^= alocal[j]; assert(chk == ret[i]);
			/*if (chk != ret[i]) {
				printf("!");
				printf("q[i]=%d chk=%d ret[i]=%d\n", q[i], chk, ret[i]);
				printf("alocal:"); REP(i, n) printf(" %d", alocal[i]); puts("");
				REP(j, n) if (gcd(alocal[j], q[i]) == 1) printf("%d\n", alocal[j]);
				REP(mask, 1 << SZ(pr)) {
					int y = 1;
					REPSZ(j, pr) if (mask & (1 << j)) y *= pr[j];
					printf("mask=%d -> y=%d -> %d\n", mask, y, localsum[y]);
				}
				exit(0);
			} else {
				printf(",");
			}*/
		}
	}
	return ret;
}

int key[MAXLIM + 1];
int anycommonsum[MAXLIM + 1];
int allcommonsum[MAXLIM + 1];
int matchingsum[MAXLIM + 1];

vector<int> ans;

void solve() {
	REPE(i, lim) pmn[i] = -1; primes.clear();
	FORE(i, 2, lim) { if (pmn[i] == -1) pmn[i] = i, primes.PB(i); for (int p : primes) if ((ll)i * p > lim) break; else { pmn[i * p] = p; if (i % p == 0) break; } }

	key[1] = 1;
	FORE(i, 2, lim) {
		int j = i / pmn[i];
		key[i] = key[j];
		if (pmn[i] != pmn[j]) key[i] *= pmn[i];
	}
	//printf("key:"); FORE(i, 1, lim) printf(" %d", key[i]); puts("");

	vector<int> rep;
	FORE(i, 1, lim) if (key[i] == i) rep.PB(i);
	vector<vector<int>> who(lim + 1);
	FORE(i, 1, lim) who[key[i]].PB(i);
	//FORE(i, 1, lim) if (SZ(who[i]) >= 100) printf("%d: %d\n", i, SZ(who[i]));

	vector<int> res = query(rep);
	REPSZ(i, rep) anycommonsum[rep[i]] = res[i] ^ res[0];

	allcommonsum[1] = res[0];
	FORE(i, 2, lim) if (key[i] == i) {
		vector<int> pr = getpr(i);
		allcommonsum[i] = 0;
		REP(mask, 1 << SZ(pr)) {
			int y = 1;
			REPSZ(j, pr) if (mask & (1 << j)) y *= pr[j];
			allcommonsum[i] ^= anycommonsum[y];
		}
	}
	for (int i = lim; i >= 1; --i) if (key[i] == i) {
		matchingsum[i] = allcommonsum[i];
		for (int j = i + i; j <= lim; j += i) matchingsum[i] ^= matchingsum[j];
	}
	/*printf("alocal:"); REP(i, n) printf(" %d", alocal[i]); puts("");
	printf("rep:"); REPSZ(i, rep) printf(" %d", rep[i]); puts("");
	printf("res:"); REPSZ(i, res) printf(" %d", res[i]); puts("");
	printf("any:"); FORE(i, 1, lim) printf(" %d", anycommonsum[i]); puts("");
	printf("all:"); FORE(i, 1, lim) printf(" %d", allcommonsum[i]); puts("");
	printf("matching:"); FORE(i, 1, lim) printf(" %d", matchingsum[i]); puts("");*/
	//vector<int> chk(lim + 1, 0); REP(i, n) chk[key[alocal[i]]] ^= alocal[i];
	//FORE(i, 1, lim) if (key[i] == i) assert(chk[i] == matchingsum[i]);

	ans.clear();
	vector<vector<pair<int, vector<int>>>> items;
	int nbit = 1; while ((1 << nbit) <= lim) ++nbit;
	vector<int> bc(1 << nbit); bc[0] = 0; FOR(i, 1, 1 << nbit) bc[i] = bc[i >> 1] + (i & 1);
	FORE(i, 1, lim) if (key[i] == i) {
		int ncol = SZ(who[i]);
		vector<vector<int>> A(nbit, vector<int>(ncol + 1));
		REPSZ(j, who[i]) REP(k, nbit) A[k][j] = (who[i][j] >> k) & 1;
		REP(k, nbit) A[k][ncol] = (matchingsum[i] >> k) & 1;
		int r = 0, c = 0;
		while (r < SZ(A) && c < SZ(A[r])) {
			{ int rr = r; while (rr < SZ(A) && A[rr][c] == 0) ++rr; if (rr >= SZ(A)) { ++c; continue; } if (rr != r) REPSZ(cc, A[r]) swap(A[r][cc], A[rr][cc]); }
			assert(A[r][c] == 1);
			FORSZ(rr, r + 1, A) if (A[rr][c] == 1) REPSZ(cc, A[r]) A[rr][cc] ^= A[r][cc];
			++r, ++c;
		}
		vector<int> pivot(ncol, -1);
		while (--r >= 0) {
			c = 0; while (A[r][c] == 0) ++c;
			assert(c != ncol);
			pivot[c] = r;
			REP(rr, r) if (A[rr][c] == 1) REPSZ(cc, A[r]) A[rr][cc] ^= A[r][cc];
		}

		vector<int> opt;
		REP(j, ncol) if (pivot[j] == -1) opt.PB(j);
		int nopt = SZ(opt);

		//if (SZ(opt) >= 20) printf("%d: %d\n", i, SZ(opt));
		if (nopt == 0) {
			REP(j, ncol) if (A[pivot[j]][ncol] == 1) ans.PB(who[i][j]);
		} else {
			vector<bool> have(ncol + 1, false);
			vector<vector<int>> how(ncol + 1);
			int val = 0; REP(k, nbit) if (A[k][ncol] == 1) val |= 1 << k;
			vector<int> optval(nopt, 0); REP(j, nopt) REP(k, nbit) if (A[k][opt[j]] == 1) optval[j] |= 1 << k;
			REPE(useopt, nopt) {
				REP(rep, 10) {
					vector<int> cur(useopt);
					REP(j, useopt) cur[j] = rnd() % (nopt - useopt + 1);
					sort(cur.begin(), cur.end());
					REP(j, useopt) cur[j] += j;
					int curval = val;
					for (int j : cur) curval ^= optval[j];
					int cnt = bc[curval] + useopt;
					if (have[cnt]) continue;
					have[cnt] = true;
					REP(j, ncol) if (pivot[j] != -1 && ((curval >> pivot[j]) & 1) != 0) how[cnt].PB(who[i][j]);
					for (int j : cur) how[cnt].PB(who[i][opt[j]]);
					assert(SZ(how[cnt]) == cnt);
					/*if (SZ(how[cnt]) != cnt) {
						printf("%d vs %d\n", SZ(how[cnt]), cnt);
						printf("useopt=%d\n", useopt);
						printf("cur:"); for (int j : cur) printf(" %d=%d=%d", j, opt[j], who[i][opt[j]]); puts("");
						REP(j, ncol) if (pivot[j] != -1) printf("%d=%d -> %d\n", j, who[i][j], pivot[j]);
						printf("val=%d curval=%d\n", val, curval);
						printf("how:"); for (int j : how[cnt]) printf(" %d", j); puts("");
						REPSZ(x, A) { REPSZ(y, A[x]) printf("%d", A[x][y]); puts(""); }
						exit(0);
					} else {
						printf(".");
					}*/
				}
			}
			//if (nopt >= 20) { printf("%d: have: ", i); REPSZ(j, have) printf("%c", have[j] ? 'x' : '.'); puts(""); }
			vector<pair<int, vector<int>>> item;
			REPSZ(j, have) if (have[j]) item.PB(MP(j, how[j]));
			items.PB(item);
		}


		/*if (ncol >= 100) {
			printf("%d:\n", i);
			REPSZ(x, A) { REPSZ(y, A[x]) printf("%d", A[x][y]); puts(""); }
		}*/
	}
	//printf("SZ(ans)=%d n=%d SZ(items)=%d\n", SZ(ans), n, SZ(items));
	
	vector<int> lo(SZ(items));
	REPSZ(i, items) { assert(SZ(items[i]) != 0); lo[i] = items[i][0].first; }
	int rem = n - SZ(ans);
	REPSZ(i, items) rem -= lo[i];
	//printf("rem=%d\n", rem);
	assert(rem >= 0);
	vector<pair<int, int>> act(rem + 1, MP(-2, -2));
	act[0] = MP(-1, -1);
	REPSZ(i, items) for (int j = rem; j >= 0; --j) if (act[j] != MP(-2, -2)) REPSZ(k, items[i]) {
		assert(items[i][k].first - lo[i] >= 0);
		if (items[i][k].first - lo[i] == 0) { assert(k == 0); continue; }
		if (j + items[i][k].first - lo[i] <= rem && act[j + items[i][k].first - lo[i]] == MP(-2, -2)) act[j + items[i][k].first - lo[i]] = MP(i, k);
	}
	assert(act[rem] != MP(-2, -2));
	{
		int at = rem;
		int lasti = SZ(items);
		while (act[at] != MP(-1, -1)) {
			//printf("at=%d act=[%d,%d]\n", at, act[at].first, act[at].second);
			assert(act[at] != MP(-2, -2));
			int i = act[at].first, k = act[at].second;
			for (int ii = lasti - 1; ii > i; --ii) for (int z : items[ii][0].second) ans.PB(z);
			for (int z : items[i][k].second) ans.PB(z);
			assert(items[i][k].first != lo[i]);
			at -= items[i][k].first - lo[i];
			lasti = i;
			assert(at >= 0);
		}
	}
	assert(SZ(ans) == n);

}

void run() {
	scanf("%d%d", &lim, &n);
	solve();
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts(""); fflush(stdout);
}

void stress() {
	std::mt19937 rnd(213);
	local = true;
	REP(rep, 1) {
		lim = MAXLIM;
		n = 100 + rnd() % (lim - 100 + 1);
		n = 499976;
		//lim = 10, n = 2;
		REP(i, n) alocal[i] = rnd() % (lim - n + 1);
		sort(alocal, alocal + n);
		REP(i, n) alocal[i] += i + 1;
		FORE(i, 1, lim) localsum[i] = 0;
		REP(i, n) localsum[alocal[i]] ^= alocal[i];
		FORE(i, 1, lim) for (int j = i + i; j <= lim; j += i) localsum[i] ^= localsum[j];

		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}