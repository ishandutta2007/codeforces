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

const int MAXDIM = 500;

int h, w;
char g[MAXDIM][MAXDIM + 1];
int ans[MAXDIM][MAXDIM];

int comp[MAXDIM][MAXDIM];

bool solve() {
	REP(x, h) REP(y, w) if (g[x][y] == 'X') {
		int cnt = 0;
		FORE(dx, -1, +1) FORE(dy, -1, +1) if (dx * dx + dy * dy == 1) {
			int nx = x + dx, ny = ny = y + dy;
			if (nx < 0 || nx >= h || ny < 0 || ny >= w || g[nx][ny] == '.') continue;
			++cnt;
		}
		if (cnt % 2 != 0) return false;
	}
	int ncomp = 0;
	REP(x, h) REP(y, w) comp[x][y] = -1;
	REP(sx, h) REP(sy, w) if (comp[sx][sy] == -1 && g[sx][sy] == '.') {
		comp[sx][sy] = ncomp++;
		queue<pair<int, int>> q;
		q.push(MP(sx, sy));
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second; q.pop();
			FORE(dx, -1, +1) FORE(dy, -1, +1) {
				int nx = x + dx, ny = y + dy;
				if (nx < 0 || nx >= h || ny < 0 || ny >= w || g[nx][ny] == 'X') continue;
				if (comp[nx][ny] != -1) { assert(comp[nx][ny] == comp[sx][sy]); continue; }
				comp[nx][ny] = comp[sx][sy]; q.push(MP(nx, ny));
			}
		}
	}

	vector<vector<int>> compadj(ncomp);
	REP(x, h) REP(y, w) if (g[x][y] == 'X') {
		vector<int> cur;
		FORE(dx, -1, +1) FORE(dy, -1, +1) if (dx * dx + dy * dy == 1) {
			int nx = x + dx, ny = ny = y + dy;
			if (nx < 0 || nx >= h || ny < 0 || ny >= w || g[nx][ny] == 'X') continue;
			cur.PB(comp[nx][ny]);
		}
		sort(cur.begin(), cur.end());
		cur.erase(unique(cur.begin(), cur.end()), cur.end());
		REPSZ(i, cur) FORSZ(j, i + 1, cur) { int a = cur[i], b = cur[j]; compadj[a].PB(b); compadj[b].PB(a); }
	}
	REP(i, ncomp) { sort(compadj[i].begin(), compadj[i].end()); compadj[i].erase(unique(compadj[i].begin(), compadj[i].end()), compadj[i].end()); }
	vector<int> compcol(ncomp, -1);
	REP(i, ncomp) if (compcol[i] == -1) {
		compcol[i] = 0;
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			for (int to : compadj[at]) {
				if (compcol[to] != -1) { assert(compcol[to] != compcol[at]); continue; }
				compcol[to] = compcol[at] ^ 1; q.push(to);
			}
		}
	}
	REP(x, h) REP(y, w) if (g[x][y] == '.') {
		int cur = compcol[comp[x][y]] ^ (x % 2 == 0 ? 1 : 0);
		ans[x][y] = cur == 0 ? 1 : 4;
	}
	REP(x, h) REP(y, w) if (g[x][y] == 'X') {
		ans[x][y] = 0;
		FORE(dx, -1, +1) FORE(dy, -1, +1) if (dx * dx + dy * dy == 1) {
			int nx = x + dx, ny = ny = y + dy;
			if (nx < 0 || nx >= h || ny < 0 || ny >= w || g[nx][ny] == 'X') continue;
			ans[x][y] += ans[nx][ny];
		}
	}
	return true;
}

void run() {
	scanf("%d%d", &h, &w);
	REP(x, h) scanf("%s", g[x]);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(x, h) { REP(y, w) { if (y != 0) printf(" "); printf("%d", ans[x][y]); } puts(""); }
}

int main() {
	run();
	return 0;
}