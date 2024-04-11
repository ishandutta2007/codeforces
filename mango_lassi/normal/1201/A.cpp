#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int M = 1000;
const int C = 5;
int cou[M][C];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j) ++cou[j][str[j] - 'A'];
	}
	ll res = 0;
	for (int j = 0; j < m; ++j) {
		ll a;
		cin >> a;
		int mx = 0;
		for (int c = 0; c < C; ++c) mx = max(mx, cou[j][c]);
		res += mx * a;
	}
	cout << res << '\n';
}