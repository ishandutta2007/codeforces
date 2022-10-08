
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
    int x, lz;
    node *left = NULL, *right = NULL;
    node(int x = 0) : x(x), lz(0) {}
    void prop(int l, int r) {
        x += lz;
        if(l < r) {
            if(!left) left = new node;
            if(!right) right = new node;
            left->lz += lz;
            right->lz += lz;
        }
        lz = 0;
    }
    int get() {
        return x + lz;
    }
    void inc(int l, int r, int L, int R, int y) {
        if(r < L || R < l) return;
        if(L <= l && r <= R) {
            lz += y;
            return;
        }
        prop(l, r);
        if(!left) left = new node;
        if(!right) right = new node;
        int m = l + (r - l) / 2;
        left->inc(l, m, L, R, y);
        right->inc(m + 1, r, L, R, y);
        x = min(left->get(), right->get());
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, len, h;
    cin >> n >> len >> h;
    vi a(n), b(len);
    rep(i, 0, len) cin >> b[i];
    rep(i, 0, n) cin >> a[i];
    int j = 0;
    node *r = new node;
    int ans = 0;
    const int INF = 1e9 + 10;

    rep(i, 0, len) {
        r->inc(-INF, INF, h - b[i] - 1, INF, 1);
    }
    rep(i, 0, n - len + 1) {
        while(j < i + len) {
            r->inc(-INF, INF, a[j], INF, -1);
            j++;
        }
        if(r->get() >= 0) {
            ans++;
        }
        r->inc(-INF, INF, a[i], INF, 1);
    }
    cout << ans << '\n';
}