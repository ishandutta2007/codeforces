#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> cou = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		cin >> n;

		int k = n/2;
		n -= 2 * k;

		string res(k, '1');
		for (int i = 0; i < k; ++i) {
			n += 2;
			for (int j = 9; j >= 0; --j) {
				if (cou[j] <= n) {
					res[i] = '0' + j;
					n -= cou[j];
					break;
				}
			}
		}
		cout << res << '\n';
	}
}