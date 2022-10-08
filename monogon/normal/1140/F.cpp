
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

const int N = 3e5 + 5;

struct ds {
    vector<int> a, cx, cy, st;
    ll ans = 0;
    ds() {
        a.assign(2 * N, -1);
        cx.assign(2 * N, 0);
        cy.assign(2 * N, 0);
        rep(i, 0, N) {
            cx[i] = 1;
            cy[N + i] = 1;
        }
    }
    int find(int x) {
        return a[x] < 0 ? x : find(a[x]);
    }
    int size(int x) {
        return -a[find(x)];
    }
    bool join(int x, int y) {
        if((x = find(x)) == (y = find(y))) {
            st.push_back(-1);
            return false;
        }
        if(a[x] > a[y]) swap(x, y);
        st.push_back(a[y]);
        st.push_back(y);
        st.push_back(x);
        ans -= 1LL * cx[x] * cy[x];
        ans -= 1LL * cx[y] * cy[y];
        cx[x] += cx[y];
        cy[x] += cy[y];
        a[x] += a[y];
        a[y] = x;
        ans += 1LL * cx[x] * cy[x];
        return true;
    }
    void push(const pii &pa) {
        join(pa.first, N + pa.second);
    }
    void pop() {
        assert(!st.empty());
        int x = st.back(); st.pop_back();
        if(x == -1) return;
        assert(!st.empty());
        int y = st.back(); st.pop_back();
        assert(!st.empty());
        int ay = st.back(); st.pop_back();
        ans -= 1LL * cx[x] * cy[x];
        a[y] = ay;
        a[x] -= a[y];
        cy[x] -= cy[y];
        cx[x] -= cx[y];
        ans += 1LL * cx[x] * cy[x];
        ans += 1LL * cx[y] * cy[y];
    }
    ll query() const {
        return ans;
    }
};

template<typename D, typename U, typename Q>
struct offline_deletion : public D {
    vector<Q> ans;
    vector<vector<U>> updates;
    int q;
    offline_deletion(int queries) : q(queries) {
        ans.resize(q);
        int lg = 0;
        while((1 << lg) < q) lg++;
        updates.resize(1 << (lg + 1));
    }
    void update(int i, int l, int r, int L, int R, U u) {
        if(r < L || R < l) return;
        if(L <= l && r <= R) {
            updates[i].push_back(u);
            return;
        }
        int m = (l + r) / 2;
        update(2 * i + 1, l, m, L, R, u);
        update(2 * i + 2, m + 1, r, L, R, u);
    }
    void insert(U u, int l, int r) {
        update(0, 0, q - 1, l, r, u);
    }
    void insert(U u, int l) {
        insert(u, l, q - 1);
    }
    void solve(int i, int l, int r) {
        for(auto &u : updates[i]) {
            D::push(u);
        }
        if(l == r) {
            ans[l] = D::query();
        }else {
            int m = (l + r) / 2;
            solve(2 * i + 1, l, m);
            solve(2 * i + 2, m + 1, r);
        }
        for(int j = 0; j < (int) updates[i].size(); j++) {
            D::pop();
        }
    }
    void solve() {
        solve(0, 0, q - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<pii, int> s;
    offline_deletion<ds, pii, ll> T(n);
    rep(i, 0, n) {
        int x, y;
        cin >> x >> y;
        if(s.count({x, y})) {
            T.insert({x, y}, s[{x, y}], i - 1);
            s.erase({x, y});
        }else {
            s[{x, y}] = i;
        }
    }
    for(auto &pa : s) {
        T.insert(pa.first, pa.second);
    }
    T.solve();
    for(ll x : T.ans) cout << x << ' ';
    cout << '\n';
}