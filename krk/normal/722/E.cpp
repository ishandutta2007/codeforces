#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef long long ll;

const int Maxn = 200005;
const int Maxm = 2005;
const int Maxk = 23;
const int mod = 1000000007;

int fac[Maxn], inv[Maxn];
int n, m, k, s;
iii seq[Maxm];
bool st, en;
int dp[Maxm][Maxk];
int res;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int C(int n, int k)
{
    if (n < 0 || k < 0 || k > n) return 0;
    return ll(fac[n]) * inv[k] % mod * inv[n - k] % mod;
}

int Get(int s, int tims)
{
    while (tims--)
        s = (s + 1) / 2;
    return s;
}

int main()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(i) * fac[i - 1] % mod;
        inv[i] = Inv(fac[i]);
    }
    scanf("%d %d %d %d", &n, &m, &k, &s);
    int pnt = 0;
    for (int i = 0; i < k; i++) {
        int r, c; scanf("%d %d", &r, &c);
        if (ii(r, c) == ii(1, 1)) st = true;
        else if (ii(r, c) == ii(n, m)) en = true;
        else seq[pnt++] = iii(r + c, ii(r, c));
    }
    seq[pnt++] = iii(n + m, ii(n, m));
    k = pnt;
    sort(seq, seq + k);
    if (st) s = (s + 1) / 2;
    if (n == 1 && m == 1) { printf("%d\n", s); return 0; }
    for (int i = 0; i < k; i++) {
        auto p = seq[i].second;
        dp[i][1] = C(p.first + p.second - 2, p.first - 1);
    }
    for (int i = 0; i < k; i++) {
        auto p1 = seq[i].second;
        for (int j = 1; j < Maxk; j++) if (dp[i][j])
            for (int ni = i + 1; ni < k; ni++) {
                auto p2 = seq[ni].second;
                int ways = ll(dp[i][j]) * C(p2.first + p2.second - p1.first - p1.second, p2.first - p1.first) % mod;
                dp[ni][j] = (dp[ni][j] - ways + mod) % mod;
                if (j + 1 < Maxk)
                    dp[ni][j + 1] = (dp[ni][j + 1] + ways) % mod;
            }
    }
    int all = C(n + m - 2, n - 1);
    int alli = Inv(all);
    for (int j = 1; j < Maxk; j++) {
        int ways = dp[k - 1][j];
        all = (all - ways + mod) % mod;
        res = (res + ll(Get(s, j - int(!en))) * ways) % mod;
    }
    res = (res + all) % mod;
    res = ll(res) * alli % mod;
    printf("%d\n", res);
    return 0;
}