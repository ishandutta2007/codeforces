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
const int MAXQ = 300000;

int n, nq;
int a[MAXN];
int qidx[MAXQ][2]; ll qans[MAXQ + 1];

int cur[MAXN];

int calc(int idx) {
	if ((idx - 1 < 0 || cur[idx] > cur[idx - 1]) && (idx + 1 >= n || cur[idx] > cur[idx + 1])) return cur[idx];
	if (idx - 1 >= 0 && cur[idx] < cur[idx - 1] && idx + 1 < n && cur[idx] < cur[idx + 1]) return -cur[idx];
	return 0;
}

void solve() {
	REP(i, n) cur[i] = a[i];
	ll sum = 0; REP(i, n) sum += calc(i);
	qans[0] = sum;
	REP(i, nq) {
		set<int> change;
		REP(j, 2) FORE(k, max(0, qidx[i][j] - 1), min(n - 1, qidx[i][j] + 1)) change.insert(k);
		for (int k : change) sum -= calc(k);
		swap(cur[qidx[i][0]], cur[qidx[i][1]]);
		for (int k : change) sum += calc(k);
		qans[i + 1] = sum;
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nq) scanf("%d%d", &qidx[i][0], &qidx[i][1]), --qidx[i][0], --qidx[i][1];
	solve();
	REPE(i, nq) printf("%lld\n", qans[i]);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}