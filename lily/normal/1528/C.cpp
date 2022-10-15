#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;

int n;
vector <int> EA[N], EB[N];
int id[N], idend[N], dfn;
const int L = 19;
int fst[L][N];

int fb[N];
void dfsb(int x) {
	id[x] = ++ dfn;
	fst[0][x] = fb[x];
	for (int i = 1; i < L; i++) fst[i][x] = fst[i - 1][fst[i - 1][x]];
	for (auto v : EB[x]) dfsb(v);
	idend[x] = dfn;
}

void upd(int t[], int x, int y) {
	for ( ; x <= n; x += x & -x) {
		t[x] += y;
	}
}

int qry(int t[], int x) {
	int ret = 0;
	for ( ; x ; x -= x & -x) {
		ret += t[x];
	}
	return ret;
}

int qry(int t[], int l, int r) {
	return qry(t, r) - qry(t, l - 1);
}

int t[N], tsub[N], tl[N];

void unchoose(int x) {
	//cerr << "unchoose " << x << endl;
	upd(tsub, id[x], -1);
	upd(tl, id[x], -1);
	upd(tl, idend[x] + 1, 1);
}

void choose(int x) {
	//cerr << "choose " << x << endl;
	upd(tsub, id[x], 1);
	upd(tl, id[x], 1);
	upd(tl, idend[x] + 1, -1);
	if (qry(tl, id[x]) == 2) {
		int y = x;
		for (int i = L - 1; ~i; i--) {
			int fa = fst[i][y];
			if (qry(tl, id[fa]) > 0) y = fst[i][y];
		}
		// y : unchoose
		unchoose(y);
	}
}

void mark(int x) {
	upd(t, id[x], 1);
	upd(t, idend[x] + 1, -1);
	int subtree = qry(tsub, id[x], idend[x]);
	if (!subtree) {
		choose(x);
	}
}


void unmark(int x) {
	upd(t, id[x], -1);
	upd(t, idend[x] + 1, 1);
	if (qry(tsub, id[x], id[x]) == 1) {
		unchoose(x);
		int cur = qry(t, id[x]);
		int y = x;
		for (int i = L - 1; ~i; i--) {
			int fa = fst[i][y];
			if (qry(t, id[fa]) == cur) y = fst[i][y];
		}
		if (y) {
			int subtree = qry(tsub, id[y], idend[y]);
			if (!subtree) {
				choose(y);
			}
		}
	}
}

int ans = 0;

void dfsa(int x) {
	//cerr << "dfs a " << x << endl;
	mark(x);
	ans = max(ans, qry(tsub, n));
	for (auto v : EA[x]) {
		dfsa(v);
	}
	unmark(x);
}

int fa[N];
void work() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) EA[i].clear(), EB[i].clear();
	for (int i = 2; i <= n; i++) scanf("%d", fa + i), EA[fa[i]].push_back(i);
	for (int i = 2; i <= n; i++) scanf("%d", fb + i), EB[fb[i]].push_back(i);

	dfn = 0;
	ans = 0;
	for (int i = 1; i <= n; i++) tl[i] = 0;
	for (int i = 1; i <= n; i++) tsub[i] = 0;
	for (int i = 1; i <= n; i++) t[i] = 0;

	dfsb(1);
	dfsa(1);

	printf("%d\n", ans);

}


int main() {
	int T;
	scanf("%d", &T);
	while (T--) work();
}