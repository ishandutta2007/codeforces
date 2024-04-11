
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
    n *= 2;
    vector<ll> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    sort(all(a));
    rep(i, 0, n - 1) {
        ll x = a[i] + a[n - 1];
        ll x1 = x;
        multiset<ll> se(all(a));
        bool ok = true;
        vector<pair<ll, ll>> ops;
        while(!se.empty() && ok) {
            ll val = *prev(se.end());
            se.erase(prev(se.end()));
            auto it = se.find(x - val);
            if(it == se.end()) {
                ok = false;
                break;
            }
            ops.push_back({val, *it});
            se.erase(it);
            x = val;
        }
        if(ok) {
            cout << "YES\n";
            cout << x1 << '\n';
            for(auto &pa : ops) {
                cout << pa.first << ' ' << pa.second << '\n';
            }
            return;
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