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

const int MAXROAD = 300000;

int nroad;
char road[MAXROAD + 1];
int ans[MAXROAD + 1];

int lft[MAXROAD + 1];
int rgt[MAXROAD + 1];


void solve() {
	REP(i, nroad + 1) {
		lft[i] = 0;
		if (i - 1 < 0 || road[i - 1] != 'L') continue;
		lft[i] = 1;
		if (i - 2 < 0 || road[i - 2] != 'R') continue;
		lft[i] = lft[i - 2] + 2;
	}
	for (int i = nroad; i >= 0; --i) {
		rgt[i] = 0;
		if (i >= nroad || road[i] != 'R') continue;
		rgt[i] = 1;
		if (i + 1 >= nroad || road[i + 1] != 'L') continue;
		rgt[i] = rgt[i + 2] + 2;
	}
	REP(i, nroad + 1) ans[i] = lft[i] + rgt[i] + 1;
}

void run() {
	scanf("%d", &nroad);
	scanf("%s", road); assert(strlen(road) == nroad);
	solve();
	REP(i, nroad + 1) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}