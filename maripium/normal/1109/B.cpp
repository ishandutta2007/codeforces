#include <bits/stdc++.h>
using namespace std;

bool can(string s) {
	string t = s;
	reverse(t.begin(), t.end());
	return s == t;
}

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	bool flag = true;
	for (int i = 0; i < n; ++i) {
		if (s[i] != s[0]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << "Impossible\n";
		return 0;
	}
	if (n % 2 == 0) {
		for (int ll = 1; ll < n; ++ll) {
			string l = s.substr(0, ll);
			string r = s.substr(ll, n - ll);
			string nw = r + l;
			if (can(nw) && nw != s) {
				cout << 1 << '\n';
				return 0;
			}
		}
		cout << 2 << '\n';
		return 0;
	} else {
		string l = s.substr(0, n / 2);
		bool flag = true;
		for (int i = 0; i < n / 2; ++i) {
			if (l[i] != l[0]) {
				flag = false;
				break;
			}
		} 
		if (flag) {
			cout << "Impossible\n";
			return 0;
		}
		for (int ll = 1; ll < n; ++ll) {
			string l = s.substr(0, ll);
			string r = s.substr(ll, n - ll);
			string nw = r + l;
			if (can(nw) && nw != s) {
				cout << 1 << '\n';
				return 0;
			}
		}
		cout << 2 << '\n';
		return 0;
	}
}