#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		string S; cin >> S;
		while (M--) {
			vector<int> nxt;
			for (int i = 0; i < N; ++i) if (S[i] == '0') {
				int cnt = 0;
				if (i) cnt += S[i - 1] == '1';
				if (i + 1 < N) cnt += S[i + 1] == '1';
				if (cnt == 1) nxt.push_back(i);
			}
			if (nxt.empty()) break;
			for (int v : nxt) S[v] = '1';
		}
		cout << S << '\n';
	}
}