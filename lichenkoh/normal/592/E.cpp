#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> rat;
#define MOD 1000000007LL
#define PB push_back
#define MP make_pair

bool eq(rat x, rat y) {
	ll a = x.first; ll b = x.second;
	ll c = y.first; ll d = y.second;
	return a*d == b*c;
}

bool cmp(rat x, rat y) {
	ll a = x.first; ll b = x.second;
	ll c = y.first; ll d = y.second;
	ll bd = b*d;
	if (bd > 0) {
		return a*d < b*c;
	}
	else if (bd < 0) {
		return a*d > b*c;
	}
	else {
		assert(false);
	}
}

bool cmpe(rat x, rat y) {
	return eq(x,y) || cmp(x,y);
}

ll go(vector<rat> a, vector<rat> b, ll negzero) {
	ll n = a.size(); ll m = b.size();
	ll *f = new ll[m];
	ll *g = new ll[n];
	for (ll i = 0; i < m; i++) f[i] = 0;
	for (ll i = 0; i < n; i++) g[i] = 0;
	ll i = m-1; ll k = n-1; ll p = 0;
	while(i >= 0 && k >= 0) {
		while(i >= 0 && k >= 0 && cmp(b[i],a[k])) {
			p++;
			//printf("/ p:\n",a[i].first,a[i].second,p);
			k--;
		}
		while(i >= 0 && k >= 0 && cmpe(a[k],b[i])) {
			f[i] = p;
			//printf("/ p: f:\n",b[i].first,b[i].second,p,f[i]);
			i--;
		}
	}
	while(i >= 0) {
		f[i] = p;
		//printf("/ p: f:\n",b[i].first,b[i].second,p,f[i]);
		i--;
	}

	ll q = 0;
	i = n-1; k = m-1;
	while(i >= 0 && k >= 0) {
		while(i >= 0 && k >= 0 && cmp(a[i],b[k])) {
			q += f[k];
			k--;
		}
		while(i >= 0 && k >= 0 && cmpe(b[k],a[i])) {
			g[i] = q;
			////printf("/ q: g:, i:, k:\n",a[i].first,a[i].second,q,g[i],i,k);
			i--;
		}
	}
	while (i >= 0) {
		////printf("/ q: g:, i:, k:\n",a[i].first,a[i].second,q,g[i],i,k);
		g[i] = q; i--;
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ans += g[i];
	}
	ll s = 0;
	for (ll i = 0; i < m; i++) {
		s += f[i];
	}
	////printf(" * \n",s,negzero);
	ans += s*negzero;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	ll n,c,d; cin >> n; cin >> c; cin >> d;
	vector<rat> a,b;
	ll poszero = 0; ll negzero =0;
	for (ll i = 0; i < n; i++) {
		ll r,w;
		cin >> r; cin >> w;
		r -= c; w -=d;
		if (r == 0 && w == 0) continue;
		if (w == 0) {
			if (r > 0) poszero++;
			if (r < 0) negzero++;
			continue;
		}
		if (w > 0) {
			a.PB(MP(r,w));
		}
		else {
			b.PB(MP(r,w));
		}
	}
	sort(a.begin(),a.end(),cmp);
	sort(b.begin(),b.end(),cmp);

	ll ans1 = go(a,b,negzero);
	//printf("Next\n");
	ll ans2 = go(b,a,poszero);
	ll ans = ans1 + ans2;
	cout << ans << endl;
}