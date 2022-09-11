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
int ans[MAXN];

void solve() {
	int start = 0;
	int curans = 0;
	vector<pair<int, int>> glst;
	REP(i, n) {
		REPSZ(j, glst) glst[j].second = gcd(glst[j].second, a[i]);
		glst.PB(MP(i, a[i]));
		{
			int sz = 0;
			REPSZ(j, glst) {
				while (sz >= 1 && glst[sz - 1].second == glst[j].second) --sz;
				glst[sz++] = glst[j];
			}
			glst.resize(sz);
		}
		//printf("glst%d:", i); for (auto z : glst) printf(" %d:%d", z.first, z.second); puts("");

		for (int j = SZ(glst) - 1; j >= 0 && glst[j].first >= start; --j) {
			int lcnt = i - glst[j].first + 1;
			int rcnt = i - max(start, (j == 0 ? 0 : glst[j - 1].first + 1)) + 1;
			//printf("i=%d j=%d = (%d,%d) -> %d..%d\n", i, j, glst[j].first, glst[j].second, lcnt, rcnt);
			if (lcnt <= glst[j].second && glst[j].second <= rcnt) {
				start = i + 1;
				++curans;
				break;
			}
		}
		ans[i] = curans;
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}