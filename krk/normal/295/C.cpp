#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 205;
const int Maxm = 52;

int C[Maxm][Maxm];
int n, lim;
int thin, fat;
int ways[Maxn][Maxm][Maxm];

int main()
{
    for (int i = 0; i < Maxm; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    scanf("%d %d", &n, &lim);
    for (int i = 1; i <= n; i++) {
        int w; scanf("%d", &w);
        if (w == 50) thin++;
        else fat++;
    }
    ways[0][thin][fat] = 1;
    for (int i = 0; i < Maxn; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; j + k <= n; k++) if (ways[i][j][k]) {
                for (int l = 0; l <= j; l++)
                    for (int z = 0; z <= k && l * 50 + z * 100 <= lim; z++) if (l || z) {
                        int nt = thin - (j - l), nf = fat - (k - z);
                        ways[i + 1][nt][nf] = (ways[i + 1][nt][nf] + ll(ways[i][j][k]) * ll(C[j][l]) % ll(mod) * ll(C[k][z]) % ll(mod)) % mod;
                    }
            }
    int i = 1;
    while (i < Maxn && !ways[i][thin][fat]) i += 2;
    if (i >= Maxn) printf("-1\n0\n");
    else printf("%d\n%d\n", i, ways[i][thin][fat]);
    return 0;
}