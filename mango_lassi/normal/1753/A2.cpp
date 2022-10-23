#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int makeZero(int a, vector<int>& res, const vector<int>& as) {
	while(a + 1 < as.size() && as[a] != 0 && as[a + 1] != 0) {
		res.push_back(a);
		if (as[a] != as[a + 1]) res.push_back(a + 1);
		a += 2;
	}
	return a;
}

void solve() {
	int n;
	cin >> n;

	vector<int> as(n);
	for (int& a : as) cin >> a;

	int s = 0;
	vector<int> res;
	s = makeZero(s, res, as);

	int cur = 0;
	if (s < n && as[s] != 0) {
		res.push_back(s);
		cur = as[s];
		++s;
	}

	for (int i = s; i + 1 < n; ++i) {
		res.push_back(i);
		if (as[i + 1] == 0) continue;

		int j = i + 1;
		while(j + 1 < n && as[j + 1] != 0) ++j;
		
		int len = j - i;
		if (len % 2 == 0) {
			i = makeZero(i + 1, res, as) - 1;
		} else {
			if (cur == 0 || (cur == as[i + 1])) {
				cur -= as[i + 1];
			} else {
				res.push_back(i + 1);
				cur += as[i + 1];
			}
			i = makeZero(i + 2, res, as) - 1;
		}
	}
	if (as[n-1] == 0) res.push_back(n-1);

	if (cur == 0) {
		cout << res.size() << '\n';
		res.push_back(n);
		for (int j = 0; j + 1 < res.size(); ++j) cout << res[j] + 1 << ' ' << res[j + 1] << '\n';
	} else {
		cout << -1 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}