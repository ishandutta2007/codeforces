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

const int MAXN = 200000;

int n;
int a[MAXN];

bool solve() {
	vector<int> neg; int cntzero = 0; vector<int> pos;
	REP(i, n) if (a[i] < 0) neg.PB(-a[i]); else if (a[i] > 0) pos.PB(a[i]); else ++cntzero;
	if (SZ(pos) >= 3 || SZ(neg) >= 3) return false;
	if (SZ(pos) >= 2 && cntzero >= 1 || SZ(neg) >= 2 && cntzero >= 1) return false;
	if (SZ(pos) + SZ(neg) <= 1) return true;
	if (SZ(pos) + SZ(neg) + cntzero <= 2) return true;
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());
	if (SZ(pos) == SZ(neg)) {
		if (pos == neg) return true;
		if (SZ(pos) == 2 && pos[0] == pos[1] && (pos[0] == neg[0] || pos[0] == neg[1]) && neg[0] + neg[1] == 4 * pos[0]) return true;
		if (SZ(neg) == 2 && neg[0] == neg[1] && (neg[0] == pos[0] || neg[0] == pos[1]) && pos[0] + pos[1] == 4 * neg[0]) return true;
		return false;
	}
	assert(SZ(pos) + SZ(neg) == 3 && cntzero == 0 && max(SZ(pos), SZ(neg)) == 2);
	if (SZ(pos) == 1) { int x = pos[0]; bool found = false; for (int y : neg) if (y == x) found = true; if (!found) return false; }
	if (SZ(neg) == 1) { int x = neg[0]; bool found = false; for (int y : pos) if (y == x) found = true; if (!found) return false; }
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}