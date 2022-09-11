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
int ansv, ansl, ansr;

void solve() {
	int best = -1;
	map<int, vector<int>> pos;
	REP(i, n) pos[a[i]].PB(i);
	for (const auto& kvp : pos) {
		const auto& lst = kvp.second;
		int cur = INT_MIN, start = -1;
		REPSZ(i, lst) {
			if (i != 0) cur -= lst[i] - lst[i - 1] - 1;
			if (cur < 0) cur = 0, start = lst[i];
			++cur;
			if (cur > best) best = cur, ansv = kvp.first, ansl = start, ansr = lst[i];
		}
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	printf("%d %d %d\n", ansv, ansl + 1, ansr + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}