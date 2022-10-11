#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

typedef long long int64;
typedef long double ld;

template <class T> bool bmin(T& a, T b) { return a > b ? (a = b, true) : false; }
template <class T> bool bmax(T& a, T b) { return a < b ? (a = b, true) : false; }

const int64 INF64 = 1e18;
const int INF = 1e9;

using namespace std;

bool can(vector <int64>& a) {
	int64 Max = a.back();
	for (int i = a.size() - 2; i >= 0; i--) {
		if (Max > a[i]) {
			return true;
		}
		Max = max(Max, a[i]);
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	vector <int64> maxs, smins(n);
	vector <char> cans(n);
	int64 cnt = 0;
	for (int i = 0; i < n; i++) {
		int L;
		cin >> L;
		vector <int64> tmp(L);
		for (int j = 0; j < L; j++) {
			cin >> tmp[j];
		}
		if (can(tmp)) {
			cans[i] = 1;
			cnt++;
		} else {
			maxs.push_back(*max_element(tmp.begin(), tmp.end()));
		}
		smins[i] = *min_element(tmp.begin(), tmp.end());
	}

	sort(maxs.begin(), maxs.end());

	int64 res = 0;
	for (int i = 0; i < n; i++) {
		if (cans[i]) {
			res += n;
		} else {
			res += int64(maxs.end() - upper_bound(maxs.begin(), maxs.end(), smins[i]));
			res += cnt;
		}
	}
	cout << res << '\n';
}