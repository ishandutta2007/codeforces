#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 1000001;
const int Maxm = 2097152;

int f[Maxn];
int n, m;
int a[Maxn];
ii mx[Maxm];
ll BIT[Maxn];
int seq[Maxn], slen;

void Union(int v)
{
	mx[v] = max(mx[2 * v], mx[2 * v + 1]);
}

void Create(int v, int l, int r)
{
	if (l == r) mx[v] = ii(a[l], l);
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		Union(v);
	}
}

ii Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return mx[v];
	else {
		int m = l + r >> 1;
		if (b <= m) return Get(2 * v, l, m, a, b);
		if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
		return max(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
	}
}

void Update(int v, int l, int r, int x, ii val)
{
	if (l == r) mx[v] = val;
	else {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x, val);
		else Update(2 * v + 1, m + 1, r, x, val);
		Union(v);
	}
}

void Insert(int x, ll val)
{
	for (int i = x; i <= n; i += i & -i)
		BIT[i] += val;
}

ll Get(int x)
{
	ll res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int main()
{
	for (int i = 1; i < Maxn; i++) {
		for (int j = i; j < Maxn; j += i)
			f[j]++;
	}
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		Insert(i, a[i]);
	}
	Create(1, 1, n);
	while (m--) {
		int t, l, r; scanf("%d %d %d", &t, &l, &r);
		if (t == 1) {
			slen = 0;
			while (true) {
				ii got = Get(1, 1, n, l, r); 
				if (got.first <= 2) break;
				Update(1, 1, n, got.second, ii(0, got.second));
				seq[slen++] = got.second;
				Insert(got.second, f[a[got.second]] - a[got.second]);
				a[got.second] = f[a[got.second]];
			}
			for (int i = 0; i < slen; i++)
				Update(1, 1, n, seq[i], ii(a[seq[i]], seq[i]));
		} else {
			ll res = Get(r) - Get(l - 1);
			printf("%I64d\n", res);
		}
	}
	return 0;
}