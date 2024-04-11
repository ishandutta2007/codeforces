#include <bits/stdc++.h>
using namespace std;

string s, t;
string res;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> s; int n = s.size();
	for (auto c : s) if (c != '1') t.push_back(c);
	int cur = n + 1;
	for (int i = 0; i < t.size(); ++i) {
		if (t[i] == '0') res.push_back('0');
		else {
			cur = i;
			break;
		}
	}
	int p = cur;
	for (int i = 0; i < n; ++i) if (s[i] == '1') res.push_back('1');
	for (int i = cur; i < t.size(); ++i) res.push_back(t[i]);
	cout << res;
}