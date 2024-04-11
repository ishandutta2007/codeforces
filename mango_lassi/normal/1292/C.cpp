#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 3000;
const int M = N-1;
vector<int> conns[N];
pair<int, int> ed[2*M];

pair<ll, ll> off[N][2*M];
int opt[N][2*M];
ll siz[2*M];

void dfs(int j) {
	siz[j] = 1;
	int p = ed[j].first;
	int i = ed[j].second;
	for (auto ei : conns[i]) {
		int t = ed[ei].second;
		if (t == p) continue;

		if (siz[ei] == 0) dfs(ei);
		siz[j] += siz[ei];
	}
}
ll upd(int a, int b) {
	int i = ed[a].second;

	if (opt[i][b] == (a^1)) return off[i][b].second;
	else return off[i][b].first;
}
void fix(int a, int b, ll v) {
	int p = ed[a].first;
	if (off[p][b].first < v) {
		opt[p][b] = a;
		swap(off[p][b].first, v);
		swap(off[p][b].second, v);
	} else if (off[p][b].second < v && opt[p][b] != a) {
		swap(off[p][b].second, v);
	}
}
ll calc(int a, int b) {
	ll off0 = upd(a, b);
	ll off1 = upd(b, a);
	ll v = siz[a] * siz[b] + max(off0, off1);
	fix(a, b, v);
	fix(b, a, v);
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int m = n-1;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		ed[2*i] = {a, b};
		ed[2*i+1] = {b, a};
		conns[a].push_back(2*i);
		conns[b].push_back(2*i+1);
	}
	vector<pair<int, int>> ord(2*m);
	for (int i = 0; i < 2*m; ++i) {
		if (siz[i] == 0) dfs(i);
		ord[i] = {siz[i], i};
		for (int j = 0; j < n; ++j) opt[j][i] = -1;
	}
	sort(ord.begin(), ord.end());

	ll res = 0;
	for (auto pr1 : ord) {
		int i = pr1.second;
		for (auto pr2 : ord) {
			int j = pr2.second;
			ll v = calc(i, j);
			if ((i^j) == 1) res = max(res, v);
		}
	}
	cout << res << '\n';
}