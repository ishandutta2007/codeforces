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


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 310000;
const int LOG = 20;
const ll MOD = 1e9 + 7;

vector<int> pp;
int pr[MAXN];
int cc[LOG];
int n;
int cc2[MAXN][LOG];
ll fc[MAXN];
ll bfc[MAXN];
int a[MAXN];
ll pw2[MAXN];


ll cnk(int n, int k) {
	if (k > n)
		return 0;
	ll ans = (fc[n] * bfc[k]) % MOD;
	return (ans * bfc[n - k]) % MOD;
}

ll solve() {
	int l = 0;
	int r = n;
	ll ans = 0;
	for (int i = 0; i < LOG - 1; ++i) {
		l +=  cc[i];
		r -= cc[i];
		ll go = 0;
		for (int k = 1; k <= r; ++k) {
			go += k * cnk(l, k);
			go %= MOD;
			ans += cnk(r, k) * go;
			ans %= MOD;
		}
	}
	l = 0;
	r = n;
	for (int i = 0; i < LOG - 1; ++i) {
		l +=  cc[i];
		r -= cc[i];
		ll go = pw2[l];
		for (int k = 0; k <= r; ++k) {
			go -= cnk(l, k);
			if (go < 0)
				go += MOD;
			ans += ((k * cnk(r, k)) % MOD) * go;
			ans %= MOD;
		}
	}
	return ans;
}

ll pw(ll a, ll b) {
	ll ans = 1;
	while (b) {
		while (!(b & 1))
			b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD;
		--b;
	}
	return ans;
}

int main() {
	for (int i = 0; i < MAXN; ++i)
		pr[i] = i;
	for (int i = 2; i < MAXN; ++i) {
		if (pr[i] == i)
			pp.push_back(i);
		for (int j: pp) {
			if (j * i >= MAXN || pr[i] < j)
				break;
			pr[i * j] = j;
		}
	}

	pw2[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		pw2[i] = (pw2[i - 1] * 2) % MOD;

	fc[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		fc[i] = (fc[i - 1] * i) % MOD;
	bfc[MAXN - 1] = pw(fc[MAXN - 1], MOD - 2);
	for (int i = MAXN - 2; i >= 0; --i)
		bfc[i] = (bfc[i + 1] * (i + 1)) % MOD;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < n; ++i) {
		int tmp = a[i];
		while (tmp != 1) {
			int x = pr[tmp];
			int cnt = 0;
			while (pr[tmp] == x)
				tmp /= x, ++cnt;
			++cc2[x][cnt];
		}
	}


	ll ans = 0;
	for (int i = 2; i < MAXN; ++i) {
		if (pr[i] != i)
			continue;
		memcpy(cc, cc2[i], sizeof(cc));
		int sm = 0;
		for (int j = 0; j < LOG; ++j)
			sm += cc[j];
		cc[0] = n - sm;
		ans = (ans + solve()) % MOD;
	}
	cout << ans << "\n";
	return 0;
}