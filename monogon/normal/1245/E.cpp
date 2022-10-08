
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 10;
int h[N][N];
int f[N * N];
double dp[N * N];

// i = row, j = col

pair<int, int> coord(int i) {
    int r = i / N;
    int c = i % N;
    if(r & 1) c = N - c - 1;
    return {r, c};
}
int getidx(int r, int c) {
    if(r & 1) c = N - c - 1;
    return N * r + c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> h[i][j];
            f[getidx(i, j)] = getidx(i - h[i][j], j);
        }
    }
    for(int i = 0; i < N * N; i++) {
        pair<int, int> p = coord(i);
        h[p.first][p.second] = i;
    }
    dp[0] = 0;
    dp[1] = 6.0 + dp[0];
    dp[2] = 3.0 + 0.5 * (dp[0] + dp[1]);
    dp[3] = 2.0 + (dp[0] + dp[1] + dp[2]) / 3.0;
    dp[4] = 1.5 + (dp[0] + dp[1] + dp[2] + dp[3]) / 4.0;
    dp[5] = 1.2 + (dp[0] + dp[1] + dp[2] + dp[3] + dp[4]) / 5.0;
    for(int i = 6; i < N * N; i++) {
        for(int j = 0; j < 6; j++) {
            dp[i] += min(dp[i - j - 1], dp[f[i - j - 1]]);
        }
        dp[i] = 1 + dp[i] / 6.0;
    }
    cout << fixed << setprecision(8) << dp[N * N - 1] << endl;
}