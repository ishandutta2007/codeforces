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

int64 one(vector <int>& a) {
	int n = int(a.size());
	int64 res = n;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (j - i == *max_element(a.begin() + i, a.begin() + j + 1) - *min_element(a.begin() + i, a.begin() + j + 1)) {
				res++;
			}
		}
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);

//	vector <int> a = { 1, 2, 3, 4, 5, 6 };
//	int64 res = one(a);
//	while (next_permutation(a.begin(), a.end())) {
//		res += one(a);
//	}
//	cout << res << '\n';

	int64 n, m;
	cin >> n >> m;

	vector <int64> fact(n + 1);
	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = (fact[i - 1] * i) % m;
	}

	int64 res = 0;
	for (int64 len = 1; len <= n; len++) {
		int64 k = n + 1 - len;
		int64 a = (fact[len] * k) % m;
		int64 delta = k * a;
		delta %= m;
		delta *= fact[n - len];
		delta %= m;
//		cout << delta << '\n';
		res += delta;
		res %= m;
	}
	cout << res << '\n';
}