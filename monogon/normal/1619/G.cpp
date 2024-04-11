
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

struct dsu {
    vector<int> a;
    vector<ll> ti;
    dsu(int n, const vector<ll> &ti) : a(n, -1), ti(ti) {}
    int find(int x) {
        return a[x] < 0 ? x : a[x] = find(a[x]);
    }
    ll getTi(int x) {
        return ti[find(x)];
    }
    int size(int x) {
        return -a[find(x)];
    }
    bool join(int x, int y) {
        if((x = find(x)) == (y = find(y))) return false;
        if(a[x] > a[y]) swap(x, y);
        ti[x] = min(ti[x], ti[y]);
        a[x] += a[y];
        a[y] = x;
        return true;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    map<ll, vi> mx, my;
    vector<ll> x(n), y(n), ti(n);
    rep(i, 0, n) {
        cin >> x[i] >> y[i] >> ti[i];
        mx[x[i]].push_back(i);
        my[y[i]].push_back(i);
    }
    dsu D(n, ti);
    for(auto &pa : mx) {
        vi &v = pa.second;
        sort(all(v), [&](int i, int j) {
            return y[i] < y[j];
        });
        rep(i, 1, sz(v)) {
            if(y[v[i]] - y[v[i - 1]] <= k) {
                D.join(v[i - 1], v[i]);
            }
        }
    }
    for(auto &pa : my) {
        vi &v = pa.second;
        sort(all(v), [&](int i, int j) {
            return x[i] < x[j];
        });
        rep(i, 1, sz(v)) {
            if(x[v[i]] - x[v[i - 1]] <= k) {
                D.join(v[i - 1], v[i]);
            }
        }
    }
    vector<ll> ve;
    rep(i, 0, n) {
        if(D.find(i) == i) {
            ve.push_back(D.getTi(i));
        }
    }
    sort(all(ve), greater<ll>());
    ll ans = sz(ve) - 1;
    rep(i, 0, sz(ve) - 1) {
        ans = min(ans, max((ll) i, ve[i + 1]));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}