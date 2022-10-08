
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

set<ll> se;
vector<ll> a;

void lmao(int l, int r) {
    if(r <= l) return;
    ll sum = 0;
    rep(i, l, r) {
        sum += a[i];
    }
    se.insert(sum);
    if(a[l] == a[r - 1]) return;
    int M = (a[l] + a[r - 1]) / 2;
    int m = lower_bound(a.begin() + l, a.begin() + r, M + 1) - a.begin();
    lmao(l, m);
    lmao(m, r);
}

void solve() {
    int n, q;
    cin >> n >> q;
    a.assign(n, 0);
    rep(i, 0, n) {
        cin >> a[i];
    }
    sort(all(a));
    se.clear();
    lmao(0, n);
    while(q--) {
        ll s;
        cin >> s;
        cout << (se.count(s) ? "Yes\n" : "No\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}