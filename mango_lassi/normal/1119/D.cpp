#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	sort(s.begin(), s.end());

	vector<ll> d(n-1);
	for (int i = 0; i+1 < n; ++i) {
		d[i] = s[i+1] - s[i];
	}
	sort(d.begin(), d.end());

	int q;
	cin >> q;

	vector<ll> ans(q);
	vector<pair<ll, int>> ques(q);
	for (int i = 0; i < q; ++i) {
		ll l, r;
		cin >> l >> r;
		ques[i] = {r-l+1, i};
	}
	sort(ques.begin(), ques.end());

	int j = 0;
	ll pv = 0;
	ll cou = 0;
	for (int i = 0; i < q; ++i) {
		ll v = ques[i].first;
		while((j < d.size()) && (d[j] <= v)) {
			cou += (d[j] - pv) * (n-j);
			pv = d[j];
			++j;
		}
		cou += (v - pv) * (n-j);
		pv = v;
		ans[ques[i].second] = cou;
	}

	for (int i = 0; i < q; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}