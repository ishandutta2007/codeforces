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

const int MAXVAL = 100000;

int nnum, nval;
int cnt[MAXVAL];
vector<vector<int>> ans;

void solve() {
	int mxcnt = cnt[0]; FOR(i, 1, nval) mxcnt = max(mxcnt, cnt[i]);
	int sz = 1;
	auto can = [&](int sz) {
		int limnum = sz * sz - (sz / 2) * (sz / 2);
		if (nnum > limnum) return false;
		int limcnt = sz * ((sz + 1) / 2);
		if (mxcnt > limcnt) return false;
		return true;
	};
	while (!can(sz)) ++sz;
	ans = vector<vector<int>>(sz, vector<int>(sz, 0));
	auto put = [&](int x, int y, int val) { assert(x >= 0 && x < sz && y >= 0 && y < sz); ans[x][y] = val; };
	int remrows = sz * ((sz + 1) / 2);
	int x = 0, y = 0;
	int xx = 0, yy = 0;
	vector<pair<int, int>> o;
	REP(i, nval) o.PB(MP(-cnt[i], i));
	sort(o.begin(), o.end());
	REP(i, nval) {
		int at = o[i].second;
		if (cnt[at] <= remrows) {
			REP(j, cnt[at]) {
				while (ans[x][y] != 0) {
					++y;
					if (y == sz) x += 2, y = 0;
				}
				put(x, y, at + 1);
				--remrows;
				++y;
				if (y == sz) x += 2, y = 0;
			}
		} else {
			REP(j, cnt[at]) {
				if (remrows > 0) {
					if (ans[xx][yy] != 0) {
						while (ans[x][y] != 0) {
							++y;
							if (y == sz) x += 2, y = 0;
						}
						put(x, y, ans[xx][yy]);
						--remrows;
						++y;
						if (y == sz) x += 2, y = 0;
					} else if (xx % 2 == 0) {
						--remrows;
					}
					put(xx, yy, at + 1);
					++xx;
					if (xx == sz) yy += 2, xx = 0;
				} else {
					while (ans[xx][yy] != 0) {
						++xx;
						if (xx == sz) yy += 2, xx = 0;
					}
					put(xx, yy, at + 1);
					++xx;
					if (xx == sz) yy += 2, xx = 0;
				}
			}
		}
	}
}

void run() {
	scanf("%d%d", &nnum, &nval);
	REP(i, nval) scanf("%d", &cnt[i]);
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { REPSZ(j, ans[i]) { if (j != 0) printf(" "); printf("%d", ans[i][j]); } puts(""); }
}

bool verify() {
	int sz = SZ(ans);
	REP(x, sz - 1) REP(y, sz - 1) if (ans[x][y] != 0 && ans[x + 1][y] != 0 && ans[x][y + 1] != 0 && ans[x + 1][y + 1] != 0) return false;
	REP(x, sz - 1) REP(y, sz - 1) if (ans[x][y] != 0 && ans[x][y] == ans[x + 1][y + 1] || ans[x + 1][y] != 0 && ans[x + 1][y] == ans[x][y + 1]) return false;
	REP(x, sz) REP(y, sz) if (ans[x][y]<0 || ans[x][y]>nval) return false;
	vector<int> chk(nval, 0);
	REP(x, sz) REP(y, sz) if (ans[x][y] != 0) ++chk[ans[x][y] - 1];
	REP(i, nval) if (chk[i] != cnt[i]) return false;
	return true;
}

void print() {
	printf("%d %d\n", nnum, nval);
	REP(i, nval) { if (i != 0) printf(" "); printf("%d", cnt[i]); } puts("");
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { REPSZ(j, ans[i]) { if (j != 0) printf(" "); printf("%d", ans[i][j]); } puts(""); }
	exit(0);
}

void stress() {
	int mxnum = 5, mxval = 20;
	REPE(a, 20) REPE(b, 20) REPE(c, 20) REPE(d, 20) REPE(e, 20) {
		nnum = a + b + c + d + e;
		if (nnum == 0) continue;
		nval = 5;
		//printf("%d %d\n", nnum, nval);
		//printf("%d %d %d %d %d\n", a, b, c, d, e);
		cnt[0] = a, cnt[1] = b, cnt[2] = c, cnt[3] = d, cnt[4] = e;
		solve();
		if (!verify()) print();
		printf(".");
	}
	REP(rep, 100000) {
		nnum = rnd() % mxnum + 1, nval = rnd() % mxval + 1;
		REP(i, nval) cnt[i] = 0;
		int a = rnd() % (nnum + 1);
		int b = rnd() % (nnum - a + 1);
		int c = rnd() % (nnum - a - b + 1);
		cnt[rnd() % nnum] += a;
		cnt[rnd() % nnum] += b;
		cnt[rnd() % nnum] += c;
		REP(i, nnum - a - b - c) ++cnt[rnd() % nnum];
		solve();
		if (!verify()) print();
		printf(".");
	}
}

int main() {
	//stress();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}