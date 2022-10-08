
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
    int m, k;
    cin >> m >> k;
    vi a(k + 1);
    rep(i, 1, k + 1) cin >> a[i];
    int mx = *max_element(all(a));
    vector<pii> b;
    rep(i, 1, k + 1) b.push_back({a[i], i});
    sort(all(b), greater<>());
    a.clear();
    for(auto &pa : b) {
        rep(i, 0, pa.first) a.push_back(pa.second);
    }
    int cnt[4] = {0, 0, 0, 0};
    for(int n = 1; ; n++) {
        cnt[0] = ((n + 1) / 2) * ((n + 1) / 2);
        cnt[1] = cnt[2] = ((n + 1) / 2) * (n / 2);
        cnt[3] = (n / 2) * (n / 2);
        if(mx <= n * n - cnt[3] - cnt[2] && m <= cnt[0] + cnt[1] + cnt[2]) {
            vector<vi> ans(n, vi(n, 0));
            vector<vector<pii>> ve(4);
            rep(i, 0, n) rep(j, 0, n) {
                ve[(i % 2) + (j % 2 ? 2 : 0)].push_back({i, j});
            }
            vector<pii> v;
            v.insert(v.end(), all(ve[1]));
            v.insert(v.end(), all(ve[0]));
            v.insert(v.end(), all(ve[2]));
            int idx = 0;
            for(int x : a) {
                int i, j;
                tie(i, j) = v[idx];
                idx++;
                ans[i][j] = x;
            }
            cout << n << '\n';
            rep(i, 0, n) {
                rep(j, 0, n) {
                    cout << ans[i][j] << ' ';
                }
                cout << '\n';
            }
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}