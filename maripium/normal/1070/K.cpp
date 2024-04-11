#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, k;
int a[N], b[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];
	if (a[n] % k) return cout << "No" << '\n',0;
	int step = a[n] / k;
	int ptr = 0;
	for (int i = 1; i <= k; ++i) {
		int nxt = lower_bound(a + 1, a + 1 + n, a[ptr] + step) - a;
		if (a[nxt] != a[ptr] + step) return cout << "No" << '\n',0;
		b[i] = nxt - ptr;
		ptr = nxt;
	} 
	cout << "Yes" << '\n';
	for (int i = 1; i <= k; ++i) cout << b[i] << ' '; 
}