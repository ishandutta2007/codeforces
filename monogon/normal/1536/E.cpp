
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
    vector<string> s(n);
    int cnt = 0;
    rep(i, 0, n) {
        cin >> s[i];
        for(char c : s[i]) {
            if(c == '#') cnt++;
        }
    }
    const int M = 1e9 + 7;
    ll ans = 1;
    rep(i, 0, cnt) ans = (2 * ans) % M;
    if(cnt == n * m) {
        ans = (ans + M - 1) % M;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}