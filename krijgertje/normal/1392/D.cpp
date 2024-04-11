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

char t[MAXN + 1];

int solve() {
	bool allsame = true;
	FOR(i, 1, n) if (s[i] != s[i - 1]) allsame = false;
	if (allsame) return n <= 2 ? 0 : (n + 2) / 3;
	REP(i, n - 1) if (s[i] != s[i + 1]) {
		REP(j, n) t[j] = s[(i + 1 + j) % n];
		t[n] = '\0';
		int ret = 0;
		for (int l = 0, r = l; l < n; l = r) {
			while (r < n && t[r] == t[l]) ++r;
			int cnt = r - l;
			ret += cnt / 3;
		}
		return ret;
	}
	assert(false);
	return -1;
}

void run() {
	scanf("%d", &n);
	scanf("%s", s); assert(strlen(s) == n);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i,1,ncase) run();
	return 0;
}