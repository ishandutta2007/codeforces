#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
#define UNDEF -1LL
#define PUNDEF MP(UNDEF,UNDEF)
#define True 1
#define False 0
#define INF 9999999999999999LL
vector<ll> *g,*h,*d;
bool *seen, *atk;
ll *val, *dploop;
pair<ll,ll> *dponce, *dpnone;
ll loop(ll x) {
	if (dploop[x] != UNDEF) return dploop[x];
	ll ans = 0;
	for (auto& y: g[x]) {
		ans += (2 + loop(y));
	}
	dploop[x] = ans;
	return ans;
}

pair<ll,ll> once(ll x) {
	if (dponce[x] != PUNDEF) return dponce[x];
	if (g[x].size() == 0) {
		dponce[x] = MP(0,x);
		return MP(0,x);
	}
	pair<ll,ll> ans = MP(INF,INF);
	ll sum = loop(x);
	for (auto& y: g[x]) {
		pair<ll,ll> cand = once(y);
		cand.first = sum - (loop(y) + 2) + (cand.first + 1);
		ans = min(ans, cand);
	}
	dponce[x] = ans;
	return ans;
}
pair<ll,ll> none(ll x);

pair<ll,ll> none2(ll x) {
	pair<ll,ll> best = MP(INF,UNDEF);
	ll sum = loop(x);
	for (auto& y: g[x]) {
		pair<ll,ll> cand = none(y);
		cand.first = sum - (loop(y) + 2) + (cand.first + 2);
		best = min(best, cand);
	}
	return best;
}

pair<ll,ll> none1(ll x) {
	if (g[x].size() < 2) {
		pair<ll,ll> ans = once(x);
		ll w = min(ans.second, x);
		return MP(ans.first, w);
	}
	pair<ll,ll> best[2];
	best[0] = MP(INF,UNDEF);
	best[1] = MP(INF,UNDEF);
	ll besti[2];
	besti[0] = UNDEF;
	besti[1] = UNDEF;
	ll prev = UNDEF;
	for (ll k = 0; k < 2; k++) {
		for (auto& y: g[x]) {
			if (y == prev) continue;
			pair<ll,ll> cand = once(y);
			cand.first = - (loop(y) + 2) + (cand.first + 1);
			if (cand < best[k]) {
				best[k] = cand;
				besti[k] = y;
			}
		}
		prev = besti[k];
	}
	//printf("%d %d\n",besti[0], besti[1]);
	ll w = min(best[0].second, best[1].second);
	ll c1 = best[0].first; ll c2 = best[1].first;
	ll sum = loop(x) + c1 + c2;
	return MP(sum, w);
}

pair<ll,ll> none(ll x) {
	if (dpnone[x].first != UNDEF) return dpnone[x];
	pair<ll,ll> ans = min(none1(x), none2(x));
	dpnone[x] = ans;
	return ans;
}


bool valid(ll x) {
	if (val[x] != UNDEF) return val[x];
	if (atk[x]) {val[x] = True; return True;}
	for (auto& y: d[x]) {
		if (valid(y)) {val[x] = True; return True;}
	}
	val[x] = False;
	return False;
}
vector<ll> vec;
void bfs(ll x) {
	queue<ll> q;
	seen[x] = true;
	q.push(x);
	while (!q.empty()) {
		ll u = q.front();
		vec.PB(u);
		q.pop();
		for (auto& y:h[u]) {
			if (!seen[y]) {
				seen[y] = true;
				d[u].PB(y);
				q.push(y);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	ll n,m; cin >> n; cin >> m;
	seen = new bool[n+1];
	dploop = new ll[n+1];
	dponce = new pair<ll,ll>[n+1];
	dpnone = new pair<ll,ll>[n+1];
	val = new ll[n+1];
	g = new vector<ll>[n+1];
	d = new vector<ll>[n+1];
	h = new vector<ll>[n+1];
	atk = new bool[n+1];
	for (ll i = 0; i <= n; i++) {
		seen[i] = false;
		dploop[i] = UNDEF;
		dponce[i] = PUNDEF;
		dpnone[i] = PUNDEF;
		val[i] = UNDEF;
		atk[i] = false;
	}

	for (ll i = 1; i < n; i++) {
		ll u,v; cin >> u; cin >> v;
		h[u].PB(v);
		h[v].PB(u);
	}
	ll src = INF;
	for (ll i = 0; i < m; i++) {
		ll x; cin >> x;
		atk[x] = true;
		src = min(src, x);
	}
	assert(src != INF);
	assert(atk[src] == true);
	bfs(src);
	for (ll x = 1; x <= n; x++) {
		val[x] = valid(x);
	}
	for (ll x = 1; x <= n; x++) {
		if(val[x]) {
			for (auto& y: d[x]) {
				if(val[y]) {
					g[x].PB(y);
				}
			}
		}
	}
	for (vector<ll>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it) {
		ll x = *it;
		loop(x);
		once(x);
		none(x);
	}
	//for (ll x = 1; x <= n; x++) {
	//	printf("x: %d loop: %d once: cost:%d start:%d\n", x, loop(x),once(x).first,once(x).second);
	//}
	pair<ll,ll> ans = none(src);
	cout << ans.second << endl;
	cout << ans.first << endl;
}