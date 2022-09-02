#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int ti = 0; ti < n; ++ti) {
		int k;
		cin >> k;
		string str;
		cin >> str;
		sort(str.begin(), str.end());
		cout << str << '\n';
	}
}