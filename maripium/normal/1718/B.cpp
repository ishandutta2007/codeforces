#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	vector<int64_t> fibs;
	fibs.push_back(1);
	fibs.push_back(1);
	for (int i = 2; i < 60; ++i) {
		fibs.push_back(fibs[i - 1] + fibs[i - 2]);
	}
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int64_t> A(N); for (auto &a : A) cin >> a;
		auto solve = [&]() {
			int64_t tot = accumulate(A.begin(), A.end(), int64_t(0));
			int m;
			for (m = 0; m < 60; ++m) {
				tot -= fibs[m];
				if (tot <= 0) break;
			}
			if (tot < 0) return false;
			priority_queue<int64_t> pq;
			for (int i = 0; i < N; ++i) pq.push(A[i]);
			int64_t prv = -1;
			for (int i = m; i >= 0; --i) {
				if (pq.empty()) return false;
				int64_t nxt = pq.top(); pq.pop();
				if (nxt < fibs[i]) return false;
				nxt -= fibs[i];
				if (prv > 0) pq.push(prv);
				prv = nxt;
			}
			return true;
		};
		if (solve()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}