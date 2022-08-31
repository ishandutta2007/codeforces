#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1e9 + 7;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
const int MX = 410000;

string a, b;
int c[4];
int ctmp[4];
int cc[4];
ll fc[MX];
ll bfc[MX];

ll cnk(int n, int k) {
	if (k > n)
		return 0;
	return fc[n] * bfc[k] % MOD * bfc[n - k] % MOD;
}

ll get2(int a, int b) {
	if (a == 0 && b == 0)
		return 1;
	return cnk(a - 1 + b, b);
}

ll get(int st) {
	for (int i = 0; i < 4; ++i)
		if (c[i] < 0)
			return 0;
	for (int i = 0; i < 4; ++i)
		cc[i] = c[i];
	if (st == 1)
		swap(cc[0], cc[3]), swap(cc[1], cc[2]);
	if (cc[1] == cc[2]) {
		return get2(cc[1] + 1, cc[0]) * get2(cc[1], cc[3]) % MOD;
	}
	else if (cc[1] == cc[2] + 1) {
		return get2(cc[1], cc[0]) * get2(cc[1], cc[3]) % MOD;
	}
	else
		return 0;
}

ll solve(string b) {
	int sm = 1 + c[0] + c[1] + c[2] + c[3];
	if (sm < b.size())
		return get(1);
	if (sm > b.size())
		return 0;
	ll ans = 0;
	for (int i = (int)b.size() - 2; i >= 0; --i) {
		int x = (b[i + 1] - '0') * 2;
		if (b[i] == '1') {
			--c[x];
			ans = (ans + get(0)) % MOD;
			++c[x];
		}
		x += b[i] - '0';
		--c[x];
	}
	return ans;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	fc[0] = 1;
	for (int i = 1; i < MX; ++i)
		fc[i] = (fc[i - 1] * i) % MOD;
	bfc[MX - 1] = pw(fc[MX - 1], MOD - 2);
	for (int i = MX - 2; i >= 0; --i)
		bfc[i] = (bfc[i + 1] * (i + 1)) % MOD;
	cin >> a >> b;
	for (int i = 0; i < 4; ++i)
		cin >> c[i], ctmp[i] = c[i];
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int cur = 0;
	while (cur < b.size() && b[cur] == '1')
		b[cur] = '0', ++cur;
	if (cur == b.size())
		b += '1';
	else
		b[cur] = '1';
	ll ans = solve(b);
	for (int i = 0; i < 4; ++i)
		c[i] = ctmp[i];
	ans = (ans + MOD - solve(a)) % MOD;
	cout << ans << "\n";
	return 0;
}