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
int p[MAXN];
vector<pair<int, int>> ans;

bool done[MAXN];
vector<vector<int>> cycs;

void solvetwo(const vector<int>& a, const vector<int>& b) {
	int alen = SZ(a), blen = SZ(b);
	ans.PB(MP(a[alen - 1], b[blen - 1]));
	REP(i, alen - 1) ans.PB(MP(a[i], b[blen - 1]));
	REP(i, blen - 1) ans.PB(MP(a[alen - 1], b[i]));
	ans.PB(MP(a[alen - 1], b[blen - 1]));
}

void solveone(const vector<int>& a) {
	int len = SZ(a);
	assert(len >= 3);
	ans.PB(MP(a[len - 3], a[len - 2]));
	ans.PB(MP(a[len - 2], a[len - 1]));
	ans.PB(MP(a[len - 3], a[len - 1]));
	REP(i, len - 2) ans.PB(MP(a[i], a[len - 2]));
}

void solve() {
	REP(i, n) done[i] = false;
	cycs.clear();
	REP(i, n) if (!done[i]) {
		vector<int> cyc; int at = i;
		while (!done[at]) { cyc.PB(at); done[at] = true; at = p[at]; }
		if (SZ(cyc) >= 2) cycs.PB(cyc);
	}
	ans.clear();
	while (SZ(cycs) >= 2) {
		vector<int> a = cycs.back(); cycs.pop_back();
		vector<int> b = cycs.back(); cycs.pop_back();
		solvetwo(a, b);
	}
	if (SZ(cycs) >= 1) {
		vector<int> a = cycs.back(); cycs.pop_back();
		if (SZ(a) >= 3) {
			solveone(a);
		} else {
			REP(i, n) { 
				bool ok = true; REPSZ(j, a) if (i == a[j]) ok = false; 
				if (!ok) continue;
				vector<int> b = { i };
				solvetwo(a, b);
				break;
			}
		}
	}

}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &p[i]), --p[i];
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main() {
	run();
	return 0;
}