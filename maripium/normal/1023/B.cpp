#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, k; cin >> n >> k;
	long long mn = max(1ll, k - n), mx = (k - 1) / 2;
	long long res = mx - mn + 1;
	res = max(res, 0ll);
	cout << res << '\n';
}