#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 505;
const int Inf = 2000000007;

int T;
int n;
int B[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < 2 * n; i++)
            for (int j = 0; j < 2 * n; j++)
                scanf("%d", &B[i][j]);
        int add = Inf;
        ll res = 0;
        for (int i = n; i < 2 * n; i++)
            for (int j = n; j < 2 * n; j++)
                res += B[i][j];
        add = min(add, B[0][n]);
        add = min(add, B[0][2 * n - 1]);
        add = min(add, B[n - 1][n]);
        add = min(add, B[n - 1][2 * n - 1]);
        add = min(add, B[n][0]);
        add = min(add, B[n][n - 1]);
        add = min(add, B[2 * n - 1][0]);
        add = min(add, B[2 * n - 1][n - 1]);
        res += add;
        printf("%I64d\n", res);
    }
    return 0;
}