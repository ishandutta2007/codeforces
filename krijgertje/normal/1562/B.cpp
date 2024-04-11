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

const int MAXN = 50;

int n;
char s[MAXN + 1];

bool isprime(int x) {
	if (x <= 1) return false;
	for (int y = 2; y * y <= x; ++y) if (x % y == 0) return false;
	return true;
}

string solve() {
	vector<int> cnt(10, 0);
	REP(i, n) {
		int x = s[i] - '0';
		if (x >= 4 && x % 2 == 0 || x == 1 || x == 9) return string(1, '0' + x);
		++cnt[x];
	}
	REP(i, 10) if (cnt[i] >= 2) return string(2, '0' + i);
	assert(n <= 4);
	string ret = "";
	FOR(mask, 1, 1 << n) {
		string cur;
		int curval = 0;
		REP(i, n) if (mask & (1 << i)) cur += string(1, s[i]), curval = 10 * curval + s[i] - '0';
		if (isprime(curval)) continue;
		if (ret == "" || SZ(cur) < SZ(ret)) ret = cur;
	}
	assert(ret != "");
	return ret;
}

void run() {
	scanf("%d", &n);
	scanf("%s", s);
	string ans = solve();
	printf("%d\n", SZ(ans));
	printf("%s\n", ans.c_str());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}