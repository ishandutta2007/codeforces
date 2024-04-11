#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
	int n;
	cin >> n;
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int ans = 1;
		if (x1 % 2)
			ans++;
		if (y1 % 2)
			ans += 2;
		cout << ans << "\n";
	}
}