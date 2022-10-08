
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<ll, int>> a(n);
    rep(i, 0, n) {
        ll v; cin >> v;
        a[i] = {v, i};
    }
    sort(all(a), greater<>());
    ll ans = 0, x = 0;
    rep(i, 0, n) {
        ans += a[i].first * x + 1;
        x++;
    }
    cout << ans << '\n';
    rep(i, 0, n) cout << a[i].second + 1 << ' ';
    cout << '\n';
}