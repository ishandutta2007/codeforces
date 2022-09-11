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

int n;
int b[MAXN];

bool solve() {
	set<int> seen;
	REP(i, n) {
		if (i == 0) { seen.insert(b[i]); continue; }
		if (b[i] == b[i - 1]) continue;
		auto it = seen.find(b[i - 1]);
		assert(it != seen.end());
		if (b[i] < b[i - 1] && it != seen.begin() && *prev(it)>b[i]) return false;
		if (b[i] > b[i - 1] && next(it) != seen.end() && *next(it) < b[i]) return false;
		if (!seen.count(b[i])) seen.insert(b[i]);
	}
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &b[i]);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}