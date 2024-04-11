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


int main() {
	int n, m; scanf("%d%d", &n, &m);
	if(n > m) swap(n, m);
	if(n == 1) {
		ll ans = 0;
		if(m > 6) {
			ll t = (m - 1) / 6 * 6;
			ans += t; m -= t;
		}
		int xx[7] = {0, 0, 0, 0, 2, 4, 6};
		printf("%lld\n", ans + xx[m]);
	}
	else if(n == 2) {
		ll xx[9] = {0, 0, 0, 4, 8, 10, 12, 12, 16};
		if(m <= 8) printf("%lld\n", xx[m]);
		else printf("%lld\n", 2LL*m);
	}
	else {
		ll t = (ll)n * m;
		if(t % 2 == 1) --t;
		printf("%lld\n", t);
	}
	return 0;
}