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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	cin >> n >> k;

	map <int, int> res;
	for (int i = 0; i < k + 1; i++) {
		cout << "? ";
		for (int j = 0; j < k + 1; j++) {
			if (i != j) {
				cout << j + 1 << ' ';
			}
		}
		cout << endl;
		int el_pos, el;
		cin >> el_pos >> el;
		res[el]++;
	}
	pair <int, int> ans;
	for (auto i : res) {
		ans = i;
	}
	cout << "! " << ans.second << endl;
}