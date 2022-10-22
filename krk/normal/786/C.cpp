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
const int Maxm = 524288;

int n;
int a[Maxn];
int lst[Maxn];
int prv[Maxn];
vector <int> st[Maxm];

void Create(int v, int l, int r)
{
	if (l == r) st[v].push_back(prv[l]);
	else {
		int m = l + r >> 1;
		int lc = 2 * v, rc = 2 * v + 1;
		Create(lc, l, m); Create(rc, m + 1, r);
		int i = 0, j = 0;
		while (i < st[lc].size() || j < st[rc].size())
			if (i < st[lc].size() && (j == st[rc].size() || st[lc][i] < st[rc][j])) st[v].push_back(st[lc][i++]);
			else st[v].push_back(st[rc][j++]);
	}
}

int Get(int v, int l, int r, int a, int val, int &lft)
{
	if (l == r) {
		lft -= (st[v].back() < val);
		return lft >= 0? l + 1: l;
	} else {
		int m = l + r >> 1;
		int res = l;
		if (a <= m)
			if (l < a) res = Get(2 * v, l, m, a, val, lft);
			else {
				int got = lower_bound(st[2 * v].begin(), st[2 * v].end(), val) - st[2 * v].begin();
				if (got <= lft) { res = m + 1; lft -= got; }
				else return Get(2 * v, l, m, a, val, lft);
			} 
		else return Get(2 * v + 1, m + 1, r, a, val, lft);
		if (lft >= 0) return Get(2 * v + 1, m + 1, r, max(m + 1, a), val, lft);
		else return res;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		prv[i] = lst[a[i]]; lst[a[i]] = i;
	}
	Create(1, 1, n);
	for (int i = 1; i <= n; i++) {
		int j = 1, res = 0;
		while (j <= n) {
			res++;
			int lft = i;
			j = Get(1, 1, n, j, j, lft);
		}
		printf("%d%c", res, i + 1 <= n? ' ': '\n');
	}
	return 0;
}