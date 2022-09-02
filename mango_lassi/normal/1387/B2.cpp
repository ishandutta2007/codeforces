#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5;
vector<int> conns[N];
int ord[N];
int res[N];
int siz[N];

ll dfs1(int i, int p, int n) {
	siz[i] = 1;
	ll ans = 0;
	for (auto t : conns[i]) {
		if (t == p) continue;
		ans += dfs1(t, i, n);
		ans += 2*min(siz[t], n - siz[t]);
		siz[i] += siz[t];
	}
	return ans;
}


void dfs2(int i, int p, int& j) {
	ord[j] = i;
	++j;

	for (auto t : conns[i]) {
		if (t != p) dfs2(t, i, j);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	
	// Move over every edge exactly min(left-size, right-size)
	// What kind of permutations are good? we just need that nothing remains on that side of the subtree
	// -> 1. Take small side of the subtree, swap them with arbitrary elements on the right side of the subtree, forget the left side of the subtree

	ll ans = dfs1(0, -1, n);
	cout << ans << '\n';
	
	int j = 0;
	dfs2(0, -1, j);

	int h = n/2;
	for (int i = 0; i < n; ++i) res[ord[i]] = ord[(i + h) % n];
	for (int i = 0; i < n; ++i) cout << res[i] + 1 << ' ' ; cout << '\n';
}