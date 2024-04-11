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

const int MAXDIM = 1000;
struct Op { int x, y, col; Op() {} Op(int x, int y, int col) :x(x), y(y), col(col) {} };

int h, w;
int g[MAXDIM][MAXDIM];
vector<Op> ans;

bool solve() {
	vector<vector<vector<int>>> prevent(h, vector<vector<int>>(w));
	vector<Op> opt;
	vector<int> blockcnt;

	REP(x, h - 1) REP(y, w - 1) {
		vector<int> have;
		REP(dx, 2) REP(dy, 2) {
			int nx = x + dx, ny = y + dy;
			have.PB(g[nx][ny]);
		}
		sort(have.begin(), have.end());
		have.erase(unique(have.begin(), have.end()), have.end());
		for (int col : have) {
			opt.PB(Op(x, y, col));
			int idx = SZ(opt) - 1;
			blockcnt.PB(0);
			REP(dx, 2) REP(dy, 2) {
				int nx = x + dx, ny = y + dy;
				if (g[nx][ny] != col) prevent[nx][ny].PB(idx), blockcnt[idx]++;
			}
		}
	}

	queue<int> q;
	REPSZ(i, opt) if (blockcnt[i] == 0) q.push(i);
	vector<vector<bool>> painted(h, vector<bool>(w, false));
	ans.clear();
	while (!q.empty()) {
		int idx = q.front(); q.pop();
		Op cur = opt[idx];
		int x = cur.x, y = cur.y, col = cur.col;
		bool any = false;
		REP(dx, 2) REP(dy, 2) {
			int nx = x + dx, ny = y + dy;
			if (painted[nx][ny]) continue;
			assert(g[nx][ny] == col);
			any = true;
		}
		if (!any) continue;
		ans.PB(cur);
		REP(dx, 2) REP(dy, 2) {
			int nx = x + dx, ny = y + dy;
			if (painted[nx][ny]) continue;
			painted[nx][ny] = true;
			for (int idx : prevent[nx][ny]) if (--blockcnt[idx] == 0) q.push(idx);
		}
	}
	REP(x, h) REP(y, w) if (!painted[x][y]) return false;
	reverse(ans.begin(), ans.end());
	return true;
}

void run() {
	scanf("%d%d", &h, &w);
	REP(x, h) REP(y, w) scanf("%d", &g[x][y]);
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", SZ(ans));
	for (auto o : ans) printf("%d %d %d\n", o.x + 1, o.y + 1, o.col);
}

int main() {
	run();
	return 0;
}