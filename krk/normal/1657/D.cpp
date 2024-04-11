#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxm = 1000005;

int n, C;
ll best[Maxm];
int m;
ll D, H;

int main()
{
    scanf("%d %d", &n, &C);
    for (int i = 0; i < n; i++) {
        int c, d, h; scanf("%d %d %d", &c, &d, &h);
        best[c] = max(best[c], ll(d) * h);
    }
    for (int i = 1; i <= C; i++)
        for (int j = i + i; j <= C; j += i)
            best[j] = max(best[j], best[i] * ll(j / i));
    for (int i = 1; i <= C; i++)
        best[i] = max(best[i], best[i - 1]);
    scanf("%d", &m);
    while (m--) {
        scanf("%I64d %I64d", &D, &H);
        int ind = upper_bound(best, best + C + 1, D * H) - best;
        printf("%d%c", ind <= C? ind: -1, m? ' ': '\n');
    }
    return 0;
}