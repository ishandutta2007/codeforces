
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
    int n; ll k;
    cin >> n >> k;
    vector<ll> h(n + 1, 0);
    rep(i, 1, n + 1) {
        cin >> h[i];
    }
    ll L = h[1], R = h[1];
    rep(i, 2, n + 1) {
        ll L2 = max(h[i], L - k + 1);
        ll R2 = min(R + k - 1, h[i] + k - 1);
        if(L2 > R2) {
            cout << "NO\n";
            return;
        }
        L = L2;
        R = R2;
    }
    if(L > h[n]) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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