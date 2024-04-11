#include <bits/stdc++.h>
using namespace std;

const int Maxn = 70;

int T;
int n, m;
char B[Maxn][Maxn];
bool R[Maxn], C[Maxn];
bool hadR[Maxn], hadC[Maxn];
bool wasA, wasP;

void Solve()
{
    if (!wasA) { printf("MORTAL\n"); return; }
    if (!wasP) { printf("0\n"); return; }
    if (R[0] || R[n - 1] || C[0] || C[m - 1]) { printf("1\n"); return; }
    for (int i = 1; i < n - 1; i++)
        if (R[i]){ printf("2\n"); return; }
    for (int j = 1; j < m - 1; j++)
        if (C[j]) { printf("2\n"); return; }
    if (B[0][0] == 'A' || B[0][m - 1] == 'A' || B[n - 1][0] == 'A' || B[n - 1][m - 1] == 'A') {
        printf("2\n"); return;
    }
    if (hadR[0] || hadR[n - 1] || hadC[0] || hadC[m - 1]) { printf("3\n"); return; }
    printf("4\n");
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        fill(R, R + n, true);
        fill(C, C + m, true);
        fill(hadR, hadR + n, false);
        fill(hadC, hadC + m, false);
        wasA = wasP = false;
        for (int i = 0; i < n; i++) {
            scanf("%s", B[i]);
            for (int j = 0; j < m; j++)
                if (B[i][j] == 'P') {
                    wasP = true;
                    R[i] = C[j] = false;
                } else wasA = hadR[i] = hadC[j] = true;
        }
        Solve();
    }
    return 0;
}