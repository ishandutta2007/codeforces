#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 5005;

int T;
int n;
int a[Maxn];
int L[Maxn][Maxn], R[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int j = 1; j <= n; j++)
            L[0][j] = R[n + 1][j] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                L[i][j] = L[i - 1][j] + (a[i] < j);
        for (int i = n; i >= 1; i--)
            for (int j = 1; j <= n; j++)
                R[i][j] = R[i + 1][j] + (a[i] < j);
        ll res = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                res += ll(L[i - 1][a[j]]) * R[j + 1][a[i]];
        printf("%I64d\n", res);
    }
    return 0;
}