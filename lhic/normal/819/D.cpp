#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

ll T;

ll now;

ll gcd(ll a, ll b) {
    while (b) { 
        ll q = a % b;
        a = b;
        b = q;
    }
    return a;
}

ll gcdex (ll a, ll b, ll & x, ll & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcdex (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

ll bck(ll a, ll MOD) {
    ll x, y;
    ll g = gcdex (a, MOD, x, y);
    assert(g == 1);
    x = (x % MOD + MOD) % MOD;
    assert((x * a) % MOD == 1);
    return x;
}


map<ll, int> mm;
map<ll, vector<pair<ll, int> >> go;
ll bc;
ll ans[220000];

void solve(vector<pair<ll, int> > vv) {
    for (int i = 0; i < vv.size(); ++i)
        vv[i].first = (vv[i].first * bc) % T;
    sort(vv.begin(), vv.end());
    if (vv.size() == 1) {
        ans[vv[0].second] = T;
        return;
    }
    for (int i = 0; i < vv.size(); ++i) {
        ll nx = 0;
        if (i == vv.size() - 1)
            nx = vv[0].first;
        else
            nx = vv[i + 1].first;
        ans[vv[i].second] = (nx + T - vv[i].first) % T;
    }
}

int n;
int main() {
    scanf("%lld%d", &T, &n);
    for (int i = 0; i < n; ++i) {
        ll x;
        scanf("%lld", &x);
        now += x;
        now %= T;
        if (mm.count(now) == 0) {
            mm[now] = i;
        }
    }
    if (now == 0) {
        for (auto it: mm)
            ans[it.second] = 1;
        for (int i = 0; i < n; ++i)
            printf("%lld ", ans[i]);
        printf("\n");
        return 0;
    }
    ll g = gcd(now, T);
    now /= g;
    T /= g;
    bc = bck(now, T);
    for (auto i: mm) {
        go[i.first % g].push_back(make_pair(i.first / g, i.second));
    }
    for (auto it: go) {
        solve(it.second);
    }
    for (int i = 0; i < n; ++i) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
    return 0;
}