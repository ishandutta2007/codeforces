#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> p(n + 1), pre(n + 1), ans(n + 1);
		vector<char> c(n + 1);
		for (int i = 1; i <= n; i++) cin >> p[i], pre[p[i]] = i;
		int id[2] = {0, 0};
		for (int i = 1; i <= n; i++) {
			cin >> c[i];
			if (c[i] == '0') ++id[1];
		}
		for (int i = 1; i <= n; i++) {
			if (c[pre[i]] == '0') ans[pre[i]] = ++id[0];
			else ans[pre[i]] = ++id[1];
		}
		for (int i = 1; i <= n; i++) cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}