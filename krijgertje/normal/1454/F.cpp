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
int a[MAXN];
int ansl, ansr;

bool solve() {
	map<int, vector<int>> pos;
	REP(i, n) pos[a[i]].PB(i);
	int l = INT_MAX, r = INT_MIN, mn = INT_MAX;

	for (auto it = pos.rbegin(); it != pos.rend(); ++it) {
		vector<int> cur = it->second;
		if (it == pos.rbegin()) {
			if (SZ(cur) >= 3) {
				ansl = ansr = cur[1];
				return true;
			}
			l = cur[0], r = cur[SZ(cur) - 1];
			FORE(i, l, r) mn = min(mn, a[i]);
		} else {
			if (SZ(cur) >= 3 && cur[0]<l && cur[SZ(cur) - 1]>r && mn >= it->first) {
				bool inside = false;
				int lft = INT_MIN, rgt = INT_MAX;
				FOR(i, 1, SZ(cur) - 1) {
					int now = cur[i];
					if (now < l) lft = max(lft, now);
					else if (now > r) rgt = min(rgt, now);
					else inside = true;
				}
				if (inside) {
					ansl = l, ansr = r;
					return true;
				}
				if (lft != INT_MIN) {
					bool ok = true;
					FOR(i, lft, l) if (a[i] < it->first) ok = false;
					if (ok) {
						ansl = lft, ansr = r;
						return true;
					}
				}
				if(rgt != INT_MAX) {
					bool ok = true;
					FORE(i, r + 1, rgt) if (a[i] < it->first) ok = false;
					if (ok) {
						ansl = l, ansr = rgt;
						return true;
					}
				}
			}
		}
		while (cur[0] < l) --l, mn = min(mn, a[l]);
		while (cur[SZ(cur) - 1] > r) ++r, mn = min(mn, a[r]);
	}
	return false;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%d %d %d\n", ansl, ansr - ansl + 1, n - ansl - (ansr - ansl + 1));
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}