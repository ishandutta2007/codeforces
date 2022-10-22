#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> piles(n, 0), sums(n);
	for (int i = 0; i < n; i++) {
		cin >> piles[i];
		sums[i] = (i == 0 ? 0 : piles[i - 1] + sums[i - 1]);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int cur;
		cin >> cur;
		int l = 0;
		int r = n;
		while (r > l + 1) {
			int mid = (l + r) / 2;
			if (sums[mid] >= cur)
				r = mid;
			else
				l = mid;
		}
		cout << r << '\n';
	}

	return 0;
}