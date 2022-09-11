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
char s[MAXN + 1];
char t[MAXN + 1];

ll solve() {
	if (s[0] != t[0] || s[n - 1] != t[n - 1]) return -1;
	vector<pair<int, int>> a;
	for (int l = 0, r = l; l < n; l = r) {
		while (r < n && s[r] == s[l]) ++r;
		if (s[l] == '1') a.PB(MP(l, r - 1));
	}
	vector<pair<int, int>> b;
	for (int l = 0, r = l; l < n; l = r) {
		while (r < n && t[r] == t[l]) ++r;
		if (t[l] == '1') b.PB(MP(l, r - 1));
	}
	if (SZ(a) != SZ(b)) return -1;
	ll ret = 0;
	REPSZ(i, a) ret += abs(a[i].first - b[i].first) + abs(a[i].second - b[i].second);
	return ret;
}

void run() {
	scanf("%d", &n);
	scanf("%s", s);
	scanf("%s", t);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}