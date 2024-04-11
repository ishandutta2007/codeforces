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

const int MAXN = 300000;

int n;
int a[MAXN];
int ans[MAXN + 1];

vector<int> pos[MAXN + 1];

void solve() {
	FORE(i, 1, n) pos[i].clear();
	REP(i, n) pos[a[i]].PB(i);
	FORE(i, 1, n) ans[i] = INT_MAX;
	FORE(i, 1, n) if(SZ(pos[i])>=1) {
		int k = max(pos[i][0] + 1, n - pos[i].back());
		FORSZ(j, 1, pos[i]) k = max(k, pos[i][j] - pos[i][j - 1]);
		ans[k] = min(ans[k], i);
	}
	FORE(i, 2, n) ans[i] = min(ans[i], ans[i - 1]);
	FORE(i, 1, n) if (ans[i] == INT_MAX) ans[i] = -1;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	FORE(i, 1, n) { if (i != 1) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}