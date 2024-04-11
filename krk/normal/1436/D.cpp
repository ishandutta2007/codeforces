#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const ll lim = 300000000000000ll;

int n;
vector <int> neigh[Maxn];
int a[Maxn];

ll Solve(int v, ll x)
{
	if (neigh[v].empty()) return a[v] > x? -1: x - a[v];
	ll eat = 0;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		ll rem = Solve(u, x);
		if (rem == -1) return -1;
		eat = min(lim, eat + rem);
	}
	if (a[v] > eat) return -1;
	eat -= a[v];
	return eat;
}

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int p; scanf("%d", &p);
		neigh[p].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	ll lef = 0, rig = lim;
	while (lef <= rig) {
		ll mid = lef + rig >> 1ll;
		if (Solve(1, mid) == -1) lef = mid + 1ll;
		else rig = mid - 1ll;
	}
	printf("%I64d\n", lef);
    return 0;
}