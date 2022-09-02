#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int res = 0;
	string str;
	cin >> str;

	vector<int> as(n), bs(n);
	for (int i = 0; i < n; ++i) cin >> as[i] >> bs[i];

	const int M = 1e4;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i >= bs[j] && (i - bs[j]) % as[j] == 0) {
				if (str[j] == '1') str[j] = '0';
				else str[j] = '1';
			}
		}
		int off = 0;
		for (auto c : str) off += (c == '1');
		res = max(res, off);
	}
	cout << res << '\n';
}