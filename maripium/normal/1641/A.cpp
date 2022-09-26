#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int T; cin >> T;
	while (T--) {
		int N, X; cin >> N >> X;
		multiset<int> st;
		for (int i = 0; i < N; ++i) {
			int a; cin >> a;
			st.insert(a);
		}
		int ans = 0;
		while (!st.empty()) {
			int v = *(--st.end());
			if (v % X == 0 && st.count(v / X)) {
				st.erase(st.find(v / X));
			} else {
				ans ++;
			}
			st.erase(st.find(v));
		}
		cout << ans << '\n';
	}
}