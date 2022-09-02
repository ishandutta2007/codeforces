#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	
	string str;
	cin >> str;

	if (n == 1) cout << "YES\n";
	else if (n == 2) {
		if (str[0] != str[1]) cout << "YES\n";
		else cout << "NO\n";
	} else if (n >= 3) cout << "NO\n";
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}