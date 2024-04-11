#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1000;
ll xs[N];
ll ys[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> xs[i] >> ys[i];

	while(true) {
		vector<int> odds, evens;
		for (int i = 0; i < n; ++i) {
			if ((xs[i] + ys[i]) & 1) odds.push_back(i);
			else evens.push_back(i);
		}
		if (odds.size() == n) {
			for (int i = 0; i < n; ++i) {
				--xs[i];
				int nx = (xs[i] + ys[i]) / 2;
				int ny = (ys[i] - xs[i]) / 2;
				xs[i] = nx;
				ys[i] = ny;
			}
		} else if (evens.size() == n) {
			for (int i = 0; i < n; ++i) {
				int nx = (xs[i] + ys[i]) / 2;
				int ny = (ys[i] - xs[i]) / 2;
				xs[i] = nx;
				ys[i] = ny;
			}
		} else {
			cout << odds.size() << '\n';
			for (auto v : odds) cout << v+1 << ' '; cout << '\n';
			break;
		}
	}

	// (x1^2 + y1^2) + (x2^2 + y2^2) - 2x1x2 - 2y1y2
	// is ODD if and only if exactly one of (x1^2 + y1^2), (x2^2 + y2^2) is odd
	// -> All nodes with odd (x1 + y1) to one component, others to the other
	// What about if all have same parity of x1 + y1?
	// Rotate and scale down! If all have even x+y, change (x, y) to ((x+y)/2, (y-x)/2)
	// Note that (x^2 + y^2) = 2(((x+y)/2)^2 + ((x-y)/2)^2), so this process will stop
}