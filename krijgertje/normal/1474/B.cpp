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

const int MAXDIFF = 10000;
const int MAXVAL = 2 * MAXDIFF + 1000;

bool isprime[MAXVAL + 1];
int nxtprime[MAXVAL + 1];

int diff;


void precalc() {
	REPE(i, MAXVAL) isprime[i] = true;
	isprime[0] = isprime[1] = false;
	REPE(i, MAXVAL) if (isprime[i]) for (int j = i + i; j <= MAXVAL; j += i) isprime[j] = false;
	for (int i = MAXVAL; i >= 0; --i) nxtprime[i] = isprime[i] ? i : i + 1 <= MAXVAL ? nxtprime[i + 1] : -1;
}

ll solve() {
	assert(1 + diff <= MAXVAL);
	int a = nxtprime[1 + diff];
	assert(a != -1 && a + diff <= MAXVAL);
	int b = nxtprime[a + diff];
	assert(b != -1);
	return (ll)a * b;
}

void run() {
	scanf("%d", &diff);
	printf("%lld\n", solve());
}

int main() {
	precalc();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}