#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int a, b, c, d;
		cin >> a >> c >> b >> d;
		int e = min(c, d);
		c -= e; d -= e;
		if (abs(c - d) > 8) {
			if (c > d) cout << ">" << endl;
			else cout << "<" << endl;
		} else {
			long long A = a, B = b;
			for (int i = 1; i <= c; i++) A *= 10;
			for (int i = 1; i <= d; i++) B *= 10;
			if (A > B) cout << ">" << endl;
			else if (A < B) cout << "<" << endl;
			else cout << "=" << endl;
		}
	}
	return 0;
}