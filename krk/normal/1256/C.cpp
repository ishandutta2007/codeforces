#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n, m, d;
int c[Maxn];
int S[Maxn];
int X[Maxn];
int res[Maxn];

int main()
{
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &c[i]);
        S[i] = S[i - 1] + c[i];
    }
    int lst = d;
    for (int i = 1; i <= m; i++) {
        int fir = n + 1 - (S[m] - S[i - 1]);
        X[i] = min(fir, lst);
        lst = X[i] + c[i] - 1 + d;
    }
    if (lst <= n) printf("NO\n");
    else {
        printf("YES\n");
        for (int i = 1; i <= m; i++)
            for (int j = 0; j < c[i]; j++)
                res[X[i] + j] = i;
        for (int i = 1; i <= n; i++)
            printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}