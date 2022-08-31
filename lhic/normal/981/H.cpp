#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 998244353;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}

const ll B = 662;
const int MAXN = 210000;

int sz[MAXN];
vector<int> eds[MAXN];

void dfs1(int v, int p) {
	sz[v] = 1;
	for (int u: eds[v]) {
		if (u == p)
			continue;
		dfs1(u, v);
		sz[v] += sz[u];
	}
}

int rev(int x, int k) {
	int ans = 0;
	for (int i = 0; i < k; ++i) {
		ans = ans * 2 + (x & 1);
		x >>= 1;
	}
	return ans;
}

void fft(ll *a, int k, int inv) {
	int n = (1 << k);
	for (int i = 0; i < n; ++i) {
		int x = rev(i, k);
		if (x > i)
			swap(a[x], a[i]);
	}
	for (int bl = 1; bl < n; bl *= 2) {
		ll wadd = pw(B, (1 << 21) / bl);
		if (inv)
			wadd = pw(wadd, MOD - 2);
		for (int i = 0; i < n; i += 2 * bl) {
			ll w = 1;
			for (int j = i; j < i + bl; ++j, w = (w * wadd) % MOD) {
				ll u = a[j];
				ll v = a[j + bl] * w % MOD;
				a[j] = (u + v) % MOD;
				a[j + bl] = (u - v + MOD) % MOD;
			}
		}
	}
	if (inv) {
		ll x = pw(n, MOD - 2);
		for (int i = 0; i < n; ++i)
			a[i] = (a[i] * x) % MOD;
	}
}

ll a[MAXN * 4];
ll b[MAXN * 4];

void mult(vector<ll> &vl, const vector<ll> &vr) {
	int nd = (int)vl.size() - 1 + (int)vr.size() - 1 + 1;
	int k = 0;
	while ((1 << k) < nd)
		++k;
	for (int i = 0; i < (1 << k); ++i)
		a[i] = b[i] = 0;
	for (int i = 0; i < vl.size(); ++i)
		a[i] = vl[i];
	for (int j = 0; j < vr.size(); ++j)
		b[j] = vr[j];
	fft(a, k, 0);
	fft(b, k, 0);
	for (int i = 0; i < (1 << k); ++i)
		a[i] = (a[i] * b[i]) % MOD;
	fft(a, k, 1);
	vl.clear();
	for (int i = 0; i < nd; ++i)
		vl.push_back(a[i]);
}
vector<int> vv;
int n, k;

vector<ll> run(int l, int r) {
	if (l + 1 == r) {
		return {1, vv[l]};
	}
	int m = (l + r) >> 1;
	vector<ll> vl = run(l, m);
	vector<ll> vr = run(m, r);
	mult(vl, vr);
	while (vl.size() >= 2 && vl.back() == 0)
		vl.pop_back();
	if (vl.size() > k + 1)
		vl.resize(k + 1);
	return vl;
}
ll ans = 0;
ll gsum = 0;
ll dp[MAXN];
vector<ll> gg[MAXN];
const int MX = MAXN;
ll fc[MX];
ll bfc[MX];

void dfs2(int v, int p, ll up) {
	ans = (ans + dp[v] * gsum) % MOD;
	ans = (ans + dp[v] * up) % MOD;
	for (int i = 0; i < eds[v].size(); ++i) {
		int u = eds[v][i];
		if (u == p)
			continue;
		dfs2(u, v, (up + gg[v][i]) % MOD);
	}
	gsum = (gsum + dp[v]) % MOD;
}

set<int> ss;
ll mm[MAXN];

vector<ll> now;
vector<ll> tmp;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	fc[0] = 1;
	for (int i = 1; i < MX; ++i)
		fc[i] = (fc[i - 1] * i) % MOD;
	bfc[MX - 1] = pw(fc[MX - 1], MOD - 2);
	for (int i = MX - 2; i >= 0; --i) {
		bfc[i] = (bfc[i + 1] * (i + 1)) % MOD;
	}
	cin >> n >> k;
	if (k == 1) {
		cout << ll(n) * (n - 1) / 2 % MOD << "\n";
		return 0;
	}
	if (n == 1) {
		cout << 0 << "\n";
		return 0;
	}
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs1(0, -1);
	for (int v = 0; v < n; ++v) {
		ss.clear();
		vv.clear();
		for (int u: eds[v]) {
			if (sz[u] > sz[v]) {
				int s = n - sz[v];
				ss.insert(s);
				vv.push_back(s);
			}
			else {
				ss.insert(sz[u]);
				vv.push_back(sz[u]);
			}
		}
		tmp = run(0, vv.size());
		for (ll c: ss) {
			now = tmp;
			for (int i = 0; i + 1 < now.size(); ++i) {
				now[i + 1] = (now[i + 1] - c * now[i] + MOD * MOD) % MOD;
			}
			ll ans = 0;
			for (int i = 0; i <= k && i < now.size(); ++i) {
				ans = (ans + fc[k] * bfc[k - i] % MOD * now[i]) % MOD;
			}
			mm[c] = ans;
		}
		for (int u: eds[v]) {
			if (sz[u] > sz[v]) {
				dp[v] = mm[n - sz[v]];
				gg[v].push_back(0);
			}
			else {
				gg[v].push_back(mm[sz[u]]);
			}
		}
	}
	dfs2(0, -1, 0);
	cout << ans << "\n";
	return 0;
}