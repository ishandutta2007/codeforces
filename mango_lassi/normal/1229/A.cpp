#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<pair<ll, ll>> as(n);
	for (int i = 0; i < n; ++i) cin >> as[i].first;
	for (int i = 0; i < n; ++i) cin >> as[i].second;
	sort(as.begin(), as.end());
	
	ll res = 0;
	vector<ll> act;
	for (int i = n-1; i >= 0;) {
		int j = i;
		ll off = 0;
		while(j >= 0 && as[j].first == as[i].first) {
			off += as[j].second;
			--j;
		}

		bool works = (i - j) >= 2;
		if (works) act.push_back(as[i].first);
		else {
			for (ll v : act) {
				if ((as[i].first | v) == v) works = true;
			}
		}

		if (works) res += off;
		i = j;

	}
	cout << res << '\n';
}