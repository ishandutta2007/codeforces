#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007LL
#define UNDEF -1LL
#define PB push_back
#define MP make_pair

int main() {
	ios_base::sync_with_stdio(false);
	ll n,m; cin >> n; cin >> m;
	ll *f = new ll[n+1];
	ll *b = new ll[m+1];
	ll *ans = new ll[m+1];
	unordered_map<ll,ll> h;
	for (ll i = 1; i <= n; i++) {
		cin >> f[i];
	}
	for (ll i = 1; i <= m; i++) {
		cin >> b[i];
	}
	unordered_set<ll> amb;
	bool ambi = false;
	bool imp = false;
	for (ll i = 1; i <= n; i++) {
		ll x = f[i];
		if (h.find(x) != h.end()) {
			amb.insert(x);
		}
		h[x] = i;
	}
	for (ll i = 1; i <= m; i++) {
		ll y = b[i];
		if (h.find(y) == h.end()) {
			imp = true;
		}
		if (amb.find(y) != amb.end()) {
			ambi = true;
		}
		ans[i] = h[y];
	}
	if (imp) {
		//cout << "Impossible" << endl;
		printf("Impossible\n");
		return 0;
	}
	else if (ambi) {
		//cout << "Ambiguity" << endl;
		printf("Ambiguity\n");
		return 0;
	}
	else {
		printf("Possible\n");
		printf("%I64d", ans[1]);
		for (ll i = 2; i <= m; i++) {
			printf(" %I64d", ans[i]);
		}
		printf("\n");
	}

}