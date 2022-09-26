#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int64_t> A(N); for (auto &a : A) cin >> a;
		bool ok = true;
		int64_t sum = 0;
		bool hit0 = false;
		for (auto a : A) {
			sum += a;
			if (sum < 0) {
				ok = false;
			} else if (sum == 0) {
				hit0 = true;
			} else {
				if (hit0) {
					ok = false;
					break;
				}
			}
		}
		if (sum) {
			ok = false;
		}
		if (ok) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	return 0;
}