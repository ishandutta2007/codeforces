#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;
const int Maxm = 524288;

int n, k;
vector <int> un;
ii st[Maxm];
bool flag[Maxm];
vector <ii> add[Maxn];
ll res;

void downOn(int v)
{
	swap(st[v].first, st[v].second);
	flag[v] = !flag[v];
}

void Down(int v)
{
	if (flag[v]) {
		downOn(2 * v);
		downOn(2 * v + 1);
		flag[v] = false;
	}
}

void Union(int v)
{
	int lc = 2 * v, rc = 2 * v + 1;
	st[v].first = st[lc].first + st[rc].first;
	st[v].second = st[lc].second + st[rc].second;
}

void Create(int v, int l, int r)
{
	st[v] = ii(0, r - l + 1);
	if (l < r) {
		int m = l + r >> 1;
		Create(2 * v, l, m);
		Create(2 * v + 1, m + 1, r);
	}
}

void Update(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) downOn(v);
	else {
		int m = l + r >> 1;
		Down(v);
		if (a <= m) Update(2 * v, l, m, a, min(m, b));
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b);
		Union(v);
	}
}

int Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v].first;
	else {
		int m = l + r >> 1;
		Down(v);
		int res = 0;
		if (a <= m) res += Get(2 * v, l, m, a, min(m, b));
		if (m + 1 <= b) res += Get(2 * v + 1, m + 1, r, max(m + 1, a), b);
		return res;
	}
}

void Add(int v, int l, int r, int a, int b, ii p)
{
	if (l == a && r == b) add[v].push_back(p);
	else {
		int m = l + r >> 1;
		if (a <= m) Add(2 * v, l, m, a, min(m, b), p);
		if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b, p);
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		un.push_back(a);
	}
	sort(un.begin(), un.end());
	for (int i = 0; i < k; i++) {
		int a, b; scanf("%d %d", &a, &b);
		int lef = lower_bound(un.begin(), un.end(), a) - un.begin();
		int rig = upper_bound(un.begin(), un.end(), b) - un.begin() - 1;
		if (lef > rig) continue;
		add[lef].push_back(ii(lef, rig));
		add[rig + 1].push_back(ii(lef, rig));
	}
	res = ll(n) * (n - 1) * (n - 2) / 6ll;
	Create(1, 0, n - 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < add[i].size(); j++)
			Update(1, 0, n - 1, add[i][j].first, add[i][j].second);
		Update(1, 0, n - 1, 0, i);
		int ones = Get(1, 0, n - 1, 0, n - 1) - Get(1, 0, n - 1, i, i);
		res -= ll(ones) * (ones - 1) / 2;
		Update(1, 0, n - 1, 0, i);
	}
	cout << res << endl;
    return 0;
}