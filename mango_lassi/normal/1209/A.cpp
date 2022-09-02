#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> as(n);
	for (int i = 0; i < n; ++i) cin >> as[i];
	sort(as.begin(), as.end());

	int res = 0;
	for (int i = 0; i < n; ++i) {
		bool divs = false;
		for (int j = 0; j < i; ++j) {
			if (as[i] % as[j] == 0) divs = true;
		}
		if (! divs) ++res;
	}
	cout << res << '\n';
}