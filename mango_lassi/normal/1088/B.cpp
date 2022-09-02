#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	set<ll> vals;
	for (int i = 0; i < n; ++i) {
		ll v;
		cin >> v;
		vals.insert(v);
	}
	
	ll add = 0;
	for (int j = 0; j < k; ++j) {
		if (vals.empty()) {
			cout << "0 ";
		} else {
			auto it = vals.begin();
			if ((*it) + add == 0) ++it;
			if (it == vals.end()) {
				cout << "0 ";
			} else {
				cout << *it + add << " ";
				add -= *it + add;
			}
			while(! vals.empty()) {
				it = vals.find(-add);
				if (it != vals.end()) vals.erase(it);
				else break;
			}
		}
	}
	cout << '\n';
}