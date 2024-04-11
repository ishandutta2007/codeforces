#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void output(const string& str) {
	int n = str.size();

	int cur = 0;
	vector<int> res;
	for (int i = 0; i <= n; ++i) {
		if ((i == n || str[i] != '#') && cur > 0) {
			res.push_back(cur);
			cur = 0;

		} else if (str[i] == '#') {
			++cur;
		}
	}

	cout << res.size() << '\n';
	for (auto v : res) cout << v << ' '; cout << '\n';
}

void fillGap(string& str, int a, int b) {
	int len = b-a+1;
	while(len >= 3) {
		str[a] = '#';
		a += 2;
		len -= 2;
	}

	if (len == 2) {
		str[a] = '#';
		str[a+1] = '#';
	} else if (len == 1) {
		str[a] = '#';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	int n = str.size();

	bool nonempty = 0;
	for (auto c : str) {
		if (c == '#') nonempty = 1;
	}
	if (! nonempty) {
		cout << 0 << '\n' << '\n';
		exit(0);
	}

	for (int t = 0; t < 4; ++t) {
		bool works = 1;
		string res = str;
		for (int i = 0; i < n-t;) {
			if (str[i] == '#') {
				++i;
				continue;
			}

			int j = i;
			while(j < n-t && str[j] != '#') ++j;

			int len = j-i;
			if (t == 0) {
				if (i == 0 || j == n || len != 1) {
					works = 0;
					break;
				}
			} else if (t == 1) {
				if (i == 0 || j == n-1) {
					if (len % 2 != 0) {
						works = 0;
						break;
					}

					if (i == 0) {
						for (int x = i; x < j; x += 2) res[x] = '#';
					} else {
						for (int x = i+1; x < j; x += 2) res[x] = '#';
					}
				} else {
					if (len % 2 != 1) {
						works = 0;
						break;
					}
					for (int x = i+1; x < j; x += 2) res[x] = '#';
				}
			} else {
				if (i == 0 || j == n-t) {
					if (len == 1) {
						works = 0;
						break;
					}

					if (i == 0) fillGap(res, i, j-2);
					else fillGap(res, i+1, j-1);
				} else {
					if (len == 2) {
						works = 0;
						break;
					}
					fillGap(res, i+1, j-2);
				}
			}
			
			i = j;
		}

		if (works) {
			output(res);
			exit(0);
		}

		// Update
		if (str[0] == '#') break;
		if (str[n-1-t] == '#') break;
		for (int i = 0; i+1 < n; ++i) {
			if (str[i+1] == '#') {
				if (i > 0 && str[i-1] == '#' && str[i] != '#') break; // gap 0
				str[i] = '#';
			}
		}
	}
	cout << -1 << '\n';

}