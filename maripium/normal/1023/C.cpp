#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, k;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k >> s;
	string res = "";
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			if (k - res.size() <= cur) continue;
			res.push_back('('); cur++;
		}
		else {
			if (cur == 0) continue;
			res.push_back(')'); cur--;
		}
	}
	cout << res << '\n';
}