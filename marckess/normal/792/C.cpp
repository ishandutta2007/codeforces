#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	int _[3] = {0}, sum = 0, c;
	string s, a, b;
 
	cin >> s;
	reverse(s.begin(), s.end());

	for (char c : s) {
		int x = c - '0';

		_[x%3]++;
		sum += x;
	}

	sum %= 3;

	if (sum == 0) {
		reverse(s.begin(), s.end());
		cout << s << endl;
		return 0;
	} else if (sum == 1) {
		
		if (_[1] >= 1) {
			c = 0;

			for (int i = 0; i < s.size(); i++) {
				if ((s[i] - '0') % 3 != 1 || sum == 0) {
					if (s[i] == '0') {
						c++;
					} else {
						while (c) {
							a.push_back('0');
							c--;
						}
						a.push_back(s[i]);
					}
				} else {
					sum = 0;
				}
			}

			if (a.empty() && c)
				a = "0";

			sum = 1;
		}

		if (_[2] >= 2) {
			c = 0;

			for (int i = 0; i < s.size(); i++) {
				if ((s[i] - '0') % 3 != 2 || sum == 0) {
					if (s[i] == '0') {
						c++;
					} else {
						while (c) {
							b.push_back('0');
							c--;
						}
						b.push_back(s[i]);
					}
				} else {
					sum -= 2;
					if (sum < 0)
						sum += 3;
				}
			} 

			if (b.empty() && c)
				b = "0";

			sum = 1;
		}

	} else {

		if (_[2] >= 1) {
			c = 0;

			for (int i = 0; i < s.size(); i++) {
				if ((s[i] - '0') % 3 != 2 || sum == 0) {
					if (s[i] == '0') {
						c++;
					} else {
						while (c) {
							a.push_back('0');
							c--;
						}
						a.push_back(s[i]);
					}
				} else {
					sum = 0;
				}
			}

			if (a.empty() && c)
				a = "0";

			sum = 2;
		}

		if (_[1] >= 2) {
			c = 0;

			for (int i = 0; i < s.size(); i++) {
				if ((s[i] - '0') % 3 != 1 || sum == 0) {
					if (s[i] == '0') {
						c++;
					} else {
						while (c) {
							b.push_back('0');
							c--;
						}
						b.push_back(s[i]);
					}
				} else {
					sum -= 1;
					if (sum < 0)
						sum += 3;
				}
			}

			if (b.empty() && c)
				b = "0";

			sum = 2;
		}

	}

	if (a.empty() && b.empty()) {
		cout << -1 << endl;
		return 0;
	}

	if (b.empty() || a.size() > b.size()) {
		reverse(a.begin(), a.end());
		cout << a << endl;
	} else {
		reverse(b.begin(), b.end());
		cout << b << endl;
	}

	return 0;
}