#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const char hard[6] = " hard";

int cost[maxn];
char str[maxn];
long long f[maxn][20];

int main() {
    int n;
    scanf("%d%s", &n, str + 1);
    for (int i = 1; i <= n; i++) scanf("%d", cost + i);
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i < 5; i++) f[0][i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < 5; j++)
            f[i][j] = str[i] == hard[j] ? min(f[i - 1][j - 1], f[i - 1][j] + cost[i]) : f[i - 1][j];
    printf("%lld\n", min(min(f[n][1], f[n][2]), min(f[n][3], f[n][4])));
    return 0;
}