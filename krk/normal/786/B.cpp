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
typedef pair <int, int> ii;
typedef pair <ii, int> iii;
typedef pair <ll, ll> llll;

const int Maxn = 100005;
const int Maxm = 524288;
const ll Inf = 1000000000000000000ll;

int n, q, s;
vector <iii> neigh[Maxn];
int V[Maxn], W[Maxn];
bool tk[Maxn];
llll mn[Maxm];
ll flag[Maxm];
int cnt[Maxm];
vector <int> has[Maxm];
ll res[Maxn];

void downOn(int v, ll val)
{
	mn[v].first = min(mn[v].first, val);
	flag[v] = min(flag[v], val);
}

void Down(int v)
{
	downOn(2 * v, flag[v]);
	downOn(2 * v + 1, flag[v]);
}

void Copy(int v, int u)
{
	mn[v] = mn[u]; cnt[v] = cnt[u];
}

void Union(int v)
{
	if (cnt[2 * v] == 0) Copy(v, 2 * v + 1);
	else if (cnt[2 * v + 1] == 0) Copy(v, 2 * v);
	else {
		cnt[v] = cnt[2 * v] + cnt[2 * v + 1];
		mn[v] = min(mn[2 * v], mn[2 * v + 1]);
	}
}

void Create(int v, int l, int r)
{
	flag[v] = Inf;
	if (l == r) {
		cnt[v] = 1;
		mn[v] = l == s? llll(0, l): llll(Inf, l);
	} else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		Union(v);
	}
}

void Update(int v, int l, int r, int a, int b, ll val)
{
	if (l == a && r == b) downOn(v, val);
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) Update(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
		Union(v);
	}
}

void Remove(int v, int l, int r, int x)
{
	if (l == r) { cnt[v] = 0; mn[v] = llll(Inf, x); }
	else {
		Down(v);
		int m = l + r >> 1;
		if (x <= m) Remove(2 * v, l, m, x);
		else Remove(2 * v + 1, m + 1, r, x);
		Union(v);
	}
}

void writeHas(int v, int l, int r, int a, int b, int ind)
{
	if (l == a && r == b) has[v].push_back(ind);
	else {
		int m = l + r >> 1;
		if (a <= m) writeHas(2 * v, l, m, a, min(m, b), ind);
		if (m + 1 <= b) writeHas(2 * v + 1, m + 1, r, max(m + 1, a), b, ind);
	}
}

void readHas(int v, int l, int r, int x)
{
	while (!has[v].empty()) {
		int ind = has[v].back();
		if (!tk[ind]) {
			tk[ind] = true;
			Update(1, 1, n, V[ind], V[ind], res[x] + W[ind]);
		}
		has[v].pop_back();
	}
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) readHas(2 * v, l, m, x);
		else readHas(2 * v + 1, m + 1, r, x);
	}
}

int main()
{
	scanf("%d %d %d", &n, &q, &s);
	Create(1, 1, n);
	for (int i = 0; i < q; i++) {
		int typ; scanf("%d", &typ);
		if (typ == 1) {
			int v, u, w; scanf("%d %d %d", &v, &u, &w);
			neigh[v].push_back(iii(ii(u, u), w));
		} else {
			int v, l, r, w; scanf("%d %d %d %d", &v, &l, &r, &w);
			if (typ == 2) neigh[v].push_back(iii(ii(l, r), w));
			else {
				V[i] = v; W[i] = w;
				writeHas(1, 1, n, l, r, i);
			}
		}
	}
	fill(res + 1, res + n + 1, Inf);
	while (cnt[1] > 0 && mn[1].first < Inf) {
		int v = mn[1].second;
		res[v] = mn[1].first;
		Remove(1, 1, n, v);
		for (int i = 0; i < neigh[v].size(); i++) {
			iii u = neigh[v][i];
			Update(1, 1, n, u.first.first, u.first.second, res[v] + u.second);
		}
		readHas(1, 1, n, v);
	}
	for (int i = 1; i <= n; i++)
		printf("%I64d%c", res[i] >= Inf? -1: res[i], i + 1 <= n? ' ': '\n');
	return 0;
}