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
int p[Maxn];
vector <int> seq[Maxm];

ll Recs(int n) { return ll(n) * (n - 1) / 2; }

void Create(int v, int l, int r)
{
	if (l == r) seq[v].push_back(p[l]);
	else {
		int m = l + r >> 1;
		int lc = 2 * v, rc = 2 * v + 1;
		Create(lc, l, m); Create(rc, m + 1, r);
		int i = 0, j = 0;
		while (i < seq[lc].size() || j < seq[rc].size())
			if (i < seq[lc].size() && (j >= seq[rc].size() || seq[lc][i] < seq[rc][j]))
				seq[v].push_back(seq[lc][i++]);
			else seq[v].push_back(seq[rc][j++]);
	}
}

int Get(int v, int l, int r, int a, int b, int x, bool up)
{
	if (a > b) return 0;
	if (l == a && r == b)
		if (up) return seq[v].end() - lower_bound(seq[v].begin(), seq[v].end(), x);
		else return upper_bound(seq[v].begin(), seq[v].end(), x) - seq[v].begin();
	else {
		int m = l + r >> 1;
		int res = 0;
		if (a <= m) res += Get(2 * v, l, m, a, min(m, b), x, up);
		if (m + 1 <= b) res += Get(2 * v + 1, m + 1, r, max(m + 1, a), b, x, up);
		return res;
	}
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	Create(1, 1, n);
	for (int i = 0; i < q; i++) {
		int l, d, r, u; scanf("%d %d %d %d", &l, &d, &r, &u);
		ll res = Recs(n) - Recs(l - 1) - Recs(n - r) - Recs(d - 1) - Recs(n - u);
		res += Recs(Get(1, 1, n, 1, l - 1, u + 1, true));
		res += Recs(Get(1, 1, n, 1, l - 1, d - 1, false));
		res += Recs(Get(1, 1, n, r + 1, n, u + 1, true));
		res += Recs(Get(1, 1, n, r + 1, n, d - 1, false));
		printf("%I64d\n", res);
	}
	return 0;
}