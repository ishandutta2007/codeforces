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

const int MAXLEN = 300000;
const int MAXLANT = 200000;
const int MAXPOINT = 16;
const int MAXQ = 500000;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { if ((a -= b) < 0) a += MOD; }

int len, nlant, npoint;
int lant[MAXLANT];
int point[MAXPOINT];
int nq;
int qlant[MAXQ];
int qans[MAXQ];

int inv[MAXLEN + 1];

int proddist[MAXPOINT][MAXLANT + 1];
int invproddist[MAXPOINT][MAXLANT + 1];

int before[MAXPOINT];
int after[MAXPOINT];
int between[MAXPOINT][MAXPOINT];

void solve() {
	inv[1] = 1; FORE(i, 2, len) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;

	sort(lant, lant + nlant);
	sort(point, point + npoint);
	REP(i, npoint) {
		proddist[i][0] = 1;
		REP(j, nlant) proddist[i][j + 1] = (ll)proddist[i][j] * abs(lant[j] - point[i]) % MOD;
		invproddist[i][0] = 1;
		REP(j, nlant) invproddist[i][j + 1] = (ll)invproddist[i][j] * inv[abs(lant[j] - point[i])] % MOD;
	}
	auto tcalcproddist = [&](int i, int l, int r) {
		//printf("\tcalcproddist for point %d to lants [%d..%d) = %d\n", i, l, r, (int)((ll)proddist[i][r] * invproddist[i][l] % MOD));
		return (ll)proddist[i][r] * invproddist[i][l] % MOD; 
	};

	REP(i, npoint) before[i] = lower_bound(lant, lant + nlant, point[i]) - lant;
	REP(i, npoint) after[i] = lower_bound(lant, lant + nlant, point[i]) - lant;
	REP(i, npoint) FOR(j, i + 1, npoint) between[i][j] = lower_bound(lant, lant + nlant, point[i] + (point[j] - point[i] + 1) / 2) - lant;

	REP(i, nq) qans[i] = 0;
	vector<int> delta(len + 1, 0);
	vector<int> deltax(len + 1, 0);
	REP(mask, 1 << npoint) {
		vector<int> fail;
		REP(i, npoint) if (mask & (1 << i)) fail.PB(i);
		int ways;
		if (SZ(fail) == 0) {
			ways = 1; REP(i, nlant) ways = (ll)ways * (len + 1) % MOD;
		} else {
			ways = 1;
			int a = fail[0], b = fail[SZ(fail) - 1];
			ways = (ll)ways * tcalcproddist(a, 0, before[a]) % MOD;
			ways = (ll)ways * tcalcproddist(b, after[b], nlant) % MOD;
			FORSZ(i, 1, fail) {
				int c = fail[i - 1], d = fail[i];
				ways = (ll)ways * tcalcproddist(c, after[c], between[c][d]) % MOD;
				ways = (ll)ways * tcalcproddist(d, between[c][d], before[d]) % MOD;
			}
		}
		//printf("mask=%x -> ways=%d\n", mask, ways);
		if (SZ(fail) % 2 == 1) ways = (MOD - ways) % MOD;
		/*REP(i, nq) {
			int mlt = len + 1; for (int x : fail) mlt = min(mlt, abs(qlant[i] - point[x]));
			qans[i] = (qans[i] + (ll)ways * mlt) % MOD;
		}*/
		if (SZ(fail) == 0) {
			inc(delta[0], (ll)ways * (len + 1) % MOD);
		} else {
			int a = fail[0], b = fail[SZ(fail) - 1];
			// for x in 0..point[a]-1: ways * (point[a] - x)
			inc(delta[0], (ll)ways * point[a] % MOD);
			dec(delta[point[a]], (ll)ways * point[a] % MOD);
			dec(deltax[0], ways);
			inc(deltax[point[a]], ways);
			// for x in point[b]+1..len: ways * (x - point[b])
			dec(delta[point[b] + 1], (ll)ways * point[b] % MOD);
			inc(deltax[point[b] + 1], ways);
			FORSZ(i, 1, fail) {
				int c = fail[i - 1], d = fail[i];
				int mid = point[c] + (point[d] - point[c] + 1) / 2;
				if (point[c] + 1 <= mid - 1) {
					// for x in point[c]+1..mid-1: ways * (x - point[c])
					dec(delta[point[c] + 1], (ll)ways * point[c] % MOD);
					inc(delta[mid], (ll)ways * point[c] % MOD);
					inc(deltax[point[c] + 1], ways);
					dec(deltax[mid], ways);
				}
				if (mid <= point[d] - 1) {
					// for x in mid..point[d]-1: ways * (point[d] - x)
					inc(delta[mid], (ll)ways * point[d] % MOD);
					dec(delta[point[d]], (ll)ways * point[d] % MOD);
					dec(deltax[mid], ways);
					inc(deltax[point[d]], ways);
				}
			}

		}
	}
	vector<int> res(len + 1);
	{
		int sum = 0, sumx = 0;
		REPE(i, len) {
			inc(sum, delta[i]);
			inc(sumx, deltax[i]);
			res[i] = (sum + (ll)sumx * i) % MOD;
		}
	}
	REP(i, nq) qans[i] = res[qlant[i]];
}

void run() {
	scanf("%d%d%d", &len, &nlant, &npoint);
	REP(i, nlant) scanf("%d", &lant[i]);
	REP(i, npoint) scanf("%d", &point[i]);
	scanf("%d", &nq);
	REP(i, nq) scanf("%d", &qlant[i]);
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}