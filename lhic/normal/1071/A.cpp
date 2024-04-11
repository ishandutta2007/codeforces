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

ll a, b;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> a >> b;
	ll k = 0;
	ll sum = 0;
	while (sum + k + 1 <= a + b)
		++k, sum += k;
	vector<int> va, vb;
	for (int i = k; i >= 1; --i) {
		if (i <= a)
			va.push_back(i), a -= i;
		else
			vb.push_back(i);
	}
	sort(ALL(va));
	sort(ALL(vb));
	cout << va.size() << "\n";
	for (int i: va)
		cout << i << " ";
	cout << "\n";
	cout << vb.size() << "\n";
	for (int i: vb)
		cout << i << " ";
	cout << "\n";
	return 0;
}