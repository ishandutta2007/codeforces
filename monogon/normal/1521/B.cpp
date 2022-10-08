
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

const int M = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    int cnt = 0;
    for(int i = 2; i <= n; i+=2) cnt++;
    cout << cnt << '\n';
    for(int i = 2; i <= n; i += 2) {
        cout << i - 1 << ' ' << i << ' ' << min(a[i - 1], a[i]) << ' ' << M << '\n';
        a[i] = M;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}