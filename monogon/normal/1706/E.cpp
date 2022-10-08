
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


template<typename T, class Compare = std::less<T>>
struct sparse {
    vector<vector<T>> st;
    vector<int> log;
    int n;
    sparse(vector<T> a) {
        n = a.size();
        log.assign(n + 1, 0);
        log[1] = 0;
        for(int i = 2; i <= n; i++) {
            log[i] = log[i / 2] + 1;
        }
        int lg = log[n] + 1;
        st.assign(n, vector<T>(lg));
        for(int i = 0; i < n; i++) {
            st[i][0] = a[i];
        }
        for(int j = 1; j < lg; j++) {
            for(int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1], Compare{});
            }
        }
    }
    T query(int l, int r) {
        int j = log[r - l + 1];
        return min(st[l][j], st[r - (1 << j) + 1][j], Compare{});
    }
};


void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vi u(m), v(m);
    rep(i, 0, m) {
        cin >> u[i] >> v[i];
    }
    vi ti(n + 1, -1);
    ti[n] = 0;
    dsu D(n + 1);
    vector<set<int>> se(n + 1);
    rep(i, 1, n + 1) se[i].insert(i);
    rep(i, 0, m) {
        u[i] = D.find(u[i]);
        v[i] = D.find(v[i]);
        if(u[i] == v[i]) continue;
        D.join(u[i], v[i]);
        int U = D.find(u[i]);
        if(U == u[i]) swap(u[i], v[i]);
        for(int x : se[u[i]]) {
            if(x < n && ti[x] == -1 && se[v[i]].count(x + 1) > 0) {
                ti[x] = i + 1;
            }
            if(x > 1 && ti[x - 1] == -1 && se[v[i]].count(x - 1) > 0) {
                ti[x - 1] = i + 1;
            }
        }
        se[v[i]].insert(all(se[u[i]]));
    }
    sparse<int, greater<int>> S(ti);
    rep(i, 0, q) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        if(l < r) {
            ans = S.query(l, r - 1);
        }
        cout << ans << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}