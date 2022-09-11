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

const int MAXN = 200000;

int n;
int a[2][MAXN];
int b[2][MAXN];

ll solve() {
	int havetop = 0, havebot = 0, needtop = 0, needbot = 0;
	ll ret = 0;
	REP(i, n) {
		ret += havetop + havebot + needtop + needbot;
		assert(havetop == 0 && havebot == 0 || needtop == 0 && needbot == 0);
		int rematop = a[0][i], remabot = a[1][i], rembtop = b[0][i], rembbot = b[1][i];
		if (needtop == 0 && needbot == 0) {	havetop += rematop; rematop = 0; havebot += remabot; remabot = 0; }
		if (havetop == 0 && havebot == 0) {	needtop += rembtop; rembtop = 0; needbot += rembbot; rembbot = 0; }
		if (rembtop >= 1 && havetop >= 1) { int cur = min(rembtop, havetop); havetop -= cur; rembtop -= cur; }
		if (rembbot >= 1 && havebot >= 1) { int cur = min(rembbot, havebot); havebot -= cur; rembbot -= cur; }
		if (rematop >= 1 && needtop >= 1) { int cur = min(rematop, needtop); needtop -= cur; rematop -= cur; }
		if (remabot >= 1 && needbot >= 1) { int cur = min(remabot, needbot); needbot -= cur; remabot -= cur; }
		if (needtop == 0 && needbot == 0) { havetop += rematop; rematop = 0; havebot += remabot; remabot = 0; }
		if (havetop == 0 && havebot == 0) { needtop += rembtop; rembtop = 0; needbot += rembbot; rembbot = 0; }
		if (rembtop >= 1) { assert(havebot >= 1); int cur = min(rembtop, havebot); havebot -= cur; rembtop -= cur; ret += cur; }
		if (rembbot >= 1) { assert(havetop >= 1); int cur = min(rembbot, havetop); havetop -= cur; rembbot -= cur; ret += cur; }
		if (rematop >= 1) { assert(needbot >= 1); int cur = min(rematop, needbot); needbot -= cur; rematop -= cur; ret += cur; }
		if (remabot >= 1) { assert(needtop >= 1); int cur = min(remabot, needtop); needtop -= cur; remabot -= cur; ret += cur; }
		if (needtop == 0 && needbot == 0) { havetop += rematop; rematop = 0; havebot += remabot; remabot = 0; }
		if (havetop == 0 && havebot == 0) { needtop += rembtop; rembtop = 0; needbot += rembbot; rembbot = 0; }
		assert(rematop == 0 && remabot == 0 && rembtop == 0 && rembbot == 0);
	}
	if (havetop != 0 || havebot != 0 || needtop != 0 || needbot != 0) return -1;
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(x, 2) REP(y, n) scanf("%d", &a[x][y]);
	REP(x, 2) REP(y, n) scanf("%d", &b[x][y]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}