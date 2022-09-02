#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>
#include <time.h>
#include <limits.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb push_back
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

ll N, K, A, B;

ll gc(ll x, ll y) { return y ? gc(y, x%y) : x; }

int main() {
	scanf("%lld%lld%lld%lld", &N, &K, &A, &B);
	ll s = A;
	ll ans[2]; ans[0] = 1e18, ans[1] = -1e18;
	for(int i=0;i<N;i++) {
		ll t = (ll)i * K;
		ll a[2];
		a[0] = (t + B) % (N*K);
		a[1] = (t - B + N*K) % (N*K);
		rep(u, 2) {
			ll val = (a[u] - s + N*K) % (N*K);
			ll g = (N*K) / gc(val, N*K);
			ans[0] = min(ans[0], g);
			ans[1] = max(ans[1], g);
		}
	}
	printf("%lld %lld\n", ans[0], ans[1]);
	return 0;
}