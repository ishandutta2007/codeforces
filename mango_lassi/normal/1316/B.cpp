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
		int n;
		cin >> n;

		string str;
		cin >> str;

		int res = 1;
		string cur = str;
		for (int m = 2; m <= n; ++m) {
			string tmp(n, '_');
			for (int i = 0; i+m-1 < n; ++i) tmp[i] = str[i+m-1];
			for (int i = 0; i < m-1; ++i) {
				tmp[n-(m-1)+i] = (((n-(m-1)) & 1) ? str[m-2-i] : str[i]);
			}
			if (tmp < cur) {
				res = m;
				cur = tmp;
			}
		}
		cout << cur << '\n' << res << '\n';
	}
}