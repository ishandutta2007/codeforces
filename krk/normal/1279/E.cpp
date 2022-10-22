#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000001ll;
const int Maxn = 52;

ll fac[Maxn];
ll dp[Maxn];
int T;
int n;
ll k;
int res[Maxn];

ll Mult(ll a, ll b)
{
    if (a == 0 || b == 0) return 0;
    if (a <= Inf / b) return a * b;
    return Inf;
}

ll Add(ll a, ll b) { return min(Inf, a + b); }

void Solve(int st, int n, ll k)
{
    if (n == 0) return;
    if (k <= dp[n - 1]) { res[st] = st; Solve(st + 1, n - 1, k); return; }
    else k -= dp[n - 1];
    for (int j = 2; j <= n; j++) {
        ll has = Mult(fac[j - 2], dp[n - j]);
        if (k <= has) {
            res[st] = st + j - 1;
            int tmp[Maxn] = {};
            for (int i = 0; i < j; i++)
                tmp[i] = i;
            tmp[j - 1] = 0;
            for (int i = 1; i + 1 < j; i++) {
                ll ways = Mult(fac[j - 2 - i], dp[n - j]);
                for (int a = 0; a + 1 < j; a++)
                    if (tmp[a] == a && tmp[i] != a)
                        if (k <= ways) {
                            res[st + i] = st + a;
                            for (int z = 0; z < j; z++)
                                if (tmp[z] == a)
                                    tmp[z] = tmp[i];
                            break;
                        } else k -= ways;
            }
            for (int a = 0; a + 1 < j; a++)
                if (tmp[a] == a) {
                    res[st + j - 1] = st + a;
                    break;
                }
            Solve(st + j, n - j, k);
            break;
        } else k -= has;
    }
}

int main()
{
    fac[0] = 1;
    for (int i = 1; i < Maxn; i++)
        fac[i] = Mult(fac[i - 1], i);
    dp[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        dp[i] = dp[i - 1];
        for (int j = 2; j <= i; j++)
            dp[i] = Add(dp[i], Mult(fac[j - 2], dp[i - j]));
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d %lld", &n, &k);
        if (k > dp[n]) { printf("-1\n"); continue; }
        Solve(1, n, k);
        for (int i = 1; i <= n; i++)
            printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}