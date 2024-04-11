#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 1e6 + 10, base = 131, P1 = 998244353, P2 = 1e9 + 7;
char s[maxn];
ll hs1[maxn],pw1[maxn],hs2[maxn],pw2[maxn];
ll get1(ll l, ll r) { return (hs1[r] - hs1[l - 1] * pw1[r - l + 1] % P1 + P1) % P1; }
ll get2(ll l, ll r) { return (hs2[r] - hs2[l - 1] * pw2[r - l + 1] % P2 + P2) % P2; }
bool chk(ll l1, ll r1, ll l2, ll r2) {
	return get1(l1, r1) == get1(l2, r2) && get2(l1, r1) == get2(l2, r2);
}
ll n,len[maxn],ans[maxn];

int main() {
	// freopen("border.in", "r", stdin), freopen("border.out", "w", stdout);
	scanf("%lld%s", &n, s + 1);// n = strlen(s + 1);
	pw1[0] = pw2[0] = 1;
	for (ll i = 1; i <= n; ++i)
		pw1[i] = pw1[i - 1] * base % P1,
		pw2[i] = pw2[i - 1] * base % P2,
		hs1[i] = (hs1[i - 1] * base % P1 + s[i] - 'a' + 1) % P1,
		hs2[i] = (hs2[i - 1] * base % P2 + s[i] - 'a' + 1) % P2;
	memset(len, -1, sizeof len), memset(ans, -1, sizeof ans);
	for (ll i = 1; i <= n - i; ++i) {
		ll l = 0, r = i - 1, mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (chk(i - mid, i + mid, n - i + 1 - mid, n - i + 1 + mid)) l = mid + 1, len[i] = mid;
			else r = mid - 1;
		}
		len[n - i + 1] = len[i];
	}
	for (ll i = (n + 1) / 2, j = i; i >= 1; --i) {
		if (len[i] == -1) continue;
		for (j = min(i, j); j >= i - len[i]; --j) ans[j] = 2 * (i - j) + 1;
	}
	for (ll i = 1; i <= (n + 1) / 2; ++i) printf("%lld%c", ans[i], " \n"[i == n]);
	return 0;
}