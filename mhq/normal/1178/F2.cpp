#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = (int)1e6 + 100;
const int maxC = 505;
int c[maxN];
int n, m;
const int LG = 21;
vector < int > all[505];
int mn[LG][maxN];
int last[maxC], first[maxC];
int lg[maxN];
int get_min(int l, int r) {
    int len = r - l + 1;
    int p = lg[len];
    return min(mn[p][l], mn[p][r - (1 << p) + 1]);
}
int dp[maxC][maxC];
int who[maxC];
int val[maxC];
int getR[maxC][maxC];
int getL[maxC][maxC];
bool is_valid[maxC][maxC];
int g[maxC];
int id[maxC];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
        all[c[i]].push_back(i);
    }
    all[0].push_back(0);
    all[0].push_back(m + 1);
    c[0] = c[m + 1] = 0;
    for (int i = 0; i <= n; i++) {
        first[i] = all[i][0];
        last[i] = all[i].back();
    }
    memset(dp, 0, sizeof dp);
    bool bad = false;
    vector < pair < int, int > > by_first;
    for (int i = 1; i <= n; i++) {
        by_first.emplace_back(first[i], i);
    }
        for (int clr2 = 1; clr2 <= n; clr2++) {
            if (bad) break;
            for (int i = first[clr2]; i <= last[clr2]; i++) {
                if (c[i] < clr2) {
                    bad = true;
                    break;
                }
            }
        }
    if (bad) {
        cout << 0;
        return 0;
    }
    sort(by_first.begin(), by_first.end());
    for (int i = 0; i < n; i++) {
        who[i + 1] = by_first[i].second;
        val[i + 1] = by_first[i].first;
        id[by_first[i].second] = i + 1;
    }
    for (int i = 1; i <= n; i++) {
        getL[i][i] = first[who[i]];
        getR[i][i] = last[who[i]];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            getL[i][j] = min(getL[i][j - 1], getL[j][j]);
            getR[i][j] = max(getR[i][j - 1], getR[j][j]);
        }
    }
    for (int len = 0; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (l > r) {
                dp[l][r] = 1;
                is_valid[l][r] = true;
                continue;
            }
            int mn = n + 1;
            bool ok = true;
            int realL = getL[l][r];
            int realR = getR[l][r];
            for (int j = l; j <= r; j++) {
                mn = min(mn, who[j]);
                if (first[who[j]] < realL || first[who[j]] > realR) {
                    ok = false;
                    break;
                }
            }
            is_valid[l][r] = ok;
            for (int j = 1; j < l; j++) {
                if (last[who[j]] >= realL && last[who[j]] <= realR) {
                    is_valid[l][r] = false;
                    break;
                }
            }
            for (int j = r + 1; j <= n; j++) {
                if (first[who[j]] <= realR) {
                    is_valid[l][r] = false;
                    break;
                }
            }
            if (!is_valid[l][r]) {
                dp[l][r] = 0;
                continue;
            }
            int updL = all[mn][0];
            int updR = all[mn].back();
            int coef = 1;
            if (updL != realL || updR != realR) {
                coef = mult(coef, g[mn]);
            }
            else {
                //assert(mn == l);
                int nowl = l + 1;
                int nowr = nowl - 1;
                g[mn] = 1;
                for (int k = 0; k + 1 < all[mn].size(); k++) {
                    while (nowr + 1 <= n && getR[nowl][nowr + 1] <= all[mn][k + 1]) nowr++;
                    g[mn] = mult(g[mn], dp[nowl][nowr]);
                    nowl = nowr + 1;
                    nowr = nowl - 1;
                }
                coef = g[mn];
            }
            int where = id[mn];
            int le = 0;
            int ri = 0;
            for (int x = l - 1; x <= where - 1; x++) {
                le = sum(le, mult(dp[l][x], dp[x + 1][where - 1]));
            }
            where = -1;
            for (int j = l; j <= r; j++) {
                if (val[j] > last[mn]) {
                    where = j;
                    break;
                }
            }
            if (where == -1) ri = 1;
            else {
                for (int x = where - 1; x <= r; x++) {
                    ri = sum(ri, mult(dp[where][x], dp[x + 1][r]));
                }
            }
            dp[l][r] = mult(coef, mult(le, ri));
        }
    }
    cout << dp[1][n];
    return 0;
}