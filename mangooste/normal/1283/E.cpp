#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

typedef int64_t int64;
typedef long double ld;

template <class T> bool bmin(T& a, T b) { return a > b ? (a = b, true) : false; }
template <class T> bool bmax(T& a, T b) { return a < b ? (a = b, true) : false; }

const int64 INF64 = 1e18;
const int INF = 1e9;

using namespace std;

int64 get_max(vector <int> cnt, int n) {
	vector <char> used(n + 2, 0);
	for (int i = 1; i <= n; i++) {
		if (cnt[i] >= 3) {
			used[i - 1] = used[i] = used[i + 1] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i] < 3) {
			vector <int> can;
			for (int j = i - 1; j <= i + 1; j++) {
				if (!used[j]) {
					can.push_back(j);
				}
			}
			for (int j = 0; j < min(int(can.size()), cnt[i]); j++) {
				used[can[j]] = 1;
			}
		}
	}
	int res = 0;
	for (auto i : used) {
		res += (i ? 1 : 0);
	}
	return res;
}

int64 get_min(vector <int> cnt, int n) {
	vector <char> used(n + 2, 0);
	for (int i = 1; i <= n; i++) {
		if (cnt[i] != 0 && !used[i]) {
			if (!used[i - 1] && !used[i]) {
				used[i + 1] = 1;
			}
		}
	}
	int res = 0;
	for (auto i : used) {
		res += (i ? 1 : 0);
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	vector <int> cnt(n + 2, 0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	cout << get_min(cnt, n) << ' ' << get_max(cnt, n) << '\n';
}