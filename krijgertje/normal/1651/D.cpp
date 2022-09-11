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
struct P { int x, y, id; P() {} P(int x, int y) :x(x), y(y), id(-1) {} };

int n;
P p[MAXN];
P ans[MAXN];

int ansdist[MAXN];
int up[MAXN], lt[MAXN];
int cntup[MAXN];

void solve() {
	REP(i, n) ansdist[i] = INT_MAX;
	REP(ydir, 2) {
		REP(xdir, 2) {
			//printf("xdir=%d ydir=%d\n", xdir, ydir);
			sort(p, p + n, [&](const P &a, const P &b) { if (a.x != b.x) return a.x < b.x; return a.y < b.y; });
			int j = 0;
			REP(i, n) {
				while (p[j].x < p[i].x - 1 || p[j].x == p[i].x - 1 && p[j].y < p[i].y) ++j;
				up[i] = p[j].x == p[i].x - 1 && p[j].y == p[i].y ? j : -1;
				lt[i] = i != 0 && p[i - 1].x == p[i].x && p[i - 1].y == p[i].y - 1 ? i - 1 : -1;
				cntup[i] = up[i] == -1 ? 0 : 1 + cntup[up[i]];
			}
			P best;
			REP(i, n) {
				if (lt[i] == -1) best = P(p[i].x, p[i].y - 1);
				P cur = P(p[i].x - cntup[i] - 1, p[i].y);
				if (cur.x + cur.y > best.x + best.y) best = cur;
				int curdist = p[i].x - best.x + p[i].y - best.y;
				if (curdist < ansdist[p[i].id]) {
					//printf("improved %d (%d,%d): (%d,%d)=%d\n", p[i].id, p[i].x, p[i].y, best.x, best.y, curdist);
					ans[p[i].id] = best, ansdist[p[i].id] = curdist;
				}
			}
			REP(i, n) p[i].y = -p[i].y,ans[i].y=-ans[i].y;
		}
		REP(i, n) p[i].x = -p[i].x, ans[i].x = -ans[i].x;
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &p[i].x, &p[i].y), p[i].id = i;
	solve();
	REP(i, n) printf("%d %d\n", ans[i].x, ans[i].y);
}

int main() {
	run();
	return 0;
}