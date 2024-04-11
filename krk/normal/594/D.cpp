#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 200005;
const int Maxm = 1048576;
const int mod = 1000000007;

struct node {
	int mult;
	vector <ii> val;
};

int mx[Maxm];
int n;
int a[Maxn];
map <int, int> M[Maxn];
node st[Maxm];
vector <int> has[Maxm];

int Inv(int a, int p = mod - 2)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		a = ll(a) * a % mod; p >>= 1;
	}
	return res;
}

void Insert(int v, int l, int r, int x, ii val)
{
	if (l == r) st[v].val.push_back(val);
	else {
		int m = l + r >> 1;
		if (x <= m) Insert(2 * v, l, m, x, val);
		else Insert(2 * v + 1, m + 1, r, x, val);
	}
}

void Create(int v, int l, int r)
{
	if (l == r) {
		st[v].mult = a[l];
		for (map <int, int>::iterator it = M[l].begin(); it != M[l].end(); it++)
			st[v].val.push_back(*it);
	} else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		int i = 0, j = 0;
		while (i < st[2 * v].val.size() || j < st[2 * v + 1].val.size())
			if (i < st[2 * v].val.size() && (j == st[2 * v + 1].val.size() || st[2 * v].val[i].first < st[2 * v + 1].val[j].first))
				st[v].val.push_back(st[2 * v].val[i++]);
			else if (j < st[2 * v + 1].val.size() && (i == st[2 * v].val.size() || st[2 * v + 1].val[j].first < st[2 * v].val[i].first))
				st[v].val.push_back(st[2 * v + 1].val[j++]);
			else {
				st[v].val.push_back(ii(st[2 * v].val[i].first, ll(st[2 * v].val[i].second) * st[2 * v + 1].val[j].second % mod));
				i++; j++;
			}
		st[v].mult = ll(st[2 * v].mult) * st[2 * v + 1].mult % mod;
	}
}

void Create2(int v, int l, int r)
{
	for (int i = 1; i < st[v].val.size(); i++)
		st[v].val[i].second = ll(st[v].val[i - 1].second) * st[v].val[i].second % mod;
	if (l < r) {
		int m = l + r >> 1;
		Create2(2 * v, l, m); Create2(2 * v + 1, m + 1, r);
	}
}

int Get(int v, int l, int r, int a, int b, int x)
{
	if (l == a && r == b) {
		int res = st[v].mult;
		int ind = lower_bound(st[v].val.begin(), st[v].val.end(), ii(x + 1, 0)) - st[v].val.begin() - 1;
		if (ind >= 0) res = ll(res) * st[v].val[ind].second % mod;
		return res;
	} else {
		int res = 1;
		int m = l + r >> 1;
		if (a <= m) res = ll(res) * Get(2 * v, l, m, a, min(m, b), x) % mod;
		if (m + 1 <= b) res = ll(res) * Get(2 * v + 1, m + 1, r, max(m + 1, a), b, x) % mod;
		return res;
	}
}

int main()
{
	for (int i = 2; i < Maxm; i++) if (mx[i] == 0)
		for (int j = i; j < Maxm; j += i) mx[j] = i;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		int num = a[i];
		while (num > 1) {
			int m = mx[num];
			a[i] -= a[i] / m;
			has[m].push_back(i);
			while (mx[num] == m) num /= m;
		}
	}
	for (int i = 0; i < Maxm; i++) if (has[i].size() >= 2) {
		int mult = ll(i) * Inv(i - 1) % mod;
		for (int j = 0; j + 1 < has[i].size(); j++) {
			map <int, int>::iterator it = M[has[i][j]].find(has[i][j + 1]);
			if (it == M[has[i][j]].end()) M[has[i][j]][has[i][j + 1]] = mult;
			else M[has[i][j]][has[i][j + 1]] = ll(it->second) * mult % mod;
		}
	}
	Create(1, 0, n - 1);
	Create2(1, 0, n - 1);
	int m; scanf("%d", &m);
	while (m--) {
		int l, r; scanf("%d %d", &l, &r); l--; r--;
		printf("%d\n", Get(1, 0, n - 1, l, r, r));
	}
	return 0;
}