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

const int MAXN = 100000;
const int MAXQ = 100000;

int n, nq;
char s[MAXN + 1];
int qidx[MAXQ]; char qc[MAXQ];
int qans[MAXQ];

char cur[MAXN];

void solve() {
	auto calc = [&](int idx) { if (idx < 0 || idx + 2 >= n) return 0; return cur[idx] == 'a' && cur[idx + 1] == 'b' && cur[idx + 2] == 'c' ? 1 : 0; };
	REP(i, n) cur[i] = s[i];
	int cnt = 0;
	REP(i, n) cnt += calc(i);
	REP(i, nq) {
		int idx = qidx[i];
		FORE(delta, -2, +2) cnt -= calc(idx + delta);
		cur[idx] = qc[i];
		FORE(delta, -2, +2) cnt += calc(idx + delta);
		qans[i] = cnt;
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	scanf("%s", s);
	REP(i, nq) scanf("%d %c", &qidx[i], &qc[i]), --qidx[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}