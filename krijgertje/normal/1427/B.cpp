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

int n, mxchange;
char s[MAXN + 1];

int solve() {
	int start = 0;
	REP(i, n) if (s[i] == 'W') start += i - 1 >= 0 && s[i - 1] == 'W' ? 2 : 1;
	if (mxchange == 0) return start;

	int pref = 0;
	while (pref < n && s[pref] == 'L') ++pref;
	if (pref == n) return 1 + (mxchange - 1) * 2;

	int suff = 0;
	while (suff < n && s[n - suff - 1] == 'L') ++suff;

	vector<int> mid;
	FOR(i, pref, n - suff - 1) if(s[i]=='W') {
		int j = i + 1; while (j < n && s[j] == 'L') ++j;
		assert(j != n);
		int cnt = j - i - 1;
		if (cnt > 0) mid.PB(cnt);
	}
	sort(mid.begin(), mid.end());

	int ret = start;
	int rem = mxchange;
	REPSZ(i, mid) {
		int cur = min(mid[i], rem);
		rem -= cur;
		ret += 2 * cur;
		if (cur == mid[i]) ++ret;
	}
	{
		int cur = min(pref + suff, rem);
		rem -= cur;
		ret += 2 * cur;
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &mxchange);
	scanf("%s", s); assert(strlen(s) == n);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}