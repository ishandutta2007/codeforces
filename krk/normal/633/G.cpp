#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int Maxn = 100005;
const int Maxm = 1001;
const int Maxs = 524288;
const int Maxb = 62;
const int Maxp = 17;

ull my[Maxp];
bool prime[Maxm];
int n, m;
int a[Maxn];
vector <int> neigh[Maxn];
int cur, L[Maxn], R[Maxn];
int val[Maxn];
ull tmp[Maxp];

struct pos {
	int flag;
	ull has[Maxp];
	pos(): flag(0) { fill(has, has + Maxp, ull(0)); }
} st[Maxs];

void Union(int v)
{
	for (int i = 0; i < Maxp; i++)
		st[v].has[i] = st[2 * v].has[i] | st[2 * v + 1].has[i];
}

void Create(int v, int l, int r)
{
	if (l == r) {
		int ind = val[l] % m;
		st[v].has[ind / Maxb] |= ull(1) << ull(ind % Maxb);
	} else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		Union(v);
	}
}

void downOn(int v, int val)
{
	st[v].flag = (st[v].flag + val) % m;
	for (int i = 0; i < Maxp && i * Maxb < m; i++) {
		int bits = min(Maxb, m - i * Maxb);
		int hg = i * Maxb + bits - 1;
		tmp[i] = 0;
		while (bits > 0) {
			int nd = (hg - val % m + m) % m;
			int ind = nd / Maxb, howmany = nd % Maxb + 1;
			if (howmany >= bits) {
				tmp[i] |= (st[v].has[ind] & ((ull(1) << ull(bits)) - ull(1)) << ull(howmany - bits)) >> ull(howmany - bits);
				bits = 0;
			} else {
				tmp[i] |= (st[v].has[ind] & (ull(1) << ull(howmany)) - ull(1)) << ull(bits - howmany);
				bits -= howmany; hg -= howmany;
			}
		}
	}
	for (int i = 0; i < Maxp; i++)
		st[v].has[i] = tmp[i];
}

void Down(int v)
{
	if (st[v].flag) {
		downOn(2 * v, st[v].flag); 
		downOn(2 * v + 1, st[v].flag);
		st[v].flag = 0;
	}
}

void Add(int v, int l, int r, int a, int b, int val)
{
	if (l == a && r == b) downOn(v, val);
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) Add(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
		Union(v);
	}
}

void Get(int v, int l, int r, int a, int b, ull res[])
{
	if (l == a && r == b)
		for (int i = 0; i < Maxp; i++)
			res[i] |= st[v].has[i];
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) Get(2 * v, l, m, a, min(m, b), res);
		if (m + 1 <= b) Get(2 * v + 1, m + 1, r, max(m + 1, a), b, res);
	}
}

void Traverse(int v, int p = 0)
{
	L[v] = ++cur; val[L[v]] = a[v];
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v);
	}
	R[v] = cur;
}

int main()
{
	scanf("%d %d", &n, &m); m = max(m, 2);
	fill(prime + 2, prime + m, true);
	for (int i = 2; i < m; i++) if (prime[i]) {
		my[i / Maxb] |= ull(1) << ull(i % Maxb);
		for (int j = i + i; j < m; j += i)
			prime[j] = false;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	Create(1, 1, n);
	int q; scanf("%d", &q);
	while (q--) {
		int typ, v, x;
		scanf("%d %d", &typ, &v);
		if (typ == 1) {
			scanf("%d", &x); x %= m;
			Add(1, 1, n, L[v], R[v], x);
		} else {
			ull res[Maxp] = {};
			Get(1, 1, n, L[v], R[v], res);
			ll tot = 0;
			for (int i = 0; i < Maxp; i++)
				tot += __builtin_popcountll(res[i] & my[i]);
			printf("%I64d\n", tot);
		}
	}
	return 0;
}