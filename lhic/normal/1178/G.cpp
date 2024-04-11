#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int N = 200100;

int p[N];
vector<int> eds[N];
int tin[N];
int tout[N];
ll C[N];
int A[N];
ll a[N];
ll b[N];
int tm1;

int n;
int q;
vector<int> GG;

void dfs1(int v, int ca, int cb) {
	ca += A[v];
	cb += C[v];
	A[v] = ca;
	C[v] = abs(cb);
	a[tm1] = C[v];
	b[tm1] = A[v] * C[v];
	tin[v] = tm1++;
	GG.push_back(v);
	for (int u: eds[v])
		dfs1(u, ca, cb);
	tout[v] = tm1;
}

const int SQ = 300;

ll ans[N];
ll ad[N];
int tp[N];
int tv[N];
int tx[N];

vector<array<ll, 2>> Vv[N / SQ];
vector<int> gg[N / SQ];

void prebuild(int k) {
	int l = k * SQ;
	int r = min(n, (k + 1) * SQ);
	gg[k].clear();
	for (int i = l; i < r; ++i)
		gg[k].push_back(i);
	sort(ALL(gg[k]), [&] (int x, int y) -> bool {
				return make_pair(a[x], b[x]) > make_pair(a[y], b[y]);
			});
}

bool bad(const array<ll, 2>& a, const array<ll, 2>& b, const array<ll, 2>& c) {
	return (a[1] - b[1]) * (c[0] - b[0]) >= (b[1] - c[1]) * (b[0] - a[0]);
}

void build(int k) {
	int l = k * SQ;
	int r = min(n, (k + 1) * SQ);
	auto& vv = Vv[k];
	vv.clear();
	for (int i = l; i < r; ++i)
		b[i] += a[i] * ad[k];
	ad[k] = 0;
	for (int i: gg[k]) {
		if (!vv.empty() && vv.back()[1] >= b[i])
			continue;
		array<ll, 2> cur = {a[i], b[i]};
		while (vv.size() >= 2 && bad(cur, vv.back(), vv[vv.size() - 2]))
			vv.pop_back();
		vv.push_back(cur);
	}
}

void upd(int k, int l, int r, ll x) {
	for (int i = l; i < r; ++i)
		b[i] += a[i] * x;
	build(k);
}

void add(int l, int r, ll x) {
	int kl = l / SQ;
	int kr = (r - 1) / SQ;
	for (int i = kl + 1; i < kr; ++i)
		ad[i] += x;
	if (kl == kr)
		upd(kl, l, r, x);
	else {
		if (kl * SQ == l)
			ad[kl] += x;
		else
			upd(kl, l, (kl + 1) * SQ, x);
		if ((kr + 1) * SQ == r)
			ad[kr] += x;
		else
			upd(kr, kr * SQ, r, x);
	}
}

ll get2(int k) {
	ll ans = 0;
	auto& vv = Vv[k];
	while (vv.size() >= 2 && vv.back()[0] * ad[k] + vv.back()[1] <= vv[vv.size() - 2][0] * ad[k] + vv[vv.size() - 2][1])
		vv.pop_back();
	if (!vv.empty())
		ans = max(ans, vv.back()[0] * ad[k] + vv.back()[1]);
	return ans;
}

ll get3(int k, int l, int r) {
	ll ans = 0;
	for (int i = l; i < r; ++i)
		ans = max(ans, a[i] * ad[k] + b[i]);
	return ans;
}

ll get(int l, int r) {
	ll ans = 0;
	int kl = l / SQ;
	int kr = (r - 1) / SQ;
	for (int i = kl + 1; i < kr; ++i)
		ans = max(ans, get2(i));
	if (kl == kr)
		ans = max(ans, get3(kl, l, r));
	else {
		if (kl * SQ == l)
			ans = max(ans, get2(kl));
		else
			ans = max(ans, get3(kl, l, (kl + 1) * SQ));
		if ((kr + 1) * SQ == r)
			ans = max(ans, get2(kr));
		else
			ans = max(ans, get3(kr, kr * SQ, r));
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n >> q;
	for(int i = 1; i < n; ++i) {
		cin >> p[i], --p[i];
		eds[p[i]].push_back(i);
	}
	for (int i = 0; i < n; ++i)
		cin >> A[i];
	for (int i = 0; i < n; ++i)
		cin >> C[i];
	dfs1(0, 0, 0);
	for (int i = 0; i < n; i += SQ)
		prebuild(i / SQ);
	for (int i = 0; i < n; i += SQ)
		ad[i / SQ] = 0, build(i / SQ);
	for (int i = 0; i < q; ++i) {
		cin >> tp[i];
		if (tp[i] == 1) {
			cin >> tv[i] >> tx[i];
			--tv[i];
			add(tin[tv[i]], tout[tv[i]], tx[i]);
		}
		else {
			cin >> tv[i];
			--tv[i];
			ans[i] = max(ans[i], abs(get(tin[tv[i]], tout[tv[i]])));
		}
	}
	for (int i = 0; i < n; ++i) {
		b[i] += a[i] * ad[i / SQ];
		b[i] = -b[i];
	}
	for (int i = 0; i < n; i += SQ)
		ad[i / SQ] = 0, build(i / SQ);
	for (int i = q - 1; i >= 0; --i) {
		if (tp[i] == 1) {
			add(tin[tv[i]], tout[tv[i]], tx[i]);
		}
		else {
			ans[i] = max(ans[i], abs(get(tin[tv[i]], tout[tv[i]])));
		}
	}
	for (int i = 0; i < q; ++i)
		if (tp[i] == 2)
			cout << ans[i] << "\n";
	return 0;
}