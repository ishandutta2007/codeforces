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
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

t3 p[100010];

void solve() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		int x, y; scanf("%d%d", &x, &y);
		p[i] = t3(x, y, i);
	}
	sort(p+1, p+1+n);
	for(int i=n;i;i--) get<0>(p[i]) -= get<0>(p[1]), get<1>(p[i]) -= get<1>(p[1]);
	sort(p+2, p+1+n, [&](t3 a, t3 b) {
		ll v = get<0>(a) * (ll)get<1>(b) - get<1>(a) *(ll)get<0>(b);
		if(v != 0) return v > 0;
		return (ll)get<0>(a) *get<0>(a) + get<1>(a) * (ll)get<1>(a) < (ll)get<0>(b) * get<0>(b) + (ll)get<1>(b) * get<1>(b);
	});
	for(int i=3;i<=n;i++) if(get<0>(p[i]) * (ll)get<1>(p[2]) != (ll)get<1>(p[i]) * get<0>(p[2])) {
		printf("%d %d %d\n", get<2>(p[1]), get<2>(p[2]), get<2>(p[i]));
		return;
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}