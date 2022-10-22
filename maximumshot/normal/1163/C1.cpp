#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

ll gcd(ll x, ll y) {
    return !x ? y : gcd(y % x, x);
}

struct Q {
    int u, v;
    Q(ll uu, ll vv) {
        u = uu;
        v = vv;
    }
};

pll get(ll u, ll v) {
    if (v < 0) {
        v = -v;
        u = -u;
    }
    ll g = gcd(u >= 0 ? u : -u, v >= 0 ? v : -v);
    u /= g;
    v /= g;
    return make_pair(u, v);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<pii> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    map<int, int> ver, hor;
    int cnt_ver = 0, cnt_hor = 0;
    int cnt_other = 0;

    map< pll, set<pll> > q;

    for (int i = 0; i < n; i++) {
        vector<pii> hlp;
        int x1, y1, x2, y2;
        tie(x1, y1) = a[i];
        for (int j = i + 1; j < n; j++) {
            tie(x2, y2) = a[j];
            if (x1 == x2) {
                ver[x1]++;
            } else if (y1 == y2) {
                hor[y1]++;
                cnt_hor++;
            } else {
                q[get(y1 - y2, x1 - x2)].insert(get(1ll * y1 * (x1 - x2) - 1ll * x1 * (y1 - y2), x1 - x2));
            }
        }
    }

    cnt_ver = (int)ver.size();
    cnt_hor = (int)hor.size();

    ll res = 0;

    int tot = 0;

    for (auto it : q) {
        tot += (int)it.second.size();
    }

    for (auto it : q) {
        int cur = (int)it.second.size();
        res += 1ll * cur * (tot - cur);
    }

    res /= 2;

    cnt_other = tot;
    res += 1ll * cnt_hor * cnt_ver + 1ll * cnt_other * (cnt_hor + cnt_ver);

    cout << res << "\n";

    return 0;
}