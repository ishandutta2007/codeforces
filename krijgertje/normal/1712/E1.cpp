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
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

const int MAXQ = 100000;
const int MAXR = 200000;
const int MAXVAL = 2 * MAXR;

int nq;
int ql[MAXQ], qr[MAXQ];
ll qans[MAXQ];

int dvcnt[MAXVAL + 1];
vector<int> who[MAXVAL + 1];

ll choose3(int n) { return (ll)n * (n - 1) * (n - 2) / 6; }
ll choose2(int n) { return (ll)n * (n - 1) / 2; }

void solve() {
	memset(dvcnt, 0, sizeof(dvcnt));
	FORE(v, 1,  MAXVAL) who[v].clear();
	REP(i, nq) who[ql[i]].PB(i);
	for (int v = MAXVAL; v >= 1; --v) {
		for (int w = v; w <= MAXVAL; w += v) ++dvcnt[w];
		for (int qid : who[v]) {
			int l = ql[qid], r = qr[qid], cnt = r - l + 1;
			qans[qid] = choose3(cnt);
			FORE(k, l, r) {
				qans[qid] -= choose2(dvcnt[k] - 1);
			}
			if (4 * l <= 2 * r) qans[qid] -= 2 * r / 12 - (4 * l - 1) / 12;
			if (5 * l <= 2 * r) qans[qid] -= 2 * r / 30 - (5 * l - 1) / 30;
		}
	}

}

void run() {
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]);
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}