
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
    int te;
    cin >> te;
    while(te--) {
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> a(n, vector<ll>(m, 0));
        rep(i, 0, n) rep(j, 0, m) {
            cin >> a[i][j];
        }
        ll ans = 0;
        rep(i, 0, (n + 1) / 2) rep(j, 0, (m + 1) / 2) {
            vector<ll> ve;
            ve.push_back(a[i][j]);
            if(n - i - 1 != i) ve.push_back(a[n - i - 1][j]);
            if(m - j - 1 != j) ve.push_back(a[i][m - j - 1]);
            if(n - i - 1 != i && m - j - 1 != j) ve.push_back(a[n - i - 1][m - j - 1]);
            sort(all(ve));
            ll med = ve[sz(ve) / 2];
            for(ll x : ve) {
                ans += abs(x - med);
            }
        }
        cout << ans << '\n';
    }
}