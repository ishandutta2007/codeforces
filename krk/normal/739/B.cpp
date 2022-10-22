#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 1048576;

vector <ll> my[Maxm];
int n;
int a[Maxn];
vector <ii> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
int wh[Maxn];
ll D[Maxn];

void Traverse(int v)
{
	cur++; lef[v] = cur; wh[cur] = v;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		D[u.first] = D[v] + u.second;
		Traverse(u.first);
	}
	rig[v] = cur;
}

void Create(int v, int l, int r)
{
	if (l == r) my[v].push_back(D[wh[l]] - a[wh[l]]);
	else {
		int m = l + r >> 1;
		int lc = 2 * v, rc = 2 * v + 1;
		Create(lc, l, m); Create(rc, m + 1, r);
		int i = 0, j = 0;
		while (i < my[lc].size() || j < my[rc].size())
			if (i < my[lc].size() && (j == my[rc].size() || my[lc][i] < my[rc][j]))
				my[v].push_back(my[lc][i++]);
			else my[v].push_back(my[rc][j++]);
	}
}

int Get(int v, int l, int r, int a, int b, ll x)
{
	if (l == a && r == b) return upper_bound(my[v].begin(), my[v].end(), x) - my[v].begin();
	else {
		int m = l + r >> 1;
		int res = 0;
		if (a <= m) res += Get(2 * v, l, m, a, min(m, b), x);
		if (m + 1 <= b) res += Get(2 * v + 1, m + 1, r, max(m + 1, a), b, x);
		return res;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 2; i <= n; i++) {
		int p, w; scanf("%d %d", &p, &w);
		neigh[p].push_back(ii(i, w));
	}
	Traverse(1);
	Create(1, 1, cur);
	for (int i = 1; i <= n; i++)
		printf("%d%c", Get(1, 1, cur, lef[i], rig[i], D[i]) - 1, i + 1 <= n? ' ': '\n');
	return 0;
}