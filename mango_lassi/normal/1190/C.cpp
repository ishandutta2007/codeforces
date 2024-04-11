#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int getStat(int c, int n) {
	if (c == 0) return -1;
	else if (c == n) return 1;
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	string str;
	cin >> str;

	// Player always wins on their first turn if they would win
	// Since if second player would lose, they can just repeat the first player's move
	vector<int> cou(n+1, 0);
	for (int i = 0; i < n; ++i) {
		cou[i+1] = cou[i] + (str[i] == '1');
	}

	bool first_win = false;
	for (int i = 0; i+k <= n; ++i) {
		int othc = cou[n] - (cou[i+k] - cou[i]);
		if (getStat(othc, n-k) != 0) first_win = true;
	}
	bool second_win = false;
	if (! first_win) {
		second_win = true;
		for (int i = 1; i + k < n; ++i) {
			int lc = cou[i];
			int rc = cou[n] - cou[i+k];
			int lc_stat = getStat(lc, i);
			int rc_stat = getStat(rc, n-(i+k));
			if (lc_stat == 0 || rc_stat == 0 || lc_stat == rc_stat || i > k || n-(i+k) > k) {
				second_win = false;
			}
		}
	}
	
	if (first_win) cout << "tokitsukaze\n";
	else if (second_win) cout << "quailty\n";
	else cout << "once again\n";
}