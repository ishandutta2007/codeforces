
#pragma GCC optimize ("Ofast")

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

// source: https://cses.fi/paste/bb611ebcf13c6000135685/
// Submitted 2020-11-19
 
struct event {
    int x, y1, y2, d;
    event(int x, int y1, int y2, int d) : x(x), y1(y1), y2(y2), d(d) {}
    bool operator<(const event &e) const {
        return x < e.x;
    }
};
 
struct node {
    int mi, occ;
    node(int mi = 1e9, int occ = 0) : mi(mi), occ(occ) {}
    node operator+(const node &o) const {
        node x(min(mi, o.mi), 0);
        if(x.mi == mi) x.occ += occ;
        if(x.mi == o.mi) x.occ += o.occ;
        return x;
    }
};
 
const int N = 1e6 + 5;
node tree[4 * N];
int lazy[4 * N];
 
void build(int i, int l, int r) {
    lazy[i] = 0;
    if(l == r) {
        tree[i] = node(0, 1);
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
void prop(int i, int l, int r) {
    if(lazy[i] == 0) return;
    tree[i].mi += lazy[i];
    if(l < r) {
        lazy[2 * i + 1] += lazy[i];
        lazy[2 * i + 2] += lazy[i];
    }
    lazy[i] = 0;
}
node query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return node();
    prop(i, l, r);
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return query(2 * i + 1, l, m, L, R) + query(2 * i + 2, m + 1, r, L, R);
}
 
void upd(int i, int l, int r, int L, int R, int x) {
    prop(i, l, r);
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lazy[i] += x;
        prop(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, x);
    upd(2 * i + 2, m + 1, r, L, R, x);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
 
struct rect {
    int x1, y1, x2, y2;
    rect(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};
 
ll rectintersection(const vector<rect> &R) {
    vector<event> ve;
    ll ans = 0;
    ll MX = 1e6 + 2;
    for(auto &r : R) {
        ans += (r.x2 - r.x1) * 1ll * (r.y2 - r.y1);
        ve.push_back(event(r.x1, r.y1, r.y2 - 1, 1));
        ve.push_back(event(r.x2, r.y1, r.y2 - 1, -1));
    }
    sort(all(ve));
    int s = sz(ve);
    build(0, 0, MX);
    rep(i, 0, s - 1) {
        upd(0, 0, MX, ve[i].y1, ve[i].y2, ve[i].d);
        node x = query(0, 0, MX, 0, MX);
        int occ = MX + 1 - (x.mi == 0 ? x.occ : 0);
        ans -= 1LL * occ * (ve[i + 1].x - ve[i].x);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    // n = 1e6;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) {
        cin >> a[i];
        // a[i] = rand() % ((ll) 1e6);
    }
    vector<rect> R;
    ll ans = 0;
    vi lmin(n), rmin(n), lmax(n), rmax(n);

    // find ranges with stack
    vi st;
    rep(i, 0, n) {
        while(!st.empty() && a[st.back()] >= a[i]) st.pop_back();
        lmin[i] = (st.empty() ? -1 : st.back());
        st.push_back(i);
    }
    // rep(i, 0, n) cout << lmin[i] << ' ';
    // cout << '\n';
    
    st.clear();
    rep(i, 0, n) {
        while(!st.empty() && a[st.back()] <= a[i]) st.pop_back();
        lmax[i] = (st.empty() ? -1 : st.back());
        st.push_back(i);
    }
    // rep(i, 0, n) cout << lmax[i] << ' ';
    // cout << '\n';

    st.clear();
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && a[st.back()] > a[i]) st.pop_back();
        rmin[i] = (st.empty() ? n : st.back());
        st.push_back(i);
    }
    // rep(i, 0, n) cout << rmin[i] << ' ';
    // cout << '\n';

    st.clear();
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && a[st.back()] < a[i]) st.pop_back();
        rmax[i] = (st.empty() ? n : st.back());
        st.push_back(i);
    }
    // rep(i, 0, n) cout << rmax[i] << ' ';
    // cout << '\n';

    vi pop(n);
    rep(i, 0, n) {
        pop[i] = 0;
        rep(j, 0, 61) {
            if(a[i] >> j & 1) pop[i]++;
        }
    }

    const int MX = 1e6 + 5;
    rep(i, 0, n) {
        // cout << "element i = " << i << ": " << lmin[i] << ' ' << rmin[i] << "; " << lmax[i] << ' ' << rmax[i] << '\n';
        // assert(lmin[i] + 1 < i + 1);
        // assert(lmax[i] + 1 < i + 1);
        // assert(i < rmin[i]);
        // assert(i < rmax[i]);
        R.push_back(rect(pop[i] * MX + lmin[i] + 1, i, pop[i] * MX + i + 1, rmin[i]));
        R.push_back(rect(pop[i] * MX + lmax[i] + 1, i, pop[i] * MX + i + 1, rmax[i]));
    }
    ans += rectintersection(R);
    cout << ans << '\n';
}