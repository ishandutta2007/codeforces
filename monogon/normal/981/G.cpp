
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

const int M = 998244353;

struct upd {
    ll badd, bmul;
    upd(ll badd = 0, ll bmul = 1) : badd(badd), bmul(bmul) {}
    void apply(const upd &u) {
        badd = (badd * u.bmul + u.badd) % M;
        bmul = (bmul * u.bmul) % M;
    }
};

struct node {
    ll B;
    node(ll B = 0) : B(B) {}
    void apply(const upd &u, int l, int r) {
        B = (u.bmul * B + u.badd * (r - l + 1)) % M;
    }
    node operator+(const node &o) const {
        return node((B + o.B) % M);
    }
};

struct rage {
    vector<node> a;
    vector<upd> lazy;
    rage(int n) {
        a.assign(4 * n + 5, node());
        lazy.assign(4 * n + 5, upd());
    }
    void prop(int i, int l, int r) {
        a[i].apply(lazy[i], l, r);
        if(l < r) {
            lazy[2 * i + 1].apply(lazy[i]);
            lazy[2 * i + 2].apply(lazy[i]);
        }
        lazy[i] = upd();
    }
    node query(int i, int l, int r, int L, int R) {
        if(r < L || R < l || R < L) return node();
        prop(i, l, r);
        if(L <= l && r <= R) return a[i];
        int m = (l + r) / 2;
        return query(2 * i + 1, l, m, L, R) + query(2 * i + 2, m + 1, r, L, R);
    }
    void update(int i, int l, int r, int L, int R, const upd &u) {
        if(R < L) return;
        prop(i, l, r);
        if(r < L || R < l) return;
        if(L <= l && r <= R) {
            lazy[i].apply(u);
            prop(i, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(2 * i + 1, l, m, L, R, u);
        update(2 * i + 2, m + 1, r, L, R, u);
        a[i] = a[2 * i + 1] + a[2 * i + 2];
    }
    // void print(int n) {
    //     rep(i, 1, n + 1) {
    //         node Q = query(0, 1, n, i, i);
    //         cout << i << ": " << Q.A << ' ' << Q.B << endl;
    //     }
    // }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    rage T(n + 1);
    vector<set<pii>> s(n + 1);
    while(q--) {
        int ty, l, r, x;
        cin >> ty >> l >> r;
        // T.print(n);
        if(ty == 1) {
            // insert
            cin >> x;
            auto it = s[x].lower_bound(make_pair(l, -1));
            if(it != s[x].begin() && prev(it)->second >= l) it--;
            vector<pii> ve;
            while(it != s[x].end() && it->first <= r) {
                ve.push_back(*it);
                it = s[x].erase(it);
            }
            if(ve.empty()) {
                T.update(0, 1, n, l, r, upd(1));
                s[x].insert(make_pair(l, r));
            }else {
                int k = sz(ve);
                rep(i, 0, k) {
                    T.update(0, 1, n, max(l, ve[i].first), min(r, ve[i].second), upd(0, 2));
                    if(i > 0) {
                        T.update(0, 1, n, ve[i - 1].second + 1, ve[i].first - 1, upd(1));
                    }
                }
                T.update(0, 1, n, l, ve[0].first - 1, upd(1));
                T.update(0, 1, n, ve.back().second + 1, r, upd(1));
                s[x].insert(make_pair(min(l, ve[0].first), max(r, ve.back().second)));
            }
        }else {
            // query
            node v = T.query(0, 1, n, l, r);
            cout << v.B << '\n';
        }
    }
}