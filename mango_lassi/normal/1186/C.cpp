#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	int n = a.size();
	int m = b.size();

	int res = 0;
	int a_ones = 0;
	int b_ones = 0;
	for (auto c : b) b_ones += (c == '1');
	for (int i = 0; i < m-1; ++i) a_ones += (a[i] == '1');
	for (int i = m-1; i < n; ++i) {
		a_ones += a[i] == '1';
		if (i >= m) a_ones -= a[i-m] == '1';
		if (a_ones % 2 == b_ones % 2) ++res;
	}
	cout << res << '\n';
}