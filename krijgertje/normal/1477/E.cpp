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
const int MAXQ = 500000;

// ascore: if x<=lo+k: asum+(k-x)*acnt
// ascore: if x>=lo+k: asum-lo*acnt (if x is from a: ascore decreases by x-lo-k)
// bscore: considering only bi>=x-k: bsum+(k-x)*bcnt

// conclusion1: if x<=lo+k, increasing x results in a gain of dx*(bcnt-acnt), so take highest if bcnt>acnt and lowest otherwise
// conclusion2: if x>=lo+k, increasing x results in a gain of dx*(bcnt-I[x is from a]), so if either take lowest x>=bhi+k or highest x<=bhi+k

int na, nb, nq;
int sa[MAXN];
int sb[MAXN];
int qkind[MAXQ], qidx[MAXQ], qval[MAXQ]; ll qans[MAXQ];

int ca[MAXN];
int cb[MAXN];

int cbfrom[MAXN];
vector<pair<int, int>> blst;
vector<pair<int, ll>> bit;

void bmod(pair<int, int> key, int by) {
	int idx = lower_bound(blst.begin(), blst.end(), key) - blst.begin(); assert(idx != SZ(blst) && blst[idx] == key);
	++idx; while (idx <= SZ(blst)) { bit[idx].first += by, bit[idx].second += by * key.first; idx += idx & -idx; }
}
pair<int, ll> bget(int idx) {
	++idx; pair<int, ll> ret = MP(0, 0LL); while (idx > 0) { ret.first += bit[idx].first; ret.second += bit[idx].second; idx -= idx & -idx; } return ret;
}

void solve() {
	blst.clear();
	REP(i, nb) blst.PB(MP(sb[i], i));
	REP(i, nq) if (qkind[i] == 2) blst.PB(MP(qval[i], nb + i));
	sort(blst.begin(), blst.end());
	bit = vector<pair<int, ll>>(SZ(blst) + 1, MP(0, 0LL));


	ll asum = 0, bsum = 0;
	multiset<int> aset;
	multiset<int> bset;
	REP(i, na) ca[i] = sa[i], asum += ca[i], aset.insert(ca[i]);
	REP(i, nb) cb[i] = sb[i], bsum += cb[i], cbfrom[i] = i, bset.insert(cb[i]), bmod(MP(cb[i], i), +1);
	REP(i, nq) {
		if (qkind[i] == 1) {
			asum -= ca[qidx[i]], aset.erase(aset.find(ca[qidx[i]]));
			asum += qval[i], aset.insert(qval[i]);
			ca[qidx[i]] = qval[i];
		}
		if (qkind[i] == 2) {
			bsum -= cb[qidx[i]], bset.erase(bset.find(cb[qidx[i]])), bmod(MP(cb[qidx[i]], cbfrom[qidx[i]]), -1);
			bsum += qval[i], bset.insert(qval[i]), bmod(MP(qval[i], nb + i), +1);
			cb[qidx[i]] = qval[i], cbfrom[qidx[i]] = nb + i;
		}
		if (qkind[i] == 3) {
			//printf("q%d\n", i);
			int k = qval[i];
			int lo = min(*aset.begin(), *bset.begin());
			int bhi = *bset.rbegin();
			auto eval = [&](int x, bool froma) {
				ll ascore = asum + (ll)max(k - x, -lo) * na;
				if (froma) ascore -= max(0, x - lo - k);
				int idx = lower_bound(blst.begin(), blst.end(), MP(x - k, -1)) - blst.begin();
				pair<int, ll> cur = bget(idx - 1);
				ll bscore = (bsum - cur.second) + (ll)(k - x) * (nb - cur.first);
				return ascore - bscore;
			};
			ll ans = LLONG_MIN;
			auto relax = [&](int x, bool froma) {
				if (x == INT_MIN || x == INT_MAX) return;
				ans = max(ans, eval(x, froma));
			};
			//for (auto it = aset.begin(); it != aset.end(); ++it) printf("%d: %lld\n", *it, eval(*it, true));
			//for (auto it = bset.begin(); it != bset.end(); ++it) printf("%d: %lld\n", *it, eval(*it, false));
			relax(*aset.begin(), true);
			relax(*aset.rbegin(), true);
			relax(*bset.begin(), false);
			relax(*bset.rbegin(), false);
			{ auto it = aset.lower_bound(bhi + k); if (it != aset.end()) relax(*it, true); }
			{ auto it = aset.lower_bound(bhi + k); if (it != aset.begin()) relax(*prev(it), true); }
			{ auto it = bset.lower_bound(bhi + k); if (it != aset.begin()) relax(*prev(it), false); }
			qans[i] = ans;
		}
	}
}

void solvestupid() {
	REP(i, na) ca[i] = sa[i];
	REP(i, nb) cb[i] = sb[i];
	REP(i, nq) {
		if (qkind[i] == 1) {
			ca[qidx[i]] = qval[i];
		}
		if (qkind[i] == 2) {
			cb[qidx[i]] = qval[i];
		}
		if (qkind[i] == 3) {
			printf("q%d\n", i);
			int k = qval[i];
			int lo = INT_MAX;
			REP(j, na) lo = min(lo, ca[j]);
			REP(j, nb) lo = min(lo, cb[j]);
			int bhi = INT_MIN;
			REP(j, nb) bhi = max(bhi, cb[j]);
			ll ans = LLONG_MIN;
			REP(rep, 3) {
				int x; bool dec = false;
				if (rep == 0) { // x<=lo+k
					if (nb > na) {
						x = INT_MIN;
						REP(j, na) if (ca[j] <= lo + k) x = max(x, ca[j]);
						REP(j, nb) if (cb[j] <= lo + k) x = max(x, cb[j]);
					} else {
						x = INT_MAX;
						REP(j, na) if (ca[j] <= lo + k) x = min(x, ca[j]);
						REP(j, nb) if (cb[j] <= lo + k) x = min(x, cb[j]);
					}
				}
				if (rep == 1) { // x>=lo+k, x>=bhi+k
					x = INT_MAX;
					REP(j, na) if (ca[j] >= bhi + k) x = min(x, ca[j]);
				}
				if (rep == 2) { // x>=lo+k, x<=bhi+k
					x = INT_MIN;
					REP(j, nb) if (cb[j] >= lo + k) x = max(x, cb[j]);
					REP(j, na) if (ca[j] >= lo + k && ca[j] <= bhi + k && ca[j] > x) x = ca[j], dec = true;
				}
				if (x != INT_MIN && x != INT_MAX) {
					ll ascore = 0, bscore = 0;
					REP(j, na) ascore += max(ca[j] + (k - x), ca[j] - lo);
					REP(j, nb) if (cb[j] >= x - k) bscore += cb[j] + (k - x);
					if (dec) ascore -= x - lo - k;
					printf("%d: x=%d%s lo=%d k=%d ascore=%lld bscore=%lld -> %lld\n", rep, x, dec ? "DEC" : "", lo, k, ascore, bscore, ascore - bscore);
					ans = max(ans, ascore - bscore);
				}
			}
			qans[i] = ans;
		}
	}
}

void run() {
	scanf("%d%d%d", &na, &nb, &nq);
	REP(i, na) scanf("%d", &sa[i]);
	REP(i, nb) scanf("%d", &sb[i]);
	REP(i, nq) { scanf("%d", &qkind[i]); if (qkind[i] == 1 || qkind[i] == 2) scanf("%d%d", &qidx[i], &qval[i]), --qidx[i]; if (qkind[i] == 3) scanf("%d", &qval[i]); }
	solve();
	REP(i, nq) if (qkind[i] == 3) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}