#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

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
		string ord = str;
		sort(ord.begin(), ord.end());

		int cou = 0;
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] != ord[i]) ++cou;
		}
		cout << cou << '\n';
	}

}