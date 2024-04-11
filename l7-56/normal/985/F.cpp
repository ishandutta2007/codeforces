#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 2e5 + 10, base = 13331, P = 1e9 + 7;
ll n,m,hs[maxn][26],pw[maxn];
ll get(ll l, ll r, ll c) { return (hs[r][c] - hs[l - 1][c] * pw[r - l + 1] % P + P) % P; }
char s[maxn];

int main() {
	scanf("%lld%lld%s", &n, &m, s + 1);
	pw[0] = 1;
	for (ll i = 1; i <= n; ++i) {
		pw[i] = pw[i - 1] * base % P;
		for (ll j = 0; j < 26; ++j)
			hs[i][j] = (hs[i - 1][j] * base % P + (s[i] - 'a' == j)) % P;
	}
	while (m--) {
		ll x, y, len;
		scanf("%lld%lld%lld", &x, &y, &len);
		vector <ll> a,b;
		for (ll c = 0; c < 26; ++c)
			a.push_back(get(x, x + len - 1, c)),
			b.push_back(get(y, y + len - 1, c));
		sort(a.begin(), a.end()), sort(b.begin(), b.end());
		if (a == b) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}