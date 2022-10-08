
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
    vector<ll> ans(m + 1, -1), smh(m + 1, 0);
    ans[0] = 0;
    const ll N = 1e5;
    rep(s, 1, n + 1) {
        int ty;
        ll x, y;
        cin >> ty >> x >> y;
        fill(all(smh), 0);
        rep(i, 0, m + 1) {
            if(ans[i] != -1) {
                if(ans[i] != s) smh[i] = max(smh[i], y);
                if(smh[i] > 0) {
                    ll p2 = (ty == 1 ? (i * N + x + N - 1) / N : (i * x + N - 1) / N);
                    if(p2 <= m) {
                        if(ans[p2] == -1) ans[p2] = s;
                        smh[p2] = max(smh[p2], smh[i] - 1);
                    }
                }
            }
        }
    }
    rep(i, 1, m + 1) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}