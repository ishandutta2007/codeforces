#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	// WIN if first player wins
	// LOSE if first player loses
	// DRAW otherwise

	// Look at numbers containing the highest bit. If there is an odd number of them, that bit alone determines the game.
	// If there is an even number of them, you can remove the highest bit (either both players get an even amount, or both get an odd amount)

	vector<int> as(n);
	for (int& a : as) cin >> a;

	int win = 0;
	for (int j = 30; j >= 0; --j) {
		int h = 1 << j;
		int cou = 0;
		for (auto a : as) {
			if (a & h) ++cou;
		}
	
		// If even amount of others, player 2 can force player 1 to pick one first
		// 

		// 1: first player always wins
		// 3: second player wins if n & 1
		// 5: 

		// n even: win if 

		if (cou & 1) {
			int a = (cou % 4);
			int b = (n - cou) & 1;
			if (b == 0) {
				if (a == 1) win = 1; // Take 1, then always take same type as opponent
				else win = -1; // Always take same type as your opponent
			} else {
				win = 1;
			}
			break;
		}
	}

	if (win == 0) cout << "DRAW\n";
	else if (win == 1) cout << "WIN\n";
	else cout << "LOSE\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		solve();
	}
}