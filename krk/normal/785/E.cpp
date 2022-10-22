#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxm = 1048576;

int n, q;
int val[Maxn], ind[Maxn];
int L[Maxn], R[Maxn];
vector <int> inind[Maxn];
vector <int> st[Maxm], BITL[Maxm], BITR[Maxm];
int qa[Maxn], qb[Maxn];
ll res;

void insertLeft(vector <int> &BIT, int ind, int val)
{
	for (int i = ind; i < BIT.size(); i += i & -i)
		BIT[i] += val;
}

void insertRight(vector <int> &BIT, int ind, int val)
{
	for (int i = ind; i > 0; i -= i & -i)
		BIT[i] += val;
}

int getLeft(vector <int> &BIT, int ind)
{
	int res = 0;
	for (int i = ind; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int getRight(vector <int> &BIT, int ind)
{
	int res = 0;
	for (int i = ind; i < BIT.size(); i += i & -i)
		res += BIT[i];
	return res;
}

void Create(int v, int l, int r)
{
	if (l == r) {
		sort(inind[l].begin(), inind[l].end()); inind[l].erase(unique(inind[l].begin(), inind[l].end()), inind[l].end());
		st[v] = inind[l];
	} else {
		int m = l + r >> 1;
		int lc = 2 * v, rc = 2 * v + 1;
		Create(lc, l, m); Create(rc, m + 1, r);
		int i = 0, j = 0;
		while (i < st[lc].size() || j < st[rc].size())
			if (i < st[lc].size() && (j == st[rc].size() || st[lc][i] < st[rc][j])) st[v].push_back(st[lc][i++]);
			else if (j < st[rc].size() && (i == st[lc].size() || st[rc][j] < st[lc][i])) st[v].push_back(st[rc][j++]);
			else { st[v].push_back(st[lc][i]); i++; j++; }
	}
	BITL[v].resize(st[v].size() + 1, 0); BITR[v].resize(st[v].size() + 1, 0);
}

int Get(int v, int l, int r, int a, int b, int val, bool les)
{
	if (a > b) return 0;
	if (l == a && r == b) {
		int ind = lower_bound(st[v].begin(), st[v].end(), val) - st[v].begin() + 1;
		return les? getLeft(BITL[v], ind - 1): getRight(BITR[v], ind);
	} else {
		int res = 0;
		int m = l + r >> 1;
		if (a <= m) res += Get(2 * v, l, m, a, min(m, b), val, les);
		if (m + 1 <= b) res += Get(2 * v + 1, m + 1, r, max(m + 1, a), b, val, les);
		return res;
	}
}

void Update(int v, int l, int r, int x, int val, int add)
{
	int ind = lower_bound(st[v].begin(), st[v].end(), val) - st[v].begin() + 1;
	insertLeft(BITL[v], ind, add);
	insertRight(BITR[v], ind, add);
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x, val, add);
		else Update(2 * v + 1, m + 1, r, x, val, add);
	}
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		ind[i] = val[i] = i;
		inind[i].push_back(i);
	}
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &qa[i], &qb[i]);
		if (qa[i] > qb[i]) swap(qa[i], qb[i]);
		if (qa[i] != qb[i]) {
			int a = val[qa[i]], b = val[qb[i]];
			val[qb[i]] = a; val[qa[i]] = b;
			ind[a] = qb[i]; ind[b] = qa[i];
			inind[qb[i]].push_back(a); inind[qa[i]].push_back(b);
		}
	}
	Create(1, 1, n);
	for (int i = 1; i <= n; i++) {
		ind[i] = val[i] = i;
		Update(1, 1, n, i, i, 1);
	}
	for (int i = 0; i < q; i++) {
		if (qa[i] != qb[i]) {
			int a = val[qa[i]], b = val[qb[i]];
			Update(1, 1, n, qa[i], a, -1);
			res -= Get(1, 1, n, 1, qa[i], a, false) + Get(1, 1, n, qa[i], n, a, true);

			Update(1, 1, n, qb[i], b, -1);
			res -= Get(1, 1, n, 1, qb[i], b, false) + Get(1, 1, n, qb[i], n, b, true);

			val[qb[i]] = a; ind[a] = qb[i];
			res += Get(1, 1, n, 1, qb[i], a, false) + Get(1, 1, n, qb[i], n, a, true);
			Update(1, 1, n, qb[i], a, 1);

			val[qa[i]] = b; ind[b] = qa[i];
			res += Get(1, 1, n, 1, qa[i] - 1, b, false) + Get(1, 1, n, qa[i] + 1, n, b, true);
			Update(1, 1, n, qa[i], b, 1);
		}
		printf("%I64d\n", res);
	}
	return 0;
}