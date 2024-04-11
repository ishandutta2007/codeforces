#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

const int N = 3 * (int)1e5;
ll fact[N + 1];

template<class T>
ll dupcou(const vector<T>& vec) {
	ll res = 1;
	for (int i = 0; i < vec.size(); ++i) {
		int j = i;
		while(j+1 < vec.size() && vec[j+1] == vec[i]) ++j;
		res = (res * fact[j-i+1]) % MOD;
		i = j;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	fact[0] = 1;
	for (int i = 1; i <= n; ++i) fact[i] = (fact[i-1] * i) % MOD;

	// Number of permutations that make it bad by first
	// Number of permutations that make it bad by second
	// Number of permutations that make it bad by both

	vector<int> as(n);
	vector<int> bs(n);
	vector<pair<int, int>> prs(n);
	for (int i = 0; i < n; ++i) {
		cin >> as[i] >> bs[i];
		prs[i] = {as[i], bs[i]};
	}
	sort(as.begin(), as.end());
	sort(bs.begin(), bs.end());
	sort(prs.begin(), prs.end());

	ll v1 = fact[n];
	ll v2 = dupcou(as);
	ll v3 = dupcou(bs);
	ll v4 = dupcou(prs);
	for (int i = 1; i < n; ++i) {
		if (prs[i].second < prs[i-1].second) v4 = 0;
	}

	ll res = (v1 - v2 - v3 + v4) % MOD;
	if (res < 0) res += MOD;
	cout << res << '\n';
}