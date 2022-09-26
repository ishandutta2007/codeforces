#include <bits/stdc++.h>
using namespace std;

const int N = 400005;

int type() {
	string s; cin >> s;
	return (s[0] - '0') * 2 + (s[1] - '0'); 
}

int n;
vector<int> vec[4];
int f[4][N];
int sz[4];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int t = type();
		int x; cin >> x;
		vec[t].push_back(x);
	}
	for (int t = 0; t < 4; ++t) {
		sort(vec[t].begin(), vec[t].end(), greater<int>());
		for (int i = 1; i <= (int)(vec[t].size()); ++i) {
			f[t][i] = f[t][i - 1] + vec[t][i - 1];
		}
		sz[t] = vec[t].size();
	}
	int res = 0;
	for (int i = 0; i <= min(sz[0], sz[3]); ++i) {
		int sub = sz[3] - i;
		int cur = f[3][sz[3]] + f[0][i];
		int pos2 = min(sz[1] + sub, sz[2]);
		if (sz[1] - pos2 <= sub) {
			res = max(res, cur + f[1][sz[1]] + f[2][pos2]);
		}
		int pos1 = min(sz[2] + sub, sz[1]);
		if (sz[2] - pos1 <= sub) {
			res = max(res, cur + f[2][sz[2]] + f[1][pos1]);
		}
	} 
	cout << res << '\n';
}