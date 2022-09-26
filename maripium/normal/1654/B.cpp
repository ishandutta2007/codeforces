#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		string S; cin >> S;
		int N = int(S.size());
		map<char, int> last;
		for (int i = 0; i < N; ++i) last[S[i]] = i;
		int st = N;
		for (auto [c, v] : last) st = min(st, v);
		cout << S.substr(st) << '\n';
	}
}