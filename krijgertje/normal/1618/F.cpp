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

ll x, y;

string tostring(ll z) {
	string ret;
	while (z > 0) ret += string(1, '0' + z % 2), z /= 2;
	reverse(ret.begin(), ret.end());
	return ret;
}

bool can(string a, string b) {
	assert(a[0] == '1' && a.back() == '1');
	if (SZ(a) > SZ(b)) return false;
	REPE(i, SZ(b) - SZ(a)) {
		bool ok = true;
		REP(j, i) if (b[j] != '1') ok = false;
		if (b.substr(i, SZ(a)) != a) ok = false;
		FORSZ(j, i + SZ(a), b) if (b[j] != '1') ok = false;
		if (ok) return true;
	}
	return false;
}

bool solve() {
	string sx = tostring(x), sy = tostring(y);
	if (sx == sy) return true;
	if (can(sx + "1", sy)) return true;
	reverse(sx.begin(), sx.end());
	if (can("1" + sx, sy)) return true;
	reverse(sx.begin(), sx.end());
	while (sx.back() == '0') sx.pop_back();
	if (can(sx, sy)) return true;
	reverse(sx.begin(), sx.end());
	if (can(sx, sy)) return true;
	return false;
}

void run() {
	scanf("%lld%lld", &x, &y);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}