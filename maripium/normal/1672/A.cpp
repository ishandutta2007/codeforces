#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int tot = 0;
		for (int i = 0; i < N; ++i) {
			int a; cin >> a;
			tot += a - 1;
		}
		if (tot & 1) {
			cout << "errorgorn\n";
		} else {
			cout << "maomao90\n";
		}
	}
}