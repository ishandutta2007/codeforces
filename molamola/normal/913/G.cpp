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

ll N;
ll pw[20], pw5[40];

ll mul(ll x, ll y, ll MOD) {
	ll res = 0;
	while(y) {
		if(y & 1) res = (res + x >= MOD ? res + x - MOD : res + x);
		x = (x + x >= MOD ? x + x - MOD : x + x);
		y >>= 1;
	}
	return res;
}

ll pww(ll x, ll y, ll MOD) {
	ll res = 1;
	while(y) {
		if(y & 1) res = mul(res, x, MOD);
		x = mul(x, x, MOD);
		y >>= 1;
	}
	return res;
}

void solve() {
	scanf("%lld", &N);
	int c = 0;
	for(ll t=1;t<=N;t*=10,c++);
	int nc = c + 7;
	ll v = N * pw[7], w = 1LL << nc;
	v = (v + w - 1) / w;
	if(v % 5 == 0) ++v;
	ll p = 0;
	rep(i, 4) if(pww(2, i, 5) == v % 5) p = i;
	for(int i=2;i<=nc;i++) {
		// 2^p = v mod 5^(i-1)
		// 2^x = v mod 5^i
		for(int j=0;j<5;j++) if(pww(2, p + j * 4 * pw5[i-2], pw5[i]) == v % pw5[i]) {
			p += j * 4 * pw5[i-2];
			break;
		}
	}
	p += nc;
	printf("%lld\n", p);
}

int main(){
	pw[0] = pw5[0] = 1;
	for(int i=1;i<20;i++) pw[i] = 10 * pw[i-1];
	for(int i=1;i<40;i++) pw5[i] = 5 * pw5[i-1];
	int Tc = 1; scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}