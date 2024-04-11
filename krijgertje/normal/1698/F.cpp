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

const int MAXN = 500;

int n;
int a[MAXN];
int b[MAXN];
vector<pair<int, int>> ans;

int c[MAXN];

bool solve() {
	ans.clear();
	REP(i, n) c[i] = a[i];
	if (c[0] != b[0]) return false;
	auto move = [&](int l, int r) { assert(0 <= l && l < r && r < n && c[l] == c[r]); ans.PB(MP(l, r)); reverse(c + l, c + r + 1); };
	FOR(i, 1, n) {
		int x = b[i - 1], y = b[i];
		if (c[i] == y) continue;
		bool found = false;
		FOR(j, i, n - 1) if (c[j] == y && c[j + 1] == x) {
			move(i - 1, j + 1);
			assert(c[i] == y);
			found = true;
			break;
		}
		if (found) continue;
		int xlast = -1;
		FOR(j, i, n) if (c[j] == x) xlast = j;
		if (xlast == -1) return false;
		FOR(j, i, n - 1) if (c[j] == x && c[j + 1] == y && j + 1 < xlast) {
			move(j, xlast);
			move(i - 1, xlast);
			assert(c[i] == y);
			found = true;
			break;
		}
		if (found) continue;
		if (xlast == n - 1) return false;
		if (c[xlast + 1] != y) return false;
		map<int, int> any;
		FOR(j, i, xlast) {
			int z = c[j];
			any[z] = j;
		}
		FOR(j, xlast + 1, n) {
			int z = c[j];
			if (any.count(z)) {
				int k = any[z];
				move(k, j);
				move(i - 1, k + j - xlast);
				assert(c[i] == y);
				found = true;
				break;
			}
		}
		if (found) continue;
		return false;
	}
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	REP(i, n) scanf("%d", &b[i]), --b[i];
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}