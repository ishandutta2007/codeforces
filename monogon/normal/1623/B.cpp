
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
    vector<pii> ve;
    rep(i, 0, n) {
        int a, b;
        cin >> a >> b;
        ve.push_back({a, b});
    }
    sort(all(ve), [&](auto pa, auto pb) { return pa.second - pa.first > pb.second - pb.first; });
    auto solve = [&](auto solve, int l, int r) -> void {
        if(l >= r) return;
        int d = ve[l].first;
        rep(i, l + 1, r) {
            if(ve[i].first == ve[l].first) {
                d = max(d, ve[i].second + 1);
            }
        }
        cout << ve[l].first << ' ' << ve[l].second << ' ' << d << '\n';
        auto idx = stable_partition(ve.begin() + l + 1, ve.begin() + r, [&](auto pa) {
            return pa.first < d;
        }) - ve.begin();
        solve(solve, l + 1, idx);
        solve(solve, idx, r);
    };
    solve(solve, 0, n);
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}