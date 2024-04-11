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

const int MAXCARROT = 100000;

int ncarrot, nrabbit;
int a[MAXCARROT];


ll calc2(int sz, int cnt) {
	int each = sz / cnt, rem = sz % cnt;
	return (ll)(cnt - rem) * each * each + (ll)rem * (each + 1) * (each + 1);
}

ll calc(int sz, int cnt) {
	return calc2(sz, cnt) - calc2(sz, cnt + 1);
}


ll solve() {
	ll have = 0; REP(i, ncarrot) have += (ll)a[i] * a[i];
	vector<int> cnt(ncarrot, 1);
	priority_queue<pair<ll, int>> pq;
	int ncuts = nrabbit - ncarrot;
	REP(i, ncarrot) pq.push(MP(calc(a[i], cnt[i]), i));
	REP(i, ncuts) {
		ll delta = pq.top().first; int at = pq.top().second; pq.pop();
		have -= delta;
		++cnt[at];
		pq.push(MP(calc(a[at], cnt[at]), at));
	}
	return have;
}

void run() {
	scanf("%d%d", &ncarrot, &nrabbit);
	REP(i, ncarrot) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

void research() {
	REP(rep, 1000000) {
		int sz = rep + 1;
		ll cur = (ll)sz * sz;
		vector<ll> gain;
		FORE(i, 2, sz) {
			int each = sz / i, rem = sz % i;
			ll now = (ll)(i - rem) * each * each + (ll)rem * (each + 1) * (each + 1);
			assert(now <= cur);
			gain.PB(cur - now);
			cur = now;
		}
		FORSZ(i, 1, gain) assert(gain[i] <= gain[i - 1]);
		printf("done %d\n", sz);
	}
}

int main() {
	//research();
	run();
	return 0;
}