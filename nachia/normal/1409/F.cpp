#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N, K;
vector<int> S;
bool same;

int score(vector<int> & S) {
    int dx=0, x=0;
    for (int c : S) {
        if (c == 1) dx++;
        if (c == -1) x += dx;
    }
    return x;
}

int main() {
    cin >> N >> K;
    string Sbuf, Tbuf;
    cin >> Sbuf >> Tbuf;
    same = (Tbuf[0] == Tbuf[1]);
    for (char c : Sbuf) {
        if (c == Tbuf[0]) S.push_back(1);
        else if (c == Tbuf[1]) S.push_back(-1);
        else S.push_back(0);
    }

    if (same) {
        int ans = 0;
        rep(i, N) if (S[i] != 0)ans++;
        ans = min(N, ans + K);
        ans = ans * (ans - 1) / 2;
        cout << ans << endl;
    }
    else {
        int dp[202][202][202];
        rep(n, N + 1) rep(dx, N + 1)rep(k, K + 1) dp[n][dx][k] = -1000000000;
        dp[0][0][0] = 0;
        rep(n, N) rep(dx, N)rep(k, K + 1) {
            if (S[n] == 0) dp[n + 1][dx][k] = max(dp[n + 1][dx][k], dp[n][dx][k]);
            if (S[n] == 1) dp[n + 1][dx + 1][k] = max(dp[n + 1][dx + 1][k], dp[n][dx][k]);
            if (S[n] == -1) dp[n + 1][dx][k] = max(dp[n + 1][dx][k], dp[n][dx][k] + dx);
            dp[n + 1][dx][k + 1] = max(dp[n + 1][dx][k + 1], dp[n][dx][k]);
            dp[n + 1][dx + 1][k + 1] = max(dp[n + 1][dx + 1][k + 1], dp[n][dx][k]);
            dp[n + 1][dx][k + 1] = max(dp[n + 1][dx][k + 1], dp[n][dx][k] + dx);
        }
        int ans = 0;
        rep(dx, N) ans = max(ans, dp[N][dx][K]);
        cout << ans << endl;
    }

    return 0;
}