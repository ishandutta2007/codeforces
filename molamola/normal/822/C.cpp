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
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

t3 P[200020];
vector <pii> X[200020], Y[200020];
int n, x;

void solve(){
	scanf("%d%d", &n, &x);
	rep(i, n){
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		P[i] = t3(a, b, c);
		X[a].pb(pii(b-a+1, c));
		Y[b].pb(pii(b-a+1, c));
	}
	multiset <int> S[200020];
	for(int i=1;i<=200000;i++) {
		for(pii e : X[i]) S[e.Fi].insert(e.Se);
	}
	ll ans = 1e10;
	for(int i=1;i<=200000;i++) {
		for(pii e : X[i]) S[e.Fi].erase(S[e.Fi].find(e.Se));
		for(pii e : Y[i]) {
			int l = x - e.Fi;
			if(l > 0 && sz(S[l])) ans = min(ans, (ll)*S[l].begin() + e.Se);
		}
	}
	printf("%lld\n", ans > 5e9 ? -1 : ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d\n", tc);
		solve();
	}
	return 0;
};