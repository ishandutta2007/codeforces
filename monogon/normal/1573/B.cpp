
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
    vi pos(2 * n + 1);
    rep(i, 0, 2 * n) {
        int a;
        cin >> a;
        pos[a] = i % n;
    }
    for(int i = 3; i < 2 * n; i += 2) {
        pos[i] = min(pos[i], pos[i - 2]);
    }
    for(int i = 2 * n - 2; i >= 2; i -= 2) {
        pos[i] = min(pos[i], pos[i + 2]);
    }
    int ans = 2 * n;
    for(int i = 1; i < 2 * n; i += 2) {
        ans = min(ans, pos[i] + pos[i + 1]);
    }
    cout << ans << '\n';
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