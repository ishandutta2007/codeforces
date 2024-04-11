
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
    int n, m, x;
    cin >> n >> m >> x;
    vi h(n);
    rep(i, 0, n) cin >> h[i];
    minpq<pair<ll, int>> Q;
    rep(i, 0, m) Q.push({0, i + 1});
    cout << "YES\n";
    rep(i, 0, n) {
        ll H;
        int idx;
        tie(H, idx) = Q.top(); Q.pop();
        cout << idx << ' ';
        Q.push({H + h[i], idx});
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