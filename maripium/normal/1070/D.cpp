#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, k;
long long a[N];
long long res;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		res += (a[i] + k - 1) / k;
		if (i < n) {
			int rem = a[i] % k;
			if (rem) {
				a[i + 1] -= k - rem;
				a[i + 1] = max(a[i + 1], 0LL);
			}
		}
	}
	cout << res << '\n';
}