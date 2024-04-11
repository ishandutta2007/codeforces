#include <bits/stdc++.h>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
using namespace std;
typedef pair<int, int> pii;
const int N = 500 + 10;
int n, c[N][N];
ll u[N][N], d[N][N], l[N][N], r[N][N], row[N], col[N];
ll calc(int x, int y) {
	ll ans = 1e18;
	ans = min(ans, u[x][y] + l[x][y] - c[x][y]);
	ans = min(ans, l[x][y] + d[x][y] - c[x][y]);
	ans = min(ans, d[x][y] + r[x][y] - c[x][y]);
	ans = min(ans, r[x][y] + u[x][y] - c[x][y]);
	return ans;
}
void solve() {
	cin >> n;
	for(int i = 1; i <= n * 2; i++) {
		for(int j = 1; j <= n * 2; j++) {
			cin >> c[i][j];
		}
	}
	for(int i = 0; i <= n * 2 + 1; i++) for(int j = 0; j <= n * 2 + 1; j++) u[i][j] = d[i][j] = l[i][j] = r[i][j] = 0;
	for(int i = 0; i <= n * 2 + 1; i++) row[i] = col[i] = 0;
	for(int i = 1; i <= n; i++) {
		col[i] = col[i - 1];
		row[i] = row[i - 1];
		for(int j = n + 1; j <= 2 * n; j++) col[i] += c[i][j], row[i] += c[j][i];
	}
	ll sum = 0;
	for(int i = n + 1; i <= n * 2; i++) {
		for(int j = n + 1; j <= n * 2; j++) {
			sum += c[i][j];
			c[i][j] = 0;
		}
	}
	for(int i = 1; i <= n * 2; i++) {
		for(int j = 1; j <= n * 2; j++) {
			u[i][j] = u[i - 1][j] + c[i][j];
			l[i][j] = l[i][j - 1] + c[i][j];
		}
	}
	for(int i = n * 2; i >= 1; i--) {
		for(int j = n * 2; j >= 1; j--) {
			r[i][j] = r[i][j + 1] + c[i][j];
			d[i][j] = d[i + 1][j] + c[i][j];
		}
	}
	ll ans = 1e18;
	for(int i = 1; i <= n; i++) {
		for(int j = n + 1; j <= n * 2; j++) {
			ll add = min(row[n] - row[j - n], row[j - n - 1]);
			ans = min(ans, calc(i, j) + add);
		}
	}
	for(int i = n + 1; i <= n * 2; i++) {
		for(int j = 1; j <= n; j++) {
			ll add = min(col[n] - col[i - n], col[i - n - 1]);
			ans = min(ans, calc(i, j) + add);
		}
	}
	cout << sum + ans << endl;
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	for(cin >> t; t--; solve());
    return 0;
}