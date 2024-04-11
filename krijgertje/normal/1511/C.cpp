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
const int NVAL = 50;

int n, nq;
int a[MAXN];
int q[MAXQ];
int ans[MAXQ];

int pos[NVAL];

void solve() {
	REP(i, NVAL) pos[i] = -1;
	REP(i, n) if (pos[a[i]] == -1) pos[a[i]] = i;
	REP(i, nq) {
		int v = q[i];
		assert(pos[v] != -1);
		ans[i] = pos[v];
		REP(j, NVAL) if (pos[j] < pos[v]) ++pos[j];
		pos[v] = 0;
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	REP(i, nq) scanf("%d", &q[i]), --q[i];
	solve();
	REP(i, nq) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}