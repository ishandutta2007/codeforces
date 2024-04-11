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

const int MAXN = 200;
const int MAXCARD = 6 * MAXN;

int n, ncard;
int col[MAXCARD];
vector<vector<int>> ans;

bool can[MAXCARD][MAXCARD];
int prv[MAXCARD + 1][4];

vector<vector<int>> lst;
vector<int> par;
vector<vector<int>> ch;
vector<bool> done;
vector<int> rem;

void build(int s, int t) {
	//printf("build(%d,%d)\n", s, t);
	vector<pair<int, vector<int>>> stck;
	FORE(i, s, t) {
		if (stck.empty() || stck.back().first != col[i]) {
			stck.PB(MP(col[i], vector<int>(1, i)));
		} else {
			stck.back().second.PB(i);
			if (SZ(stck.back().second) == 3) {
				vector<int> cur = stck.back().second;
				lst.PB(cur);
				stck.pop_back();
			}
		}
	}
	assert(SZ(stck) == 0);
}

bool inside(const vector<int>& a, const vector<int>& b) {
	bool pos1 = true, pos2 = true;
	REPSZ(i, a) {
		if (a[i]<b[0] || a[i]>b[1]) pos1 = false;
		if (a[i]<b[1] || a[i]>b[2]) pos2 = false;
	}
	return pos1 || pos2;
}
bool conflicting(const vector<int> &a, const vector<int> &b) {
	if (inside(a, b) || inside(b, a)) return false;
	if (a[2] < b[0] || b[2] < a[0]) return false;
	return true;
}


void solve() {
	//printf("col: "); REP(i, ncard) printf(" %d", col[i]); puts("");
	
	REP(s, ncard) {
		vector<pair<int, int>> stck;
		FOR(i, s, ncard) {
			if (stck.empty() || stck.back().first != col[i]) stck.PB(MP(col[i], 1)); else if (stck.back().second == 2) stck.pop_back(); else ++stck.back().second;
			can[s][i] = stck.empty();
			//if (can[s][i]) printf("can %d..%d\n", s, i);
		}
	}
	
	REPE(i, ncard) REPE(j, 3) prv[i][j] = -2;
	REP(i, ncard) if (col[i] == 1 && (i == 0 || can[0][i - 1])) prv[i][0] = -1;
	REP(i, ncard) REP(j, 3) if (prv[i][j] != -2) {
		FORE(k, i + 1, ncard) if ((k == ncard || col[k] == 1) && (k == i + 1 || can[i + 1][k - 1])) prv[k][j + 1] = i;
	}
	//REPE(i, ncard) REPE(j, 3) if (prv[i][j] != -2) printf("prv[%d][%d]=%d\n", i, j, prv[i][j]);
	assert(prv[ncard][3] != -2);
	
	vector<int> last;
	for (int i = prv[ncard][3], j = 2; i != -1; i = prv[i][j], --j) last.PB(i);
	reverse(last.begin(), last.end());
	//printf("last:"); REPSZ(i, last) printf(" %d", last[i]); puts("");

	lst.clear();
	REPE(j, 3) {
		int s = j == 0 ? 0 : last[j - 1] + 1;
		int t = j == 3 ? ncard - 1 : last[j] - 1;
		if (s <= t) build(s, t);
	}
	lst.PB(last);
	int lastid = SZ(lst) - 1;
	//printf("lst:"); REPSZ(i, lst) printf(" (%d,%d,%d)", lst[i][0], lst[i][1], lst[i][2]); puts("");
	assert(SZ(lst) == ncard / 3);

	ch = vector<vector<int>>(SZ(lst));
	par = vector<int>(SZ(lst), -1);
	REPSZ(i, lst) FORSZ(j, i + 1, lst) {
		assert(!conflicting(lst[i], lst[j]));
		assert(!inside(lst[j], lst[i]));
		if (inside(lst[i], lst[j])) {
			bool direct = true;
			FOR(k, i + 1, j) if (inside(lst[i], lst[k]) && inside(lst[k], lst[j])) { direct = false; break; }
			if (direct) {
				//printf("(%d,%d,%d) is directly inside (%d,%d,%d)\n", lst[i][0], lst[i][1], lst[i][2], lst[j][0], lst[j][1], lst[j][2]);
				assert(col[lst[i][0]] != col[lst[j][0]]);
				par[i] = j;
				ch[j].PB(i);
			}
		}
	}
	rem = vector<int>(SZ(lst), 0); REPSZ(i, lst) rem[i] = SZ(ch[i]);
	done = vector<bool>(SZ(lst), false);
	ans.clear();
	REPSZ(i, lst) {
		int c = i % 2;
		int use = -1;
		REPSZ(j, lst) if (!done[j] && col[lst[j][0]] == c && rem[j] == 0) { use = j; break; }
		assert(use != -1);
		done[use] = true; if (par[use] != -1) --rem[par[use]]; ans.PB(lst[use]);
	}






}

void run() {
	scanf("%d", &n); ncard = 6 * n;
	REP(i, ncard) col[i] = 1;
	REP(i, 3 * n) { int x; scanf("%d", &x); --x; col[x] = 0; }
	solve();
	REPSZ(i, ans) { REPSZ(j, ans[i]) { if (j != 0) printf(" "); printf("%d", ans[i][j] + 1); } puts(""); }

}

int main() {
	run();
	return 0;
}