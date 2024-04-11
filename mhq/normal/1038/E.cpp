#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 105;
int n;
int clr[maxN][2], val[maxN];
int bits[maxN];
int ans = 0;
vector < int > a[6][6];
bool in[maxN];
// C(2, 5) 1 << 10
int dp[1 << 10][1 << 4];
int ndp[1 << 10][1 << 4];
int pos[10][10];
pair < int, int > inv[maxN];
const int INF = (int)1e9;
bool used[maxN];
int sz = 0;
int back[maxN];
void dfs(int v, int& cnt, int mask) {
    used[v] = true;
    cnt++;
    for (int i = 0; i < sz; i++) {
        if (mask & (1 << i)) {
            auto t = inv[i];
            if (t.first == v) {
                if (!used[t.second]) dfs(t.second, cnt, mask);
            }
            if (t.second == v) {
                if (!used[t.first]) dfs(t.first, cnt, mask);
            }
        }
    }
}
void solve(int mask) {
    //cout << mask << endl;
    vector < int > all;
    for (int i = 0; i < 4; i++) {
        in[i] = false;
        if (mask & (1 << i)) {
            all.push_back(i);
            in[i] = true;
            back[i] = all.size() - 1;
        }
    }
    sz = 0;
    int k = all.size();
    for (int i = 0; i < k; i++) {
        for (int j = i; j < k; j++) {
            pos[back[all[i]]][back[all[j]]] = pos[back[all[j]]][back[all[i]]] = sz;
            inv[sz] = make_pair(back[all[i]], back[all[j]]);
            sz++;
        }
    }

    //cout << sz <<  " E" << endl;
    // 0 .. sz - 1
    for (int j = 0; j < (1 << sz); j++) {
        for (int t = 0; t < (1 << k); t++) {
            dp[j][t] = -INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        if (!in[clr[i][0]] || !in[clr[i][1]]) continue;
        for (int j = 0; j < (1 << sz); j++) {
            for (int t = 0; t < (1 << k); t++) {
                ndp[j][t] = -INF;
            }
        }
        for (int j = 0; j < (1 << sz); j++) {
            for (int t = 0; t < (1 << k); t++) {
                int x = back[clr[i][0]];
                int y = back[clr[i][1]];
                if (x > y) swap(x, y);
                ndp[j | (1 << pos[x][y])][(t ^ (1 << x)) ^ (1 << y)] = max(ndp[j | (1 << pos[x][y])][(t ^ (1 << x)) ^ (1 << y)],
                    dp[j][t] + val[i]);
                ndp[j][t] = max(ndp[j][t], dp[j][t]);
            }
        }
        for (int j = 0; j < (1 << sz); j++) {
            for (int t = 0; t < (1 << k); t++) {
                dp[j][t] = ndp[j][t];
            }
        }
    }
    for (int i = 0; i < (1 << sz); i++) {
        for (int j = 0; j < (1 << k); j++) {
            if (bits[j] > 2) continue;
            memset(used, 0, sizeof used);
            int cnt = 0;
            dfs(back[all[0]], cnt, i);
            if (cnt == k) ans = max(ans, dp[i][j]);
        }
    }
}
int main() {
    srand(123 + 23123123 + 123123 - 123123);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> clr[i][0] >> val[i] >> clr[i][1];
        clr[i][0]--;
        clr[i][1]--;
    }
    bits[0] = 0;
    for (int i = 1; i < 16; i++) {
        for (int j = 0; j < 4; j++) {
            if (i & (1 << j)) {
                bits[i] = bits[i ^ (1 << j)] + 1;
                break;
            }
        }
    }
    for (int mask = 1; mask < (1 << 4); mask++) {
        solve(mask);
    }
    cout << ans;
    return 0;
}