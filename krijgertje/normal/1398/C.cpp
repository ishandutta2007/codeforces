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

int n;
char s[MAXN + 1];

int have[MAXN + 1]; int nhave;

ll solve() {
	nhave = 0;
	int cur = 0; 
	REPE(i, n) {
		have[nhave++] = cur;
		if (i == n) break;
		cur += s[i] - '0' - 1;
	}
	sort(have, have + nhave);
	ll ret = 0;
	for (int l = 0, r = l; l < nhave; l = r) { while (r < nhave && have[r] == have[l]) ++r; int cnt = r - l; ret += (ll)cnt * (cnt - 1) / 2; }
	return ret;
}


void run() {
	scanf("%d", &n);
	scanf("%s", s); assert(strlen(s) == n);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}