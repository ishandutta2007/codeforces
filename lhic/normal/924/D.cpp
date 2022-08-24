#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const ld eps = 1e-12;

vector<pair<ld, ld> > go;
vector<ld> vv;
vector<ld> st;

ld l[120000];
ld r[120000];

int fv[120000];

bool cmp(const pair<ld, ld> &a, const pair<ld, ld> &b) {
	if (abs(a.first - b.first) <= eps) {
		return a.second > b.second;
	}
	else {
		return a.first < b.first;
	}
}

int get(int x) {
	if (x < 0)
		return 0;
	int ans = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1)
		ans += fv[x];
	return ans;
}

void add(int x) {
	for (; x < vv.size(); x |= (x + 1))
		fv[x] += 1;
}

int fnd(ld x) {
	int k = lower_bound(vv.begin(), vv.end(), x) - vv.begin();
	if (k == vv.size())
		return k - 1;
	if (k == 0)
		return 0;
	if (abs(x - vv[k]) < abs(x - vv[k - 1]))
		return k;
	else
		return k - 1;
}

int n;
ld w;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> w;
	for (int i = 0; i < n; ++i) {
		ld x, v;
		cin >> x >> v;
		l[i] = -x / (v - w);
		r[i] = -x / (v + w);
		vv.push_back(r[i]);
		go.push_back(make_pair(l[i], r[i]));
	}
	sort(vv.begin(), vv.end());
	for (ld x: vv) {
		if (!st.empty() && abs(st.back() - x) <= eps)
			continue;
		st.push_back(x);
	}
	vv = st;
	ll ans = ll(n) * (n - 1) / 2;
	sort(go.begin(), go.end(), cmp);
	for (int i = 0; i < go.size(); ++i) {
		int k = fnd(go[i].second);
		ans -= get(k - 1);
		add(k);
	}
	cout << ans << "\n";
	return 0;
}