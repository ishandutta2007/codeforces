
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

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll val = 0;
    vi smh;
    rep(i, 0, n) {
        cin >> a[i];
        if(i % 2 == 0) {
            val += a[i];
        }else {
            val -= a[i];
        }
    }
    auto cnt = [&](int i) {
        if(i < 0 || i >= n) return 0;
        ll s = 0;
        if(i > 0) s += a[i - 1];
        if(i + 1 < n) s += a[i + 1];
        return (s < a[i] ? 1 : 0);
    };
    int c = 0;
    rep(i, 0, n) c += cnt(i);
    if(c == 0 && val == 0) {
        cout << "YES\n";
        return;
    }
    rep(i, 0, n - 1) {
        ll x = a[i] - a[i + 1];
        if(i % 2 == 1) x = -x;
        if(2 * x == val) {
            ll c1 = c;
            c -= cnt(i - 1);
            c -= cnt(i);
            c -= cnt(i + 1);
            c -= cnt(i + 2);
            swap(a[i], a[i + 1]);
            c += cnt(i - 1);
            c += cnt(i);
            c += cnt(i + 1);
            c += cnt(i + 2);
            if(c == 0) {
                cout << "YES\n";
                return;
            }
            swap(a[i], a[i + 1]);
            c = c1;
        }
    }
    cout << "NO\n";
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