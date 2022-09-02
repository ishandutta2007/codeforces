#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		string str;
		cin >> str;
		int n = str.size();
		int a = -1, b = n;
		for (int i = 0; i < n; ++i) {
			if (str[i] == '1') {
				a = max(a, i);
				b = min(b, i);
			}
		}
		int res = 0;
		for (int i = 0; i < n; ++i) {
			if (str[i] == '0' && b <= i && i <= a) ++res;
		}
		cout << res << '\n';
	}
}