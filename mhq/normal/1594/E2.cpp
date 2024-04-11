#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, ll b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int F[65];
int k;
int n;
const int maxP = 2002 * 65 * 10;
int clr[maxP];
int dp[maxP][6];
int nxt[maxP][2];
int SZ = 0;
void add(ll x, int c) {
    vector<int> digs;
    while (x > 1) {
        digs.emplace_back(x % 2);
        x /= 2;
    }
    reverse(digs.begin(), digs.end());
    int st = 0;
    for (int z = 0; z < digs.size(); z++) {
        if (nxt[st][digs[z]] == -1) {
            nxt[st][digs[z]] = ++SZ;
        }
        st = nxt[st][digs[z]];
    }
    clr[st] = c;
}
void dfs(int v, int k) {
    if (k == 1) {
        if (clr[v] != -1) {
            dp[v][clr[v]] = 1;
        }
        else {
            for (int z = 0; z < 6; z++) {
                dp[v][z] = 1;
            }
        }
        return;
    }
    else {
        if (nxt[v][0] == -1 && nxt[v][1] == -1) {
            if (clr[v] != -1) {
                dp[v][clr[v]] = F[k];
            }
            else {
                for (int z = 0; z < 6; z++) {
                    dp[v][z] = F[k];
                }
            }
            return;
        }
        if (nxt[v][0] == -1) {
            nxt[v][0] = ++SZ;
        }
        if (nxt[v][1] == -1) {
            nxt[v][1] = ++SZ;
        }
        dfs(nxt[v][0], k - 1);
        dfs(nxt[v][1], k - 1);
        for (int z = 0; z < 6; z++) {
            if (clr[v] != -1 && z != clr[v]) continue;
            for (int was1 = 0; was1 < 6; was1++) {
                for (int was2 = 0; was2 < 6; was2++) {
                    if ((was1 / 2) == (z / 2) || (was2 / 2) == (z / 2)) {
                        continue;
                    }
                    dp[v][z] = sum(dp[v][z], mult(dp[nxt[v][0]][was1], dp[nxt[v][1]][was2]));
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> k;
    for (int z = 1; z <= k; z++) {
        F[z] = pw(4, (1LL << z) - 2);
    }
    cin >> n;
    vector<pair<ll,int>> t;
    memset(clr, -1, sizeof clr);
    memset(nxt, -1, sizeof nxt);
    for (int i = 1; i <= n; i++) {
        ll x;
        string s;
        cin >> x >> s;
        int c = 0;
        if (s == "white") c = 0;
        else if (s == "yellow") c = 1;
        else if (s == "green") c = 2;
        else if (s == "blue") c = 3;
        else if (s == "red") c = 4;
        else c = 5;
        add(x, c);
    }
    dfs(0, k);
    int ans = 0;
    for (int z = 0; z < 6; z++) {
        ans = sum(ans, dp[0][z]);
    }
    cout << ans << '\n';
    return 0;
}