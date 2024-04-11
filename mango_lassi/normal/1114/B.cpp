#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

const int N = 2 * (int)1e5;
ll vals[N];
bool large[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<pair<ll, int>> ord(n);
	for (int i = 0; i < n; ++i) {
		cin >> vals[i];
		ord[i] = {vals[i], i};
	}
	sort(ord.begin(), ord.end());

	ll res = 0;
	for (int j = n-1; j >= n-k*m; --j) {
		res += ord[j].first;
		large[ord[j].second] = true;
	}

	cout << res << '\n';
	int cou = 0;
	int ccs = 0;
	for (int i = 0; i < n; ++i) {
		if (large[i]) ++cou;
		if (cou == m) {
			cout << i+1 << ' ';
			cou = 0;
			++ccs;
			if (ccs == k-1) break;
		}
	}
	cout << '\n';
}