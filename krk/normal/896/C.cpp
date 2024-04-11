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
typedef pair <ll, ll> llll;

const int mod = 1000000007;
const int Maxn = 100005;
const int Maxm = 524288;

int n, m, seed, vmax;
int a[Maxn];
llll flag[Maxm];
ll add[Maxm];
vector <llll> st[Maxm];

void downOn(int v, int siz, llll f)
{
	if (f.first == 1) {
		flag[v].second += f.second;
		add[v] += f.second;
	} else {
		flag[v] = f;
		add[v] = 0;
		st[v].clear();
		st[v].push_back(llll(f.second, siz));
	}
}

void Down(int v, int l, int m, int r)
{
	if (flag[v] != llll(1, 0)) {
		downOn(2 * v, m + 1 - l, flag[v]);
		downOn(2 * v + 1, r - m, flag[v]);
		flag[v] = llll(1, 0);
	}
}

void Merge(const vector <llll> &a, ll adda, const vector <llll> &b, ll addb, vector <llll> &c)
{
	c.clear();
	int i = 0, j = 0;
	while (i < a.size() || j < b.size())
	if (i < a.size() && (j >= b.size() || a[i].first + adda < b[j].first + addb)) {
		c.push_back(llll(a[i].first + adda, a[i].second));
		i++;
	} else if (j < b.size() && (i >= a.size() || b[j].first + addb < a[i].first + adda)) {
		c.push_back(llll(b[j].first + addb, b[j].second));
		j++;
	} else {
		c.push_back(llll(a[i].first + adda, a[i].second + b[j].second));
		i++; j++;
	}
}

void Union(int v)
{
	Merge(st[2 * v], add[2 * v], st[2 * v + 1], add[2 * v + 1], st[v]);
	add[v] = 0;
}

void Create(int v, int l, int r)
{
	add[v] = 0; flag[v] = llll(1, 0);
	if (l == r) st[v].push_back(llll(a[l], 1));
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		Union(v);
	}
}

void Update(int v, int l, int r, int a, int b, llll f)
{
	if (l == a && r == b) downOn(v, r - l + 1, f);
	else {
		int m = l + r >> 1;
		Down(v, l, m, r);
		if (a <= m) Update(2 * v, l, m, a, min(m, b), f);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, f);
		Union(v);
	}
}

void Copy(const vector <llll> &V, ll add, vector <llll> &res)
{
	res.clear();
	for (int i = 0; i < V.size(); i++)
		res.push_back(llll(V[i].first + add, V[i].second));
}

void Get(int v, int l, int r, int a, int b, vector <llll> &res)
{
	if (l == a && r == b) Copy(st[v], add[v], res);
	else {
		int m = l + r >> 1;
		Down(v, l, m, r);
		if (b <= m) Get(2 * v, l, m, a, b, res);
		else if (m + 1 <= a) Get(2 * v + 1, m + 1, r, a, b, res);
		else {
			vector <llll> res1, res2;
			Get(2 * v, l, m, a, m, res1);
			Get(2 * v + 1, m + 1, r, m + 1, b, res2);
			Merge(res1, 0, res2, 0, res);
		} 
	}
}

int toPower(int a, int p, int mod)
{
	int res = 1 % mod;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int rnd()
{
	int ret = seed;
	seed = (ll(seed) * 7ll + 13ll) % mod;
	return ret;
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &seed, &vmax);
	for (int i = 1; i <= n; i++)
		a[i] = rnd() % vmax + 1;
	Create(1, 1, n);
	for (int i = 1; i <= m; i++) {
		int op = rnd() % 4 + 1;
		int l = rnd() % n + 1;
		int r = rnd() % n + 1;
		if (l > r) swap(l, r);
		int x, y;
		if (op == 3) x = rnd() % (r - l + 1) + 1;
		else x = rnd() % vmax + 1;
		if (op == 4) y = rnd() % vmax + 1;

		if (op == 1) Update(1, 1, n, l, r, llll(1, x));
		else if (op == 2) Update(1, 1, n, l, r, llll(2, x));
		else {
			vector <llll> res;
			Get(1, 1, n, l, r, res);
			if (op == 3) {
				x--;
				int j = 0;
				while (res[j].second <= x) { x -= res[j].second; j++; }
				printf("%I64d\n", res[j].first);
			} else {
				int ans = 0;
				for (int j = 0; j < res.size(); j++)
					ans = (ans + ll(res[j].second) * toPower(res[j].first % y, x, y)) % y;
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}