
#pragma GCC optimize("Ofast")
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

struct node {
    // (bit pos, mask)
    vector<pii> a;
    node() {}
    bool add(int x) {
        for(auto &pa : a) {
            int i, y; tie(i, y) = pa;
            if(x >> i & 1) x ^= y;
        }
        if(x != 0) {
            int p = 19;
            while(~x >> p & 1) p--;
            a.push_back({p, x});
            return true;
        }
        return false;
    }
    int query() const {
        int x = 0;
        for(auto &pa : a) {
            int i, y; tie(i, y) = pa;
            if(~x >> i & 1) x ^= y;
        }
        return x;
    }
};

const int N = 5e5 + 5;
int ans[4 * N];
vector<array<int, 3>> qu[4 * N];

void solve(int idx, int l, int r, vi &c) {
    int m = (l + r) / 2;
    if(l < r) {
        solve(2 * idx + 1, l, m, c);
        solve(2 * idx + 2, m + 1, r, c);
    }
    vi le, ri;
    node x;
    for(int i = m; i >= l; i--) {
        if(x.add(c[i])) {
            le.push_back(i);
        }
    }
    x = node();
    rep(i, m + 1, r + 1) {
        if(x.add(c[i])) {
            ri.push_back(i);
        }
    }
    for(auto &ar : qu[idx]) {
        int qi = ar[0], L = ar[1], R = ar[2];
        x = node();
        for(int i : le) {
            if(i >= L) x.add(c[i]);
        }
        for(int i : ri) {
            if(i <= R) x.add(c[i]);
        }
        ans[qi] = x.query();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi c(n + 1);
    rep(i, 1, n + 1) cin >> c[i];
    int q;
    cin >> q;
    rep(i, 0, q) {
        int l, r;
        cin >> l >> r;
        int idx = 0, L = 1, R = n;
        while(L < R) {
            int m = (L + R) / 2;
            if(r <= m) {
                idx = 2 * idx + 1;
                R = m;
            }else if(l > m) {
                idx = 2 * idx + 2;
                L = m + 1;
            }else break;
        }
        qu[idx].push_back({i, l, r});
    }
    solve(0, 1, n, c);
    rep(i, 0, q) {
        cout << ans[i] << '\n';
    }
}