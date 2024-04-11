#include <cstdio>
using namespace std;

const int Maxl = 3005;
const int Maxn = 105;
const int mod = 1000000007;

int n, l;
int a[Maxn], b[Maxn];
int ways[Maxl][Maxn][2];
int res;

int main()
{
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) scanf("%d %d", &a[i], &b[i]);
    for (int i = 0; i < n; i++) {
        if (a[i] <= l) ways[a[i]][i][0]++;
        if (a[i] != b[i] && b[i] <= l) ways[b[i]][i][1]++;
    }
    for (int i = 1; i < l; i++)
        for (int j = 0; j < n; j++)
            for (int c = 0; c < 2; c++) {
                int need = c? a[j]: b[j];
                if (i + need > l) continue;
                for (int k = 0; k < n; k++) if (j != k)
                    if (a[k] == need) ways[i + need][k][0] = (ways[i + need][k][0] + ways[i][j][c]) % mod;
                    else if (b[k] == need) ways[i + need][k][1] = (ways[i + need][k][1] + ways[i][j][c]) % mod;
            }
    for (int j = 0; j < n; j++)
        for (int c = 0; c < 2; c++) res = (res + ways[l][j][c]) % mod;
    printf("%d\n", res);
    return 0;
}