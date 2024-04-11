
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
    dsu(int n) : a(n, -1) {}
    int find(int x) {
        return a[x] < 0 ? x : a[x] = find(a[x]);
    }
    int size(int x) {
        return -a[find(x)];
    }
    bool join(int x, int y) {
        if((x = find(x)) == (y = find(y))) return false;
        if(a[x] > a[y]) swap(x, y);
        a[x] += a[y];
        a[y] = x;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // find all sorting orders of weights
    // for each sorting order, write a linear function of x
    // for each query, binary search where it belongs and evaluate
    int n, m;
    cin >> n >> m;
    vi u(m), v(m);
    vector<ll> w(m);
    rep(i, 0, m) {
        cin >> u[i] >> v[i] >> w[i];
        u[i]--;
        v[i]--;
    }
    vector<ll> ve;
    ve.push_back(-1);
    rep(i, 0, m) rep(j, i, m) {
        ve.push_back(w[i] + w[j]);
    }
    sort(all(ve));
    ve.erase(unique(all(ve)), ve.end());
    vector<ll> c1, cx;
    vi edges(m);
    rep(i, 0, m) edges[i] = i;
    dsu D(n);
    for(ll val2x : ve) {
        fill(all(D.a), -1);
        sort(all(edges), [&](int i, int j) {
            return abs(2 * w[i] - (val2x + 0.25)) < abs(2 * w[j] - (val2x + 0.25));
        });
        c1.push_back(0);
        cx.push_back(0);
        for(int i : edges) {
            if(D.find(u[i]) != D.find(v[i])) {
                D.join(u[i], v[i]);
                if(2 * w[i] <= val2x) {
                    c1.back() -= w[i];
                    cx.back() += 1;
                }else {
                    c1.back() += w[i];
                    cx.back() -= 1;
                }
            }
        }
    }

    ll ans = 0;
    ll lastq = 0;
    int p;
    ll k, a, b, c;
    cin >> p >> k >> a >> b >> c;
    auto solve = [&](ll x) {
        int i = upper_bound(all(ve), 2 * x) - ve.begin() - 1;
        ll res = c1[i] + cx[i] * x;
        return res;
    };
    rep(i, 0, p) {
        ll q;
        cin >> q;
        ans ^= solve(q);
        lastq = q;
    }
    rep(i, p, k) {
        ll q = ((lastq * a) + b) % c;
        ans ^= solve(q);
        lastq = q;
    }

    cout << ans << '\n';
}