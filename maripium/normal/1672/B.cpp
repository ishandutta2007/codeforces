#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		string S; cin >> S;
		int bal = 0;
		bool fail = false;
		for (char c : S) {
			if (c == 'A') bal ++;
			else {
				bal --;
				if (bal < 0) {
					fail = true;
					break;
				}
			}
		}

		if (S.back() == 'A') fail = true;
		cout << (fail ? "NO" : "YES") << '\n';
	}
	return 0;
}