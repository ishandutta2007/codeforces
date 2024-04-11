#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int64_t A, B, C; cin >> A >> B >> C;
		cout << A + B + C << ' ' << B + C << ' ' << C << '\n';
	}
	return 0;
}