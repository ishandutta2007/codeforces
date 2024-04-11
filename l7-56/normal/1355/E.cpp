#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
typedef long double ld;
using namespace std;

const ll maxn = 1e5 + 10;
ll h[maxn],n,A,R,M;

ll f(ll H) {
	ll cnt[2];
	cnt[0] = cnt[1] = 0;
	for(ll i = 1; i <= n; ++i)
		cnt[h[i] >= H] += abs(h[i] - H);
	return min(cnt[0], cnt[1]) * min(M, A + R) + max(cnt[0] - cnt[1], 0ll) * A + max(cnt[1] - cnt[0], 0ll) * R;
}

int main() {
	ll l = 1, r = 0, mid, ans = -1;
	scanf("%lld%lld%lld%lld", &n, &A, &R, &M);
	for(ll i = 1; i <= n; ++i) scanf("%lld", &h[i]), r = max(r, h[i]);
	while(l <= r) {
		mid = (l + r) >> 1;
		if(f(mid + 1) >= f(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%lld", f(ans));
	return 0;
}