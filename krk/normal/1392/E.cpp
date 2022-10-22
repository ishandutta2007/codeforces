#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 30;

int n;
ll B[Maxn][Maxn];

void Print(int r, int c)
{
    printf("%d %d\n", r + 1, c + 1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) if (i % 2 == 0) {
            if (i == 0 && j == 0 || i == n - 1 && j == n - 1) continue;
            B[i][j] = 1ll << ll(i + j - 1);
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            printf("%I64d%c", B[i][j], j + 1 < n? ' ': '\n');
    fflush(stdout);
    int q; scanf("%d", &q);
    while (q--) {
        ll k; scanf("%I64d", &k);
        int r = 0, c = 0;
        Print(r, c);
        for (int i = 0; i < 2 * n - 2; i++) {
            ll md = k % (1ll << ll(i + 1));
            k -= md;
            if (r + 1 < n && B[r + 1][c] == md) r++;
            else c++;
            Print(r, c);
        }
        fflush(stdout);
    }
    return 0;
}