#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		string S; cin >> S;
		if (S.size() == 2) cout << S[1] << '\n';
		else cout << *min_element(S.begin(), S.end()) << '\n';
	}
}