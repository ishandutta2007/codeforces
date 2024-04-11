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

int get_level(ll x) {
	return 63 - __builtin_clzll(x);
}

ll rot[100];

void rotf(int l, ll k) {
	if(l == 0) return;
	ll z = 1LL << l;
	rot[l] = (rot[l] + k) % z;
	if(rot[l] < 0) rot[l] += z;
}

ll get_par(int l, ll v) {
	if(l == 0) return -1;
	v += rot[l];
	if(v >= 1LL << (l + 1)) v -= 1LL << l;
	return v / 2;
}

void solve() {
	int q; scanf("%d", &q);
	while(q--) {
		int cmd; scanf("%d", &cmd);
		if(cmd == 3) {
			ll x; scanf("%lld", &x);
			while(x != -1) {
				printf("%lld ", x);
				x = get_par(get_level(x), x);
			} puts("");
		}
		else if(cmd == 2) {
			ll x, k; scanf("%lld%lld", &x, &k);
			rotf(get_level(x), k);
		}
		else {
			ll x, k; scanf("%lld%lld", &x, &k);
			rotf(get_level(x), k);
			rotf(get_level(x) + 1, -k * 2);
		}
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}