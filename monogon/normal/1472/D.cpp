
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
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    rep(i, 0, n) {
        if(i % 2 == a[i] % 2) {
            if(i % 2 == 0) ans += a[i];
            else ans -= a[i];
        }
    }
    cout << (ans > 0 ? "Alice" : ans == 0 ? "Tie" : "Bob") << '\n';
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