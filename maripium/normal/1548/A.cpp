#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int N, M; cin >> N >> M;

	int ans = N;
	vector<int> cnt(N);
	auto add_edge = [&](int v, int u) {
		if (v > u) swap(v, u);
		if (++cnt[v] == 1) ans--;
	};
	auto remove_edge = [&](int v, int u) {
		if (v > u) swap(v, u);
		if (--cnt[v] == 0) ans++;
	};

	for (int i = 0; i < M; ++i) {
		int v, u; cin >> v >> u;
		add_edge(--v, --u);
	}

	int Q; cin >> Q;
	while (Q--) {
		int op; cin >> op;
		if (op == 1) {
			int v, u; cin >> v >> u;
			add_edge(--v, --u);
		} else if (op == 2) {
			int v, u; cin >> v >> u;
			remove_edge(--v, --u);
		} else {
			cout << ans << '\n';
		}
	}
	return 0;
}