#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
long long a[N + N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n + n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + n + 1);
	long long res = (a[n] - a[1]) * (a[n + n] - a[n + 1]);
	for (int i = 2; i <= n; ++i) {
		res = min(res, (a[n + n] - a[1]) * (a[n + i - 1] - a[i]));
	}
	cout << res;
}