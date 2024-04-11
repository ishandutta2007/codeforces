#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int m;
int B[2][Maxn];
int L[Maxn], R[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &m);
        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &B[i][j]);
        for (int j = 1; j <= m; j++)
            L[j] = L[j - 1] + B[1][j];
        R[m + 1] = 0;
        for (int j = m; j >= 1; j--)
            R[j] = R[j + 1] + B[0][j];
        int res = 2000000000;
        for (int j = 1; j <= m; j++)
            res = min(res, max(L[j - 1], R[j + 1]));
        printf("%d\n", res);
    }
    return 0;
}