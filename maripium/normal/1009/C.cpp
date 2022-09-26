#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long x, d;
long long sum = 0;
long long mn, mx;

long long calc(long long n) {
	return (n * (n + 1)) / 2LL;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	mx = calc(n - 1);
	long long mid = (n + 1) / 2LL;
	mn = calc(mid - 1) + calc(n - mid);
	// cout << mn << ' ' << mx << '\n';
	while (m--) {
		cin >> x >> d;
		if (d < 0) sum += n * x + d * mn;
		else sum += n * x + d * mx;
	}
	cout << fixed << setprecision(7) << (double) sum / n << '\n';
}