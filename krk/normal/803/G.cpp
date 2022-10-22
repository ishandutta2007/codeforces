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

const int Maxn = 100005;
const int Maxm = 2097152;
const int Maxk = 20;
const int Inf = 2000000007;

int n, k;
int b[Maxn][Maxk];
int q;
int typ[Maxn], lef[Maxn], rig[Maxn], x[Maxn];
vector <int> un, seq, vals;
int st[Maxm], flag[Maxm];

int Get(int l, int r)
{
	int res = Inf;
	for (int i = Maxk - 1; i >= 0; i--) if (l + (1 << i) <= r + 1) {
		res = min(res, b[l][i]); l += 1 << i;
	}
	return res;
}

int getBig(int l, int r)
{
	if (r - l + 1 >= n) return Get(0, n - 1);
	if (l % n <= r % n) return Get(l % n, r % n);
	return min(Get(l % n, n - 1), Get(0, r % n));
}

void downOn(int v, int val)
{
	st[v] = flag[v] = val;
}

void Down(int v)
{
	if (flag[v] < Inf) {
		downOn(2 * v, flag[v]); 
		downOn(2 * v + 1, flag[v]);
		flag[v] = Inf;
	}
}

void Union(int v)
{
	st[v] = min(st[2 * v], st[2 * v + 1]);
}

void Create(int v, int l, int r)
{
	flag[v] = Inf;
	if (l == r) st[v] = vals[l];
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		Union(v);
	}
}

void Update(int v, int l, int r, int a, int b, int x)
{
	if (l == a && r == b) downOn(v, x);
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) Update(2 * v, l, m, a, min(m, b), x);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, x);
		Union(v);
	}
}

int Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v];
	else {
		Down(v);
		int m = l + r >> 1;
		int res = Inf;
		if (a <= m) res = min(res, Get(2 * v, l, m, a, min(m, b)));
		if (m + 1 <= b) res = min(res, Get(2 * v + 1, m + 1, r, max(m + 1, a), b));
		return res;
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i][0]);
	for (int j = 1; j < Maxk; j++)
		for (int i = 0; i + (1 << j) <= n; i++)
			b[i][j] = min(b[i][j - 1], b[i + (1 << j - 1)][j - 1]);
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d %d %d", &typ[i], &lef[i], &rig[i]); lef[i]--; rig[i]--;
		if (typ[i] == 1) scanf("%d", &x[i]);
		un.push_back(lef[i]); un.push_back(rig[i]);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	int lst = -1;
	for (int i = 0; i < un.size(); i++) {
		if (lst + 1 < un[i]) { seq.push_back(lst + 1); vals.push_back(getBig(lst + 1, un[i] - 1)); }
		seq.push_back(un[i]); vals.push_back(b[un[i] % n][0]);
		lst = un[i];
	}
	if (lst + 1 < k * n) { seq.push_back(lst + 1); vals.push_back(getBig(lst + 1, k * n - 1)); }
	Create(1, 0, seq.size() - 1);
	for (int i = 0; i < q; i++) {
		lef[i] = lower_bound(seq.begin(), seq.end(), lef[i]) - seq.begin();
		rig[i] = lower_bound(seq.begin(), seq.end(), rig[i]) - seq.begin();
		if (typ[i] == 1) Update(1, 0, seq.size() - 1, lef[i], rig[i], x[i]);
		else printf("%d\n", Get(1, 0, seq.size() - 1, lef[i], rig[i]));
	}
	return 0;
}