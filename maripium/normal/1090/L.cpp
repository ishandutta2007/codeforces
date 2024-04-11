#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t, n, a, b, k; 
	cin >> t >> n >> a >> b >> k;
	auto check = [&](long long mid) {
		long long ma = min(a, mid), mb = min(b, mid);
		long long num = (ma + mb) * (n / 2) + (n % 2) * ma;
		return num >= k * mid;
	};
	long long low = 0, high = t;
	while (low < high) {
		int mid = (low + high + 1) >> 1;
		if (check(mid)) low = mid;
		else high = mid - 1;
	}
	cout << low << '\n';
}