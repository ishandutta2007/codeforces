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

const int MAXN = 100000;
const int ALPH = 26;

int n;
char a[MAXN + 1];
char b[MAXN + 1];

int par[ALPH], sz[ALPH];
int uffind(int x) { if (par[x] == x) return x; return par[x] = uffind(par[x]); }
void ufunite(int x, int y) { x = uffind(x), y = uffind(y); if (x == y) return; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; }

int solve() {
	REP(i, n) if (a[i] > b[i]) return -1;
	REP(i, ALPH) par[i] = i, sz[i] = 1;
	REP(i, n) {
		int x = a[i] - 'a', y = b[i] - 'a';
		//printf("unite (%d,%d)\n", x, y);
		ufunite(x, y);
	}
	//REP(i, ALPH) if (par[i] == i) printf("%d: %d\n", i, sz[i]);
	int ret = 0; REP(i, ALPH) if (par[i] == i) ret += sz[i] - 1; return ret;
}

void run() {
	scanf("%d", &n);
	scanf("%s", a); assert(strlen(a) == n);
	scanf("%s", b); assert(strlen(b) == n);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}