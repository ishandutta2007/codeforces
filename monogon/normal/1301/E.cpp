
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 505, K = 50;

int n, m, q, r1, c1, r2, c2;
string s[N];
int amt[N][N][4], val[N][N], dp[N][N][K];
map<char, int> ma = {{'R', 0}, {'G', 1}, {'Y', 2}, {'B', 3}};

bool iscolor(int r1, int r2, int c1, int c2, int col) {
    for(int k = 0; k < 4; k++) {
        int a = amt[r2][c2][k] - amt[r2][c1 - 1][k] - amt[r1 - 1][c2][k] + amt[r1 - 1][c1 - 1][k];
        if(a > 0 && k != col) return false;
    }
    return true;
}
int count(int r1, int r2, int c1, int c2, int v) {
    return dp[r2][c2][v] - dp[r1 - 1][c2][v] - dp[r2][c1 - 1][v] + dp[r1 - 1][c1 - 1][v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) cin >> s[i];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 0; k < 4; k++) {
                amt[i][j][k] = amt[i - 1][j][k] + amt[i][j - 1][k] - amt[i - 1][j - 1][k];
            }
            amt[i][j][ma[s[i][j - 1]]]++;
        }
    }
    vector<pair<int, int>> ve;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            int k = 0;
            for(; i - k >= 0 && i + k <= n && j - k >= 0 && j + k <= m; k++) {
                if(!iscolor(i - k + 1, i, j - k + 1, j, 0) ||
                   !iscolor(i - k + 1, i, j + 1, j + k, 1) ||
                   !iscolor(i + 1, i + k, j - k + 1, j, 2) ||
                   !iscolor(i + 1, i + k, j + 1, j + k, 3)) break;
            }
            val[i][j] = k - 1;
            if(val[i][j] >= K) ve.emplace_back(i, j);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 0; k < K; k++) {
                dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k];
            }
            if(val[i][j] < K) dp[i][j][val[i][j]]++;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = K - 2; k >= 0; k--) {
                dp[i][j][k] += dp[i][j][k + 1];
            }
        }
    }
    while(q--) {
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--;
        int best = 0;
        for(int k = 0; k < K && r1 + k <= r2 - k && c1 + k <= c2 - k; k++) {
            if(count(r1 + k, r2 - k, c1 + k, c2 - k, k) > 0) {
                best = max(best, k);
            }
        }
        for(auto p : ve) {
            auto [i, j] = p;
            best = max(best, min({val[i][j], i - r1, r2 - i, j - c1, c2 - j}));
        }
        cout << (4 * best * best) << "\n";
    }
}