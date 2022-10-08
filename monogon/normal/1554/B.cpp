
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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    ll ans = 1LL * n * (n - 1) - k * (a[n] | a[n - 1]);
    for(int i = n; i >= 1; i--) {
        for(int j = i - 1; j >= 1 && 1LL * i * j >= ans; j--) {
            ans = max(ans, 1LL * i * j - 1LL * k * (a[i] | a[j]));
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