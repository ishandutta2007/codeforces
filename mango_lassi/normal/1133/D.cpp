#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

const int N = 2 * (int)1e5;
int as[N];
int bs[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> as[i];
	for (int i = 0; i < n; ++i) cin >> bs[i];

	int base = 0;
	int res = 0;
	vector<pair<int, int>> ds;
	for (int i = 0; i < n; ++i) {
		if (as[i] == 0 && bs[i] == 0) ++base;
		else if (bs[i] == 0) {
			++res;
		} else if (as[i] != 0) {
			int gd = gcd(as[i], bs[i]);
			as[i] /= gd;
			bs[i] /= gd;
			if (as[i] < 0) {
				as[i] *= -1;
				bs[i] *= -1;
			}
			ds.push_back({as[i], bs[i]});
		}
	}
	sort(ds.begin(), ds.end());

	int j = 0;
	for (int i = 0; i < ds.size(); ++i) {
		while(ds[j] != ds[i]) ++j;
		res = max(res, i-j+1);
	}
	cout << res + base << '\n';
}