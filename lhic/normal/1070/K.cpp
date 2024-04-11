#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = uint64_t;

using namespace std;

const int MAXN = 120000;

int n, k;
ll sum;

ll a[MAXN];

void no() {
	cout << "No\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i], sum += a[i];
	if (sum % k != 0) 
		no();
	sum /= k;
	ll now = 0;
	vector<int> vv;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		now += a[i];
		++cnt;
		if (now == sum) {
			vv.push_back(cnt);
			cnt = 0;
			now = 0;
		}
	}
	if (vv.size() != k) {
		no();
	}
	else {
		cout << "Yes\n";
		for (int i: vv)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}