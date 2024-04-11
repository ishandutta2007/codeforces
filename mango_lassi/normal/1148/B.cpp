#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	ll t1, t2;
	cin >> n >> m >> t1 >> t2 >> k;
	
	vector<ll> ta(n);
	for (int i = 0; i < n; ++i) cin >> ta[i];
	vector<ll> tb(m);
	for (int i = 0; i < m; ++i) {
		cin >> tb[i];
		tb[i] -= t1;
	}
	sort(ta.begin(), ta.end());
	sort(tb.begin(), tb.end());

	// Cancel prefix of flights from A, Then rest from B of those that have >= than last blocked of A
	ll res = 0;
	int j = 0;
	for (int i = 0; i < min(n, k+1); ++i) {
		while((j < m) && (tb[j] < ta[i])) ++j;
		if (j + (k-i) >= m) {
			res = INF;
		} else {
			res = max(res, tb[j+k-i] + t1 + t2);
		}
	}
	if (k >= n) res = INF;

	if (res == INF) cout << "-1\n";
	else cout << res << '\n';
}