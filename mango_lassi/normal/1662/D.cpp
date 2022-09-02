#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string minimise(const string& str) {
	int bc = 0;
	for (char c : str) bc ^= (c == 'B');
	
	string res;
	if (bc) res.push_back('B');

	for (char c : str) {
		if (c == 'B') continue;
		if (! res.empty() && res.back() == c) {
			res.pop_back();
		} else {
			res.push_back(c);
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		string a, b;
		cin >> a >> b;
		
		string ma = minimise(a);
		string mb = minimise(b);
		cout << ((ma == mb) ? "YES\n" : "NO\n");
	}
}