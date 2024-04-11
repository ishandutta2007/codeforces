#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int n, m;
ll a, d, A[100010];

void solve() {
	scanf("%d%d%lld%lld", &n, &m, &a, &d);
	for(int i=1;i<=m;i++) {
		ll x; scanf("%lld", &x);
		if(x % a == 0 && a <= x && x <= n*a) { --i; --m; }
		else A[i] = x;
	}
	sort(A+1, A+1+m);
	ll ans = 0, last = -1;
	ll jp = d / a + 1;
	if(m == 0) {
		printf("%lld\n", (n + jp - 1) / jp);
		return;
	}
	if(A[1] > a) {
		ll tk = (min(A[1], n*a) - a) / (a * jp);
		ans += tk + 1;
		last = (1 + tk * jp) * a + d;
		if(last < A[1]) last = A[1] + d, ++ans;
	}
	else {
		ans = 1, last = A[1] + d;
	}
	for(int i=2;i<=m;i++) {
		if(last >= A[i]) continue;
		ll x = last / a + 1;
		if(x > n || x*a > A[i]) last = A[i] + d, ++ans;
		else {
			ll tk = (min(A[i], n*a) - x*a) / (a * jp);
			ans += tk + 1;
			last = (x + tk * jp) * a + d;
			if(last < A[i]) last = A[i] + d, ++ans;
		}
	}
	if(last < n*a) {
		ll x = last / a + 1;
		ll tk = (n - x) / jp;
		ans += tk + 1;
	}
	printf("%lld\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}