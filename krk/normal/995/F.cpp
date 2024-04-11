#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 3005;
const int mod = 1000000007;

int fac[Maxn], inv[Maxn];
int n, d;
vector <int> neigh[Maxn];
int dp[Maxn][Maxn];
int res[Maxn];
int ans;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int a) { return toPower(a, mod - 2); }

int C(int n, int k)
{
    if (n < 0 || k < 0 || k > n) return 0;
    if (n < Maxn) return ll(fac[n]) * inv[k] % mod * inv[n - k] % mod;
    else {
        int res = 1;
        for (int i = 0; i < k; i++)
            res = ll(res) * (n - i) % mod;
        return ll(res) * inv[k] % mod;
    }
}

void Traverse(int v)
{
    for (int i = 1; i <= n; i++)
        dp[v][i] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        Traverse(u);
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            sum = (sum + dp[u][j]) % mod;
            dp[v][j] = ll(dp[v][j]) * sum % mod;
        }
    }
}

int main()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(i) * fac[i - 1] % mod;
        inv[i] = Inv(fac[i]);
    }
    scanf("%d %d", &n, &d);
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        neigh[p].push_back(i);
    }
    Traverse(1);
    for (int i = 1; i <= n; i++) {
        res[i] = dp[1][i];
        for (int j = 1; j < i; j++)
            res[i] = (res[i] - ll(res[j]) * C(i - 1, j - 1) % mod + mod) % mod;
        ans = (ans + ll(res[i]) * C(d, i)) % mod;
    }
    printf("%d\n", ans);
    return 0;
}