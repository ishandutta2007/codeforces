#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 2 * (int)1e5;
const int C = 26;
int cou[N+1][C];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int n, m;
		cin >> n >> m;
		string str;
		cin >> str;
		for (int i = 1; i <= n; ++i) {
			for (int c = 0; c < C; ++c) cou[i][c] = cou[i-1][c];
			++cou[i][str[i-1] - 'a'];
		}

		vector<ll> res(C, 0);
		for (int j = 0; j < m; ++j) {
			int p;
			cin >> p;
			for (int c = 0; c < C; ++c) res[c] += cou[p][c];
		}
		for (int c = 0; c < C; ++c) {
			res[c] += cou[n][c];
			cout << res[c] << ' ';
		}
		cout << '\n';
	}
}