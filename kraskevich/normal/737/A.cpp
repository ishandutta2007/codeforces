#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll INF = (ll) 1e18;

vector<ll> g;

ll go(ll x) {
    ll res = 0;
    for (int i = 1; i < g.size(); i++) {
        ll len = g[i] - g[i - 1];
        if (len > x)
            return INF;
        ll slow = max(0ll, 2 * len - x);
        res += len + slow;    
    } 
    return res;
}   

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    ll n, s, t, k;
    cin >> n >> k >> s >> t;
    vector<ll> c(n);
    vector<ll> v(n);
    for (int i = 0; i < n; i++)    
        cin >> c[i] >> v[i];
    g = {0, s};
    for (int i = 0; i < k; i++) {
        ll x;
        cin >> x;
        g.push_back(x);
    }
    ll lo = 0;
    ll hi = INF;
    sort(g.begin(), g.end());
    ll res = INF;
    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (go(mid) <= t)
            hi = mid;
        else
            lo = mid;
    }
    //cerr << hi << endl;
    for (int i = 0; i < n; i++) {
        //cerr << go(v[i]) << endl;
        if (v[i] >= hi)
            res = min(res, c[i]);
    }
    if (res == INF)
        res = -1;
    cout << res << endl;  
}