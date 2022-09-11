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

const int MAXH = 500;
const int MAXW = 500;

int h, w;
int a[MAXH][MAXW];
int b[MAXH][MAXW];

void solve() {
	int want = 720720;
	FORE(i, 1, 16) assert(want % i == 0);
	vector<int> found(16 + 1, -1);
	for (int k = 1; k * k * k * k < want; ++k) {
		int have = want - k * k * k * k;
		FORE(i, 1, 16) if (have % i == 0) found[i] = have;
	}
	//FORE(i, 1, 16) printf("%d: %d\n", i, found[i]);

	REP(x, h) REP(y, w) if ((x + y) % 2 == 0) b[x][y] = want; else b[x][y] = found[a[x][y]];
}

void run() {
	scanf("%d%d", &h, &w);
	REP(x, h) REP(y, w) scanf("%d", &a[x][y]);
	solve();
	REP(x, h) { REP(y, w) { if (y != 0) printf(" "); printf("%d", b[x][y]); } puts(""); }
}

int main() {
	run();
	return 0;
}