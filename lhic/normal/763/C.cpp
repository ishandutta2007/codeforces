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

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
		cerr << (*i) << " ";
    }
    cerr << "\n";
}

ll pw(ll a, ll b, ll MOD) {
	ll ans = 1;
	while (b) {
		while (!(b & 1))
			b >>= 1, a = (a * a) % MOD;
		--b;
		ans = (ans * a) % MOD;
	}
	return ans;
}

ll a[220000];
int en[220000];
set<ll> ss;

pair<ll, ll> solve(int n, ll m) {
	ll x = (a[1] - a[0] + m) % m;
	for (int i = 0; i < n; ++i)
		ss.insert(a[i]);
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		if (ss.count((a[i] + x) % m))
			++cnt;
	cnt = n - cnt;
	ll d = x * pw(cnt, m - 2, m) % m;
	int cc = 1;
	int now = (a[0] + d) % m;
	while (ss.count(now))
		++cc, now = (now + d) % m;
	now = (a[0] - d + m) % m;
	while (ss.count(now))
		++cc, now = (now - d + m) % m;
	if (cc == n)
		return make_pair((now + d) % m, d);
	else {
		cout << "-1\n";
		exit(0);
	}
}

int main() {
	ll m;
	int n;
	scanf("%lld%d", &m, &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i);
	sort(a, a + n);
	if (n == 1) {
		cout << a[0] << " " << 0 << "\n";
		return 0;
	}
	if (n == m) {
		cout << 0 << " " << 1 << "\n";
		return 0;
	}
	if (2 * n > m) {
		for (int i = 0; i < n; ++i)
			en[a[i]] = 1;
		int cc = 0;
		for (int i = 0; i < m; ++i)
			if (!en[i])
				a[cc++] = i;
		pair<ll, ll> ans = solve(cc, m);
		ans.first += cc * ans.second;
		ans.first %= m;
		cout << ans.first << " " << ans.second << "\n";
	}
	else {
		pair<ll, ll> ans = solve(n, m);
		cout << ans.first << " " << ans.second << "\n";
	}
	return 0;
}