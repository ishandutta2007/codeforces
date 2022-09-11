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

const int MAXN = 200000;

int na, nb;
int a[MAXN], b[MAXN];
int saidx, sbidx;

int w[MAXN];
int v[MAXN];

bool can(int lim) {
	{
		int cur = nb;
		REP(i, na) {
			while (cur - 1 >= 0 && a[i] + b[cur - 1] > lim) --cur;
			w[i] = cur;
		}
	}
	{
		int cur = na;
		REP(j, nb) {
			while (cur - 1 >= 0 && a[cur - 1] + b[j] > lim) --cur;
			v[j] = cur;
		}
	}
	//printf("can(%d) -> w:", lim); REP(i, na) printf(" %d", w[i]); puts("");
	assert(sbidx >= w[saidx]);
	ll mybest, hisbest;
	{
		ll cur = 0;
		REP(i, na) cur += nb - w[i];
		mybest = cur;
		int i = 0;
		//printf("%d columns, %d rows -> %lld\n", 0, i, cur);
		REP(j, nb) {
			cur += v[j] + i - na;
			while (i < na && w[i] + j + 1 >= nb) {
				cur += w[i] + j + 1 - nb;
				++i;
			}
			//printf("%d columns, %d rows -> %lld\n", j + 1, i, cur);
			mybest = max(mybest, cur);
		}
	}
	{
		ll cur = 0;
		REP(i, na) cur += nb - w[i];
		--cur;
		hisbest = cur;
		int i = 0;
		//printf("%d columns, %d rows -> %lld\n", 0, i, cur);
		REP(j, nb) {
			cur += v[j] + i - na + (saidx >= i && sbidx == j ? 1 : 0);
			while (i < na && w[i] + j + 1 + (saidx == i && sbidx > j ? 1 : 0) >= nb) {
				cur += w[i] + j + 1 + (saidx == i && sbidx > j ? 1 : 0) - nb;
				++i;
			}
			//printf("%d columns, %d rows -> %lld (v[j]=%d)\n", j + 1, i, cur, v[j]);
			hisbest = max(hisbest, cur);
		}
	}
	//printf("mybest=%lld histbest=%lld\n", mybest, hisbest);
	return hisbest == mybest;
}

int solve() {
	int sa = a[0], sb = b[0];
	sort(a, a + na);
	sort(b, b + nb);
	saidx = -1; REP(i, na) if (a[i] == sa) { saidx = i; break; } assert(saidx != -1);
	sbidx = -1; REP(i, nb) if (b[i] == sb) { sbidx = i; break; } assert(sbidx != -1);
	//printf("s=(%d,%d)\n", saidx, sbidx);

	int lo = 0, hi = sa + sb;
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		if (can(mi)) hi = mi; else lo = mi;
	}
	return hi;
}

void run() {
	scanf("%d%d", &na, &nb);
	REP(i, na) scanf("%d", &a[i]);
	REP(i, nb) scanf("%d", &b[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}