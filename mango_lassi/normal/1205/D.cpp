#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1000;
vector<int> conns[N];
int siz[N];

int dfs(int i, int p, int n) {
	siz[i] = 1;
	int res = -1;
	for (auto t : conns[i]) {
		if (t == p) continue;
		int sub = dfs(t, i, n);
		if (sub != -1) res = sub;
		siz[i] += siz[t];
	}
	if (res == -1 && 2*siz[i] >= n) res = i;
	return res;
}

ll build(int i, int p, ll add, ll mx, ll cur) {
	cout << i+1 << ' ' << p+1 << ' ' << (mx + add - cur) << '\n';
	mx += add;
	cur = mx;
	for (auto t : conns[i]) {
		if (t == p) continue;
		mx = build(t, i, add, mx, cur);
	}
	return mx;
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
	int r = dfs(0, 0, n);
	dfs(r, r, n);

	vector<pair<int, int>> off;
	for (auto t : conns[r]) {
		off.push_back({siz[t], t});
	}
	sort(off.begin(), off.end());

	int h = n / 2; // At most this much in smaller bucket
	vector<int> small;
	vector<int> large;
	for (int j = (int)off.size() - 1; j >= 0; --j) {
		if (off[j].first <= h) {
			h -= off[j].first;
			small.push_back(off[j].second);
		} else {
			large.push_back(off[j].second);
		}
	}
	ll mx = 0;
	for (auto t : small) {
		mx = build(t, r, 1, mx, 0);
	}
	ll mx2 = 0;
	for (auto t : large) {
		mx2 = build(t, r, mx+1, mx2, 0);
	}
}