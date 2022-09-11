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

const int MAXN = 100000;
const int MAXQ = 100000;

int n, nq;
int a[MAXN];
int qkind[MAXQ], qarg[MAXQ], qans[MAXQ];

int cur[MAXN];

void solve() {
	REP(i, n) cur[i] = a[i];
	int none = 0;
	REP(i, n) if (cur[i] == 1) ++none;
	REP(i, nq) {
		if (qkind[i] == 1) {
			int idx = qarg[i] - 1;
			if (cur[idx] == 1) --none; else ++none;
			cur[idx] = 1 - cur[idx];
		}
		if (qkind[i] == 2) {
			int want = qarg[i] - 1;
			qans[i] = want < none ? 1 : 0;
		}
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nq) scanf("%d%d", &qkind[i], &qarg[i]);
	solve();
	REP(i, nq) if (qkind[i] == 2) printf("%d\n", qans[i]);

}

int main() {
	run();
	return 0;
}