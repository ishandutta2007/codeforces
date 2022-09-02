#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll k;
	cin >> k;

	string str = "codeforces";
	int n = str.size();
	vector<int> cou(n, 1);
	ll cur = 1;

	for (int i = 0; cur < k; ++i) {
		int j = i % n;
		cur /= cou[j];
		++cou[j];
		cur *= cou[j];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < cou[i]; ++j) cout << str[i];
	}
	cout << '\n';
}