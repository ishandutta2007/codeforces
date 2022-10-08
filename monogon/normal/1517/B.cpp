
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
    int n, m;
    cin >> n >> m;
    vi b(m), mi(m, INT_MAX);
    vi p(m);
    vector<pii> ve;
    rep(i, 0, n) {
        ve.clear();
        rep(j, 0, m) {
            cin >> b[j];
            ve.push_back({mi[j], j});
        }
        sort(all(ve));
        sort(all(b), greater<>());
        rep(j, 0, m) {
            int idx = ve[j].second;
            mi[idx] = min(mi[idx], b[j]);
            p[idx] = b[j];
        }
        rep(j, 0, m) {
            cout << p[j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}