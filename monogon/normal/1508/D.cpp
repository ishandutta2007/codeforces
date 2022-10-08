
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

struct pt {
    ll x, y;
    pt(ll x = 0, ll y = 0) : x(x), y(y) {}
    pt operator-(const pt &o) const {
        return pt(x - o.x, y - o.y);
    }
    ll cross(const pt &o) const {
        return x * o.y - y * o.x;
    }
    bool operator<(const pt &o) const {
        return cross(o) > 0;
    }
};

struct dsu {
    vi a;
    dsu(int n) {
        a.assign(n, -1);
    }
    int trace(int x) {
        return a[x] < 0 ? x : a[x] = trace(a[x]);
    }
    void join(int x, int y) {
        if((x = trace(x)) == (y = trace(y))) return;
        if(a[x] > a[y]) swap(x, y);
        a[x] += a[y];
        a[y] = x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n + 1);
    vector<pt> p(n + 1);
    rep(i, 1, n + 1) {
        cin >> p[i].x >> p[i].y >> a[i];
    }
    int idx = -1;
    rep(i, 1, n + 1) {
        if(a[i] != i && (idx == -1 || p[i].y < p[idx].y)) {
            idx = i;
        }
    }
    if(idx == -1) {
        cout << 0 << '\n';
        return 0;
    }
    vi balls;
    rep(i, 1, n + 1) {
        if(i != idx && a[i] != i) {
            balls.push_back(i);
        }
    }
    sort(all(balls), [&](int i, int j) {
        return p[i] - p[idx] < p[j] - p[idx];
    });
    dsu D(n + 1);
    rep(i, 1, n + 1) D.join(i, a[i]);
    int k = sz(balls);
    vector<pii> ops;
    auto pass = [&](int i, int j) {
        swap(a[i], a[j]);
        ops.push_back({i, j});
    };
    rep(i, 0, k - 1) {
        if(D.trace(balls[i]) != D.trace(balls[i + 1])) {
            pass(balls[i], balls[i + 1]);
            D.join(balls[i], balls[i + 1]);
        }
    }
    while(a[idx] != idx) {
        pass(idx, a[idx]);
    }

    cout << sz(ops) << '\n';
    for(auto &pa : ops) {
        cout << pa.first << ' ' << pa.second << '\n';
    }
}