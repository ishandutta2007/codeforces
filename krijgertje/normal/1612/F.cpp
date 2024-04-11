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

const int MAXCOMBO = 200000;

int wanta, wantb;
int ncombo;
int combo[MAXCOMBO][2];

set<pair<int, int>> comboset;

int rec(int amx, int bmx, bool forced) {
	if (amx >= wanta && bmx >= wantb) return 0;
	if (amx >= wanta) { int ret = 0; while (bmx < wantb) { ++ret; bmx += amx + (comboset.count(MP(amx, bmx)) ? 1 : 0); } return ret; }
	if (bmx >= wantb) { int ret = 0; while (amx < wanta) { ++ret; amx += bmx + (comboset.count(MP(amx, bmx)) ? 1 : 0); } return ret; }
	int lim = amx + bmx + (comboset.count(MP(amx, bmx)) ? 1 : 0);
	int ret = INT_MAX;
	if (!forced || amx <= bmx) ret = min(ret, 1 + rec(min(lim, wanta), bmx, forced || amx > bmx));
	if (!forced || bmx <= amx) ret = min(ret, 1 + rec(amx, min(lim, wantb), forced || bmx > amx));
	assert(ret != INT_MAX);
	return ret;
}

int solve() {
	comboset.clear();
	REP(i, ncombo) comboset.insert(MP(combo[i][0], combo[i][1]));
	return rec(1, 1, false);
}

void run() {
	scanf("%d%d", &wanta, &wantb);
	scanf("%d", &ncombo);
	REP(i, ncombo) scanf("%d%d", &combo[i][0], &combo[i][1]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}