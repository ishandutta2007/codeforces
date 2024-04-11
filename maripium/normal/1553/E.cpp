#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int Q; cin >> Q;
	while (Q--) {
		int N, M; cin >> N >> M;
		vector<int> P(N); for (int &a : P) cin >> a, --a;
		// shift K P[i] -> NP[(i + K) % N] 
		map<int, int> mp;
		for (int i = 0; i < N; ++i) {
			mp[(i - P[i] + N) % N] ++;
		}
		vector<int> ans;
		for (auto [k, c] : mp) {
			if (c >= N - 2 * M) {
				vector<int> Q(N);
				for (int i = 0; i < N; ++i) Q[i] = P[(i + k) % N];
				vector<int> invQ(N);
				for (int i = 0; i < N; ++i) invQ[Q[i]] = i;
				int ops = 0;
				for (int i = 0; i < N; ++i) {
					int j = invQ[i];
					if (i == j) continue;
					swap(Q[i], Q[j]);
					ops++;
					invQ[Q[i]] = i;
					invQ[Q[j]] = j;
				}
				if (ops <= M) ans.push_back(k);
			}
		}
		cout << int(ans.size());
		for (int v : ans) cout << ' ' << v; cout << '\n';
	}	
	return 0;
}