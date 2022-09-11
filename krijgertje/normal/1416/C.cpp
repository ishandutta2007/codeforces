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

const int MAXN = 300000;

int n;
int a[MAXN];

pair<int, int> o[MAXN];
int b[MAXN], nb;

pair<ll, int> solve() {
	pair<ll, int> ret = MP(0, 0);
	REPE(bit, 30) {
		REP(i, n) o[i] = MP(a[i] >> (bit + 1), i);
		sort(o, o + n);
		ll inv0 = 0, inv1 = 0;
		for (int l = 0, r = l; l < n; l = r) {
			while (r < n && o[r].first == o[l].first) ++r;
			nb = 0; FOR(i, l, r) b[nb++] = (a[o[i].second] >> bit) & 1;
			//printf("\tbit=%d [%d..%d): ", bit, l, r); REP(i, nb) printf("%d", b[i]); puts("");
			int cnt0 = 0, cnt1 = 0;
			REP(i, nb) {
				if (b[i] == 0) inv0 += cnt1; else inv1 += cnt0;
				if (b[i] == 0) ++cnt0; else ++cnt1;
			}
		}
		//printf("->%lld vs %lld\n", inv0, inv1);
		if (inv0 <= inv1) ret.first += inv0; else ret.first += inv1, ret.second += 1 << bit;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	pair<ll, int> ans = solve();
	printf("%lld %d\n", ans.first, ans.second);
}

int main() {
	run();
	return 0;
}