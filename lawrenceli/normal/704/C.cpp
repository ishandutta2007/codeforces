#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 100100;
const int mod = 1e9 + 7;

int n, m;
int vn[maxn], va[maxn][2];
vector<int> vp[maxn], adj[maxn];
bool vis[maxn];

int dp[2][2][2], dp2[2][2], dp3[2][2];

void add(int& a, int b) { a = (a + b) % mod; }

void go(vector<int> v, int x1, int v1) {
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    int cur = -1;
    for (int i = 0; i < vn[v[0]]; i++) {
        int x = abs(va[v[0]][i]);
        if (x == x1) continue;
        if (vp[x].size() == 1) {
            dp[0][1][0] = 1;
            cur = x;
        }
    }

    for (int i = 0; i < v.size(); i++) {
        int x = v[i];
        int nxt = -1;
        for (int j = 0; j < vn[x]; j++) {
            int a = abs(va[x][j]);
            if (a != x1 && a != cur) {
                nxt = a;
                break;
            }
        }

        if (nxt == -1) {
            assert(i + 1 == v.size());
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++) {
                    int val = 0;
                    for (int l = 0; l < vn[x]; l++) {
                        int a = abs(va[x][l]);
                        if (a == cur) val |= (j ^ (va[x][l] < 0));
                        else if (a == x1) val |= (v1 ^ (va[x][l] < 0));
                    }
                    add(dp[1][j][k ^ val], dp[0][j][k]);
                }

            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    dp[0][j][k] = dp[1][j][k], dp[1][j][k] = 0;

            continue;
        }

        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++) if (dp[0][j][k])
                for (int j1 = 0; j1 < 2; j1++) {
                    int val = 0;
                    for (int l = 0; l < vn[x]; l++) {
                        int a = abs(va[x][l]);
                        if (a == cur) val |= (j ^ (va[x][l] < 0));
                        else if (a == nxt) val |= (j1 ^ (va[x][l] < 0));
                        else if (a == x1) val |= (v1 ^ (va[x][l] < 0));
                    }

                    add(dp[1][j1][k ^ val], dp[0][j][k]);
                }

        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                dp[0][j][k] = dp[1][j][k], dp[1][j][k] = 0;

        cur = nxt;
    }

    if (v1 == 1) {
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                add(dp[0][j][k], dp3[j][k]);
    }

    if (v1 != 0) {
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                for (int k1 = 0; k1 < 2; k1++)
                    add(dp2[1][k1 ^ k], ll(dp2[0][k1]) * dp[0][j][k] % mod);

        for (int k = 0; k < 2; k++)
            dp2[0][k] = dp2[1][k], dp2[1][k] = 0;
    } else if (v1 == 0) {
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                dp3[j][k] = dp[0][j][k];
    }

    //for (int k = 0; k < 2; k++) cout << (dp[0][0][k] + dp[0][1][k]) % mod << endl;
}

void go2(vector<int> v) {
    int x = -1;
    for (int i = 0; i < vn[v[0]]; i++) {
        int a = abs(va[v[0]][i]);
        if (abs(va[v.back()][0]) == a || abs(va[v.back()][1]) == a) {
            x = a;
            break;
        }
    }

    assert(x != -1);
    memset(dp3, 0, sizeof(dp3));
    go(v, x, 0);
    go(v, x, 1);
}

int main() {
    scanf("%d %d", &n, &m);
    int mult = 1, st = 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &vn[i]);
        for (int j = 0; j < vn[i]; j++) scanf("%d", &va[i][j]);
        if (vn[i] == 1) vp[abs(va[i][0])].push_back(i);
        else {
            if (va[i][0] == -va[i][1]) {
                st = !st;
                vis[i] = 1;
            } else if (va[i][0] == va[i][1]) {
                vn[i] = 1;
                vp[abs(va[i][0])].push_back(i);
            } else {
                vp[abs(va[i][0])].push_back(i);
                vp[abs(va[i][1])].push_back(i);
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        assert(vp[i].size() <= 2);
        if (vp[i].size() == 2) {
            adj[vp[i][0]].push_back(vp[i][1]);
            adj[vp[i][1]].push_back(vp[i][0]);
        } else if (vp[i].size() == 0) mult = (mult * 2) % mod;
    }

    dp2[0][st] = mult;

    for (int i = 0; i < n; i++)
        if (!vis[i] && adj[i].size() < 2) {
            vector<int> v;
            int cur = i;
            while (1) {
                v.push_back(cur);
                vis[cur] = 1;
                int nxt = -1;
                for (int j : adj[cur])
                    if (!vis[j]) {
                        nxt = j;
                        break;
                    }

                if (nxt == -1) break;
                cur = nxt;
            }

            //for (int j : v) cout << j << ' '; cout << endl;
            go(v, -1, -1);
        }

    for (int i = 0; i < n; i++)
        if (!vis[i]) {
            vector<int> v;
            int cur = i;
            while (1) {
                v.push_back(cur);
                vis[cur] = 1;
                int nxt = -1;
                for (int j : adj[cur])
                    if (!vis[j]) {
                        nxt = j;
                        break;
                    }

                if (nxt == -1) break;
                cur = nxt;
            }

            //for (int j : v) cout << j << ' '; cout << endl;
            go2(v);
        }

    cout << dp2[0][0] << '\n';
}