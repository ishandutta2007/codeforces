#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
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
const int MX = 1e6 + 10;

int n;
int a[MX];
vector<int> gg[MX];

ld get(int c) {
	if (gg[c].empty())
		return 0;
	int lst = -1;
	ld ans = 1;
	for (int i: gg[c]) {
		ld btw = ld(i - lst - 1) / n;
		ans -= btw * btw;
		lst = i;
	}
	ld btw = ld(n - lst - 1) / n;
	ans -= btw * btw;
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i), gg[a[i]].push_back(i);
	ld ans = 0;
	for (int i = 0; i < MX; ++i)
		ans += get(i);
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << ans << "\n";
	return 0;
}