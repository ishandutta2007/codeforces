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

const int MOD = 1e9 + 7;
map <int, int> M;
vector <pii> V;
ll F1[12][100010], F2[12][100010];
int p;

int pw(int x, int y, int M) {
	int res = 1;
	while(y) {
		if(y & 1) res = (ll) res * x % M;
		x = (ll)x * x % M;
		y >>= 1;
	}
	return res;
}

ll gc(ll x, ll y) { return y == 0 ? x : gc(y, x%y); }
pll helper(ll a, ll b){
	if( !b ) return pll(1, 0);
	else{
		pll c = helper(b, a%b);
		return pll(c.second, c.first - a/b * c.second);
	}
}

ll my_mul2(ll a, ll b, ll m) { return a * b % m; }

ll DODO(vector<pll> &L){
	if(szz(L) == 0) return 0;
	if( L.size() == 1 ) return L[0].first;
	else{
		pll a = L.back(); L.pop_back();
		pll b = L.back(); L.pop_back();
		
		pll t = helper(a.second, b.second);
		ll g = gc(a.second, b.second);
		if( (b.first - a.first) % g != 0 ) return -1;
		ll m = b.second / g * a.second;
		ll x = (my_mul2((b.first - a.first) / g % m + m, (t.first * a.second % m), m) + a.first) % m;
		x = (x%m+m) % m;
		L.emplace_back(x, m);
		return DODO(L);
	}
}

int Get(int n, int r) {
	if(r > n) return 0;
	vector <pll> L;
	for(int i=0;i<szz(V);i++) {
		int p = V[i].first;
		ll px = 1;
		rep(b, V[i].second) px = px * p;
		int val = (int)(F1[i][n] - F1[i][r] - F1[i][n-r]);
		ll g = 0;
		if(val >= V[i].second) g = 0;
		else {
			int ppx = 1, ppy = 1;
			rep(b, V[i].second - val) ppx = ppx * p;
			ppy = ppx / p * (p - 1);
			ll temp = F2[i][n] * pw((int)F2[i][r], ppy - 1, ppx) % ppx * pw((int)F2[i][n-r], ppy - 1, ppx) % ppx;
			g = (int)temp; rep(b, val) g = g * p;
		}
		L.pb(pll(g, px));
	}
	return (int)DODO(L);
}

int Do(int n, int x) {
	if(x < 0) return 0;
	ll res = 0;
	for(int j=0;j<=n;j++) {
		ll t = Get(n, j);
		ll t2 = Get(n+1-j, 1+j);
		if(n-j+1 >= x+j+2) t2 = t2 - Get(n+1-j, x+j+2);
		if(t2 < 0) t2 += p;
		t = t * t2 % p;
		res = (res + t) % p;
	}
	return (int)res;
}

void solve() {
	int n, l, r;
	scanf("%d%d%d%d", &n, &p, &l, &r);
	int tp = p;
	for(int i=2;(ll)i*i<=tp;i++) {
		while(tp % i == 0) {
			M[i]++; tp /= i;
		}
	}
	if(tp > 1) M[tp]++;
	for(pii e : M) V.pb(e);
	int m = szz(V);
	rep(i, m) {
		F1[i][0] = 0; F2[i][0] = 1;
		int p = V[i].first;
		int px = 1;
		rep(b, V[i].second) px = px * p;
		for(int a=1;a<100010;a++) {
			int cnt = 1, ta = a;
			while(ta % p == 0) ++cnt, ta /= p;
			F1[i][a] = F1[i][a-1] + cnt;
			F2[i][a] = (ll) F2[i][a-1] * ta % px;
		}
	}
	int ans = Do(n, r) - Do(n, l-1);
	if(ans < 0) ans += p;
	printf("%d\n", ans);
}

int main() {
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++) {
		solve();
	}
	return 0;
}