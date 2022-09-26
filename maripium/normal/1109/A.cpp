#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n;
int a[N];
int cnt[2][1 << 20];

int main() {
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	long long ans = 0;
	for (int i = 0; i <= n; ++i) {
		if (i) {
			a[i] ^= a[i - 1];
		}
		ans += cnt[i & 1][a[i]];
		cnt[i & 1][a[i]]++;
	}
	cout << ans << '\n';
}