
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
    vector<vi> cnt(n + 1);
    rep(i, 1, n + 1) {
        int a;
        cin >> a;
        cnt[a].push_back(i);
    }
    vi ans(n + 1, 0);
    vi ve;
    rep(i, 1, n + 1) {
        rep(j, 0, min(sz(cnt[i]), k)) {
            ve.push_back(cnt[i][j]);
        }
    }
    while(sz(ve) % k != 0) ve.pop_back();
    rep(i, 0, sz(ve)) {
        ans[ve[i]] = i % k + 1;
    }
    rep(i, 1, n + 1) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}