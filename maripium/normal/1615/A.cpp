#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int tot = 0;
		vector<int> A(N); for (int &a : A) cin >> a, tot += a;
		cout << (tot % N ? 1 : 0) << '\n';

	}
	return 0;
}