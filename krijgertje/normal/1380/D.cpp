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

int na, nb;
int rangecost, rangecnt, duelcost;
int a[MAXN];
int b[MAXN];

bool keep[MAXN];
int c[MAXN], nc;

ll solve() {
	REP(i, na) keep[i] = false;
	REP(i, nb) keep[b[i]] = true;
	nc = 0; REP(i, na) if (keep[a[i]]) c[nc++] = a[i];
	if (nc != nb) return -1; REP(i, nb) if (c[i] != b[i]) return -1;
	ll ret = 0;
	for (int l = 0, r = l; l < na; l = r) {
		while (r < na && keep[a[r]] == keep[a[l]]) ++r;
		if (keep[a[l]]) continue;
		int mx = -1; FOR(i, l, r) mx = max(mx, a[i]);
		bool canduelall = false;
		if (l - 1 >= 0 && a[l - 1] > mx) canduelall = true;
		if (r<na && a[r]>mx) canduelall = true;
		int cnt = r - l;
		//printf("cnt=%d canduelall=%s [%d..%d)\n", cnt, canduelall ? "YES" : "NO", l, r);
		ll cur = LLONG_MAX;
		if (canduelall) cur = min(cur, (ll)duelcost * cnt);
		if (cnt >= rangecnt) {
			int minduel = cnt % rangecnt;
			int maxrange = cnt / rangecnt;
			cur = min(cur, (ll)minduel * duelcost + (ll)maxrange * rangecost);
			int minrange = 1;
			int maxduel = cnt - rangecnt;
			cur = min(cur, (ll)maxduel * duelcost + (ll)minrange * rangecost);
		}
		if (cur == LLONG_MAX) return -1;
		ret += cur;
	}
	return ret;
}

void run() {
	scanf("%d%d", &na, &nb);
	scanf("%d%d%d", &rangecost, &rangecnt, &duelcost);
	REP(i, na) scanf("%d", &a[i]), --a[i];
	REP(i, nb) scanf("%d", &b[i]), --b[i];
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}