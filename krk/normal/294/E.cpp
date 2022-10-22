#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 5005;
const ll Inf = 9000000000000000000ll;

int n;
int a[Maxn], b[Maxn], c[Maxn];
vector <ii> neigh[Maxn];
ll pd[Maxn], adist[Maxn], siz[Maxn];
ll res = Inf;

void Precompute(int v, int p)
{
	pd[v] = 0; adist[v] = 0; siz[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.first == p) continue;
		Precompute(u.first, v); siz[v] += siz[u.first];
	}
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.first == p) continue;
		pd[v] += pd[u.first] + (siz[v] - siz[u.first]) * siz[u.first] * ll(u.second) + (siz[v] - siz[u.first]) * adist[u.first];
		adist[v] += siz[u.first] * ll(u.second) + adist[u.first];
	}
}

ll getMin(int v, int p, ll fromp, int tsiz)
{
	ll res = adist[v] + fromp;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.first == p) continue;
		res = min(res, getMin(u.first, v, adist[v] + fromp - siz[u.first] * ll(u.second) - adist[u.first] + (tsiz - siz[u.first]) * ll(u.second), tsiz));
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		neigh[a[i]].push_back(ii(b[i], c[i])); neigh[b[i]].push_back(ii(a[i], c[i]));
	}
	for (int i = 0; i < n - 1; i++) {
		Precompute(a[i], b[i]); Precompute(b[i], a[i]);
		ll mn1 = getMin(a[i], b[i], 0ll, siz[a[i]]), mn2 = getMin(b[i], a[i], 0ll, siz[b[i]]);
		res = min(res, pd[a[i]] + pd[b[i]] + mn1 * siz[b[i]] + mn2 * siz[a[i]] + ll(c[i]) * siz[b[i]] * siz[a[i]]);
	}
	printf("%I64d\n", res);
	return 0;
}