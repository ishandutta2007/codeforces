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
const int MAXQ = 200000;

int n, nq;
int baked[MAXN];
int qdemand[MAXQ], qans[MAXQ];

int a[MAXN]; ll b[MAXN]; // for alive blocks, when demand is x, there is a shortage of ax-b breads in the block
int prv[MAXN], nxt[MAXN];
set<pair<ll, int>> e; // (x,at)
ll ex[MAXN];

void update(int at) {
	if (ex[at] != -1) e.erase(e.find(MP(-ex[at], at)));
	ex[at] = (b[at] - 1) / a[at];
	e.insert(MP(-ex[at], at));
}

void solve() {
	REP(i, n) a[i] = 1, b[i] = baked[i];
	REP(i, n) prv[i] = i == 0 ? -1 : i - 1, nxt[i] = i == n - 1 ? -1 : i + 1;
	e.clear();
	REP(i, n) ex[i] = -1;
	REP(at, n) update(at);
	int curans = 0;
	int qidx = nq - 1;
	while (true) {
		//printf("curans=%d\n", curans);
		if (SZ(e) == 0) break;
		ll x = -e.begin()->first;
		//printf("x=%lld\n", x);
		while (qidx >= 0 && qdemand[qidx] > x) qans[qidx--] = curans;
		while (SZ(e) > 0 && -e.begin()->first == x) {
			int at = e.begin()->second;
			e.erase(e.begin());
			int to = nxt[at];
			if (nxt[at] != -1) prv[nxt[at]] = prv[at];
			if (prv[at] != -1) nxt[prv[at]] = nxt[at];
			if (to == -1) {
				//printf("\tat=%d to=%d: a[at]=%d -> %d\n", at, to, a[at], n - 1 - (at - a[at] + 1));
				curans = max(curans, n - 1 - (at - a[at] + 1));
			} else {
				a[to] += a[at], b[to] += b[at];
				update(to);
				curans = max(curans, a[to] - 1);
			}
		}
	}
	while (qidx >= 0) qans[qidx--] = curans;
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &baked[i]);
	REP(i, nq) scanf("%d", &qdemand[i]);
	solve();
	REP(i, nq) { if (i != 0) printf(" "); printf("%d", qans[i]); } puts("");
}

int main() {
	run();
	return 0;
}