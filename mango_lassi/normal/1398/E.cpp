#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;

struct HighSum {
	int m = 0; // Max amount of elements in high part
	ll sum = 0; // Sum of elements in high part
	multiset<int> low, high;

	void incCou() {
		++m;
		while(high.size() < m && low.size() > 0) {
			auto it = low.end();
			--it;
			sum += *it;
			high.insert(*it);
			low.erase(it);
		}
	}
	void decCou() {
		--m;
		while(high.size() > max(0, m)) {
			auto it = high.begin();
			sum -= *it;
			low.insert(*it);
			high.erase(it);
		}
	}
	void add(int v) {
		sum += v;
		high.insert(v);
		++m;
		decCou();
	}
	void erase(int v) {
		auto it = high.find(v);
		if (it != high.end()) {
			sum -= v;
			high.erase(it);

			--m;
			incCou();
		} else {
			it = low.find(v);
			low.erase(it);
		}
	}
};

void solve() {
	// Say we have n FIRE and m LIGHTNING spells. We can double any m spells we want, except all m LIGHTNING spells.
	// So answer is SUM + max fire + m-1 other maximum values

	// Store fire spells and lightning spells in a multiset. Store maximum fire spell, m-1 maximum other spells,
	// and all other spells in separate sets.

	int q;
	cin >> q;

	ll sum = 0; // Total sum of spells
	multiset<int> fire = {0}; // Fire spells
	HighSum oth; // All spells but strongest fire spell
	oth.decCou(); // Initially m is -1

	for (int qi = 0; qi < q; ++qi) {
		int t, v;
		cin >> t >> v;
		sum += v;
		if (t == 0) {
			// Fire spell
			if (v > 0) {
				auto it = fire.end();
				--it;
				oth.add(min(*it, v));
				fire.insert(v);
			} else {
				auto it = fire.find(-v);
				auto it2 = it;
				++it2;
				if (it2 == fire.end()) {
					auto it3 = it;
					--it3;
					if (it3 != fire.begin()) oth.erase(*it3);
				} else {
					oth.erase(*it);
				}
				fire.erase(it);
			}
		} else {
			// Lightning spell
			if (v > 0) {
				oth.incCou();
				oth.add(v);
			} else {
				oth.decCou();
				oth.erase(-v);
			}
		}
		
		auto it = fire.end();
		--it;
		int fire_mx = *it;

		cout << sum + oth.sum + (oth.m >= 0 ? fire_mx : 0) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}