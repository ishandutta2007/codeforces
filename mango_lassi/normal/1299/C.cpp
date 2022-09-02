#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;
using ld = long double;

bool comp(pair<ll, ll> a, pair<ll, ll> b) {
	return a.first * b.second <= a.second * b.first;
}
pair<ll, ll> add(pair<ll, ll> a, pair<ll, ll> b) {
	return {a.first + b.first, a.second + b.second};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// When is the value of the first as small as it can get?
	// -> When every prefix has at least as large of an average
	// Thus, our first operation is on some prefix. After that, we do no operations on any of the
	// values in the prefix anymore

	// Store the first value, then loop forward.
	// Whenever we get a smaller value than the previous, we apply the operation

	vector<pair<ll, ll>> sta;
	for (int i = 0; i < n; ++i) {
		ll v;
		cin >> v;
		pair<ll, ll> off = {v, 1};
		while(! sta.empty() && comp(off, sta.back())) {
			off = add(sta.back(), off);
			sta.pop_back();
		}
		sta.push_back(off);
	}
	for (int i = 0; i < sta.size(); ++i) {
		for (int j = 0; j < sta[i].second; ++j) {
			cout << fixed << setprecision(20) << (ld)sta[i].first / sta[i].second << '\n';
		}
	}
}