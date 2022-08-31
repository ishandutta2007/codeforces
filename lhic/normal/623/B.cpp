#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 1200000;

int n;
ll a, b;
int arr[MAXN];
ll c[MAXN];

ll get(int x) {
	for (int i = 0; i < n; ++i) {
		int k = arr[i] % x;
		if (k == 0)
			c[i] = 0;
		else if (k == 1 || k == x - 1)
			c[i] = b;
		else
			c[i] = b * n;
	}
	ll dp0 = 0;
	ll dp1 = 0;
	ll dp2 = 0;
	for (int i = 0; i < n; ++i) {
		dp2 = min(dp2 + c[i], dp1 + c[i]);
		dp1 = min(dp1 + a, dp0 + a);
		dp0 += c[i];
		dp0 = min(dp0, b * n + 10);
		dp1 = min(dp1, b * n + 10);
		dp2 = min(dp2, b * n + 10);
	}
	ll ans = min(dp0, dp2);
	ans = min(ans, dp1);
	return ans;
}

int main() {
	scanf("%d%lld%lld", &n, &a, &b);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
	vector<int> vv;
	int x = arr[0];
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			vv.push_back(i);
			while (x % i == 0)
				x /= i;
		}
	}
	if (x != 1)
		vv.push_back(x);
	x = arr[0] - 1;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			vv.push_back(i);
			while (x % i == 0)
				x /= i;
		}
	}
	if (x != 1)
		vv.push_back(x);
	x = arr[0] + 1;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			vv.push_back(i);
			while (x % i == 0)
				x /= i;
		}
	}
	if (x != 1)
		vv.push_back(x);

	x = arr[n - 1];
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			vv.push_back(i);
			while (x % i == 0)
				x /= i;
		}
	}
	if (x != 1)
		vv.push_back(x);
	x = arr[n - 1] - 1;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			vv.push_back(i);
			while (x % i == 0)
				x /= i;
		}
	}
	if (x != 1)
		vv.push_back(x);
	x = arr[n - 1] + 1;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			vv.push_back(i);
			while (x % i == 0)
				x /= i;
		}
	}
	if (x != 1)
		vv.push_back(x);

	sort(vv.begin(), vv.end());
	vv.resize(unique(vv.begin(), vv.end()) - vv.begin());

	ll ans = b * n;

	for (int i = 0; i < (int)vv.size(); ++i)
		ans = min(ans, get(vv[i]));

	cout << ans << "\n";
	return 0;
}