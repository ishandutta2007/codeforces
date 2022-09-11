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
char s[MAXN + 1];

vector<int> pos[26];
vector<int> npos[26];

int who[MAXN];
int bit[MAXN + 1];

int bget(int idx) { ++idx; int ret = 0; while (idx >0) { ret += bit[idx]; idx -= idx & -idx; } return ret; }
void bmod(int idx, int by) { ++idx; while (idx <= n) { bit[idx] += by; idx += idx & -idx; } }

ll solve() {
	REP(i, 26) pos[i].clear();
	REP(i, n) pos[s[i] - 'a'].PB(i), npos[s[i] - 'a'].PB(n - i - 1);
	REP(i, 26) reverse(npos[i].begin(), npos[i].end());
	REP(i, 26) REPSZ(j, pos[i]) { int x = pos[i][j], y = npos[i][j]; who[y] = x; }
	REPE(i, n) bit[i] = 0;
	ll ret = 0;
	for (int i = n - 1; i >= 0; --i) {
		int idx = who[i];
		ret += bget(idx);
		bmod(idx, +1);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	scanf("%s", s); assert(strlen(s) == n);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}