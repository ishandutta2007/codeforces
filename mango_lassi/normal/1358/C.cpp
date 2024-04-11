#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	// Consider the sequence of moves.
	// Compared to RRR...RRRDDD...DDD, every order has a sum larger by k, where k is the number of inversions (subsequences DR) in that order
	// -> Answer is the number of different amounts of inversions, which is 1 + (#R-1 * #D-1)

	ll dx = x2 - x1;
	ll dy = y2 - y1;
	cout << (dx * dy + 1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}