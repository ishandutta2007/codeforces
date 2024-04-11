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

int n;
t3 p[100010];
int T[100010];
int update(int x) { for(int i=x;i<100010;i+=(i&-i)) T[i]++; }
int read(int l, int r) {
	int res = 0;
	for(int i=r;i;i-=(i&-i)) res += T[i];
	for(int i=l-1;i;i-=(i&-i)) res -= T[i];
	return res;
}

void solve() {
	int w;
	scanf("%d%d", &n, &w);
	rep(i, n) {
		int x, y; scanf("%d%d", &x, &y);
		p[i] = t3(x, y, i);
		get<1>(p[i]) -= w;
	}
	sort(p, p+n, [](t3 a, t3 b) {
		ll v = (ll) get<0>(a) * get<1>(b) - (ll)get<1>(a) * get<0>(b);
		ll w = (ll) get<1>(b) * get<1>(a);
		if(w > 0) v = -v;
		if(v != 0) return v < 0;
		ll v2 = -get<0>(a) + get<0>(b);
		if(w > 0) v2 = -v2;
		return v2 < 0;
	});
	rep(i, n) get<2>(p[i]) = i, get<1>(p[i]) += 2 * w;
	sort(p, p+n, [](t3 a, t3 b) {
		ll v = (ll) get<0>(a) * get<1>(b) - (ll)get<1>(a) * get<0>(b);
		ll w = (ll) get<1>(b) * get<1>(a);
		if(w > 0) v = -v;
		if(v != 0) return v < 0;
		ll v2 = -get<0>(a) + get<0>(b);
		if(w < 0) v2 = -v2;
		return v2 < 0;
	});
	ll ans = 0;
	rep(i, n) {
		ans += get<2>(p[i]) - read(1, get<2>(p[i]));
		update(get<2>(p[i]) + 1);
	}
	printf("%lld\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}