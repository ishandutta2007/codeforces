#ifndef LOCAL
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int MAXN = 210000;
const int SQ = 300;
const int SQ2 = MAXN / SQ + 10;
const int CC = 110;

int cl[SQ2][CC];
int go[SQ2][CC];
int sz[SQ2][CC];
int p[SQ2][CC];
int a[MAXN];
int bcnt;
int n;

int get(int k, int a) {
	if (p[k][a] == a)
		return a;
	return p[k][a] = get(k, p[k][a]);
}

void un(int k, int a, int b) {
	int atmp = a;
	a = go[k][a];
	int b2 = go[k][b];
	go[k][atmp] = -1;
	if (a == -1)
		return;
	if (b2 == -1) {
		go[k][b] = a;
		cl[k][a] = b;
		return;
	}
	if (sz[k][a] > sz[k][b2])
		swap(a, b2);
	p[k][a] = b2;
	sz[k][b2] += sz[k][a];
	cl[k][b2] = b;
	go[k][b] = b2;
}

void rebuild(int k) {
	for (int i = 0; i < CC; ++i)
		sz[k][i] = 1, p[k][i] = i, cl[k][i] = i, go[k][i] = i;
}

void push(int k) {
	int l = k * SQ;
	int r = min(n, (k + 1) * SQ);
	for (int i = l; i < r; ++i)
		a[i] = cl[k][get(k, a[i])];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	bcnt = (n - 1) / SQ + 1;
	for (int i = 0; i < bcnt; ++i)
		rebuild(i);
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int l, r, x, y;
		scanf("%d%d%d%d", &l, &r, &x, &y);
		if (x == y)
			continue;
		--l;
		int bl = (l + SQ - 1) / SQ;
		int br = r / SQ;
		for (int j = bl; j < br; ++j)
			un(j, x, y);
		int r2 = bl * SQ;
		if (l < r2) {
			push(l / SQ);
			for (int i = l; i < min(r, r2); ++i)
				if (a[i] == x)
					a[i] = y;
			rebuild(l / SQ);
		}
		int l2 = br * SQ;
		if (l2 < r && l <= l2) {
			push(r / SQ);
			for (int i = l2; i < r; ++i)
				if (a[i] == x)
					a[i] = y;
			rebuild(r / SQ);
		}
	}
	for (int i = 0; i < bcnt; ++i)
		push(i);
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}