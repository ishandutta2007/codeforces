#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9 + 7;

string shift(const string& str) {
	int n = str.size();
	string res(n, 'a');
	for (int i = 0; i < n; ++i) res[i] = str[(i+1)%n];
	return res;
}

int main() {
	int n;
	cin >> n;

	vector<string> strs(n);
	for (int i = 0; i < n; ++i) cin >> strs[i];

	int m = strs[0].size();

	int res = INF;
	for (int i = 0; i < m; ++i) {
		int cost = i;
		string tar = strs[0];
		for (int j = 1; j < n; ++j) {
			string tmp = strs[j];
			for (int r = 0; r < m; ++r) {
				if (tmp == tar) {
					cost += r;
					break;
				}
				tmp = shift(tmp);
			}
			if (tmp != tar) cost = INF;
		}
		strs[0] = shift(tar);
		res = min(res, cost);
	}
	if (res >= INF) cout << "-1\n";
	else cout << res << '\n';
}