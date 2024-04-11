#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int C = 26;
vector<int> locs[C];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n ;
	cin >> n;
	string str;
	cin >> str;
	for (int i = 0; i < n; ++i) {
		locs[str[i]-'a'].push_back(i);
	}

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		string tar;
		cin >> tar;

		vector<int> counts(C, 0);
		for (auto c : tar) ++counts[c-'a'];

		int res = 0;
		for (int c = 0; c < 26; ++c) {
			if (counts[c] == 0) continue;
			res = max(res, 1 + locs[c][counts[c]-1]);
		}
		cout << res << '\n';
	}
}