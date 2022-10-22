#include <bits/stdc++.h>
using namespace std;

const int Maxn = 404;
const int Maxm = 3 * Maxn;

int n, m;
char A[Maxn][Maxn];
int r, c;
char B[Maxn][Maxn];
char str[Maxm];
int slen;
int Z[Maxm];
int res[Maxn][Maxn];

bool Eq(char a, char b) { return a == '?' || a == b; }

void Match(int bin, int ain)
{
    slen = 0;
    for (int j = 0; j < c; j++)
        str[slen++] = B[bin][j];
    int nd = m + c - 1;
    for (int j = 0; j < nd; j++)
        str[slen++] = A[ain][j % m];
    fill(Z, Z + slen, 0);
    int L = -1, R = -1;
    for (int i = 1; i < slen; i++) {
        if (i <= R) Z[i] = min(R - i, Z[i - L]);
        while (i + Z[i] < slen && Eq(str[Z[i]], str[i + Z[i]]))
            Z[i]++;
        if (Z[i] >= c && i >= c)
            res[(ain - bin % n + n) % n][i - c]++;
        if (i + Z[i] - 1 > R) {
            L = i; R = i + Z[i] - 1;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", A[i]);
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++)
        scanf("%s", B[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            Match(j, i);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d", res[i][j] >= r);
        printf("\n");
    }
    return 0;
}