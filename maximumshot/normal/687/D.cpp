#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <math.h>
#include <unordered_map>
#include <array>
#include <complex>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

struct DSU {
	int n;
	vec< int > par, color, h;
	
	DSU() {
		n = 0;
	} 

	DSU(int nn) {
		n = nn;
		par.resize(n + 1);
		color.resize(n + 1);
		h.resize(n + 1);
		for(int i = 1;i <= n;i++) {
			par[i] = i;
			color[i] = h[i] = 0;
		}
	}

	int find(int x) {
		if(x == par[x]) return x;
		else {
			int t = find(par[x]);
			color[x] ^= color[par[x]];
			return par[x] = t;
		}
	}

	int parity(int x) {
		find(x);
		return color[x];
	}

	int add_edge(int x, int y) {
		// 0 -    ,   
		// 1 -   
		// 2 -   ,   

		int px = find(x);
		int py = find(y);

		if(px == py) {
			if(parity(x) == parity(y)) return 2;
			else return 0;
		}

		if(h[px] < h[py]) {
			swap(px, py);
			swap(x, y);
		}

		// par[py] = px;

		color[py] ^= (parity(x) ^ parity(y) ^ 1);
		if(h[py] == h[px]) h[px]++;
		par[py] = px;
		
		return 1;
	}
};

int n, m, q;

struct edge {
	int u, v, id, w;
	static int EdgeCount;

	edge() {
		u = v = id = w = 0;
	}

	void read() {
		scanf("%d %d %d", &u, &v, &w);
		id = EdgeCount++;
	}

	void print() {
		printf("#%d {%d %d} [%d]\n", id, u, v, w);
	}

	bool operator < (const edge & b) const {
		return mt(w, u, v, id) < mt(b.w, b.u, b.v, b.id);
	}

	bool operator > (const edge & b) const {
		return mt(w, u, v, id) > mt(b.w, b.u, b.v, b.id);
	}

	bool operator == (const edge & b) const {
		return mt(w, u, v, id) == mt(b.w, b.u, b.v, b.id);
	}
};

int edge :: EdgeCount = 1;

int RESULT;

void upd(vec< edge > & l) {
	vec< edge > res;

	DSU dsu(n);

	RESULT = -1;

	for(auto _e : l) {
		int type = dsu.add_edge(_e.u, _e.v);
		if(type) res.push_back(_e);
		if(type == 2) {
			RESULT = _e.w;
			break;
		}
	}

	l = res;
}

vec< edge > merge(const vec< edge> & l, const vec< edge > & r) {
	int left_size = (int)l.size();
	int right_size = (int)r.size();
	int left_cur = 0, right_cur = 0;

	vec< edge > res;

	while(left_cur < left_size && right_cur < right_size) {
		if(l[left_cur] > r[right_cur]) res.push_back(l[left_cur++]);
		else res.push_back(r[right_cur++]);
	}

	while(left_cur < left_size) res.push_back(l[left_cur++]);
	while(right_cur < right_size) res.push_back(r[right_cur++]);

	upd(res);

	return res;
}

vec< vec< edge > > st;
vec< edge > e;

void build(int v, int tl, int tr) {
	if(tl == tr) {
		st[v].push_back(e[tl]);
	}else {
		int tm = (tl + tr) / 2;
		build(v << 1, tl, tm);
		build(v << 1 | 1, tm + 1, tr);
		st[v] = merge(st[v << 1], st[v << 1 | 1]);
	}
}

vec< edge > get(int v, int tl, int tr, int l, int r) {
	if(l <= tl && tr <= r) return st[v];
	else {
		int tm = (tl + tr) / 2;
		if(l <= tm) {
			if(r > tm) return merge(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
			else return get(v << 1, tl, tm, l, r);
		}else return get(v << 1 | 1, tm + 1, tr, l, r);
	}
}

bool solve() {

	scanf("%d %d %d", &n, &m, &q);

	e.resize(m + 1);

	for(int i = 1;i <= m;i++) e[i].read();
	
	st.resize(4 * m);

	build(1, 1, m);

	for(int l, r;q > 0;q--) {
		scanf("%d %d", &l, &r);
		auto tmp = get(1, 1, m, l, r);
		upd(tmp);
		//cerr << "result = ";
		printf("%d\n", RESULT);
	}

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}