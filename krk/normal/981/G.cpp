#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 1048576;
const int mod = 998244353;

int n, q;
int sum[Maxm];
ii flag[Maxm];
set <ii> S[Maxn];

void downOn(int v, int siz, ii f)
{
	sum[v] = (ll(sum[v]) * f.first + ll(f.second) * siz) % mod;
	flag[v].first = ll(flag[v].first) * f.first % mod;
	flag[v].second = (ll(flag[v].second) * f.first + ll(f.second)) % mod;
}

void Down(int v, int l, int m, int r)
{
	if (flag[v] != ii(1, 0)) {
		downOn(2 * v, m - l + 1, flag[v]);
		downOn(2 * v + 1, r - m, flag[v]);
		flag[v] = ii(1, 0);
	}
}

void Union(int v)
{
	sum[v] = (sum[2 * v] + sum[2 * v + 1]) % mod;
}

void Create(int v, int l, int r)
{
	flag[v] = ii(1, 0);
	if (l < r) {
		int m = l + r >> 1;
		Create(2 * v, l, m);
		Create(2 * v + 1, m + 1, r);
	}
}

void Update(int v, int l, int r, int a, int b, ii my)
{
	if (l == a && r == b) downOn(v, r - l + 1, my);
	else {
		int m = l + r >> 1;
		Down(v, l, m, r);
		if (a <= m) Update(2 * v, l, m, a, min(m, b), my);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, my);
		Union(v);
	}
}

int Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return sum[v];
	else {
		int m = l + r >> 1;
		Down(v, l, m, r);
		if (b <= m) return Get(2 * v, l, m, a, b);
		if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
		return (Get(2 * v, l, m, a, m) + Get(2 * v + 1, m + 1, r, m + 1, b)) % mod;
	}
}

void addSet(set <ii> &S, int lef, int rig)
{
	set <ii>::iterator it = S.lower_bound(ii(lef + 1, 0));
	vector <ii> tmp;
	if (it != S.begin()) {
		it--;
		if (it->second + 1 < lef) it++;
	}
	while (it != S.end() && it->first - 1 <= rig) {
		tmp.push_back(*it);
		S.erase(it++);
	}
	if (tmp.empty()) {
		Update(1, 1, n, lef, rig, ii(1, 1));
		S.insert(ii(lef, rig));
		return;
	}
	if (lef < tmp[0].first)
		Update(1, 1, n, lef, tmp[0].first - 1, ii(1, 1));
	for (int i = 0; i < tmp.size(); i++) {
		int nlef = max(tmp[i].first, lef);
		int nrig = min(tmp[i].second, rig);
		if (nlef <= nrig) Update(1, 1, n, nlef, nrig, ii(2, 0));
		if (i + 1 < tmp.size()) {
			int a = tmp[i].second + 1;
			int b = tmp[i + 1].first - 1;
			if (a <= b) Update(1, 1, n, a, b, ii(1, 1));
		}
	}
	if (tmp.back().second < rig)
		Update(1, 1, n, tmp.back().second + 1, rig, ii(1, 1));
	lef = min(lef, tmp[0].first); rig = max(rig, tmp.back().second);
	S.insert(ii(lef, rig));
}

int main()
{
	scanf("%d %d", &n, &q);
	Create(1, 1, n);
	while (q--) {
		int typ, l, r, x;
		scanf("%d %d %d", &typ, &l, &r);
		if (typ == 1) {
			scanf("%d", &x);
			addSet(S[x], l, r);
		} else printf("%d\n", Get(1, 1, n, l, r));
	}
	return 0;
}