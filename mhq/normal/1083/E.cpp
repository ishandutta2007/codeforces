#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct pt{
    ll x, y;
    pt(ll _x, ll _y) {
        x = _x;
        y = _y;
    }
};
bool del(const pt& x, const pt& y, const pt& z) {
    return ((ld)y.y - x.y) * (x.x - z.x) <= ((ld)z.y - x.y) * (x.x - y.x);
}
void add(ll x, ll y, vector < pt >& vec) {
    pt nw(x, y);
    while (vec.size() >= 2 && del(vec[vec.size() - 1], vec[vec.size() - 2], nw)) {
        vec.pop_back();
    }
    vec.push_back(nw);
}
ll get(const pt& a, ll y) {
    return (a.x * y + a.y);
}
const ll INF = 2 * (ll)1e18;
ll get(ll x, vector < pt >& vec) {
    if (vec.empty()) return -INF;
    int l = 0;
    int r = vec.size() - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (get(vec[m], x) > get(vec[m + 1], x)) {
            r = m;
        }
        else l = m;
    }
    return max(get(vec[r], x), get(vec[l], x));
}
const int maxN = (int)1e6 + 10;
int n;
ll dp[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(239);
    cin >> n;
    vector < pair < pair < int, int >, ll > > all;
    for (int i = 1; i <= n; i++) {
        int x, y;
        ll a;
        cin >> x >> y >> a;
        all.push_back(make_pair(make_pair(x, y), a));
    }
    sort(all.begin(), all.end());
    dp[0] = 0;
    vector < pt > vec;
    for (int i = 0; i < n; i++) {
        auto t = all[i].first;
        ll a = all[i].second;
        ll x = t.first;
        ll y = t.second;
        dp[i + 1] = x * y - a;
        ll val = get(-y, vec);
        dp[i + 1] = max(dp[i + 1], val + dp[i + 1]);
        add(x, dp[i + 1], vec);
    }
    ll mx = 0;
    for (int i = 0; i <= n; i++) mx = max(mx, dp[i]);
    cout << mx;
    return 0;
}