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

struct P { int x, y; };

P a, b, c;

bool between(int c, int a, int b) {
	return min(a, b) <= c && c <= max(a, b);
}

int solve() {
	int ret = abs(a.x - b.x) + abs(a.y - b.y);
	if (a.x == b.x && b.x == c.x && between(c.y,a.y,b.y) || a.y == b.y && b.y == c.y && between(c.x, a.x, b.x)) {
		ret += 2;
	}
	return ret;
}

void run() {
	scanf("%d%d", &a.x, &a.y);
	scanf("%d%d", &b.x, &b.y);
	scanf("%d%d", &c.x, &c.y);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}