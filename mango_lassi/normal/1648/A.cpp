#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int C = 1e5;

ll solve(const vector<vector<int>>& arr) {
	int h = arr.size();
	int w = arr[0].size();

	vector<ll> tot(C + 1, 0), pref(C + 1, 0);
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) ++tot[arr[y][x]];
	}
	
	ll res = 0, add = 0;
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			int c = arr[y][x];
			add -= (tot[c] - pref[c]) * pref[c];
			++pref[c];
			add += (tot[c] - pref[c]) * pref[c];
		}
		res += add;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int h, w;
	cin >> h >> w;

	vector<vector<int>> tp(w, vector<int>(h)), arr(h, vector<int>(w));
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			cin >> arr[y][x];
			tp[x][y] = arr[y][x];
		}
	}

	ll res0 = solve(arr);
	ll res1 = solve(tp);
	cout << res0 + res1 << '\n';
}