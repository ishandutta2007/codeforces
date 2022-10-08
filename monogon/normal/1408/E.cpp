
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

const int N = 5e5 + 5;
int m, n;
ll a[N], b[N];
using edge = tuple<ll, int, int>;
int dsu[N];

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}

void join(int x, int y) {
    x = trace(x);
    y = trace(y);
    if(dsu[x] > dsu[y]) {
        swap(x, y);
    }
    dsu[x] += dsu[y];
    dsu[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    rep(i, 0, m) {
        cin >> a[i];
    }
    rep(i, 1, n + 1) {
        cin >> b[i];
    }
    fill(dsu, dsu + N, -1);
    vector<edge> e;
    ll cost = 0;
    rep(i, 0, m) {
        int s;
        cin >> s;
        rep(j, 0, s) {
            int val;
            cin >> val;
            e.emplace_back(a[i] + b[val], i, val);
            cost += a[i] + b[val];
        }
    }
    sort(e.rbegin(), e.rend());
    for(auto &ed : e) {
        ll w;
        int u, v;
        tie(w, u, v) = ed;
        if(trace(u) != trace(m + v)) {
            cost -= a[u] + b[v];
            join(u, m + v);
        }
    }
    cout << cost << '\n';
}