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

const int NDIG = 6;
const int MAXSUM = 999999;
const int MAXQ = 100000;

int nvals;
ll gain[NDIG];
int nq;
int qsum[MAXQ];
ll qans[MAXQ];

ll dp[NDIG + 1][MAXSUM + 1];
ll tmp[MAXSUM + 1];

pair<ll, int> q[MAXSUM + 1]; int qhead, qtail;

void solve() {
	REPE(ndig, NDIG) REPE(sum, MAXSUM) dp[ndig][sum] = ndig == 0 && sum == 0 ? 0 : LLONG_MIN;
	FORE(ndig, 1, NDIG) {
		ll curgain = gain[NDIG - ndig];
		REPE(sum, MAXSUM) { tmp[sum] = dp[ndig - 1][sum]; if (tmp[sum] != LLONG_MIN) tmp[sum] -= (sum / 3) * 10 * curgain; }
		REP(mod,10) {
			REP(offset, 3) {
				int firstnow = mod + offset * 10;
				int num = (nvals - 1) * 3 - firstnow / 3;
				int special = firstnow % 3 != 0 ? (num >= 0 ? (num + 9) / 10 : 0) : INT_MAX;
				REP(offset2, 3) {
					int firstidx = offset2;
					qhead = qtail = 0;
					for (int sum = firstnow + 10 * offset2; sum <= MAXSUM; sum += 30, firstidx += 3) {
						int limnow = min(sum, nvals * 9);
						while (qtail < qhead && q[qhead - 1].first <= tmp[firstidx]) --qhead;
						q[qhead++] = MP(tmp[firstidx], firstidx);
						if (firstnow > limnow) continue;
						int mx = (limnow - firstnow) / 30;
						int upto = min(mx, special - 1);
						while (qtail < qhead && q[qtail].second < firstidx - 3 * upto) ++qtail;
						//ll best = LLONG_MIN; REPE(i, upto) best = max(best, tmp[firstidx - 3 * i]);
						ll best = qtail < qhead ? q[qtail].first : LLONG_MIN;
						if (best != LLONG_MIN) {
							best += curgain * (firstnow / 3) + ((firstidx) / 3) * 10 * curgain;
							dp[ndig][sum] = max(dp[ndig][sum], best);
						}
						FORE(i, special, mx) {
							ll val = dp[ndig - 1][(sum - firstnow) / 10 - 3 * i];
							if (val == LLONG_MIN) continue;
							val += curgain * ((nvals - 1) * 3);
							dp[ndig][sum] = max(dp[ndig][sum], val);
						}
					}
				}
			}
		}
	}
	REP(i, nq) qans[i] = dp[NDIG][qsum[i]];
}


void run() {
	scanf("%d", &nvals);
	REP(i, NDIG) scanf("%lld", &gain[i]);
	scanf("%d", &nq);
	REP(i, nq) scanf("%d", &qsum[i]);
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}