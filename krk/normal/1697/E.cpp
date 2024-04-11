#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Inf = 2000000007;
const int mod = 998244353;
const int Maxn = 105;

int fac[Maxn];
int C[Maxn][Maxn];
int n;
int X[Maxn], Y[Maxn];
vector <int> seq[Maxn];
int st;
vector <int> V;
bool tk[Maxn];
int dp[Maxn];

int getDist(int a, int b)
{
    return abs(X[a] - X[b]) + abs(Y[a] - Y[b]);
}

int main()
{
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    fac[0] = 1;
    for (int i = 1; i < Maxn; i++)
        fac[i] = ll(fac[i - 1]) * i % mod;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &X[i], &Y[i]);
    for (int i = 0; i < n; i++) {
        int best = Inf;
        for (int j = 0; j < n; j++) if (j != i) {
            int cur = getDist(i, j);
            if (cur < best) { best = cur; seq[i].clear(); }
            if (cur == best) seq[i].push_back(j);
        }
        seq[i].push_back(i);
        sort(seq[i].begin(), seq[i].end());
    }
    for (int i = 0; i < n; i++) if (!tk[i]) {
        bool ok = true;
        for (int j = 0; j < seq[i].size() && ok; j++) {
            int u = seq[i][j];
            ok = seq[i] == seq[u];
        }
        if (!ok) st++;
        else {
            int cnt = 0;
            for (int j = 0; j < seq[i].size(); j++) {
                int u = seq[i][j];
                cnt++;
                tk[u] = true;
            }
            V.push_back(cnt);
        }
    }
    dp[st] = 1;
    for (int i = 0; i < V.size(); i++)
        for (int j = n; j >= 0; j--) if (dp[j]) {
            int ways = dp[j]; dp[j] = 0;
            dp[j + V[i]] = (dp[j + V[i]] + ways) % mod;
            dp[j + 1] = (dp[j + 1] + ways) % mod;
        }
    int res = 0;
    for (int i = 0; i <= n; i++)
        res = (res + ll(dp[i]) * C[n][i] % mod * fac[i]) % mod;
    printf("%d\n", res);
    return 0;
}