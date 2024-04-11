#include <bits/stdc++.h>
using namespace std;

int n, m;
string s, t;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> s >> t;
	int pos = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '*') pos = i;
	}
	if (pos == -1) {
		if (s == t) cout << "YES";
		else cout << "NO";
	}
	else {
		while (s.size() && t.size() && s.back() == t.back()) {
			s.pop_back();
			t.pop_back();
		}
		reverse(s.begin(), s.end());
		reverse(t.begin(), t.end());
		while (s.size() && t.size() && s.back() == t.back()) {
			s.pop_back();
			t.pop_back();
		}
		if (s.size() != 1) cout << "NO";
		else cout << "YES";
	}
}