#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int dp[500][500];
constexpr int X0 = 250, Y0 = 250;
int cost[700][700][4];
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};
constexpr int INF = 1001001001;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    if (k & 1) {
        rep(i, n) rep(j, m) cout << -1 << " \n"[j + 1 == m];
        return 0;
    }
    k /= 2;
    rep(i, 700) rep(j, 700) rep(k, 4) cost[i][j][k] = -1;
    rep(i, n) rep(j, m - 1) {
        int x;
        cin >> x;
        cost[i][j][1] = cost[i][j+1][3] = x;
    }
    rep(i, n - 1) rep(j, m) {
        int x;
        cin >> x;
        cost[i][j][0] = cost[i+1][j][2] = x;
    }
    rep(i0, n) rep(j0, m) {
        dp[X0][Y0] = 0;
        rep(tt, k) {
            for(int i = 0; i <= tt + 1; i++) {
                for(int j = -tt - 1 + i; j <= tt + 1 - i; j += 2) {
                    dp[X0 + i][Y0 + j] = INF;
                    dp[X0 - i][Y0 + j] = INF;
                }
            }
            for(int i = 0; i <= tt; i++) {
                for(int j = -tt + i; j <= tt - i; j += 2) {
                    int V = dp[X0 + i][Y0 + j];
                    if (V == INF) continue;
                    int i1 = i0 + i, j1 = j0 + j;
                    if (!(0 <= i1 && i1 < n && 0 <= j1 && j1 < m)) continue;
                    rep(k, 4) {
                        int c = cost[i1][j1][k];
                        if (c == -1) continue;
                        int ni = i + di[k], nj = j + dj[k];
                        chmin(dp[X0 + ni][Y0 + nj], V + c);
                    }
                }
                for(int j = -tt + i; j <= tt - i; j += 2) {
                    int V = dp[X0 - i][Y0 + j];
                    if (V == INF) continue;
                    int i1 = i0 - i, j1 = j0 + j;
                    if (!(0 <= i1 && i1 < n && 0 <= j1 && j1 < m)) continue;
                    rep(k, 4) {
                        int c = cost[i1][j1][k];
                        if (c == -1) continue;
                        int ni = -i + di[k], nj = j + dj[k];
                        chmin(dp[X0 + ni][Y0 + nj], V + c);
                    }
                }
            }
        }
        int ans = INF;
        for(int j = -k; j <= k; j += 2) chmin(ans, dp[X0][Y0 + j]);
        for(int i = 1; i <= k; i++) {
            for(int j = -k + i; j <= k - i; j += 2) {
                chmin(ans, dp[X0 + i][Y0 + j]);
                chmin(ans, dp[X0 - i][Y0 + j]);
            }
        }
        cout << 2 * ans << " \n"[j0 + 1 == m];
    }
}