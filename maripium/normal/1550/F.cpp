#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, Q, S, D; cin >> N >> Q >> S >> D; --S;
	const int INF = 1e9;
	vector<int> A(N); for (int &a : A) cin >> a;
	vector<array<int, 3>> dists(N, array<int, 3>{INF, INF, INF}); // (real, from left, from right)
	using pq_type = tuple<int, int, int>;

	priority_queue<pq_type, vector<pq_type>, greater<pq_type>> hp;
	
	auto update = [&](int v, int t, int d) {
		if (dists[v][t] > d) {
			dists[v][t] = d;
			hp.push(make_tuple(d, v, t));
		}
	};
	set<int> alive; for (int i = 0; i < N; ++i) alive.insert(i);
	update(S, 0, 0);
	while (!hp.empty()) {
		auto [d, v, t] = hp.top(); hp.pop();
		if (dists[v][t] != d) continue;
		if (t == 0) {
			alive.erase(v);
			for (int loc : {A[v] - D, A[v] + D}) {
				int l = lower_bound(A.begin(), A.end(), loc - dists[v][0]) - A.begin();
				int r = lower_bound(A.begin(), A.end(), loc + dists[v][0] + 1) - A.begin();
				for (auto it = alive.lower_bound(l); it != alive.end() && *it < r; it = alive.erase(it)) {
					update(*it, 0, dists[v][0]);
				}
				if (r < N) update(r, 1, A[r] - loc);
				if (l) update(l - 1, 2, loc - A[l - 1]);
			}
		} else if (t == 1) {
			update(v, 0, d);
			if (v + 1 < N) update(v + 1, t, d + A[v + 1] - A[v]);
		} else if (t == 2) {
			update(v, 0, d);
			if (v) update(v - 1, t, d + A[v] - A[v - 1]);
		}
	}
	while (Q--) {
		int i, k; cin >> i >> k; --i;
		if (dists[i][0] <= k) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	return 0;
}