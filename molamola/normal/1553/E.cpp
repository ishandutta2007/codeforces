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

mt19937 rng(0x86201);
int rand_int(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
int p[300030], q[300030], h[300030], chk[300030];

void solve() {
	int n, m; scanf("%d%d", &n, &m);
	rep(i, n) {
		scanf("%d", p + i);
		--p[i];
	}
	set <int> ans;
	auto trial = [&](int x) {
		rep(i, n) {
			q[i] = i - x + n;
			if(q[i] >= n) q[i] -= n;
		}
		rep(i, n) h[p[i]] = q[i];
		int res = n;
		rep(i, n) chk[i] = 0;
		rep(i, n) {
			if(chk[i]) continue;
			chk[i] = 1;
			for(int t = h[i]; t != i; t = h[t]) chk[t] = 1;
			--res;
		}
		if(res <= m) ans.insert(x);
	};
	rep(t, 200) {
		int x = rand_int(0, n - 1);
		int r = (x - p[x] + n) % n;
		trial(r);
	}
	printf("%d ", szz(ans));
	for(int e : ans) printf("%d ", e); puts("");
}

int main() {
	int TC; scanf("%d", &TC);
	rep(tt, TC) {
		solve();
	}
	return 0;
}