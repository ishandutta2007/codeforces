#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int N = 2 * (int)1e5;
int par[N];
vector<int> lrs[N];

bool can(ll n, ll s, ll d) {
	ll low = 0;
	ll mult = 1;
	for (ll dep = 1; n > 0; ++dep) {
		low += dep * min(mult, n);
		n -= min(mult, n);
		mult *= d;
	}
	return (low <= s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, s;
	cin >> n >> s;
	// Possible IFF 2n-1 <= s <= n(n+1)/2
	// Certain D possible if can(n, s, d)

	if ((s < 2*n-1) || (s > n * (n+1) / 2)) {
		cout << "No\n";
	} else if (n == 1) {
		cout << "Yes\n";
		cout << '\n';
	} else {
		ll d = 1;
		while(! can(n, s, d)) ++d;

		ll sum = n * (n+1) / 2;
		for (int i = 0; i < n; ++i) {
			lrs[i].push_back(i);
		}

		int low = 1;
		int high = n-1;
		while(sum > s) {
			while (lrs[low].size() >= lrs[low-1].size() * d) ++low;
			while(lrs[high].empty()) --high;

			ll dif = min((ll)(high - low), sum - s);
			sum -= dif;

			int i = lrs[high].back();
			lrs[high].pop_back();
			lrs[high-dif].push_back(i);
		}


		// Print ans
		for (int j = 1; j < n; ++j) {
			for (int i = 0; i < lrs[j].size(); ++i) {
				par[lrs[j][i]] = lrs[j-1][i/d];
			}
		}
		cout << "Yes\n";
		for (int i = 1; i < n; ++i) cout << par[i]+1 << ' '; cout << '\n';
	}
}