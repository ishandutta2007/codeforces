#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 524288;
const int Inf = 1000000000;

int n;
int a[Maxn], b[Maxn], c[Maxn], d[Maxn];
vector <int> un;
vector <ii> mn[Maxn];
int dist[Maxn], par[Maxn];
ii mx[Maxm];

void Union(int v)
{
	mx[v] = max(mx[2 * v], mx[2 * v + 1]);
}

void Create(int v, int l, int r)
{
	if (l == r) mx[v] = mn[l].empty()? ii(-Inf, 0): mn[l].back();
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		Union(v);
	}
}

ii Get(int v, int l, int r, int a, int b)
{
	if (a == l && b == r) return mx[v];
	else {
		int m = l + r >> 1;
		if (b <= m) return Get(2 * v, l, m, a, b);
		if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
		return max(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
	}
}

void Erase(int v, int l, int r, int x)
{
	if (l == r) {
		mn[l].pop_back();
		mx[v] = mn[l].empty()? ii(-Inf, 0): mn[l].back();
	} else {
		int m = l + r >> 1;
		if (x <= m) Erase(2 * v, l, m, x);
		else Erase(2 * v + 1, m + 1, r, x);
		Union(v);
	}
}

int main()
{
	scanf("%d", &n);
	un.push_back(0);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
		un.push_back(c[i]);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 0; i < n; i++) {
		c[i] = lower_bound(un.begin(), un.end(), c[i]) - un.begin();
		mn[c[i]].push_back(ii(d[i], i));
	}
	for (int i = 0; i < un.size(); i++)
		sort(mn[i].begin(), mn[i].end());
	Create(1, 0, un.size() - 1);

	fill(dist, dist + n + 1, Inf); dist[n] = 0;
	queue <int> Q; Q.push(n);
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		if (v == 0) break;
		int ind = lower_bound(un.begin(), un.end(), a[v]) - un.begin();
		if (ind >= un.size()) continue;
		while (true) {
			ii got = Get(1, 0, un.size() - 1, ind, un.size() - 1);
			if (got.first < b[v]) break;
			dist[got.second] = dist[v] + 1; par[got.second] = v;
			Q.push(got.second);
			Erase(1, 0, un.size() - 1, c[got.second]);
		}
	}
	if (dist[0] != Inf) {
		printf("%d\n", dist[0]);
		int v = 0;
		do {
			v = par[v];
			printf("%d%c", v, v != n? ' ': '\n');
		} while (v != n);
	} else printf("-1\n");
	return 0;
}