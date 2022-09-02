#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> h(n);
	for (int i = 0; i < n; ++i) cin >> h[i];
	sort(h.begin(), h.end());

	for (int i = 0; i < n; i += 2) {
		cout << h[i] << ' ';
	}
	for (int i = (n % 2 == 0 ? n-1 : n-2); i >= 0; i -= 2) {
		cout << h[i] << ' ';
	}
	cout << '\n';
}