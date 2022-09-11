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

const int MAXN = 1000000;

int n, step;
int a[MAXN];

int b[MAXN], nb;

int solve() {
	int g = gcd(n, step);
	int ret = 0;
	REP(offset, g) {
		int at = offset;
		nb = 0;
		while (true) {
			b[nb++] = a[at];
			at += step;
			if (at >= n) at -= n;
			if (at == offset) break;
		}
		int zeropos = -1;
		REP(i, nb) if (b[i] == 0) { zeropos = i; break; }
		if (zeropos == -1) return -1;
		rotate(b, b + zeropos, b + nb);
		for (int l = 0, r = l; l < nb; l = r) {
			while (r < nb && b[r] == b[l]) ++r;
			if (b[l] == 1) ret = max(ret, r - l);
		}
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &step);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}