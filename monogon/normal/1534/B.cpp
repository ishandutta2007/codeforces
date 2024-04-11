
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
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll cost = 0;
    rep(i, 0, n) {
        ll b = max((i == 0 ? 0 : a[i - 1]), (i == n - 1 ? 0 : a[i + 1]));
        cost += max(0LL, a[i] - b);
        a[i] = min(a[i], b);
    }
    cost += a[0] + a[n - 1];
    rep(i, 1, n) {
        cost += abs(a[i] - a[i - 1]);
    }
    cout << cost << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te = 1;
    cin >> te;
    while(te--) solve();
}