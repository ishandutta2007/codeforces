#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (int &a : A) cin >> a, --a;
		vector<vector<int>> loc(N);
		for (int i = 0; i < N; ++i) loc[A[i]].push_back(i);
		vector<int> B(N);
		while (loc.size()) {
			vector<int> cyc;
			vector<vector<int>> nloc;
			for (auto& v : loc) {
				if (v.empty()) continue;
				cyc.push_back(v.back());
				v.pop_back();
				if (v.empty()) continue;
				nloc.push_back(move(v));
			}
			for (int i = 0; i < int(cyc.size()); ++i) {
				B[cyc[i]] = A[cyc[(i + 1) % cyc.size()]];
			}
			loc = move(nloc);
		}

		for (int b : B) cout << b + 1 << ' '; cout << '\n';
	}
	return 0;
}