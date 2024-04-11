#include<bits/stdc++.h>
using namespace std;
const int nax = 512;
const int INF = 1e9;
void upd_max(int &a, int b) {
    a = max(a, b);
}
/**
    Oops, I misread the problem, the very very important detail....,
    you must change one of the element to zero...

    Straight forward dp might work well

    dp[t][lst][moves] = maximum score in t-th turn if last element at postion t = lst
    and we spend moves times doing operation.

    By must replacing, for example, let's say we move from
    k -> t we have to spend exactly k - t moves,
    dp[t + 1][lst][moves + 1] = dp[t][lst][moves] + a[lst]
    dp[t + 1][lst][moves + lst - x] = dp[t][x = 0 ... lst-1][moves] + a[lst]

    doing prefix maximum on such array is straightforward,
*/

int dp[nax][nax];
int nxt[nax][nax];
int pref[nax][nax];
int n;
int a[nax];

void fill_array(decltype(dp) dp) {
    for (int i = 0 ; i <= n ; ++ i)
    for (int j = 0 ; j <= n ; ++ j) {
        dp[i][j] = -INF;
    }
}

int main() {
    cin >> n;
    for (int i = 0 ; i < n ; ++ i)
        cin >> a[i];
    fill_array(dp);
    fill_array(pref);

    dp[0][0] = 0;
    for (int i = 0 ; i < n ; ++ i) pref[i][0] = 0;

    for (int i = 0 ; i < n ; ++ i) {
        fill_array(nxt);
        if (i == 0) upd_max(nxt[0][0], a[0]);
        for (int lst = 0 ; lst < n ; ++ lst)
        for (int m = 0 ; m <= i + 1 ; ++ m) {
            if (m && dp[lst][m - 1] != - INF)
                upd_max(nxt[lst][m], dp[lst][m - 1] + a[lst]);
            if (lst >= max(i, 1) && m - (lst - i) >= 0 && pref[lst - 1][m - (lst - i)] != - INF)
                upd_max(nxt[lst][m], pref[lst - 1][m - (lst - i)] + a[lst]);
        }

        swap(dp, nxt);
        for (int i = 0 ; i < n ; ++ i)
        for (int j = 0 ; j <= n ; ++ j) {
            pref[i][j] = dp[i][j];
            if (i > 0) upd_max(pref[i][j], pref[i - 1][j]);
        }
    }

    int ans = 0;

    for (int i = 0 ; i <= n ; ++ i)
    for (int j = 0 ; j <= n ; ++ j) {
        upd_max(ans, dp[i][j]);
    }

    cout << ans << '\n';

}