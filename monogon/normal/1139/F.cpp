
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ord;

const int N = 1e5 + 5;
int n, m;
ll p[N], s[N], b[N], inc[N], pref[N];
int ans[N];
ord seg[8 * N];

// [0, n) -> dish (point)
// [n, n + m) -> person (query)
struct event {
    int x, y, z, idx;
    bool operator<(const event &o) const {
        return make_tuple(x, y, z, idx) < make_tuple(o.x, o.y, o.z, o.idx);
    }
};

int query(int i, int l, int r, int L, int R, int val) {
    if(r < L || R < l) return 0;
    if(L <= l && r <= R) return seg[i].order_of_key(val+1);
    int m = (l + r) / 2;
    return query(2 * i + 1, l, m, L, R, val) + query(2 * i + 2, m + 1, r, L, R, val);
}
void upd(int i, int l, int r, int idx, int val) {
    seg[i].insert(val);
    if(l == r) return;
    int m = (l + r) / 2;
    if(idx <= m) upd(2 * i + 1, l, m, idx, val);
    else upd(2 * i + 2, m + 1 , r, idx, val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) cin >> p[i];
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, n) cin >> b[i];
    rep(i, 0, m) cin >> inc[i];
    rep(i, 0, m) cin >> pref[i];
    vector<ll> vx, vy, vz;
    rep(i, 0, n) {
        vx.push_back(-s[i]);
        vy.push_back(p[i] - b[i]);
        vz.push_back(p[i] + b[i]);
    }
    rep(i, 0, m) {
        vx.push_back(-inc[i]);
        vy.push_back(inc[i] - pref[i]);
        vz.push_back(inc[i] + pref[i]);
    }
    sort(all(vx));
    vx.erase(unique(all(vx)), vx.end());
    sort(all(vy));
    vy.erase(unique(all(vy)), vy.end());
    sort(all(vz));
    vz.erase(unique(all(vz)), vz.end());
    vector<event> ve;
    rep(i, 0, n) {
        int x = lower_bound(all(vx), -s[i]) - vx.begin();
        int y = lower_bound(all(vy), p[i] - b[i]) - vy.begin();
        int z = lower_bound(all(vz), p[i] + b[i]) - vz.begin();
        ve.push_back({x, y, z, i});
    }
    rep(i, 0, m) {
        int x = lower_bound(all(vx), -inc[i]) - vx.begin();
        int y = lower_bound(all(vy), inc[i] - pref[i]) - vy.begin();
        int z = lower_bound(all(vz), inc[i] + pref[i]) - vz.begin();
        ve.push_back({x, y, z, n + i});
    }
    sort(all(ve));
    for(auto &e : ve) {
        if(e.idx >= n) {
            // person query
            ans[e.idx - n] = query(0, 0, n + m - 1, 0, e.y, e.z);
        }else {
            upd(0, 0, n + m - 1, e.y, e.z);
        }
    }
    rep(i, 0, m) cout << ans[i] << ' ';
    cout << '\n';
}