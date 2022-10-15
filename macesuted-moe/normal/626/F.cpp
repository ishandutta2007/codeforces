#include <bits/stdc++.h>
using namespace std;

const int maxn = 510, maxk = 1010, mod = 1e9 + 7;

long long f[2][maxn][maxk], ans;
int N, K, M, base[maxn], dif[maxn];

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++) scanf("%d", &base[i]);
    sort(base + 1, base + N + 1);
    f[0][1][0] = f[0][0][0] = 1;
    for (int i = 1; i < N; i++) dif[i] = base[i + 1] - base[i];
    for (int d = 1, i = 1; i < N; i++, d ^= 1) {
        int o = d ^ 1;
        for (int j = 0; j <= N; ++j) {
            int op = dif[i] * j;
            for (int k = 0; k <= K; ++k) {
                int val = k + op;
                long long res = f[o][j][k], v = res * j % mod;
                f[o][j][k] = 0;
                if (val > K) continue;
                if (j) f[d][j - 1][val] = (f[d][j - 1][val] + v) % mod;
                f[d][j][val] = (f[d][j][val] + v + res) % mod;
                f[d][j + 1][val] = (f[d][j + 1][val] + res) % mod;
            }
        }
    }
    for (int i = 0; i <= K; ++i)
        ans = (ans + f[(N - 1) & 1][0][i]) % mod;
    printf("%lld\n", ans);
    return 0;
}