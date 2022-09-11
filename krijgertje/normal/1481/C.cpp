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

const int MAXPLANK = 100000;
const int MAXPAINTER = 100000;

int nplank, npainter;
int a[MAXPLANK];
int b[MAXPLANK];
int c[MAXPAINTER];
int ans[MAXPAINTER];

vector<int> need[MAXPLANK];

bool solve() {
	REP(i, nplank) need[i].clear();
	REP(i, nplank) if (b[i] != a[i]) need[b[i]].PB(i);
	int last = -1;
	REP(i, nplank) if (b[i] == c[npainter - 1] && (last == -1 || b[i] != a[i] && b[last] == a[last])) last = i;
	if (last == -1) return false;
	REP(i, npainter) {
		int col = c[i];
		if (!need[col].empty()) { int to = need[col].back(); need[col].pop_back(); ans[i] = to; continue; }
		ans[i] = last;
	}
	REP(i, nplank) if (SZ(need[i]) != 0) return false;
	return true;
}

void run() {
	scanf("%d%d", &nplank, &npainter);
	REP(i, nplank) scanf("%d", &a[i]), --a[i];
	REP(i, nplank) scanf("%d", &b[i]), --b[i];
	REP(i, npainter) scanf("%d", &c[i]), --c[i];
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, npainter) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}