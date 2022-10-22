#include <cstdio>
using namespace std;

const int Maxn = 100005;
const int Maxb = 31;

int n, m;
int l[Maxn], r[Maxn], q[Maxn];
int delt[Maxn][Maxb];
int cur[Maxb];
int res[Maxn];
int rfreq[Maxn][Maxb];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &l[i], &r[i], &q[i]);
        for (int j = 0; j < Maxb; j++)
            if (q[i] & 1 << j) {
                delt[l[i]][j]++;
                delt[r[i] + 1][j]--;
            }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < Maxb; j++) {
            cur[j] += delt[i][j];
            rfreq[i][j] = rfreq[i - 1][j];
            if (cur[j]) { res[i] |= 1 << j; rfreq[i][j]++; }
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < Maxb; j++)
            if (q[i] & 1 << j) {
                if (rfreq[r[i]][j] - rfreq[l[i] - 1][j] != r[i] - l[i] + 1) {
                    printf("NO\n");
                    return 0;
                }
            } else {
                if (rfreq[r[i]][j] - rfreq[l[i] - 1][j] >= r[i] - l[i] + 1) {
                    printf("NO\n");
                    return 0;
                }
            }
    printf("YES\n");
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}