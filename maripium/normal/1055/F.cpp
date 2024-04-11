#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n;
long long k;
long long a[N];
int from[N], to[N];
int le[N], ri[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 2; i <= n; ++i) {
		int p; long long w; cin >> p >> w;
		a[i] = a[p] ^ w;
	}
	sort(a + 1, a + n + 1);
	long long ans = 0;
	for (int i = 1; i <= n; ++i) from[i] = 1, to[i] = n;
	for (int b = 61; b >= 0; --b) {
		int pre = 1;
		while (pre <= n) {
			int nxt = pre;
			while (nxt + 1 <= n && (a[nxt] ^ a[nxt + 1]) < (1LL << b)) nxt++;
			le[nxt] = pre, ri[pre] = nxt, pre = nxt + 1;
		}
		long long add = 0;
		for (int i = 1; i <= n; ++i) if (from[i] <= to[i]) {
			if ((a[i] >> b) & 1LL) {
				if ((a[to[i]] >> b) & 1LL) add += to[i] - le[to[i]] + 1;
			}
			else {
				if (((a[from[i]] >> b) & 1LL) == 0LL) add += ri[from[i]] - from[i] + 1;
			}
		}
		long long inc = 0;
		if (add < k) {
			k -= add;
			ans += (1LL << b);
			inc = 1;
		}
		for (int i = 1; i <= n; ++i) if (from[i] <= to[i]) {
			if (((a[i] >> b) & 1LL) == inc) {
				if ((a[from[i]] >> b) & 1LL) to[i] = from[i] - 1;
				else to[i] = ri[from[i]];
			} else {
				if (((a[to[i]] >> b) & 1LL) == 0LL) from[i] = to[i] + 1;
				else from[i] = le[to[i]];
			}
		}
	}
	cout << ans << '\n';
}