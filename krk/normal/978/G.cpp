#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int n, m;
int S[Maxn], D[Maxn], C[Maxn];
bool ex[Maxn];
int res[Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &S[i], &D[i], &C[i]);
        res[D[i]] = m + 1;
    }
    for (int i = 1; i <= n; i++) if (!res[i]) {
        int my = 0;
        for (int j = 1; j <= m; j++)
            if (S[j] <= i && i < D[j] && C[j] > 0 && (my == 0 || D[j] < D[my]))
                my = j;
        if (my > 0) {
            res[i] = my;
            C[my]--;
        }
    }
    for (int i = 1; i <= m; i++)
        if (C[i] > 0) { printf("-1\n"); return 0; }
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}