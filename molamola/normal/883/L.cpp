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
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

multiset <int> W;
set <pll> S[200020];

struct str{
	str(){}
	str(ll tm, int c, int b) : tm(tm), c(c), b(b) {}
	ll tm; int c, b;
	bool operator>(const str &rhs) const {
		return tm > rhs.tm;
	}
};

priority_queue <str, vector<str>, greater<str> > pq;

void solve() {
	int n, k, m; scanf("%d%d%d", &n, &k, &m);
	for(int i=1;i<=k;i++) {
		int x; scanf("%d", &x);
		S[x].insert(pll(0, i));
		W.insert(x);
	}
	ll fm = 0;
	for(int i=1;i<=m;i++) {
		ll t; int a, b;
		scanf("%lld%d%d", &t, &a, &b);
		fm = max(fm, t);
		while(!pq.empty() && pq.top().tm <= fm) {
			auto e = pq.top(); pq.pop();
			W.insert(e.b);
			S[e.b].insert(pll(e.tm, e.c));
		}
		if(sz(W) == 0) {
			fm = pq.top().tm;
			while(!pq.empty() && pq.top().tm == fm) {
				auto e = pq.top(); pq.pop();
				W.insert(e.b);
				S[e.b].insert(pll(e.tm, e.c));
			}
		}
		auto it = W.lower_bound(a);
		int idis = 1e9, jdis = 1e9;
		if(it != W.end()) idis = *it - a;
		auto jt = it;
		if(it != W.begin()) jt = prev(it), jdis = a - *jt;
		pll tex = pll(-1, -1);
		if(idis < jdis || (idis == jdis && *S[*it].begin() < *S[*jt].begin())) {
			tex = *S[*it].begin();
			S[*it].erase(S[*it].begin());
			W.erase(it);
			ll det = fm + idis + abs(a - b);
			pq.push(str(det, (int)tex.Se, b));
			printf("%d %lld\n", (int)tex.Se, fm + idis - t);
		}
		else {
			tex = *S[*jt].begin();
			S[*jt].erase(S[*jt].begin());
			W.erase(jt);
			ll det = fm + jdis + abs(a - b);
			pq.push(str(det, (int)tex.Se, b));
			printf("%d %lld\n", (int)tex.Se, fm + jdis - t);
		}
		
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}