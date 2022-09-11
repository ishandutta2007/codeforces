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

const int MAXN = 1000;

int n;

int state[MAXN];

void solve() {
	int best = -1, bestblock = -1;
	FORE(i, 1, n) {
		int cur = max(0, n - ((n + i - 1) / i + (i - 1)));
		if (cur > best) best = cur, bestblock = i;
	}

	REP(i, n) state[i] = 0;
	while (true) {
		int cur = 0; REP(i, n) cur += state[i]; if (cur >= best) break;
		vector<int> move; REP(i, n) if (state[i] == 0 && i%bestblock != 0) move.PB(i);
		printf("%d", SZ(move)); REPSZ(i, move) printf(" %d", move[i] + 1); puts(""); fflush(stdout);
		REPSZ(i, move) state[move[i]] = 1;
		int reply; scanf("%d", &reply); if (reply == -1) exit(0); --reply;
		REPSZ(i, move) state[(reply + i) % n] = 0;
	}
	printf("0\n");
	fflush(stdout);
}

void run() {
	scanf("%d", &n);
	solve();
}

int main() {
	run();
	return 0;
}