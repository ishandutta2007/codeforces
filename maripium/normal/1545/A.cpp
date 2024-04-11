#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<pair<int, int>> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i].first;
			A[i].second = i;		
		}
		sort(A.begin(), A.end());
		map<int, array<int, 2>> mp;
		for (int i = 0; i < N; ++i) {
			mp[A[i].first][i & 1]++;
			mp[A[i].first][A[i].second & 1] --;
		}
		bool fail = false;
		for (auto [_, v] : mp) {
			if (v[0] || v[1]) {
				fail = true;
			}
		}
		cout << (fail ? "NO" : "YES") << '\n';
	}	
	return 0;
}