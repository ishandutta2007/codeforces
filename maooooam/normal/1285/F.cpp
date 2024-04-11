#include <bits/stdc++.h>
using namespace std;

constexpr const int maxn = 100000;
int vis[maxn + 1], mu[maxn + 1], cnt[maxn + 1];
vector<int> prime, f[maxn + 1], stk;

int count(int x) { int res = 0; for (int p : f[x]) res += mu[p] * cnt[p]; return res; }

void update(int x, int d) { for (int p : f[x]) cnt[p] += d; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	mu[1] = 1;
	for (int i = 2; i <= maxn; ++i) {
		if (!vis[i]) {
			prime.push_back(i);
			mu[i] = -1;
		}
		for (int p : prime) {
			if (i * p > maxn) break;
			vis[i * p] = 1;
			if (i % p == 0) break;
			mu[i * p] = -mu[i];
		}
	}
	for (int i = 1; i <= maxn; ++i) for (int j = i; j <= maxn; j += i) f[j].push_back(i);
	memset(vis, 0, sizeof (vis));
	int n;
	cin >> n;
	long long ans = 0;
	while (n--) {
		int a;
		cin >> a;
		for (int x : f[a]) vis[x] = 1;
		ans = max(ans, 1LL * a);
	}
	for (int i = maxn; i; --i) if (vis[i]) {
		while (count(i)) {
			ans = max(ans, 1LL * i * stk.back());
			update(stk.back(), -1);
			stk.pop_back();
		}
		update(i, 1);
		stk.push_back(i);
	}
	cout << ans << endl;
}