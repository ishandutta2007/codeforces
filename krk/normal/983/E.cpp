#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxs = 1048576;
const int Maxm = 20;

int n;
vector <int> neigh[Maxn];
int L[Maxn], P[Maxn][Maxm];
int my[Maxn];
int cur, lef[Maxn], rig[Maxn];
int m;
vector <int> st[Maxs];
vector <ii> rl;
map <ii, map <int, int> > M;
int R[Maxn][Maxm];
int q;

void Add(int v, int l, int r, int x, int val)
{
	st[v].push_back(val);
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) Add(2 * v, l, m, x, val);
		else Add(2 * v + 1, m + 1, r, x, val);
	}
}

bool Get(int v, int l, int r, int a, int b, int val1, int val2)
{
	if (l == a && r == b) {
		int ind = lower_bound(st[v].begin(), st[v].end(), val1) - st[v].begin();
		return ind < st[v].size() && st[v][ind] <= val2;
	} else {
		int m = l + r >> 1;
		bool res = false;
		if (a <= m) res |= Get(2 * v, l, m, a, min(m, b), val1, val2);
		if (m + 1 <= b) res |= Get(2 * v + 1, m + 1, r, max(m + 1, a), b, val1, val2);
		return res;
	}
}

int getLCA(int a, int b)
{
	if (L[a] < L[b]) swap(a, b);
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b])
			a = P[a][i];
	if (a == b) return a;
	for (int i = Maxm - 1; i >= 0; i--)
		if (P[a][i] != P[b][i])
			a = P[a][i], b = P[b][i];
	return P[a][0];
}

void Insert(map <int, int> &M, int x, int val)
{
	map <int, int>::iterator it = M.lower_bound(x);
	if (it != M.end() && val <= it->second) return;
	it = M.upper_bound(x);
	while (it != M.begin()) {
		it--;
		if (it->second <= val) M.erase(it++);
		else break;
	}
	M.insert(make_pair(x, val));
}

bool Get(map <int, int> &M, int x, int val)
{
	map <int, int>::iterator it = M.lower_bound(x);
	return it != M.end() && val <= it->second;
}

void Enumerate(int v)
{
	lef[v] = ++cur;
	for (int i = 0; i < neigh[v].size(); i++)
		Enumerate(neigh[v][i]);
	rig[v] = cur;
}

void Traverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		Traverse(u);
		my[v] = min(my[v], my[u]);
	}
}

int Solve(int a, int b)
{
	if (L[a] < L[b]) swap(a, b);
	int lca = getLCA(a, b);
	if (b == lca) {
		int cnt = 0;
		while (L[a] > L[b]) {
			if (my[a] == a) return -1;
			cnt++; a = my[a];
		}
		return cnt;
	}
	int res = 0;
	for (int i = Maxm - 1; i >= 0; i--) {
		if (L[R[a][i]] > L[lca]) {
			res += 1 << i;
			a = R[a][i];
		}
		if (L[R[b][i]] > L[lca]) {
			res += 1 << i;
			b = R[b][i];
		}
	}
	if (my[a] == a || my[b] == b) return -1;
	if (lef[a] > lef[b]) swap(a, b);
	if (Get(1, 1, n, lef[a], rig[a], lef[b], rig[b])) res++;
	else res += 2;
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int p; scanf("%d", &p);
		neigh[p].push_back(i);
		L[i] = L[p] + 1; P[i][0] = p;
	}
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	for (int i = 1; i <= n; i++)
		my[i] = i;
	Enumerate(1);
	scanf("%d", &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		int lca = getLCA(a, b);
		my[a] = min(my[a], lca);
		my[b] = min(my[b], lca);
		if (lef[a] > lef[b]) swap(a, b);
		rl.push_back(ii(lef[b], lef[a]));
	}
	sort(rl.begin(), rl.end());
	for (int i = 0; i < rl.size(); i++) {
		int l = rl[i].second, r = rl[i].first;
		Add(1, 1, n, l, r);
	}
	Traverse(1);
	for (int i = 1; i <= n; i++)
		R[i][0] = my[i];
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			R[i][j] = R[R[i][j - 1]][j - 1];
	scanf("%d", &q);
	while (q--) {
		int a, b; scanf("%d %d", &a, &b);
		printf("%d\n", Solve(a, b));
	}
	return 0;
}