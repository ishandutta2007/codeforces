#include <cstdio>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 100005;

int n, m;
int a[Maxn];
iii E[Maxn];
int p[Maxn], siz[Maxn];
ld tot;

int getPar(int x) { return x == p[x]? x: p[x] = getPar(p[x]); }

ld unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return 0ll;
	ld res = ld(siz[a]) * ld(siz[b]);
	if (siz[a] >= siz[b]) { siz[a] += siz[b]; p[b] = a; }
	else { siz[b] += siz[a]; p[a] = b; }
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		p[i] = i; siz[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d %d", &u, &v);
		E[i] = iii(min(a[u], a[v]), ii(u, v));
	}
	sort(E, E + m);
	for (int i = m - 1; i >= 0; i--) {
		int u = E[i].second.first, v = E[i].second.second;
		tot += ld(E[i].first) * unionSet(u, v);
	}
	tot /= ld(n) * ld(n - 1) / 2;
	cout << fixed << setprecision(10) << tot << endl;
	return 0;
}