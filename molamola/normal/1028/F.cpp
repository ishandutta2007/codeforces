#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;

int N;
int inp[200020][3];
vector <pii> vx;
vector <ll> lx;
vector <pii> pts[200020];
int ans[200020];

int gc(int x, int y) { return y == 0 ? x : gc(y, x%y); }

void Ins(int a, pii p) {
	int g = gc(p.Fi, p.Se);
	pii temp = pii(p.Fi / g, p.Se / g);
	int idx = (int)(lower_bound(all(vx), temp) - vx.begin());
	if(vx[idx] == temp) ans[idx]++;
	for(pii& e : pts[a]) {
		int sx = (p.Fi + e.Fi);
		int sy = (p.Se + e.Se);
		int g = gc(sx, sy);
		sx /= g, sy /= g;
		int idx = (int)(lower_bound(all(vx), pii(sx, sy)) - vx.begin());
		if(vx[idx] == pii(sx, sy)) ans[idx] += 2;
	}
	pts[a].pb(p);
}

void Del(int a, pii p) {
	int g = gc(p.Fi, p.Se);
	pii temp = pii(p.Fi / g, p.Se / g);
	int idx = (int)(lower_bound(all(vx), temp) - vx.begin());
	if(vx[idx] == temp) ans[idx]--;
	int f = -1;
	rep(j, szz(pts[a])) {
		pii &e = pts[a][j];
		if(e != p) {
			int sx = (p.Fi + e.Fi);
			int sy = (p.Se + e.Se);
			int g = gc(sx, sy);
			sx /= g, sy /= g;
			int idx = (int)(lower_bound(all(vx), pii(sx, sy)) - vx.begin());
			if(vx[idx] == pii(sx, sy)) ans[idx] -= 2;
		}
		else f = j;
	}
	pts[a].erase(pts[a].begin() + f);
}

int main() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++) rep(j, 3) scanf("%d", inp[i] + j);
	
	for(int i=1;i<=N;i++) if(inp[i][0] == 3) {
		int x = inp[i][1], y = inp[i][2];
		int g = gc(x, y);
		x /= g, y /= g;
		vx.push_back(pii(x, y));
		inp[i][1] = x; inp[i][2] = y;
	}
	sort(all(vx)); vx.resize(unique(all(vx)) - vx.begin());
	for(int i=1;i<=N;i++) if(inp[i][0] == 1) {
		ll L = (ll) inp[i][1] * inp[i][1] + (ll) inp[i][2] * inp[i][2];
		lx.pb(L);
	}
	sort(all(lx)); lx.resize(unique(all(lx)) - lx.begin());
	int cnt = 0;
	for(int i=1;i<=N;i++) {
		int cmd = inp[i][0];
		if(cmd == 1) {
			++cnt;
			ll L = (ll) inp[i][1] * inp[i][1] + (ll) inp[i][2] * inp[i][2];
			int a = (int) (lower_bound(all(lx), L) - lx.begin());
			Ins(a, pii(inp[i][1], inp[i][2]));
		}
		else if(cmd == 2) {
			--cnt;
			ll L = (ll) inp[i][1] * inp[i][1] + (ll) inp[i][2] * inp[i][2];
			int a = (int) (lower_bound(all(lx), L) - lx.begin());
			Del(a, pii(inp[i][1], inp[i][2]));
		}
		else {
			int idx = (int)(lower_bound(all(vx), pii(inp[i][1], inp[i][2])) - vx.begin());
			printf("%d\n", cnt - ans[idx]);
		}
	}
	return 0;
}