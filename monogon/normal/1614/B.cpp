
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
    vi a(n + 1);
    vector<pii> ve;
    rep(i, 1, n + 1) {
        cin >> a[i];
        ve.push_back({a[i], i});
    }
    sort(all(ve), greater<>());
    vi ans(n + 1);
    int k = 1;
    ll cost = 0;
    for(auto &pa :ve) {
        int i = pa.second;
        ans[i] = k;
        cost += abs(k) * 1ll * pa.first;
        if(k < 0) k = -k + 1;
        else k = -k;
    }
    cout << cost * 2 << '\n';
    rep(i, 0, n + 1) cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}