#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int MAXN = 228228;
int n, k, m;
set<tuple<ll, int, int> > sp;
set<int> ss;
queue<pair<ll, int> > qu[MAXN];


int main() {
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < k; ++i) {
		int x;
		scanf("%d", &x);
		--x;
		sp.insert(make_tuple(0, i, x));
	}
	ll lst = 0;
	for (int i = 0; i < m; ++i) {
		ll tt;
		int a, b;
		scanf("%lld%d%d", &tt, &a, &b);
		int ansc = -1;
		ll tmp = tt;
		ll ans = 0;
		tt = max(tt, lst);
		--a, --b;
		while (!sp.empty() && get<0>(*sp.begin()) <= tt) {
			ll t = get<0>(*sp.begin());
			int x = get<1>(*sp.begin());
			int y = get<2>(*sp.begin());
			if (qu[y].empty())
				ss.insert(y);
			qu[y].push(make_pair(t, x));
			sp.erase(sp.begin());
		}
		if (ss.empty()) {
			tt = get<0>(*sp.begin());
			while (!sp.empty() && get<0>(*sp.begin()) <= tt) {
				ll t = get<0>(*sp.begin());
				int x = get<1>(*sp.begin());
				int y = get<2>(*sp.begin());
				if (qu[y].empty())
					ss.insert(y);
				qu[y].push(make_pair(t, x));
				sp.erase(sp.begin());
			}
		}
		auto itr = ss.lower_bound(a);
		auto itl = itr;
		if (itr != ss.begin()) {
			--itl;
		}
		else
			itl = ss.end();
		if (itl != ss.end() && itr != ss.end()) {
			int p = *itl;
			int q = *itr;
			tuple<int, ll, int> xx = make_tuple(abs(a - p), qu[p].front().first, qu[p].front().second);
			tuple<int, ll, int> yy = make_tuple(abs(a - q), qu[q].front().first, qu[q].front().second);
			if (xx < yy) {
				ansc = qu[p].front().second;
				qu[p].pop();
				if (qu[p].empty())
					ss.erase(p);
				ans = tt + abs(p - a);
			}
			else {
				ansc = qu[q].front().second;
				qu[q].pop();
				if (qu[q].empty())
					ss.erase(q);
				ans = tt + abs(q - a);
			}
		}
		else if (itl != ss.end()) {
			int p = *itl;
			auto x = qu[p].front();
			qu[p].pop();
			if (qu[p].empty())
				ss.erase(p);
			ans = tt + abs(p - a);
			ansc = x.second;
		}
		else {
			int p = *itr;
			auto x = qu[p].front();
			qu[p].pop();
			if (qu[p].empty())
				ss.erase(p);
			ans = tt + abs(p - a);
			ansc = x.second;
		}
		printf("%d %lld\n", ansc + 1, ans - tmp);
		sp.insert(make_tuple(ans + abs(a - b), ansc, b));
		lst = max(lst, tt);
	}
	return 0;
}