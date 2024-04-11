#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 1e9 + 7;

int main() {
	// You lose when you make a pile go to zero, since then on your next turn there are less than n/2 piles with >0 left.
	// -> Piles of size 1 cannot be acted upon

	// You lose when you make a pile go to one, since then on your next turn there are less than n/2 piles with >1 left.
	// -> Piles of size 2 cannot be acted upon
	
	// ...

	// First player wins if on their turn they can make there be more than n/2 of the minimum pile
	// Then after the opponent's turn, there are at most n/2 of the new minimum.
	// Otherwise the second player wins.

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int minv = INF;
	vector<int> as(n);
	for (int i = 0; i < n; ++i) {
		cin >> as[i];
		minv = min(minv, as[i]);
	}

	int minc = 0;
	for (int i = 0; i < n; ++i) {
		if (as[i] == minv) ++minc;
	}
	if (minc > n/2) {
		cout << "Bob\n";
	} else {
		cout << "Alice\n";
	}
}