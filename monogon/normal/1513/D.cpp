
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
        a.resize(n);
        rep(i, 0, n) a[i] = i;
    }
    int trace(int x) {
        return a[x] == x ? x : a[x] = trace(a[x]);
    }
    void join(int x, int y) {
        a[trace(x)] = trace(y);
    }
};

void solve() {
    int n;
    ll p;
    cin >> n >> p;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    dsu D(n + 1);
    vi le(n, 0), ri(n, n - 1);
    vi st;
    rep(i, 0, n) {
        while(!st.empty() && a[i] % a[st.back()] != 0) {
            ri[st.back()] = i - 1;
            st.pop_back();
        }
        st.push_back(i);
    }
    st.clear();
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && a[i] % a[st.back()] != 0) {
            le[st.back()] = i + 1;
            st.pop_back();
        }
        st.push_back(i);
    }
    vector<tuple<ll, int, int>> ve;
    rep(i, 0, n) {
        if(a[i] < p) ve.push_back({a[i], le[i], ri[i]});
    }
    ve.push_back({p, 0, n - 1});
    sort(all(ve));
    ll ans = 0;
    for(auto &pa : ve) {
        ll w; int l, r;
        tie(w, l, r) = pa;
        l = D.trace(l);
        r = D.trace(r);
        while(l != r) {
            D.join(l, l + 1);
            ans += w;
            l = D.trace(l);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}