#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 2005;
const int Maxm = 35;
const int Maxb = 60;

int T;
int n, m;
vector <int> neigh[Maxn];
ll B[Maxn][Maxm];
int res[Maxn];

void Swap(int a, int b)
{
    for (int j = 0; j < Maxm; j++)
        swap(B[a][j], B[b][j]);
}

void Eliminate(int a, int b)
{
    for (int j = 0; j < Maxm; j++)
        B[b][j] ^= B[a][j];
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < m; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        int i = 1;
        while (i <= n && neigh[i].size() % 2 == 0) i++;
        if (i > n) {
            printf("1\n");
            for (int i = 1; i <= n; i++)
                printf("1%c", i + 1 <= n? ' ': '\n');
            continue;
        }
        for (int i = 1; i <= n; i++) {
            fill(B[i], B[i] + Maxm, 0ll);
            for (int j = 0; j < neigh[i].size(); j++)
                B[i][neigh[i][j] / Maxb] |= 1ll << ll(neigh[i][j] % Maxb);
            if (neigh[i].size() % 2) {
                B[i][(n + 1) / Maxb] |= 1ll << ll((n + 1) % Maxb);
                B[i][i / Maxb] |= 1ll << ll(i % Maxb);
            }
        }
        for (int i = 1; i <= n; i++) {
            int j = i;
            while (j <= n && !(B[j][i / Maxb] & 1ll << ll(i % Maxb))) j++;
            if (j > n) continue;
            if (i != j) Swap(i, j);
            for (j++; j <= n; j++) if (B[j][i / Maxb] & 1ll << ll(i % Maxb))
                Eliminate(i, j);
        }
        for (int i = n; i >= 1; i--) {
            res[i] = bool(B[i][(n + 1) / Maxb] & 1ll << ll((n + 1) % Maxb));
            for (int j = i + 1; j <= n; j++)
                if (B[i][j / Maxb] & 1ll << ll(j % Maxb))
                    res[i] ^= res[j];
        }
        printf("2\n");
        for (int i = 1; i <= n; i++)
            printf("%d%c", res[i] + 1, i + 1 <= n? ' ': '\n');
    }
    return 0;
}