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

int n, m;
int C[100010], W[100010];
int tt[100010];

void solve(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) scanf("%d", C+i);
	for(int i=1;i<=n;i++) scanf("%d", W+i);
	priority_queue <pll, vector<pll>, greater<pll> > pq;
	ll ans = 0;
	for(int i=1;i<=n;i++) if(C[i] % 100) {
		m -= (C[i] % 100);
		pq.push(pll((100 - C[i] % 100) * W[i], i));
		if(m < 0) {
			pll t = pq.top(); pq.pop();
			ans += t.Fi; tt[t.Se] = 1;
			m += 100;
		}
	}
	printf("%lld\n", ans);
	for(int i=1;i<=n;i++) {
		if(tt[i]) {
			printf("%d %d\n", C[i] / 100 + 1, 0);
		}
		else printf("%d %d\n", C[i] / 100, C[i] % 100);
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d\n", tc);
		solve();
	}
	return 0;
};