#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 410;
int dp[maxN / 2][maxN / 2][maxN];
short prv[maxN / 2][maxN / 2][maxN];
short prvs[maxN / 2][maxN / 2][maxN];
short prvt[maxN / 2][maxN / 2][maxN];
string s, t;
int vals[maxN];
int valt[maxN];
const int INF = (int)1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> s >> t;
    int n = s.size() + t.size();
    for (int i = 0; i <= s.size(); i++) {
        for (int j = 0; j <= t.size(); j++) {
            for (int k = 0; k <= n + 1; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') vals[i] = 1;
        else vals[i] = -1;
    }

    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '(') valt[i] = 1;
        else valt[i] = -1;
    }
    dp[0][0][0] = 0;
    for (int c = 0; c <= s.size(); c++) {
        for (int d = 0; d <= t.size(); d++) {
            for (int bal = 0; bal <= n; bal++) {
                if (dp[c][d][bal] == INF) continue;
                for (int r = -1; r <= 1; r += 2) {
                    if (bal + r < 0) continue;
                    int nc = c;
                    if (c != s.size() && vals[c] == r) nc++;
                    int nd = d;
                    if (d != t.size() && valt[d] == r) nd++;
                    if (dp[nc][nd][bal + r] > dp[c][d][bal] + 1) {
                        prv[nc][nd][bal + r] = r;
                        prvs[nc][nd][bal + r] = c;
                        prvt[nc][nd][bal + r] = d;
                        dp[nc][nd][bal + r] = dp[c][d][bal] + 1;
                    }
                }
            }
            for (int bal = n; bal >= 0; bal--) {
                if (dp[c][d][bal] == INF) continue;
                for (int r = -1; r <= 1; r += 2) {
                    if (bal + r < 0) continue;
                    int nc = c;
                    if (c != s.size() && vals[c] == r) nc++;
                    int nd = d;
                    if (d != t.size() && valt[d] == r) nd++;
                    if (dp[nc][nd][bal + r] > dp[c][d][bal] + 1) {
                        prv[nc][nd][bal + r] = r;
                        prvs[nc][nd][bal + r] = c;
                        prvt[nc][nd][bal + r] = d;
                        dp[nc][nd][bal + r] = dp[c][d][bal] + 1;
                    }
                }
            }
            for (int bal = 0; bal <= n; bal++) {
                if (dp[c][d][bal] == INF) continue;
                for (int r = -1; r <= 1; r += 2) {
                    if (bal + r < 0) continue;
                    int nc = c;
                    if (c != s.size() && vals[c] == r) nc++;
                    int nd = d;
                    if (d != t.size() && valt[d] == r) nd++;
                    if (dp[nc][nd][bal + r] > dp[c][d][bal] + 1) {
                        prv[nc][nd][bal + r] = r;
                        prvs[nc][nd][bal + r] = c;
                        prvt[nc][nd][bal + r] = d;
                        dp[nc][nd][bal + r] = dp[c][d][bal] + 1;
                    }
                }
            }
            for (int bal = n; bal >= 0; bal--) {
                if (dp[c][d][bal] == INF) continue;
                for (int r = -1; r <= 1; r += 2) {
                    if (bal + r < 0) continue;
                    int nc = c;
                    if (c != s.size() && vals[c] == r) nc++;
                    int nd = d;
                    if (d != t.size() && valt[d] == r) nd++;
                    if (dp[nc][nd][bal + r] > dp[c][d][bal] + 1) {
                        prv[nc][nd][bal + r] = r;
                        prvs[nc][nd][bal + r] = c;
                        prvt[nc][nd][bal + r] = d;
                        dp[nc][nd][bal + r] = dp[c][d][bal] + 1;
                    }
                }
            }
        }
    }
    int best = 0;
//    for (int i = 0; i <= n; i++) {
//        if (dp[s.size()][t.size()][i] < dp[s.size()][t.size()][best]) best = i;
//    }
    int a = s.size();
    int b = t.size();
    int bal = best;
    string ans;
    while (a > 0 || b > 0 || bal > 0) {
        int symb = prv[a][b][bal];
        if (symb == 1) ans += '(';
        else ans += ')';
        int na = prvs[a][b][bal];
        int nb = prvt[a][b][bal];
        a = na;
        b = nb;
        bal -= symb;
//        if (a > 0 && vals[a - 1] == symb) a--;
//        if (b > 0 && valt[b - 1] == symb) b--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}