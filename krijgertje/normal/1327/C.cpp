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

const int MAXH = 200;
const int MAXW = 200;

int h, w;
char ans[2 * MAXH * MAXW + 1];

void solve() {
	int anslen = 0;
	REP(i, h - 1) ans[anslen++] = 'U';
	REP(i, w - 1) ans[anslen++] = 'L';
	REP(x, h) {
		if (x != 0) ans[anslen++] = 'D';
		REP(i, w - 1) ans[anslen++] = x % 2 == 0 ? 'R' : 'L';
	}
	ans[anslen] = '\0';
}


void run() {
	scanf("%d%d", &h, &w);
	solve();
	printf("%d\n", strlen(ans));
	printf("%s\n", ans);
}


int main() {
	run();
	return 0;
}