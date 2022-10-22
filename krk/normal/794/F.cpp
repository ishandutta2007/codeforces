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

const int Maxn = 100005;
const int Maxm = 524288;
const int Maxd = 10;

int n, q;
ll a[Maxn];
ll st[Maxm][Maxd], res[Maxm];
int ch[Maxm][Maxd];
bool fl[Maxm];

void downOn(int v, int my[])
{
	fl[v] = true;
	for (int i = 0; i < Maxd; i++) {
		res[v] += ll(my[ch[v][i]] - ch[v][i]) * st[v][i];
		ch[v][i] = my[ch[v][i]];
	}
}

void Down(int v)
{
	if (fl[v]) {
		downOn(2 * v, ch[v]);
		downOn(2 * v + 1, ch[v]);
		fl[v] = false;
	}
}

void Union(int v)
{
	res[v] = 0;
	for (int i = 0; i < Maxd; i++) {
		st[v][i] = 0;
		ch[v][i] = i;
	}
	fl[v] = false;
	for (int i = 0; i < Maxd; i++) {
		res[v] += ll(ch[2 * v][i]) * st[2 * v][i] + ll(ch[2 * v + 1][i]) * st[2 * v + 1][i];
		st[v][ch[2 * v][i]] += st[2 * v][i];
		st[v][ch[2 * v + 1][i]] += st[2 * v + 1][i];
	}
}

void Update(int v, int l, int r, int a, int b, int my[])
{
	if (l == a && r == b) downOn(v, my);
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) Update(2 * v, l, m, a, min(m, b), my);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, my);
		Union(v);
	}
}

ll Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return res[v];
	else {
		Down(v);
		int m = l + r >> 1;
		ll res = 0;
		if (a <= m) res += Get(2 * v, l, m, a, min(m, b));
		if (m + 1 <= b) res += Get(2 * v + 1, m + 1, r, max(m + 1, a), b);
		Union(v);
		return res;
	}
}

void Create(int v, int l, int r)
{
	if (l == r) {
		res[v] = a[l]; fl[v] = false;
		for (int i = 0; i < Maxd; i++)
			ch[v][i] = i;
		ll cur = 1;
		while (a[l] > 0) {
			st[v][a[l] % 10] += cur;
			a[l] /= 10ll; cur *= 10ll;
		}
	} else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		Union(v);
	}
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%I64d", &a[i]);
	Create(1, 1, n);
	int my[Maxd];
	while (q--) {
		int typ, l, r, x, y; scanf("%d %d %d", &typ, &l, &r);
		if (typ == 1) {
			scanf("%d %d", &x, &y);
			for (int i = 0; i < Maxd; i++)
				my[i] = i;
			my[x] = y;
			Update(1, 1, n, l, r, my);
		} else printf("%I64d\n", Get(1, 1, n, l, r));
	}
	return 0;
}