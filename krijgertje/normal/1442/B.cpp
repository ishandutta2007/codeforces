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

const int MAXN = 200000;
const int MOD = 998244353;

int na, nb;
int a[MAXN];
int b[MAXN];

int apos[MAXN];
bool seen[MAXN];


int solve() {
	REP(i, na) apos[a[i]] = i, seen[i] = false;

	int ret = 1;
	for (int i = nb - 1; i >= 0; --i) {
		int idx = apos[b[i]];
		int cur = 0;
		seen[a[idx]] = true;
		if (idx - 1 >= 0 && !seen[a[idx - 1]]) ++cur;
		if (idx + 1 < na && !seen[a[idx + 1]]) ++cur;
		ret = (ll)ret * cur % MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d", &na, &nb);
	REP(i, na) scanf("%d", &a[i]), --a[i];
	REP(i, nb) scanf("%d", &b[i]), --b[i];
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}