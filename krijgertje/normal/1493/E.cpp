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

int n;
char l[MAXN + 1];
char r[MAXN + 1];
char ans[MAXN + 1];

void solve() {
	REP(i, n) ans[i] = '?'; ans[n] = '\0';
	if (l[0] != r[0]) {
		REP(i, n) ans[i] = '1';
	} else {
		REP(i, n) ans[i] = r[i];
		if (ans[n - 1] == '0') {
			int prefsame = 0; while (prefsame < n && l[prefsame] == r[prefsame]) ++prefsame;
			bool same = prefsame == n;
			bool lhi = true; FOR(i, prefsame + 1, n) if (l[i] != '1') lhi = false;
			bool rlo = true; FOR(i, prefsame + 1, n) if (r[i] != '0') rlo = false;
			if (!same && (!lhi || !rlo)) ans[n - 1] = '1';
		}
	}
}

void run() {
	scanf("%d", &n);
	scanf("%s", l);
	scanf("%s", r);
	solve();
	printf("%s\n", ans);
}

int main() {
	run();
	return 0;
}