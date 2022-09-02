#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// If both have same sign:
	// |a-b| <= |a|, |b|
	// If one is negative:
	// |a+b| <= |a|, |b|
	// -> Must have ||a|-|b|| <= |a|, |b|
	// -> Must have |a|-|b| <= |b| <= |a|
	// -> Must have |a| <= 2|b|

	vector<int> as(n);
	for (int i = 0; i < n; ++i) {
		cin >> as[i];
		as[i] = abs(as[i]);
	}
	sort(as.begin(), as.end());

	ll res = 0;
	int j = 0;
	for (int i = 1; i < n; ++i) {
		while((j < i) && (as[j]*2 < as[i])) ++j;
		res += i-j;
	}
	cout << res << '\n';
}