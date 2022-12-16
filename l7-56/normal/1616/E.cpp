#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll maxn = 1e5 + 10, inf = 3e18;
char s[maxn],t[maxn];
vector <ll> pos[30];
ll p[30],c[maxn],n,T;

void add(ll pos, ll val) {
	for (; pos <= n; pos += pos & (-pos)) c[pos] += val;
}

ll ask(ll pos) {
	ll res = 0;
	for (; pos; pos &= pos - 1) res += c[pos];
	return res;
}

int main() {
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld%s%s", &n, s + 1, t + 1);
		for (ll ch = 0; ch < 26; ++ch) pos[ch].clear(), p[ch] = 0;
		for (ll i = 1; i <= n; ++i) c[i] = 0;
		for (ll i = 1; i <= n; ++i) add(i, 1), pos[s[i] - 'a'].push_back(i);
		ll tot = 0, ans = inf;
		for (ll i = 1; i <= n; ++i) {
			for (ll ch = 0; ch < t[i] - 'a'; ++ch)
				if (p[ch] < (ll) pos[ch].size()) ans = min(ans, tot + ask(pos[ch][p[ch]] - 1));
			ll ch = t[i] - 'a';
			if (p[ch] < (ll) pos[ch].size()) {
				tot += ask(pos[ch][p[ch]] - 1);
				add(pos[ch][p[ch]], -1);
				++p[ch];
			}
			else break;
		}
		printf("%lld\n", ans < inf ? ans : -1);
	}
	return 0;
}
//