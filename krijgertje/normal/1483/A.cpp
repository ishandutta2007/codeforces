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

const int MAXFRIEND = 100000;
const int MAXDAY = 100000;

int nfriend, nday;
vector<int> avail[MAXDAY];
int ans[MAXDAY];

int cnt[MAXFRIEND];

bool solve() {
	int lim = (nday + 1) / 2;
	REP(i, nfriend) cnt[i] = 0;
	REP(i, nday) ans[i] = -1;
	REP(i, nday) if (SZ(avail[i]) == 1) {
		int x = avail[i][0];
		++cnt[x], ans[i] = x;
		if (cnt[x] > lim) return false;
	}
	REP(i, nday) if (SZ(avail[i]) >= 2) {
		int x = avail[i][0], y = avail[i][1];
		if (cnt[x] < lim) ++cnt[x], ans[i] = x; else if (cnt[y] < lim) ++cnt[y], ans[i] = y; else assert(false);
	}
	return true;
}

void run() {
	scanf("%d%d", &nfriend, &nday);
	REP(i, nday) { int cnt; scanf("%d", &cnt); avail[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &avail[i][j]), --avail[i][j]; }
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, nday) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}


int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}