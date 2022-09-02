#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1e18;


int main() {
	int n;
	cin >> n;

	vector<int> probs(n);
	for (int i = 0; i < n; ++i) cin >> probs[i];
	sort(probs.begin(), probs.end());

	vector<int> counts = {1};
	for (int i = 1; i < n; ++i) {
		if (probs[i] != probs[i-1]) counts.push_back(1);
		else ++counts.back();
	}
	sort(counts.begin(), counts.end());
	
	ll res = 0;
	ll lim = INF;
	int cs = counts.size();
	for (int i = cs - 1; i >= 0; --i) {
		lim = min(lim / 2, (ll)counts[i]);
		if (lim == 0) break;
		res = max(res, lim * ((((ll)1)<<(cs-i)) - 1));
	}
	cout << res << '\n';
}