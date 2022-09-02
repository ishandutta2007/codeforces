#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int cnt(int i, const string& str) {
	return (i >= 0 && i + 2 < str.size() && str[i] == 'a' && str[i+1] == 'b' && str[i+2] == 'c');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	string str;
	cin >> str;

	int c = 0;
	for (int i = 0; i + 2 < n; ++i) c += cnt(i, str);

	for (int qi = 0; qi < q; ++qi) {
		int i;
		char ch;
		cin >> i >> ch;
		--i;
		c -= cnt(i-2, str);
		c -= cnt(i-1, str);
		c -= cnt(i-0, str);
		str[i] = ch;
		c += cnt(i-2, str);
		c += cnt(i-1, str);
		c += cnt(i-0, str);
		cout << c << '\n';
	}
}