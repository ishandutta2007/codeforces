#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>

#include <algorithm>
#include <numeric>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define foreach(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define len(a) ((int) (a).size())

#ifdef CUTEBMAING
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef long double ld;
typedef unsigned long long lint;

const int inf = (1 << 30) - 1;
const int64 linf = (1ll << 62) - 1;
const int N = 5e5 + 100;
const int K = 50;

struct cooldsu {
	int parent[N], rank[N], parity[N];
	int flag = 0;
	vector<pair<int*, int>> changes;

	void init(int n) {
		for (int i = 0; i < n; i++) {
			parent[i] = i, rank[i] = 0, parity[i] = 0;
		}
	}

	int size() { return changes.size(); }

	void set(int *a, int b) { changes.push_back(mp(a, *a)), *a = b; }

	void revert(int len) {
		while (len(changes) > len) {
			*changes.back().fs = changes.back().sc, changes.pop_back();
		}
	}

	pair<int, int> findSetAndParity(int v) {
		int curParity = 0;
		while (parent[v] != v) {
			curParity ^= parity[v], v = parent[v];
		}
		return mp(v, curParity);
	}

	void unite(int a, int b) {
		pair<int, int> pa = findSetAndParity(a), pb = findSetAndParity(b);
		if (pa.fs == pb.fs) {
			if (!flag && pa.sc == pb.sc) {
				set(&flag, 1);
			}
			return ;
		}
		if (rank[pa.fs] == rank[pb.fs]) {
			set(rank + pa.fs, rank[pa.fs] + 1);
		}
		if (rank[pa.fs] > rank[pb.fs]) {
			swap(pa, pb);
		}
		set(parent + pa.fs, pb.fs), set(parity + pa.fs, pa.sc ^ pb.sc ^ 1);
	}
};

vector<pair<int, int>> rmq[N * 4 + 100];

cooldsu dsu[K];

int n, m, k, q;
int a[N], b[N];
int e[N], c[N];
int nextRequest[N], last[N];
int curColor[N];

void update(int i, int ll, int rr, int l, int r, const pair<int, int> &add) {
	if (ll > r || rr < l) {
		return ;
	}
	if (l <= ll && rr <= r) {
		return void (rmq[i].push_back(add));
	}
	update(i * 2, ll, (ll + rr) / 2, l, r, add);
	update(i * 2 + 1, (ll + rr) / 2 + 1, rr, l, r, add);
}

void solve(int i, int l, int r) {
	vector<int> ln(len(rmq[i]));
	for (int j = 0; j < len(ln); j++) {
		ln[j] = len(dsu[rmq[i][j].sc]);
	}
	for (auto upd : rmq[i]) {
		dsu[upd.sc].unite(a[upd.fs], b[upd.fs]);
	}
	if (l == r) {
		int edge = e[l], color = c[l];
		int u = a[edge], v = b[edge];
		pair<int, int> a = dsu[color].findSetAndParity(u), b = dsu[color].findSetAndParity(v);
		if (a != b) {
			puts("YES");
			update(1, 0, q - 1, l + 1, nextRequest[l] - 1, mp(edge, color));
			curColor[edge] = color;
		} else {
			puts("NO");
			if (curColor[edge] != -1) {
				update(1, 0, q - 1, l + 1, nextRequest[l] - 1, mp(edge, curColor[edge]));
			}
		}
	} else {
		solve(i * 2, l, (l + r) / 2);
		solve(i * 2 + 1, (l + r) / 2 + 1, r);
	}
	for (int j = 0; j < len(ln); j++) {
		dsu[rmq[i][j].sc].revert(ln[j]);
	}
}

int main() {
	cin >> n >> m >> k >> q;
	for (int i = 0; i < k; i++) {
		dsu[i].init(n);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a[i], &b[i]), a[i]--, b[i]--;
		curColor[i] = -1;
	}
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &e[i], &c[i]), e[i]--, c[i]--;
	}
	fill_n(last, m, inf);
	for (int i = q - 1; i >= 0; i--) {
		nextRequest[i] = last[e[i]];
		last[e[i]] = i;
	}
	solve(1, 0, q - 1);
    return 0;
}