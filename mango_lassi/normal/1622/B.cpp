#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<pair<pair<int, int>, int>> songs(n);
	for (int i = 0; i < n; ++i) {
		songs[i].second = i;
		cin >> songs[i].first.second;
	}

	string str;
	cin >> str;
	for (int i = 0; i < n; ++i) songs[i].first.first = str[i] - '0';
	sort(songs.begin(), songs.end());

	vector<int> perm(n);
	for (int i = 0; i < n; ++i) perm[songs[i].second] = i + 1;
	for (int v : perm) cout << v << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}