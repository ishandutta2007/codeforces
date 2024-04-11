#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 10005, INF = 1E9 + 7;

int n, m, dp[2][N];
char s[N], t[N];
vector<pair<int, int>> st;
vector<int> mi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> (s + 1) >> (t + 1);
    n = strlen(s + 1) + 1;
    m = strlen(t + 1) + 1;
    s[n] = t[m] = '/';
    for (int i = 1; i <= m; i++) {
        int *cur = dp[i & 1], *prv = dp[(i & 1) ^ 1];
        st.clear(); mi.clear();
        st = {{0, -INF}}; mi = {INF};
        for (int j = 0, h = 0; j <= n; j++) {
            if (t[i] == s[j]) {
                cur[j] = mi.back() + h;
            }
            h += (s[j] == '.' ? -1 : 1);
            int ins = INF;
            while (st.back().se > h) {
                ins = min(ins, st.back().fi + 2 * st.back().se);
                st.pop_back(); mi.pop_back();
            }
            if (t[i - 1] == s[j]) {
                ins = min(ins, prv[j] + h);
            }
            if (ins < INF) {
                st.push_back({ins - 2 * h, h});
                mi.push_back(min(mi.back(), st.back().fi));
            }
        }
    }
    cout << dp[m & 1][n];
}