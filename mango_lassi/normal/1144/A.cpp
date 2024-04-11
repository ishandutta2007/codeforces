#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const int C = 26;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		
		vector<int> cou(C, 0);
		for (auto c : str) ++cou[c-'a'];

		bool fail = false;
		int sect = 0;
		for (int c = 0; c < C; ++c) {
			if (cou[c] > 1) fail = true;
			if (cou[c] > 0 && sect == 0) sect = 1;
			if (cou[c] == 0 && sect == 1) sect = 2;
			if (cou[c] > 0 && sect == 2) fail = true;
		}
		if (fail) cout << "No\n";
		else cout << "Yes\n";
	}
}