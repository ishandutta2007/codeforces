#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 5 * (int)1e5;
vector<int> conns[N];
pair<int, int> res[N];
int siz[N];

int dfs(int i, int p) {
	siz[i] = 1;
	for (auto t : conns[i]) {
		if (t != p) siz[i] += dfs(t, i);
	}
	return siz[i];
}

void solve(int i, int p, int a, int b) {
	int m = (int)conns[i].size() - (p != i);
	int x = b+m;
	res[i] = {a, x};

	int j = 1;
	int s = 1;
	for (auto t : conns[i]) {
		if (t == p) continue;
		solve(t, i, x-j, x+s);
		s += 2*siz[t] - 1;
		++j;
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
	dfs(0, 0);
	solve(0, 0, 0, 1);
	for (int i = 0; i < n; ++i) {
		cout << res[i].first + 1 << ' ' << res[i].second + 1 << '\n';
	}
}