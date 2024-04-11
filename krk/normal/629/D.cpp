#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

const int Maxn = 100005;
const int Maxm = 524288;

int n;
int r[Maxn], h[Maxn];
ll V[Maxn];
vector <ll> un;
ll st[Maxm];
ll res;

ll Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v];
	else {
		int m = l + r >> 1;
		ll res = 0ll;
		if (a <= m) res = max(res, Get(2 * v, l, m, a, min(m, b)));
		if (m + 1 <= b) res = max(res, Get(2 * v + 1, m + 1, r, max(m + 1, a), b));
		return res;
	}
}

void Update(int v, int l, int r, int x, ll val)
{
	if (l == r) st[v] = max(st[v], val);
	else {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x, val);
		else Update(2 * v + 1, m + 1, r, x, val);
		st[v] = max(st[2 * v], st[2 * v + 1]);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &r[i], &h[i]); V[i] = ll(r[i]) * r[i] * h[i];
		un.push_back(V[i]);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 0; i < n; i++) {
		int ind = lower_bound(un.begin(), un.end(), V[i]) - un.begin();
		ll my = V[i];
		if (ind > 0) my += Get(1, 0, un.size() - 1, 0, ind - 1);
		res = max(res, my);
		Update(1, 0, un.size() - 1, ind, my);
	}
	printf("%.10lf\n", double(acos(-1.0l) * ld(res)));
	return 0;
}