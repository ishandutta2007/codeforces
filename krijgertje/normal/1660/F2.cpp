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
#include <functional>
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

struct BIT {
	int n; vector<int> val;
	void init(int _n) { n = _n; val = vector<int>(n + 1, 0); }
	int get(int idx) { ++idx; int ret = 0; while (idx > 0) { ret += val[idx]; idx -= idx & -idx; } return ret; }
	void mod(int idx, int by) { ++idx; while (idx <= n) { val[idx] += by; idx += idx & -idx; } }
};

const int MAXN = 200000;

int n;
char s[MAXN + 1];

int bal[MAXN + 1];

BIT bit[3];

ll solve() {
	bal[0] = 0;
	REP(i, n) bal[i + 1] = bal[i] + (s[i] == '+' ? -1 : +1);
	int mnbal = 0;
	REPE(i, n) mnbal = min(mnbal, bal[i]);
	REPE(i, n) bal[i] -= mnbal;
	int mxbal = 0;
	REPE(i, n) mxbal = max(mxbal, bal[i]);
	//printf("bal:"); REPE(i, n) printf(" %d", bal[i]); puts("");
	REP(i, 3) bit[i].init(mxbal + 1);
	ll ret = 0;
	REP(i, n) {
		bit[bal[i] % 3].mod(bal[i], +1);
		ret += bit[bal[i + 1] % 3].get(bal[i + 1]);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	scanf("%s", s);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}