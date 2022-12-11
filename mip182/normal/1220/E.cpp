#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 200200;
int n, m, s;
ll w[N];
ll b[N];
vector<int> g[N];
int deg[N];
int q[N];
int topQ;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%lld", &w[i]);
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	scanf("%d", &s);
	s--;
	if (n == 1) {
		printf("%lld\n", w[0]);
		return 0;
	}
	deg[s] = N;
	for (int v = 0; v < n; v++) {
		deg[v] += (int)g[v].size();
		if (deg[v] == 1) {
			q[topQ++] = v;
		}
	}
	for (int i = 0; i < topQ; i++) {
		int v = q[i];
//		eprintf("%d ", v);
		deg[v] = 0;
		int u = -1;
		for (int x : g[v])
			if (deg[x] > 0)
				u = x;
		b[u] = max(b[u], w[v] + b[v]);
		deg[u]--;
		if (deg[u] == 1)
			q[topQ++] = u;
	}
	ll ans1 = 0, ans2 = 0;
	for (int v = 0; v < n; v++) {
		if (deg[v] == 0) continue;
		ans1 += w[v];
		ans2 = max(ans2, b[v]);
	}
	printf("%lld\n", ans1 + ans2);

	return 0;
}