#include <bits/stdc++.h>
//#include <iostream>
//#include <map>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define MAXN 100008
ll n,A,cf,cm,m;
pair<ll,ll> s[MAXN];
ll sum[MAXN], final[MAXN];
map<ll,ll> h;
bool g(ll minskill, ll left, ll nlim) {
	auto it = h.lower_bound(minskill);
	ll idx = nlim;
	if (it != h.end()) {
		idx = min(idx, it->second);
	}
	ll need = idx*minskill - sum[idx];
	return need <= left;
}

pair<ll,ll> f(ll k) {
	ll left = m;
	ll need = A*k - (sum[n] - sum[n-k]);
	//cout << k << ":" << need << endl;
	left -= need;
	if (left < 0) return MP(-1LL,-1LL);
	ll imin = 0;
	ll imax = A+1;
	while(imin<imax) {
		ll imid = imin + (imax-imin)/2;
		if (g(imid, left, n-k)) {
			imin = imid+1;
		}
		else {
			imax = imid;
		}
	}
	ll minskill = imin-1;
	ll score = cf * k + cm * minskill;
	//cout << minskill << "," << score << endl;
	return MP(score, minskill);
}
void gen(ll k, ll minskill) {
	for (ll i = n-1; i >= n-k; i--) {
		final[s[i].second] = A;
	}
	for (ll i = n-k-1; i >= 0; i--) {
		final[s[i].second] = max(minskill, s[i].first);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> A >> cf >> cm >> m;
	for (ll i = 0; i < n; i++) {
		cin >> s[i].first; s[i].second = i;
	}
	sort(s,s+n);
	for (ll i = 0; i < n; i++) {
		h[s[i].first] = i;
	}
	sum[0] = 0;
	for (ll i = 0; i < n; i++) {
		sum[i+1] = sum[i] + s[i].first;
	}
	pair<ll,ll> best = MP(-1LL,-1LL);
	ll bestk = -1;
	for (ll k = 0; k <= n; k++) {
		pair<ll,ll> cand = f(k);
		if (cand > best) {
			best = cand;
			bestk = k;
		}
	}
	cout << best.first << endl;
	gen(bestk, best.second);
	for (ll i = 0; i < n; i++) {
		cout << final[i] << " ";
	}
	cout << endl;

}