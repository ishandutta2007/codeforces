#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

const int mod = 1e9 + 7;
int pw(int x, int y = mod - 2) {
	int res = 1;
	while(y) {
		if(y & 1) res = (ll) res * x % mod;
		x = (ll)x * x % mod;
		y >>= 1;
	}
	return res;
}

int n, k;
int ft[200020], ift[200020];

void solve() {
	scanf("%d%d", &n, &k);
	ll ans = 0;
	for(int a=1;n-k*(a-1)-1>=0;a++) {
		ll val = (ll)ft[a] * ft[n-a] % mod * ift[n] % mod;
		int x = n - k * (a - 1) - 1 + a;
		val = val * ft[x] % mod * (ll)ift[a] % mod * ift[x-a] % mod;
		ans = (ans + val) % mod;
	}
	printf("%lld\n", (ans + 1) % mod);
}

int main() {
	ft[0] = 1;
	for(int i=1;i<200020;i++) ft[i] = (ll) i * ft[i-1] % mod;
	ift[200019] = pw(ft[200019]);
	for(int i=200018;i>=0;i--) ift[i] = (ll) (i+1) * ift[i+1] % mod;
	int T = 1; scanf("%d", &T);
	rep(tt, T) {
		solve();
	}
	return 0;
}