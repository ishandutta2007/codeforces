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

const int MAXN = 52;

int n;
int a[MAXN];
vector<vector<int>> ans;

int cur[MAXN];
int pos[MAXN];

void perform(vector<int> op) {
	int nparts = SZ(op);
	vector<int> x(nparts); x[0] = 0; REP(i, nparts - 1) x[i + 1] = x[i] + op[i];
	vector<int> y(nparts); y[nparts - 1] = 0; for (int i = nparts - 1; i > 0; --i) y[i - 1] = y[i] + op[i];
	vector<int> ncur(n, -1);
	REP(i, nparts) REP(j, op[i]) ncur[y[i] + j] = cur[x[i] + j];
	REP(i, n) cur[i] = ncur[i];
}

void solve() {
	ans.clear();
	REP(i, n) cur[i] = a[i];
	while (true) {
		assert(SZ(ans) < n);
		REP(i, n) pos[cur[i]] = i;
		int d = 0; while (d + 1 < n && pos[d + 1] > pos[d]) ++d;
		if (d + 1 >= n) {
			REP(i, n) assert(cur[i] == i);
			break;
		}
		int a = d + 1;
		int c = d; while (c - 1 >= 0 && pos[c - 1] == pos[c] - 1) --c;
		int b = a; while (b + 1 < n && pos[b + 1] == pos[b] + 1) ++b;
		assert(pos[b] < pos[c]);
		vector<int> op;
		if (pos[a] != 0) op.PB(pos[a]);
		op.PB(pos[c] - pos[a]);
		op.PB(pos[d] - pos[c] + 1);
		if (pos[d] != n - 1) op.PB(n - pos[d] - 1);
		ans.PB(op);
		perform(op);
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { printf("%d", SZ(ans[i])); REPSZ(j, ans[i]) printf(" %d", ans[i][j]); puts(""); }
}

int main() {
	run();
	return 0;
}