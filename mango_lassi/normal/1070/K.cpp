#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int N = 1e5;
int vals[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; ++i) cin >> vals[i];
	
	ll sum = 0;
	for (int i = 0; i < n; ++i) sum += vals[i];

	bool fail = false;
	if (sum % k != 0) fail = true;

	if (! fail) {
		ll tar = sum / k;
		ll cur = 0;
		vector<int> ss;
		for (int i = 0; i < n; ++i) {
			cur += vals[i];
			if (cur >= tar) {
				if (cur > tar) fail = true;
				ss.push_back(i);
				cur = 0;
			}
		}
		if (ss.size() != k) {
			fail = true;
		} else {
			for (int i = 0; i < k; ++i) ++ss[i];
			for (int i = k-1; i > 0; --i) ss[i] -= ss[i-1];

			cout << "Yes\n";
			for (auto v : ss) cout << v << ' '; cout << '\n';
		}
	}
	if (fail) {
		cout << "No\n";
	}
}