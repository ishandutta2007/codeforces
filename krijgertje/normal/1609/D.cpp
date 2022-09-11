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

const int MAXN = 1000;
const int MAXQ = MAXN - 1;

int n, nq;
int qa[MAXQ], qb[MAXQ];
int qans[MAXQ];

int col[MAXN];
int cnt[MAXN];

void solve() {
	REP(i, n) col[i] = i;
	int nextra = 0;
	REP(i, nq) {
		int a = qa[i], b = qb[i];
		if (col[a] == col[b]) { 
			++nextra;
		} else {
			int ocol = col[b];
			REP(j, n) if (col[j] == ocol) col[j] = col[a];
		}
		REP(j, n) cnt[j] = 0;
		REP(j, n) ++cnt[col[j]];
		sort(cnt, cnt + n);
		reverse(cnt, cnt + n);
		qans[i] = -1;
		REP(j, 1 + nextra) qans[i] += cnt[j];
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, nq) scanf("%d%d", &qa[i], &qb[i]), --qa[i], --qb[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}