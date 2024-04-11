#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 105;
const int Maxm = 10005;

int n, m;
int lw[Maxn][Maxn], sum[Maxn][Maxn], len[Maxn];
ll mx[Maxn][Maxn];
ll res[Maxm];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &len[i]);
        for (int j = 1; j <= len[i]; j++) {
            int a; scanf("%d", &a);
            sum[i][j] = sum[i][j - 1] + a;
        }
        fill(lw[i] + 1, lw[i] + len[i] + 1, 1000000000);
        for (int j = 0; j <= len[i]; j++)
            for (int l = j + 1; l <= len[i]; l++)
                lw[i][l - j] = min(lw[i][l - j], sum[i][l] - sum[i][j]);
        for (int j = 0; j <= len[i]; j++) mx[i][len[i] - j] = sum[i][len[i]] - lw[i][j];
    }
    for (int i = 0; i < n; i++)
        for (int j = m - 1; j >= 0; j--)
            for (int l = 0; l <= len[i] && j + l <= m; l++)
                res[j + l] = max(res[j + l], res[j] + mx[i][l]);
    printf("%I64d\n", res[m]);
    return 0;
}