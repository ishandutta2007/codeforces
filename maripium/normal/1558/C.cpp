#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (int &a : A) cin >> a, --a;
		{
			bool fail = false;
			for (int i = 0; i < N; ++i) {
				if (A[i] + i & 1) fail = true;
			}
			if (fail) {
				cout << "-1\n";
				continue;
			}
		}
		vector<int> ops;
		auto rev = [&](int L) {
			ops.push_back(L);
			reverse(A.begin(), A.begin() + L);
		};
		for (int v = N - 1; v > 0; v -= 2) {
			int loc = find(A.begin(), A.end(), v) - A.begin();
			rev(loc + 1);
			loc = find(A.begin(), A.end(), v - 1) - A.begin();
			rev(loc);
			rev(loc + 2);
			rev(3);
			rev(v + 1);
		}
		cout << int(ops.size()) << '\n';
		for (int v : ops) cout << v << ' '; cout << '\n';
	}
}