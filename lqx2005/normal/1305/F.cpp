#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5 + 10, K = 16;
int n;
ll a[N], f[N], g[N * K];
mt19937 rnd(__builtin_ia32_rdtsc());
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	ll l = max(1ll, a[1] - n), r = a[1] + n;
	for(ll i = l; i <= r; i++) f[i - l] = i;
	int tot = 0;
	int v = 1e6;
	for(int i = 2; i <= v; i++) {
		ll k = (l + i - 1) / i * i;
		int est = 0;
		for(ll j = k; j <= r; j += i) {
			if(f[j - l] % i == 0) {
				while(f[j - l] % i == 0) f[j - l] /= i, est = 1;
			}			
		}
		if(est) g[++tot] = i;
	}
	for(ll i = l; i <= r; i++) if(f[i - l] > 1) g[++tot] = f[i - l];
	sort(g + 1, g + tot + 1);
	tot = unique(g + 1, g + tot + 1) - (g + 1);
	shuffle(a + 1, a + n + 1, rnd);
	shuffle(a + 1, a + n + 1, rnd);
	shuffle(a + 1, a + n + 1, rnd);
	shuffle(a + 1, a + n + 1, rnd);
	int ans = n;
	for(int i = 1; i <= tot; i++) {
		ll p = g[i];
		ll sum = 0;
		for(int j = 1; j <= n; j++) {
			if(a[j] < p) sum += p - a[j];
			else sum += min(a[j] % p, (p - a[j] % p) % p);
			if(sum > ans) break;
		}
		if(sum < ans) ans = sum;
	}
	cout << ans << endl;
	return 0;
}