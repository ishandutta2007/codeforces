#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 1005;
const ll Inf = 9000000000000000000LL;

int n, m;
ll c[Maxn][Maxn];
int y, x;
ll mn1 = Inf, mn2 = Inf;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) scanf("%I64d", &c[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) c[i][0] += c[i][j];
    for (int j = 1; j <= m; j++)
        for (int i = 1; i <= n; i++) c[0][j] += c[i][j];
    for (int cand = 0; cand <= n; cand++) {
        ll sum = 0LL;
        for (int i = 1, d = 2; i <= n; i++, d += 4)
            sum += c[i][0] * ll(4 * cand - d) * ll(4 * cand - d);
        if (sum < mn1) { mn1 = sum; y = cand; }
    }
    for (int cand = 0; cand <= m; cand++) {
        ll sum = 0LL;
        for (int j = 1, d = 2; j <= m; j++, d += 4)
            sum += c[0][j] * ll(4 * cand - d) * ll(4 * cand - d);
        if (sum < mn2) { mn2 = sum; x = cand; }
    }
    printf("%I64d\n%d %d\n", mn1 + mn2, y, x);
    return 0;
}