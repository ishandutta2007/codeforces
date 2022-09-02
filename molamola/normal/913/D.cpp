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

int n; ll T;
int a[200020], t[200020];
vector <int> X[200020];

void solve() {
	scanf("%d%lld", &n, &T);
	for(int i=1;i<=n;i++) {
		int x, y; scanf("%d%d", &x, &y);
		a[i] = x, t[i] = y;
		X[a[i]].pb(i);
	}
	set <pii> S1, S2;
	for(int i=1;i<=n;i++) S1.insert(pii(t[i], i));
	ll c = 0;
	int ans = 0;
	for(int i=1;i<=n;i++) {
		for(int e : X[i-1]) {
			if(S1.find(pii(t[e], e)) != S1.end()) S1.erase(S1.find(pii(t[e], e)));
			else S2.erase(S2.find(pii(t[e], e))), c -= t[e];
		}
		while(szz(S2) < i && szz(S1) > 0) {
			S2.insert(*S1.begin());
			c += S1.begin() -> Fi;
			S1.erase(S1.begin());
		}
		if(szz(S2) == i && c <= T) ans = i;
	}
	printf("%d\n", ans);
	S1.clear(); S2.clear();
	for(int i=1;i<=n;i++) S1.insert(pii(t[i], i));
	
	for(int i=1;i<=ans;i++) {
		for(int e : X[i-1]) {
			if(S1.find(pii(t[e], e)) != S1.end()) S1.erase(S1.find(pii(t[e], e)));
			else S2.erase(S2.find(pii(t[e], e))), c -= t[e];
		}
		while(szz(S2) < i && szz(S1) > 0) {
			S2.insert(*S1.begin());
			c += S1.begin() -> Fi;
			S1.erase(S1.begin());
		}
	}
	vector <int> v;
	for(pii e : S2) v.pb(e.Se);
	sort(all(v));
	printf("%d\n", szz(v));
	for(int e : v) printf("%d ", e); puts("");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}