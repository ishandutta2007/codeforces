#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 1005;

int n;
signed main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	vector<string> s(n);
	for (int i = 0;i < n;++i) {
		cin >> s[i];
		sort(s[i].begin(), s[i].end());
		s[i].resize(unique(s[i].begin(), s[i].end()) - s[i].begin());
	}
	sort(s.begin(), s.end());
	s.resize(unique(s.begin(), s.end()) - s.begin());
	cout << s.size();
}