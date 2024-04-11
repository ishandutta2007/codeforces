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

const int MAXX = 200000;
const int MAXY = 200000;
const int MAXS = 4 * MAXY;

int X, Y;
ll l, r;
int ans[MAXX + 1][4];


int sval[MAXS];
void spull(int x) { sval[x] = max(sval[2 * x + 1], sval[2 * x + 2]); }
void sinit(int x, int l, int r) {
	if (l == r) {
		sval[x] = 0;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l, int r, int IDX, int VAL) {
	if (l == r) {
		sval[x] = max(sval[x], VAL);
	} else {
		int m = l + (r - l) / 2;
		if (IDX <= m) smod(2 * x + 1, l, m, IDX, VAL);
		if (m + 1 <= IDX) smod(2 * x + 2, m + 1, r, IDX, VAL);
		spull(x);
	}
}
int sget(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2, ret = 0;
		if (L <= m) ret = max(ret, sget(2 * x + 1, l, m, L, R));
		if (m + 1 <= R) ret = max(ret, sget(2 * x + 2, m + 1, r, L, R));
		return ret;
	}
}


struct Q { int x, a, g, lb, rb, lprod, rprod; Q() {} Q(int x, int a, int g, int lb, int rb, int lprod, int rprod) :x(x), a(a), g(g), lb(lb), rb(rb), lprod(lprod), rprod(rprod) {} };
vector<Q> q[MAXY + 1];

void solve() {

	FORE(x, 1, X) ans[x][0] = -1;
	FORE(g, 1, X) {
		for (int x = g, a = 1; x <= X; x += g, ++a) {
			int lb = a + 1, rb = X / g;
			ll lprod = (l + x - 1) / x, rprod = min(r / x, (ll)Y);
			if (lb > rb || lprod > rprod) continue;
			q[rb].PB(Q(x, a, g, lb, rb, lprod, rprod));
			/*FORE(b, lb, rb) {
				if (ans[x][0] != -1) break;
				int d = (lprod + b - 1) / b;
				if ((ll)b * d <= rprod) {
					ans[x][0] = x, ans[x][1] = b * d, ans[x][2] = b * g, ans[x][3] = d * a;
				}
			}*/
		}
	}
	sinit(0, 1, Y);
	FORE(bcur, 2, X) {
		for (int y = bcur; y <= Y; y += bcur) {
			//printf("setting %d to %d\n", y, bcur);
			smod(0, 1, Y, y, bcur);
		}
		REPSZ(i, q[bcur]) {
			Q cur = q[bcur][i];
			if (ans[cur.x][0] != -1) continue;
			int b = sget(0, 1, Y, cur.lprod, cur.rprod);
			//printf("x=%d: querying %d..%d -> %d [%d..%d]\n", cur.x, cur.lprod, cur.rprod, b, cur.lb, cur.rb);
			if (b >= cur.lb) {
				int x = cur.x, a = cur.a, d = (cur.lprod + b - 1) / b, g = cur.g;
				assert((ll)b * d <= cur.rprod && b <= cur.rb);
				ans[x][0] = x, ans[x][1] = b * d, ans[x][2] = b * g, ans[x][3] = d * a;
			}
		}
	}
}

void run() {
	scanf("%d%d", &X, &Y);
	scanf("%lld%lld", &l, &r);
	solve();
	FORE(x, 1, X) if (ans[x][0] == -1) printf("-1\n"); else printf("%d %d %d %d\n", ans[x][0], ans[x][1], ans[x][2], ans[x][3]);
}

int main() {
	run();
	return 0;
}