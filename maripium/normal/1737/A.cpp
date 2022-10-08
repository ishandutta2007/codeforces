#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		vector<int> cnt(26);
		string S; cin >> S;
		for (char c : S) cnt[c - 'a']++;

		for (int i = 0; i < K; ++i) {
			int mex = 0;
			while (mex < N / K && cnt[mex] > 0) {
				cnt[mex]--;
				mex++;
			}
			cout << char(mex + 'a');
		}
		cout << '\n';
	}
}