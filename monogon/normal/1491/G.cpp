
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
    vi p(n + 1);
    dsu D(n + 1);
    rep(i, 1, n + 1) {
        cin >> p[i];
        D.join(i, p[i]);
    }
    vi ve;
    rep(i, 1, n + 1) {
        if(D.trace(i) == i && D.a[i] != -1) {
            ve.push_back(i);
        }
    }
    vector<pii> ops;
    auto frick = [&](int i, int j) {
        ops.push_back({i, j});
        swap(p[i], p[j]);
    };
    auto heck = [&](int i) {
        vi a;
        a.push_back(i);
        int j = p[i];
        while(j != i) {
            a.push_back(j);
            j = p[j];
        }
        int k = sz(a);
        rep(i, 2, k + 1) {
            frick(a[1], a[i % k]);
        }
    };
    while(sz(ve) >= 2) {
        int i = ve.back();
        ve.pop_back();
        int j = ve.back();
        ve.pop_back();
        frick(i, j);
        frick(p[i], p[j]);
        heck(i);
        heck(j);
    }
    if(!ve.empty()) {
        int i = ve.back();
        if(D.a[i] == -2) {
            int j = 1;
            while(j == i || j == p[i]) j++;
            frick(i, j);
            heck(i);
        }else {
            int j = p[i], k = p[j];
            frick(j, k);
            frick(i, k);
            heck(k);
        }
    }
    cout << sz(ops) << '\n';
    for(auto &pa : ops) {
        cout << pa.first << ' ' << pa.second << '\n';
    }
}