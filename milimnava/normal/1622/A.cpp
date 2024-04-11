#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int a[3];
		for (int i = 0; i <= 2; i++) cin >> a[i];
		sort(a, a + 3);
		if (a[2] == a[0] + a[1]) cout << "YES" << endl;
		else if (a[0] == a[1] && a[2] % 2 == 0) cout << "YES" << endl;
		else if (a[1] == a[2] && a[0] % 2 == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}