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

namespace Matching{
	//matching [1...n] <-> [1...m]
	const int MX = 40040, MY = 40040;
	vector <int> E[MX], RE[MY];
	int xy[MX], yx[MY];
	int n, m;
	
	void addE(int x, int y) { E[x].pb(y); RE[y].pb(x); }
	void setnm(int sn, int sm) { n = sn; m = sm; }
	
	int tdis[MX], que[MX], *dis = tdis + 1;
	int bfs() {
		int *fr = que, *re = que;
		for(int i=1;i<=n;i++) {
			if(xy[i] == -1) *fr++ = i, dis[i] = 0;
			else dis[i] = -1;
		}
		dis[-1] = -1;
		while(fr != re) {
			int t = *re++;
			if(t == -1) return 1;
			for(int e : E[t]) {
				if(dis[yx[e]] == -1) dis[yx[e]] = dis[t] + 1, *fr++ = yx[e];
			}
		}
		return 0;
	}
	
	int dfs(int x) {
		for(int e : E[x]) {
			if(yx[e] == -1 || (dis[yx[e]] == dis[x] + 1 && dfs(yx[e]))) {
				xy[x] = e;
				yx[e] = x;
				return 1;
			}
		}
		dis[x] = -1;
		return 0;
	}
	
	void Do(vector <int>& aa, vector <int>& bb) {
		memset(xy, -1, sizeof xy);
		memset(yx, -1, sizeof yx);
		
		int ans = 0;
		while(bfs()) {
			for(int i=1;i<=n;i++) if(xy[i] == -1 && dfs(i)) ++ans;
		}
		int chka[1010] = {}, chkb[1010] = {};
		vector <int> v;
		for(int i=1;i<=n;i++) if(xy[i] == -1) v.pb(i), chka[i] = 1;
		rep(i, szz(v)) {
			int t = v[i];
			for(int e : E[t]) if(yx[e] != -1 && chka[yx[e]] == 0) {
				chka[yx[e]] = 1;
				v.pb(yx[e]);
			}
		}
		aa = v;
		v.clear();
		for(int i=1;i<=m;i++) if(yx[i] == -1) v.pb(i), chkb[i] = 1;
		rep(i, szz(v)) {
			int t = v[i];
			for(int e : RE[t]) if(xy[e] != -1 && chkb[xy[e]] == 0) {
				chkb[xy[e]] = 1;
				v.pb(xy[e]);
			}
		}
		bb = v;
		v.clear();
		for(int i=1;i<=n;i++) if(xy[i] != -1 && chka[i] == 0 && chkb[xy[i]] == 0) {
			aa.pb(i);
		}
	}
}


int n;
pii p[1010];
int mark[1010][1010];
int num_x[1010][1010];
int num_y[1010][1010];
int cnt_x, cnt_y;
int chx[100010], chy[100010];

vector <pair<pii, pii> > ans[2];

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d%d", &p[i].Fi, &p[i].Se);
	vector <int> vx, vy;
	for(int i=1;i<=n;i++) vx.pb(p[i].Fi), vy.pb(p[i].Se);
	sort(all(vx)); vx.resize(unique(all(vx)) - vx.begin());
	sort(all(vy)); vy.resize(unique(all(vy)) - vy.begin());
	
	for(int i=1;i<=n;i++) p[i].Fi = (int)(lower_bound(all(vx), p[i].Fi) - vx.begin());
	for(int i=1;i<=n;i++) p[i].Se = (int)(lower_bound(all(vy), p[i].Se) - vy.begin());
	
	for(int i=1;i<=n;i++) {
		mark[p[i].Fi][p[i].Se] = 1;
	}
	rep(i, szz(vx)) {
		int p = -1;
		rep(j, szz(vy)) {
			if(mark[i][j]) {
				if(p != -1) {
					++cnt_x;
					for(int a=p+1;a<j;a++) num_x[i][a] = cnt_x;
				}
				p = j;
			}
		}
	}
	rep(j, szz(vy)) {
		int p = -1;
		rep(i, szz(vx)) {
			if(mark[i][j]) {
				if(p != -1) {
					++cnt_y;
					for(int a=p+1;a<i;a++) num_y[a][j] = cnt_y;
				}
				p = i;
			}
		}
	}
	
	Matching::setnm(cnt_x, cnt_y);
	
	rep(i, szz(vx)) rep(j, szz(vy)){
		if(num_x[i][j] && num_y[i][j]) {
			int a = num_x[i][j];
			int b = num_y[i][j];
			Matching::addE(a, b);
		}
	}
	vector <int> ax, ay;
	Matching::Do(ax, ay);
	for(int e : ax) chx[e] = 1;
	for(int e : ay) chy[e] = 1;
	rep(i, szz(vx)) {
		int p = -1;
		vector <int> temp(szz(vy));
		rep(j, szz(vy)) {
			int ok = mark[i][j];
			if(mark[i][j] == 0 && chx[num_x[i][j]]) ok = 1;
			temp[j] = ok;
		}
		rep(j, szz(vy)) {
			if(p == -1 && temp[j]) p = j;
			if(temp[j] && (j == szz(vy) - 1 || temp[j+1] == 0)) {
				ans[0].pb(make_pair(pii(i, p), pii(i, j)));
				p = -1;
			}
		}
	}
	
	rep(i, szz(vy)) {
		int p = -1;
		vector <int> temp(szz(vx));
		rep(j, szz(vx)) {
			int ok = mark[j][i];
			if(mark[j][i] == 0 && chy[num_y[j][i]]) ok = 1;
			temp[j] = ok;
		}
		rep(j, szz(vx)) {
			if(p == -1 && temp[j]) p = j;
			if(temp[j] &&  (j == szz(vx) - 1 || temp[j+1] == 0)) {
				ans[1].pb(make_pair(pii(p, i), pii(j, i)));
				p = -1;
			}
		}
	}
	rep(u, 2) {
		printf("%d\n", szz(ans[u^1]));
		for(auto e : ans[u^1]) {
			pii t = e.Fi;
			printf("%d %d ", vx[t.Fi], vy[t.Se]);
			t = e.Se;
			printf("%d %d\n", vx[t.Fi], vy[t.Se]);
		}
	}
	
	return 0;
}