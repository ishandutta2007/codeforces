#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> cou(n);
	for (int i = 0; i < n; ++i) cin >> cou[i];
	int res = 0;
	for (int a = 0; a < n; ++a) {
		int sum = 0;
		for (int b = a; b < n; ++b) {
			sum += cou[b];
			int len = b - a + 1;
			if (sum > len * 100) res = max(res, len);
		}
	}
	cout << res << '\n';
}