#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	const int M = 11;
	vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

	int tc;
	cin >> tc;
	for (int ti = 0; ti < tc; ++ti) {
		int n;
		cin >> n;

		vector<int> used(M, 0);
		vector<int> res(n);
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			for (int j = 0; j < M; ++j) {
				if (a % primes[j] == 0) {
					res[i] = j;
					used[j] = 1;
					break;
				}
			}
		}
		int m = 0;
		for (int i = 0; i < M; ++i) {
			if (used[i]) {
				++m;
				used[i] = m;
			}
		}

		cout << m << '\n';
		for (int i = 0; i < n; ++i) cout << used[res[i]] << ' '; cout << '\n';
	}
}