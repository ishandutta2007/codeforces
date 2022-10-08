
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
    int n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m, 0));
    const int C = 1e5 + 5;
    vector<vi> ve(2 * C);
    rep(i, 0, n) rep(j, 0, m) {
        cin >> a[i][j];
        ve[a[i][j]].push_back(i);
        ve[a[i][j] + C].push_back(j);
    }
    ll ans = 0;
    for(auto &v : ve) {
        sort(all(v));
        rep(i, 1, sz(v)) {
            ll dist = v[i] - v[i - 1];
            ans += dist * i * (v.size() - i);
        }
    }
    cout << ans << '\n';
}