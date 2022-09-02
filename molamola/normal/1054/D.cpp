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
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;

int n, k, A[200020];
map <int, int> Mx;

int main() {
	scanf("%d%d", &n, &k);
	Mx[0] = 1;
	int now = 0;
	for(int i=1;i<=n;i++) {
		scanf("%d", A+i);
		now ^= A[i];
		if(now >= (1<<(k-1))) {
			now = (1<<k) - 1 - now;
		}
		Mx[now]++;
	}
	ll ans = (ll)n * (n+1) / 2;
	for(pii e : Mx) {
		int t1 = e.Se / 2;
		int t2 = (e.Se + 1) / 2;
		ans -= (ll) t1 * (t1 - 1) / 2;
		ans -= (ll) t2 * (t2 - 1) / 2;
	}
	printf("%lld\n", ans);
	return 0;
}