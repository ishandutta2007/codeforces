#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int P = 1000000007;
int n, m, k, f[500001];
long long a[500001], c[500001];
map<long long, vector<pair<int, int> > > edges;

int gf(int i) {
	return i == f[i] ? i : f[i] = gf(f[i]);
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	a[0] = 1;
	for (int i = 1; i <= n; i++)
		a[i] = a[i - 1] << 1,
		a[i] %= P, f[i] = i,
		scanf("%lld", &c[i]);
	edges.clear();
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		long long z = c[x] ^ c[y];
		if(edges.find(z) == edges.end())
			edges[z].clear();
		edges[z].push_back(make_pair(x, y));
	}
	long long ans = a[n] * ((1LL << k) % P) % P;
	for (auto i : edges) {
		vector<pair<int, int> > edge = i.second;
		int cnt = n;
		ans -= a[n]; ans += P; ans %= P;
		for (auto j : edge) {
			int x = j.first, y = j.second;
			if (gf(x) != gf(y))
				--cnt, f[gf(x)] = gf(y);
		}
		ans +=a[cnt]; ans %= P;
		for (auto j : edge) {
			int x = j.first, y = j.second;
			f[x] = x; f[y] = y;
		}
	}
	printf("%lld\n", ans);
}