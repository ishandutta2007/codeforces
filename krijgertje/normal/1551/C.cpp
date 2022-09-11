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
string s[MAXN];

int solve() {
	int ret = 0;
	REP(z, 5) {
		vector<int> opt;
		int start = 0;
		int cur = 0;
		REP(i, n) {
			int bal = 0;
			REPSZ(j, s[i]) if (s[i][j] == 'a' + z) ++bal; else --bal;
			if (bal >= 0) start += bal, ++cur; else opt.PB(-bal);
		}
		if (start <= 0) continue;
		sort(opt.begin(), opt.end());
		REPSZ(i, opt) if (start - opt[i] > 0) start -= opt[i], ++cur;
		ret = max(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) cin >> s[i];
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}