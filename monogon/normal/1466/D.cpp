
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
    vector<pair<ll, int>> w;
    ll ans = 0;
    rep(i, 1, n + 1) {
        ll val;
        cin >> val;
        ans += val;
        w.push_back({val, i});
    }
    sort(w.rbegin(), w.rend());
    vi deg(n + 1, 0);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    int idx = 0;
    rep(k, 1, n) {
        cout << ans << ' ';
        if(k == n - 1) break;
        while(deg[w[idx].second] == 1) idx++;
        ans += w[idx].first;
        deg[w[idx].second]--;
    }
    cout << '\n';
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