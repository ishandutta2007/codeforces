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

const int MX = 210;
const int MAXN = 120000;

int dp[400];
int cnt[400];

int a[MAXN];
int n, t;

int main() {
	cin >> n >> t;
	for (int i = 0; i < n; ++i)
		cin >> a[i], ++cnt[a[i]];
	int p = 0;
	for (int i = 0; i < 400; ++i)
		p = max(p, cnt[i]);
	int k = min(t, MX);
	for (int i = n; i < n * k; ++i)
		a[i] = a[i - n];
	for (int i = 0; i < n * k; ++i) {
		dp[a[i]] += 1;
		for (int j = a[i] - 1; j >= 0; --j)
			dp[a[i]] = max(dp[a[i]], dp[j] + 1);
	}
	int mx = 0;
	for (int i = 0; i < 400; ++i)
		mx = max(mx, dp[i]);
	mx += (t - k) * p;
	cout << mx;
	return 0;
}