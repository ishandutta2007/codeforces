#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

bool exists(const multiset<ll>& s, ll low, ll high) {
	auto it = s.lower_bound(low);
	return !((it == s.end()) || (*it > high));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	multiset<ll> bs;
	for (int i = 0; i < n; ++i) {
		ll v;
		cin >> v;
		bs.insert(v);
	}

	bool fail = false;
	vector<ll> res;
	
	ll val = 0;
	while(! bs.empty()) {
		bool found = false;
		for (int j = 0; (! found) && (j < 60); ++j) {
			ll bit = 1ll << j;
			if (val & bit) continue;
			
			ll low = bit;
			ll high = 2*bit-1;
			if (exists(bs, low, high)) {
				// Pick best
				while(bit > 1) {
					bit >>= 1;
					if (low & high & bit) continue;

					ll mid = low ^ bit;
					if (val & bit) {
						if (exists(bs, mid, high)) low = mid;
						else high = mid-1;
					} else {
						if (exists(bs, low, mid-1)) high = mid-1;
						else low = mid;
					}
				}
				
				auto it = bs.find(low);
				res.push_back(*it);
				val ^= *it;
				bs.erase(it);

				found = true;
			}
		}
		if (! found) {
			fail = true;
			break;
		}
	}

	if (fail) {
		cout << "No\n";
		// for (auto v : res) cout << v << ' '; cout << '\n';
	} else {
		cout << "Yes\n";
		for (auto v : res) cout << v << ' '; cout << '\n';
	}
}