#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 300005;
const int Maxm = 1000005;
const int Maxs = 4194304;

int n, m;
vector <int> has[Maxm];
vector <int> st[Maxs];
int cnt;
int query[Maxn];
int res;

void Create(int v, int l, int r)
{
	if (l == r) st[v] = has[l];
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		int i = 0, j = 0;
		while (i < st[2 * v].size() || j < st[2 * v + 1].size())
			if (i < st[2 * v].size() && (j == st[2 * v + 1].size() || st[2 * v][i] < st[2 * v + 1][j]))
				st[v].push_back(st[2 * v][i++]);
			else st[v].push_back(st[2 * v + 1][j++]);
	}
}

int Get(int v, int l, int r, int a, int b, int lim)
{
	int res = 0;
	if (l == a && r == b) {
		int ind = lower_bound(st[v].begin(), st[v].end(), lim) - st[v].begin();
		res = st[v].size() - ind;
	} else {
		int m = l + r >> 1;
		if (a <= m) res += Get(2 * v, l, m, a, min(m, b), lim);
		if (m + 1 <= b) res += Get(2 * v + 1, m + 1, r, max(m + 1, a), b, lim);
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int l, r; scanf("%d %d", &l, &r);
		has[l].push_back(r);
	}
	for (int i = 0; i < Maxm; i++)
		sort(has[i].begin(), has[i].end());
	Create(1, 1, Maxm - 1);
	while (m--) {
		res = 0;
		scanf("%d", &cnt);
		for (int i = 1; i <= cnt; i++) {
			scanf("%d", &query[i]);
			res += Get(1, 1, Maxm - 1, query[i - 1] + 1, query[i], query[i]);
		}
		printf("%d\n", res);
	}
	return 0;
}