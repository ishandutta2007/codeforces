#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, K; cin >> N >> K;
	if (N % 2 == 1 && K % 2 == 0) {
		cout << "-1\n";
		return 0;
	}
	int ops = 0;
	auto solve = [&]() {
		if (ops * K < N) return;
		if ((ops * K - N) % 2) return;
		int extra = (ops * K - N) / 2;
		vector<int> cnts(N, 1);
		for (int i = 0; i < extra; ++i) {
			cnts[i % N] += 2; 
		}
		if (ops < *max_element(cnts.begin(), cnts.end())) return;
		vector<int> ids(N); iota(ids.begin(), ids.end(), 0);
		int ans = 0;
		for (int i = 0; i < ops; ++i) {
			sort(ids.begin(), ids.end(), [&](const int &x, const int &y) {
				return cnts[x] > cnts[y];
			});
			cout << '?';
			for (int j = 0; j < K; ++j) {
				cout << ' ' << ids[j] + 1;
				cnts[ids[j]]--;
			}
			cout << '\n';
			cout << flush;
			int cnd; cin >> cnd;
			ans ^= cnd;
		}
		cout << "! " << ans << '\n';
		cout << flush;
		exit(0);
	};

	while (true) {
		solve();
		ops++;
	}
}