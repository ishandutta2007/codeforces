#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
#define sz(a) (int)a.size()
const int mod = 1e9 + 7;

const int N = 2100;

int dp_left[N][2 * N + 1];
int dp_right[N][2 * N + 1];

void add_mod(int &a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		for (int i = 0; i < n; i += 2) {
			if (a[i] == '0') {
				a[i] = '1';
			}
			else if (a[i] == '1') {
				a[i] = '0';
			}
			if (b[i] == '0') {
				b[i] = '1';
			}
			else if (b[i] == '1') { 
				b[i] = '0';
			}
		}
		//cout << a << "\n" << b << "\n";
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= 2 * n; j++) {
				dp_left[i][j] = dp_right[i][j] = 0;
			}
		}
		dp_left[0][n] = 1;
		dp_right[n][n] = 1;
		for (int i = 1; i <= n; i++) {
			for (int x = 0; x < 2; x++) {
				if (a[i - 1] != '?' && a[i - 1] - '0' != x) {
					continue;
				}
				for (int y = 0; y < 2; y++) {
					if (b[i - 1] != '?' && b[i - 1] - '0' != y) {
						continue;
					}
					int add = x - y;
					for (int bal = 0; bal <= 2 * n; bal++) {
						if (bal + add < 0 || bal + add > 2 * n) {
							continue;
						}
						add_mod(dp_left[i][bal + add], dp_left[i - 1][bal]);
					}
				}
			}
		}
	//	cout << dp_left[1][n + 1] << "\n";
		for (int i = n - 1; i >= 0; i--) {
			for (int x = 0; x < 2; x++) {
				if (a[i] != '?' && a[i] - '0' != x) {
					continue;
				}
				for (int y = 0; y < 2; y++) {
					if (b[i] != '?' && b[i] - '0' != y) {
						continue;
					}
					int add = x - y;
					for (int bal = 0; bal <= 2 * n; bal++) {
						if (bal + add < 0 || bal + add > 2 * n) {
							continue;
						}
						add_mod(dp_right[i][bal + add], dp_right[i + 1][bal]);
					}
				}
			}
		}
		//cout << dp_right[1][n - 1] << "\n";
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= 2 * n; j++) {
				add_mod(ans, 1LL * abs(j - n) * dp_left[i][j] % mod * dp_right[i][2 * n - j] % mod);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}