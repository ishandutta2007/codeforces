#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> hs(n);
	for (ll& h : hs) {
		cin >> h;
	}
	
	// If we subtract i from index i, then slide happens if height is at least one higher
	// Then, initially h[i] <= h[i+1]
	// So at every step, we can store a queue of current heights and how much of that height there is.
	// Using the amount of different heights as a potential function gives a linear time algorithm.

	for (int i = 0; i < n; ++i) hs[i] -= i;

	vector<pair<ll, int>> sta = {{hs[0], 1}};
	for (int i = 1; i < n; ++i) {
		while(true) {
			int m = sta.size();
			ll ini_h = sta[m-1].first;
			int k = sta[m-1].second;
			ll max_h = (m > 1 ? sta[m-2].first : INF);

			ll th = min(max_h, ini_h + (hs[i] - ini_h) / (k+1));
			ll rem = (hs[i] - ini_h) % (k+1);

			if (th == max_h) {
				hs[i] -= (th - ini_h) * k;
				sta.pop_back();
				sta[m-2].second += k;
			} else {
				sta.pop_back();
				if (rem > 0) {
					if (m > 1 && sta[m-2].first == th + 1) sta[m-2].second += rem;
					else sta.emplace_back(th + 1, rem);
				}
				sta.emplace_back(th, (k+1) - rem);
				break;
			}
		}

		// cerr << i << ", sta: ";
		// for (auto pr : sta) cerr << pr.first << ' ' << pr.second << ",   ";
		// cerr << endl;
	}

	for (int i = n; i > 0;) {
		ll v = sta.back().first;
		int k = sta.back().second;
		sta.pop_back();
		// cerr << i-k << ' ' << i << ": " << v << endl;

		for (int j = i-k; j < i; ++j) hs[j] = v + j;
		i -= k;
	}

	for (int i = 0; i < n; ++i) cout << hs[i] << ' '; cout << '\n';
}