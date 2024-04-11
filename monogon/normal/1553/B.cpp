
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

// possible [index in s][index in t][left/right]

const int N = 505;
int dp[N][2 * N][2];

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    rep(i, 0, n + 1) rep(j, 0, m + 1) rep(b, 0, 2) {
        dp[i][j][b] = -1;
    }
    auto get = [&](auto get, int i, int j, bool b) -> bool {
        auto &d = dp[i][j][b];
        if(d != -1) return d;
        if(s[i] != t[j]) return (d = 0);
        if(b && get(get, i, j, false)) return (d = 1);
        if(b && i + 1 < n && j - 1 >= 0 && get(get, i + 1, j - 1, b)) return (d = 1);
        if(!b && i - 1 >= 0 && j - 1 >= 0 && get(get, i - 1, j - 1, b)) return (d = 1);
        if(j == 0) return (d = 1);
        return (d = 0);
    };
    rep(i, 0, n) {
        if(get(get, i, m - 1, 1)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}