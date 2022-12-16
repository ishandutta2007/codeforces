#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 2e5 + 10;
ll n,sr[maxn],sd[maxn];
char s[maxn];
void work() {
	scanf("%lld%s", &n, s + 1);
	ll len = strlen(s + 1), ans = len + 1;
	if (s[1] == 'D') {
		for (ll i = 1; i <= len; ++i)
			if (s[i] == 'D') s[i] = 'R';
			else s[i] = 'D';
	}
	for (ll i = 1; i <= len; ++i)
		sr[i] = sr[i - 1] + (s[i] == 'R'), sd[i] = sd[i - 1] + (s[i] == 'D');
	if (!sd[len]) return printf("%lld\n", n), void();
	ll a = n - sd[len] - 1, b = n - sr[len] - 1, l = 1;
	while (l <= len && s[l] == 'R') ++l;
	ans += a * b + a * (sr[len] - sr[l] + 1) + b * (sd[len] + 1);
	printf("%lld\n", ans);
}

int main() {
	ll t; scanf("%lld", &t);
	while (t--) work();
	return 0;
}