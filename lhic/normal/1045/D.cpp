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
const int MAXN = 120000;
const int SQ = 300;

int n;
string s;
ld p[MAXN];

ld read() {
	cin >> s;
	return s[0] - '0' + 0.1 * (s[2] - '0') + 0.01 * (s[3] - '0');
}

vector<int> eds[MAXN];
int fl[MAXN];
ld cs[MAXN];
vector<int> eds2[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(6);
	cin >> n;
	ld ans = 0;
	for (int i = 0; i < n; ++i) {
		p[i] = read();
		p[i] = 1 - p[i];
		ans += p[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		ans -= p[a] * p[b];
		eds[a].push_back(b);
		eds[b].push_back(a);
		cs[a] += p[b];
		cs[b] += p[a];
	}
	for (int i = 0; i < n; ++i)
		if (eds[i].size() > SQ)
			fl[i] = 1;
	for (int i = 0; i < n; ++i) {
		for (int x: eds[i])
			if (fl[x])
				eds2[i].push_back(x);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int x;
		cin >> x;
		ld np = 1 - read();
		ans += np - p[x];
		if (fl[x]) {
			ans -= (np - p[x]) * cs[x];
		}
		else {
			for (int y: eds[x])
				ans -= (np - p[x]) * p[y];
		}
		for (int y: eds2[x])
			cs[y] += (np - p[x]);
		p[x] = np;
		cout << ans << "\n";
	}
	return 0;
}