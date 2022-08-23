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


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/
const int MAXN = 310000;

ll gcd(ll a, ll b) {
	while (b) {
		ll q = a % b;
		a = b;
		b = q;
	}
	return a;
}

int n;
ll a[MAXN];
const int XM = 16000000;
int bb[XM];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	vector<int> pr;
	for (int i = 0; i < XM; ++i)
		bb[i] = i;
	for (int i = 2; i < XM; ++i) {
		if (i == bb[i])
			pr.push_back(i);
		for (int j: pr) {
			if (j * i >= XM || j > bb[i])
				break;
			bb[i * j] = j;
		}
	}
	cin >> n;
	ll now = 0;
	for (int i = 0; i < n; ++i)
		cin >> a[i], now = gcd(now, a[i]);
	for (int i = 0; i < n; ++i)
		a[i] /= now;
	vector<int> go;
	for (int i = 0; i < n; ++i) {
		while (a[i] != 1) {
			int x = bb[a[i]];
			while (a[i] % x == 0)
				a[i] /= x;
			go.push_back(x);
		}
	}
	sort(go.begin(), go.end());
	int ans = n;
	int cnt = 0;
	for (int i = 0; i < go.size(); ++i) {
		++cnt;
		ans = min(ans, n - cnt);
		if (i == go.size() - 1 || go[i + 1] != go[i])
			cnt = 0;
	}
	if (ans == n)
		cout << -1 << "\n";
	else
		cout << ans << "\n";
	return 0;
}