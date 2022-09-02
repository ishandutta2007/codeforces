#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2 * (int)1e5;
set<int> nbs[N];
int res = 0;

bool counts(int i) {
	auto it = nbs[i].end();
	--it;
	return (*it) == i;
}

void solve() {
	int n, m;
	cin >> n >> m;

	for (int j = 0; j < m; ++j) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		nbs[a].insert(b);
		nbs[b].insert(a);
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		nbs[i].insert(i);
		res += counts(i);
	}

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		int t;
		cin >> t;
		if (t == 3) cout << res << '\n';
		else {
			int a, b;
			cin >> a >> b;
			--a; --b;

			res -= counts(a);
			res -= counts(b);
			if (t == 1) {
				nbs[a].insert(b);
				nbs[b].insert(a);
			} else {
				nbs[a].erase(b);
				nbs[b].erase(a);
			}
			res += counts(a);
			res += counts(b);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}