#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int M = 25;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> cou(M, 0);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		for (int j = 0; j < M; ++j) {
			if (a & (1 << j)) ++cou[j];
		}
	}
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		ll num = 0;
		for (int j = 0; j < M; ++j) {
			if (cou[j] > 0) {
				--cou[j];
				num += (1 << j);
			}
		}
		res += num * num;
	}
	cout << res << '\n';
}