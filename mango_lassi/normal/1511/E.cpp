#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

const int H = 3 * (int)1e5;
const int HW = 3 * (int)1e5;
ll tp[HW + 1];
ll adds[HW + 1];
string arr[H];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;
	
	tp[0] = 1;
	for (int i = 1; i <= h*w; ++i) tp[i] = (tp[i-1] * 2) % MOD;

	int wc = 0;
	for (int y = 0; y < h; ++y) {
		cin >> arr[y];
		for (auto c : arr[y]) wc += (c == 'o');
	}

	for (int i = 2; i <= wc; ++i) {
		adds[i] = (tp[wc - i] + adds[i - 1 - (i & 1)]) % MOD;
	}

	ll res = 0;
	for (int y = 0; y < h; ++y) {
		int cur = 0;
		for (int x = 0; x < w; ++x) {
			if (arr[y][x] == 'o') {
				++cur;
				res += adds[cur];
			} else {
				cur = 0;
			}
		}
	}
	for (int x = 0; x < w; ++x) {
		int cur = 0;
		for (int y = 0; y < h; ++y) {
			if (arr[y][x] == 'o') {
				++cur;
				res += adds[cur];
			} else {
				cur = 0;
			}
		}
	}

	cout << res % MOD << '\n';

}