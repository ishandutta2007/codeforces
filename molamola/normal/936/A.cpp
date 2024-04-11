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
typedef pair<ldouble, ldouble> pdd;

void solve() {
	ll k, d, t; cin >> k >> d >> t;
	t *= 2;
	ll f = (k + d - 1) / d * d;
	ll val = f + k;
	ll ans = 0;
	ll rm = t / val;
	ans = rm * f; t %= val;
	if(t <= 2 * k) {
		double res = ans + t / 2.0;
		printf("%.12f\n", res);
	}
	else {
		ans += k; t -= 2 * k;
		printf("%lld\n", ans + t);
	}
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}