#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = (ll)1e9 + 7;

const int N = 1e3;
ll vals[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> vals[y][x];
		}
	}

	ll t = vals[0][1] * vals[0][2] / vals[1][2];
	ll low = 0;
	ll high = INF;
	while(low != high) {
		ll mid = (low + high) >> 1;
		if (mid * mid < t) low = mid + 1;
		else high = mid;
	}

	vector<ll> ans(n, 0);
	ans[0] = low;
	for (int i = 1; i < n; ++i) ans[i] = vals[0][i] / ans[0];
	for (auto v : ans) cout << v << ' '; cout << '\n';
}