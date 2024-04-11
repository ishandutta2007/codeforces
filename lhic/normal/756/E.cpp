#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const ll MAXN = 310000;
const ll MOD = 1e9 + 7;
const ll MD = 1e9;


int n;
ll a[MAXN];
ll b[MAXN];
vector<tuple<int, int, int> > vv;
ll rm[MAXN];
char ss[MAXN];
ll dp[MAXN];
ll dp2[MAXN];
ll d[MAXN];
int dlen;

ll rem(ll x) {
	ll now = 0;
	for (int i = dlen - 1; i >= 0; --i) {
		now *= MD;
		d[i] += now;
		now = d[i] % x;
		d[i] /= x;
	}
	while (dlen > 0 && d[dlen - 1] == 0)
		--dlen;
	return now;
}

ll get() {
	ll ans = 0;
	for (int i = dlen - 1; i >= 0; --i) {
		ans = (ans * MD + d[i]);
		if (ans >= MAXN) {
			cout << 0 << "\n";
			exit(0);
		}
	}
	return ans;
}

void init() {
	int slen = strlen(ss);
	reverse(ss, ss + slen);
	int k = 0;
	for (int i = 0; i < slen; i += 9) {
		ll now = 0;
		for (int j = min(slen - 1, i + 8); j >= i; --j)
			now = (now * 10 + ss[j] - '0');
		d[k++] = now;
	}
	dlen = k;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
		scanf("%lld", a + i);
	for (int i = 0; i < n; ++i)
		scanf("%lld", b + i);
	scanf(" %s", ss);
	init();
	int l = 0;
	int cnt = 0;
	a[n - 1] = 1;
	for (int i = 0; i < n; ++i) {
		cnt += b[i];
		if (i == n - 1 || a[i] != 1) {
			vv.push_back(make_tuple(l, i, cnt));
			l = i + 1;
			cnt = 0;
		}
	}
	for (int i = 0; i < vv.size(); ++i) {
		int l, r, cnt;
		tie(l, r, cnt) = vv[i];
		rm[i] = rem(a[r]);
	}
	ll now = get();
	dp[now] = 1;
	for (int i = vv.size() - 1; i >= 0; --i) {
		int l, r, cnt;
		tie(l, r, cnt) = vv[i];
		ll cc = 1;
		for (int j = i; j >= 0 && j > i - 20; --j)
			cc += get<2>(vv[j]);
		cc = min(cc, now * a[r] + rm[i]);
		now = cc;
		for (int i = 0; i <= cc; ++i)
			dp2[i] = 0;
		for (ll j = 0; j * a[r] + rm[i] <= cc; ++j)
			dp2[j * a[r] + rm[i]] += dp[j];
		for (int j = 0; j <= cc; ++j)
			dp[j] = dp2[j];
		for (int j = l; j <= r; ++j) {
			int c = b[j];
			memset(dp2, 0, sizeof(dp2[0]) * (cc + 1));
			ll sum = 0;
			for (int k = cc; k >= 0; --k) {
				sum += dp[k];
				if (k + c < cc)
					sum -= dp[k + c + 1];
				if (sum >= MOD)
					sum -= MOD;
				else if (sum < 0)
					sum += MOD;
				dp2[k] = sum;
			}
			memcpy(dp, dp2, sizeof(dp2[0]) * (cc + 1));
		}
	}
	cout << dp[0] << "\n";
	return 0;
}