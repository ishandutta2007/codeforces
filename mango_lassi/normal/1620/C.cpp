#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, k;
	ll x;
	cin >> n >> k >> x;
	--x;

	string str;
	cin >> str;
	
	vector<int> ls;
	for (int i = 0; i < n;) {
		int j = i;
		while(j < n && str[j] == str[i]) ++j;
		if (str[i] == '*') ls.push_back(k * (j - i) + 1);
		i = j;
	}

	int m = ls.size();
	vector<int> vals(m, 0);
	for (int i = m-1; i >= 0; --i) {
		vals[i] = x % ls[i];
		x /= ls[i];
	}

	int t = 0;
	for (int i = 0; i < n;) {
		int j = i;
		while(j < n && str[j] == str[i]) ++j;
		if (str[i] == '*') {
			for (int x = 0; x < vals[t]; ++x) cout << 'b';
			++t;
		} else {
			for (int x = 0; x < j-i; ++x) cout << 'a';
		}
		i = j;
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}