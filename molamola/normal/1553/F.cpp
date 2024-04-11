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

struct fen {
	ll T[300030];
	void init() { memset(T, 0, sizeof T); }
	void update(int x, ll v) {
		for(int i = x; i < 300030; i += (i & -i)) T[i] += v;
	}
	ll read(int l, int r) {
		ll res = 0;
		for(int i=r;i;i-=(i&-i)) res += T[i];
		for(int i=l-1;i;i-=(i&-i)) res -= T[i];
		return res;
	}
} T[3];

int n, p[200020];

void solve() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", p + i);
	ll ans = 0;
	const int L = 300000;
	for(int i=1;i<=n;i++) {
		int x = p[i];
		ans += T[0].read(1, x - 1);
		ans += T[2].read(1, x) * x - T[1].read(1, x);
		for(int j=x;j<=L;j+=x) {
			int r = min(j + x - 1, L);
			ll cnt = T[2].read(j, r);
			ans += cnt * x;
			ans += T[0].read(j, r) - cnt * (j / x) * x;
		}
		printf("%lld ", ans);
		for(int j=x;j<=L;j+=x) {
			T[1].update(j, x);
		}
		T[0].update(x, x);
		T[2].update(x, 1);
	} puts("");
}

int main() {
	int TC = 1; //scanf("%d", &TC);
	rep(tt, TC) {
		solve();
	}
	return 0;
}