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
int a[MAXN];

int b[MAXN];

bool solve() {
	REP(i, n) {
		int x = a[i];
		while (true) {
			int y = x % 10;
			if (y == 0 || y == 2) break;
			x += y;
		}
		b[i] = x;
	}
	//printf("b:"); REP(i, n) printf(" %d", b[i]); puts("");
	int xx = b[0] % 10, yy = b[0] / 10;
	if (xx == 0) {
		FOR(i, 1, n) if (b[i] != b[0]) return false;
	} else {
		assert(xx == 2);
		FOR(i, 1, n) if (b[i] % 10 != 2 || b[i] / 10 % 2 != yy % 2) return false;
	}
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%s\n", solve() ? "Yes" : "No");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}