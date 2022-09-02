#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		string s1, s2;
		int k1, k2;
		cin >> s1 >> k1;
		cin >> s2 >> k2;

		int l1 = s1.size() + k1;
		int l2 = s2.size() + k2;
		if (l1 != l2) {
			if (l1 < l2) cout << "<\n";
			else cout << ">\n";
		} else {
			while(s1.size() < s2.size()) s1.push_back('0');
			while(s2.size() < s1.size()) s2.push_back('0');

			if (s1 < s2) {
				cout << "<\n";
			} else if (s1 > s2) {
				cout << ">\n";
			} else {
				cout << "=\n";
			}
		}
	}
}