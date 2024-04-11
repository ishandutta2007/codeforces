
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

int DX[4] = {0, 0, -1, 1};
int DY[4] = {-1, 1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> ri(n, vi(m - 1)), dn(n - 1, vi(m));
    rep(i, 0, n) rep(j, 0, m - 1) cin >> ri[i][j];
    rep(i, 0, n - 1) rep(j, 0, m) cin >> dn[i][j];
    if(k % 2 == 1) {
        rep(i, 0, n) {
            rep(j, 0, m) {
                cout << -1 << ' ';
            }
            cout << '\n';
        }
        return 0;
    }
    vector<vector<vi>> dp(2, vector<vi>(n, vi(m, 0)));
    auto ins = [&](int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < m;
    };
    auto cost = [&](int i, int j, int x, int y) {
        if(i > x || j > y) {
            swap(i, x);
            swap(j, y);
        }
        if(i != x) return dn[i][j];
        else return ri[i][j];
    };

    rep(s, 1, k/2 + 1) {
        rep(i, 0, n) rep(j, 0, m) dp[1][i][j] = INT_MAX;
        rep(i, 0, n) rep(j, 0, m) {
            rep(d, 0, 4) {
                int x = i + DX[d];
                int y = j + DY[d];
                if(ins(x, y)) {
                    dp[1][i][j] = min(dp[1][i][j], cost(i, j, x, y) + dp[0][x][y]);
                }
            }
        }
        swap(dp[0], dp[1]);
    }
    
    rep(i, 0, n) rep(j, 0, m) {
        cout << 2*dp[0][i][j] << ' ';
        if(j == m - 1) cout << '\n';
    }
}