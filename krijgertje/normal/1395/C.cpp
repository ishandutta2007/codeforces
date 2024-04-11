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

const int MAXA = 200;
const int MAXB = 200;
const int MAXBIT = 8;

int na, nb;
int a[MAXA];
int b[MAXB];

bool kill[2 << MAXBIT];

int solve() {
	REP(mask, 2 << MAXBIT) kill[mask] = false;
	REP(i, nb) kill[(2 << MAXBIT) - 1 - b[i]] = true;
	REPE(bit, MAXBIT) REP(mask, 2 << MAXBIT) if (mask & (1 << bit)) kill[mask ^ (1 << bit)] |= kill[mask];
	REP(ret, 2 << MAXBIT) {
		bool ok = true;
		REP(i, na) if (!kill[a[i] & ~ret]) ok = false;
		if (ok) return ret;
	}
	assert(false); return -1;
}

void run() {
	scanf("%d%d", &na, &nb);
	REP(i, na) scanf("%d", &a[i]);
	REP(i, nb) scanf("%d", &b[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}