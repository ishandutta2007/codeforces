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

const int MAXN = 100;
const int MAXQ = 100;

int n, nq;
char s[MAXN + 1];
int ql[MAXQ], qr[MAXQ]; bool qans[MAXQ];

bool prefsame[MAXN];
bool suffsame[MAXN];

void solve() {
	prefsame[0] = true; FOR(i, 1, n) prefsame[i] = prefsame[i - 1] && s[i] == s[i - 1];
	suffsame[n - 1] = true; for (int i = n - 2; i >= 0; --i) suffsame[i] = suffsame[i + 1] && s[i] == s[i + 1];
	REP(i, nq) {
		int l = ql[i], r = qr[i];
		qans[i] = !((l == 0 || s[l - 1] != s[l] && prefsame[l - 1]) && (r == n - 1 || s[r] != s[r + 1] && suffsame[r + 1]));
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	scanf("%s", s); assert(strlen(s) == n);
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%s\n", qans[i] ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}