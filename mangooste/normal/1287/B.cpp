#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>

typedef long long int64;
typedef long double ld;

template <class T> bool bmin(T& a, T b) { return a > b ? (a = b, true) : false; }
template <class T> bool bmax(T& a, T b) { return a < b ? (a = b, true) : false; }

const int64 INF64 = 1e18;
const int INF = 1e9;

using namespace std;

int64 get_value(vector <int>& a) {
	int64 res = 0;
	int n = a.size();
	for (int i = 0; i < n; i++) {
		res *= 3;
		res += a[i];
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	cin >> n >> k;

	vector <vector <int>> dict(n, vector <int>(k));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			char tmp;
			cin >> tmp;
			if (tmp == 'S') {
				dict[i][j] = 0;
			} else if (tmp == 'E') {
				dict[i][j] = 1;
			} else {
				dict[i][j] = 2;
			}
		}
	}

	vector <int64> v = { get_value(dict.back()) };

	bool used[3];
	int64 res = 0;
	for (int mid = n - 2; mid > 0; mid--) {
		for (int left = mid - 1; left >= 0; left--) {
			vector <int> need(k);
			for (int z = 0; z < k; z++) {
				if (dict[left][z] == dict[mid][z]) {
					need[z] = dict[left][z];
				} else {
					for (int i = 0; i < 3; i++) {
						used[i] = false;
					}
					used[dict[left][z]] = true;
					used[dict[mid][z]] = true;
					for (int i = 0; i < 3; i++) {
						if (!used[i]) {
							need[z] = i;
						}
					}
				}
			}
			int64 cnt = get_value(need);
			res += int(upper_bound(v.begin(), v.end(), cnt) - lower_bound(v.begin(), v.end(), cnt));
		}
		v.push_back(get_value(dict[mid]));
		if (!is_sorted(v.begin(), v.end())) {
			sort(v.begin(), v.end());
		}
	}
	cout << res << '\n';
}