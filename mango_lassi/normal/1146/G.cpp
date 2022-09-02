#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 50;
ll dp[N][N][N+1]; // Max money we earn from interval a to b, when building to max height h
// Effective penalty intervals are the ones with height < c and entirely contained in the current interval.

// Penalties
vector<int> ls;
vector<int> rs;
vector<int> xs;
vector<int> cs;

void solve(int a, int b, int h) {
	for (int i = a; i <= b; ++i) {
		vector<pair<int, int>> pens;
		for (int j = 0; j < ls.size(); ++j) {
			if (a <= ls[j] && ls[j] <= i && i <= rs[j] && rs[j] <= b) {
				pens.push_back({xs[j], cs[j]});
			}
		}
		sort(pens.begin(), pens.end());

		int pj = 0;
		ll pen = 0;
		for (int l = 0; l <= h; ++l) {
			while ((pj < pens.size()) && (pens[pj].first < l)) {
				pen += pens[pj].second;
				++pj;
			}
			ll val = 0;
			val += (i > a ? dp[a][i-1][l] : 0);
			val += (i < b ? dp[i+1][b][l] : 0);
			val += l*l - pen;
			dp[a][b][l] = max(dp[a][b][l], val);
		}
	}
	for (int l = 1; l <= h; ++l) {
		dp[a][b][l] = max(dp[a][b][l], dp[a][b][l-1]);
	}
}

// Loop the tallest building. Divide and conquer.
// Left and right sides have to have less than or equal heights.
// That way the maximum element decides for all intervals it intersects whether they get broken or not
// and intervals that are active for the subproblems are completely contained in those subintervals.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, h, m;
	cin >> n >> h >> m;

	ls.resize(m);
	rs.resize(m);
	xs.resize(m);
	cs.resize(m);
	for (int i = 0; i < m; ++i) {
		cin >> ls[i] >> rs[i] >> xs[i] >> cs[i];
		ls[i] -= 1;
		rs[i] -= 1;
	}

	for (int len = 0; len < n; ++len) {
		for (int a = 0; a + len < n; ++a) {
			solve(a, a + len, h);
		}
	}
	cout << dp[0][n-1][h] << '\n';
}