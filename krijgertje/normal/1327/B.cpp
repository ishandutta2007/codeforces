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

int n;
vector<int> opt[MAXN];
int ansl, ansr;

bool used[MAXN];

bool solve() {
	REP(i, n) used[i] = false;
	ansl = -1;
	REP(i, n) {
		bool matched = false;
		REPSZ(j, opt[i]) { int x = opt[i][j]; if (used[x]) continue; used[x] = true; matched = true; break; }
		if (!matched && ansl == -1) ansl = i;
	}
	if (ansl == -1) return false;
	REP(i, n) if (!used[i]) { ansr = i; return true; }
	assert(false); return false;
}

void run() {
	scanf("%d", &n);
	REP(i, n) { int cnt; scanf("%d", &cnt); opt[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &opt[i][j]), --opt[i][j]; }
	if (!solve()) { printf("OPTIMAL\n"); return; }
	printf("IMPROVE\n");
	printf("%d %d\n", ansl + 1, ansr + 1);
}


int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}