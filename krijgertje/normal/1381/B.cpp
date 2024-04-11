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

const int MAXN = 2000;

int n;
int a[2 * MAXN];

int b[2 * MAXN], nb;

bool can[MAXN + 1];

bool solve() {
	nb = 0;
	for (int l = 0, r = l; l < 2 * n; l = r) {
		while (r < 2 * n && a[r] <= a[l]) ++r;
		b[nb++] = r - l;
	}
	//printf("b:"); REP(i, nb) printf(" %d", b[i]); puts("");

	REPE(i, n) can[i] = false; can[0] = true;
	REP(i, nb) for (int j = n - b[i]; j >= 0; --j) if (can[j]) can[j + b[i]] = true;
	return can[n];
}

void run() {
	scanf("%d", &n);
	REP(i, 2 * n) scanf("%d", &a[i]);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}