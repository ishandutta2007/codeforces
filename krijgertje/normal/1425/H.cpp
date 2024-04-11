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

int a, b, c, d;
bool ans[4];

void solve() {
	ans[0] = ans[1] = ans[2] = ans[3] = true;
	if (a == 0 && d == 0) ans[0] = ans[3] = false;
	if (b == 0 && c == 0) ans[1] = ans[2] = false;
	if ((a + b) % 2 == 0) ans[0] = ans[1] = false; else ans[2] = ans[3] = false;
}

void run() {
	scanf("%d%d%d%d", &a, &b, &c, &d);
	solve();
	REP(i, 4) { if (i != 0) printf(" "); printf("%s", ans[i] ? "Ya" : "Tidak"); } puts("");
}


int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}