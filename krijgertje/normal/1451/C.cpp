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

int n, blocksz;
char s[MAXN + 1];
char t[MAXN + 1];

int bal[26];

bool solve() {
	REP(i, 26) bal[i] = 0;
	REP(i, n) bal[s[i] - 'a']++;
	REP(i, n) bal[t[i] - 'a']--;
	REP(i, 26) {
		if (bal[i] < 0 || bal[i] % blocksz != 0) return false;
		if (bal[i] == 0) continue;
		assert(i + 1 < 26);
		bal[i + 1] += bal[i];
		bal[i] = 0;
	}
	return true;
}

void run() {
	scanf("%d%d", &n, &blocksz);
	scanf("%s", s);
	scanf("%s", t);
	assert(strlen(s) == n && strlen(t) == n);
	printf("%s\n", solve() ? "Yes" : "No");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}